class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // slow and fast both start at index 0
        int slow = 0, fast = 0;

        // -------- PHASE 1: find a meeting point inside the cycle --------
        // slow moves 1 step at a time
        // fast moves 2 steps at a time
        // because a duplicate exists, a cycle MUST exist
        while (true) {
            slow = nums[slow];          // move slow by 1 step
            fast = nums[nums[fast]];    // move fast by 2 steps

            // when they meet, we know we are inside the cycle
            if (slow == fast) {
                break;
            }
        }

        // -------- PHASE 2: find the entrance of the cycle (duplicate) --------
        // start a new pointer from the beginning
        int slow2 = 0;

        // move both pointers 1 step at a time
        // they will meet at the entrance of the cycle
        while (true) {
            slow = nums[slow];      // move inside the cycle
            slow2 = nums[slow2];    // move from the start

            // the meeting point is the duplicate number
            if (slow == slow2) {
                return slow;
            }
        }
    }
};
