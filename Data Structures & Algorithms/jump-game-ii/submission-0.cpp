class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int end = 0;       // current jump "window" ends here
        int farthest = 0;  // farthest we can reach inside this window

        // we stop at n-2 because once we're at last index, no need to jump
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]); // best reach from current window

            // if we reached the end of current window, we must take a jump
            if (i == end) {
                jumps++;
                end = farthest; // new window after taking this jump
            }
        }

        return jumps;
    }
};