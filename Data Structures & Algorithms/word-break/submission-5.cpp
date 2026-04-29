class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();

        queue<int> q;
        vector<bool> visited(n + 1, false);

        // start exploring from index 0 (start of the string)
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            // try every word from this start index
            for (const auto& w : wordDict) {
                int len = (int)w.size();
                int next = start + len;

                // word must fit
                if (next > n) continue;

                // check if s[start..start+len-1] == w
                if (s.compare(start, len, w) != 0) continue;

                // if we reached the end, we successfully broke the string
                if (next == n) return true;

                // only push if we haven't explored this "next" index before
                // this prevents infinite repeats / extra work
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        return false;
    }
};
