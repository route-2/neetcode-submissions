class Solution {
public:
    int hammingWeight(uint32_t n) {
 int count = 0;

        while (n > 0) {
            n = n & (n - 1);  // removes the last set bit
            count++;          // count how many times we removed a 1
        }

        return count;
    }
};
