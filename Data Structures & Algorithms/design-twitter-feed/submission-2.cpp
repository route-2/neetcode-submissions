#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    // "count" is our global timestamp.
    // We will DECREMENT it after every post: 0, -1, -2, -3, ...
    // That means: the NEWER the tweet, the SMALLER (more negative) the time.
    // This is useful because a MIN-HEAP can then pop the newest tweet first
    // (smallest time value = newest).
    int count;

    // tweetMap[userId] = list of that user's tweets.
    // Each tweet stored as: {time, tweetId}
    // The vector is in chronological order of posting:
    //    tweetMap[userId][0] is oldest kept
    //    tweetMap[userId].back() is newest kept
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    // followMap[followerId] = set of followees that followerId follows.
    // Example: followMap[1] = {2, 3} means user 1 follows users 2 and 3.
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        count = 0;
    }

    void postTweet(int userId, int tweetId) {
        // Store this tweet with its timestamp (count).
        // Pair = {time, tweetId}
        tweetMap[userId].push_back({count, tweetId});

        // Optional optimization:
        // Keep only the last 10 tweets PER USER in tweetMap to limit memory + speed.
        // If we have more than 10, remove the oldest one (begin()).
        if (tweetMap[userId].size() > 10) {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }

        // Decrement time so that newer tweets have smaller numbers (more negative).
        // Example: first tweet time=0, second tweet time=-1, third=-2 ...
        count--;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res; // result feed of tweetIds (size up to 10)

        // IMPORTANT: user should see their OWN tweets in their feed too.
        // Easiest trick: ensure they "follow themselves" during this query.
        // Using unordered_set means inserting twice is harmless.
        followMap[userId].insert(userId);

        // minHeap will store candidates for the "next tweet to show".
        //
        // We store each heap entry as a vector<int> of 4 fields:
        //   {time, tweetId, tweetOwnerUserId, nextIndex}
        //
        // time:         tweetMap[user][idx].first
        // tweetId:      tweetMap[user][idx].second
        // tweetOwner:   which user posted this tweet
        // nextIndex:    the index of that same user's NEXT older tweet we should consider
        //              (because after using the newest, we may want their 2nd newest, etc.)
        //
        // Comparator: greater<vector<int>> makes it a MIN-HEAP lexicographically.
        // So it compares first by time, then tweetId, then userId, then nextIndex.
        //
        // Because NEWER tweets have SMALLER time (more negative),
        // the minHeap.top() will always be the NEWEST tweet among all candidates.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // --------------------------------------------------------------------
        // The code has two branches:
        //   1) If followees >= 10, it tries to pre-select only ~10 "starting tweets"
        //      using another heap (maxHeap) then transfers them into minHeap.
        //   2) Else, it directly pushes each followee's newest tweet into minHeap.
        //
       
       
        if (followMap[userId].size() >= 10) {
            // maxHeap is intended to keep ONLY 10 "best" initial tweets when we
            // have many followees, to reduce how many items we put in minHeap.
            //
            // Each entry pushed here is:
            //   {-time, tweetId, userId, nextIndex}
            //
            // Why -time?
            //   Our time values are negative for newer tweets.
            //   Using -time turns "newer" into a larger positive number.
            //
            // CAUTION:
            //   default priority_queue<vector<int>> is a MAX-HEAP,
            //   meaning top() returns the lexicographically largest entry.
            priority_queue<vector<int>> maxHeap;

            // For every followee f (including userId themself),
            // push f's newest tweet into maxHeap as a starting candidate.
            for (auto f : followMap[userId]) {
                // If this followee has never tweeted, skip.
                if (!tweetMap.count(f)) continue;

                // idx = index of newest tweet for user f
                int idx = (int)tweetMap[f].size() - 1;

                // p = {time, tweetId} of that newest tweet
                auto &p = tweetMap[f][idx];

                // Push into maxHeap:
                //  -p.first  : (-time) so newer tweets become bigger numbers
                //  p.second  : tweetId
                //  f         : tweet owner
                //  idx - 1   : next older tweet index for this same user
                maxHeap.push({-p.first, p.second, f, idx - 1});

                // Try to keep only 10 entries in this heap.
               
                if (maxHeap.size() > 10) maxHeap.pop();
            }

            // Transfer candidates into minHeap.
            // maxHeap stores -time, minHeap expects time, so flip sign back.
            while (!maxHeap.empty()) {
                auto t = maxHeap.top();
                maxHeap.pop();

                // t is {-time, tweetId, user, nextIndex}
                // convert to {time, tweetId, user, nextIndex} for minHeap:
                minHeap.push({-t[0], t[1], t[2], t[3]});
            }

        } else {
            // Simpler (and standard) approach:
            // For each followee f, push their newest tweet into minHeap.
            for (auto f : followMap[userId]) {
                if (!tweetMap.count(f)) continue;

                int idx = (int)tweetMap[f].size() - 1; // newest tweet index
                auto &p = tweetMap[f][idx];            // p = {time, tweetId}

                // Push candidate tweet from user f into minHeap:
                // { time, tweetId, userId, nextIndex }
                minHeap.push({p.first, p.second, f, idx - 1});
            }
        }

        // --------------------------------------------------------------------
        // CORE MERGE LOGIC (most important part):
        //
        // We repeatedly take the newest available tweet among all followees.
        //
        // Key idea: "k-way merge" of many sorted lists.
        // Each followee's tweets are stored in order in tweetMap[f].
        //
        // Heap stores ONE "current candidate" tweet per followee.
        //
        // When we pop a tweet from some user u, we then push u's NEXT older tweet
        // (using the saved nextIndex) so that u remains represented in the heap.
        //
        // This continues until we collect 10 tweets or heap is empty.
        // --------------------------------------------------------------------
        while (!minHeap.empty() && res.size() < 10) {
            // Get the globally newest tweet candidate (because min time => newest).
            auto t = minHeap.top();
            minHeap.pop();

            // t = {time, tweetId, userId, nextIndex}
            // tweetId is t[1].
            res.push_back(t[1]);

            // nextIndex tells us: "the next older tweet index for this SAME user".
            // IMPORTANT: this is NOT a userId. It's an index in tweetMap[userId].
            int idx = t[3];

            // If idx >= 0, it means this user still has older tweets left.
            // If idx < 0, we already reached that user's oldest kept tweet.
            if (idx >= 0) {
                int user = t[2]; // tweet owner userId

                // p is the next older tweet for that same user
                // at position idx.
                auto &p = tweetMap[user][idx]; // p = {time, tweetId}

                // Push that older tweet into heap, and update nextIndex to idx-1.
                minHeap.push({p.first, p.second, user, idx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        // followerId starts following followeeId
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // followerId stops following followeeId (if they were following)
        if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};
