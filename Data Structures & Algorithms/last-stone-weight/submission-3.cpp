

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int W = 0;
        for (int s : stones) W = max(W, s);

        vector<int> count(W + 1, 0);
        for (int s : stones) count[s]++;

        int i = W;
        while (i > 0) {
            // find current heaviest available weight i
            while (i > 0 && count[i] == 0) i--;
            if (i == 0) return 0;

            // if we have at least two stones of weight i, smash pairs away
            if (count[i] >= 2) {
                count[i] %= 2;           // remove all pairs (i vs i)
                if (count[i] == 0) {     // no leftover i
                    continue;            // keep scanning from same i (it will drop via while)
                }
            }

            // now count[i] == 1 (one heaviest stone exists). find next heaviest j
            int j = i - 1;
            while (j > 0 && count[j] == 0) j--;

            if (j == 0) {
                // no second stone exists
                return i;
            }

            // smash i and j -> (i - j)
            count[i]--;
            count[j]--;
            count[i - j]++;

            // next iteration: i might still exist, or might need to drop down
            // (no need to increase i, since (i-j) <= i always)
        }

        return 0;
    }
};
