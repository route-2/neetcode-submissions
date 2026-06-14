class Twitter:

    def __init__(self):
        # time, tweetMap, followMap
        self.time = 0
        self.tweetMap = defaultdict(list)
        self.followMap = defaultdict(set)
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        # add time, tweetid to tweetMap
        self.tweetMap[userId].append((self.time,tweetId))
        self.time += 1
        

    def getNewsFeed(self, userId: int) -> List[int]:
        # copy of tweetMap
        feed = self.tweetMap[userId][:]
        # for every followee in followmap
        # add tweets to your feed
        for followeeId in self.followMap[userId]:
            feed.extend(self.tweetMap[followeeId])
        # sort based on time
        feed.sort(key = lambda x : -x[0])
        # return the latest tweets 
        return [tweetId for _, tweetId in feed[:10]]
        

    def follow(self, followerId: int, followeeId: int) -> None:
        # if not follower, add followeeId to followerId
        if followerId != followeeId:
            self.followMap[followerId].add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].discard(followeeId)
        
