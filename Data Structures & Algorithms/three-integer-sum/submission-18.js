class Solution {
  /**
   * LeetCode 15: 3Sum
   * @param {number[]} nums
   * @return {number[][]}  // list of unique triplets [a,b,c] such that a+b+c = 0
   */
  threeSum(nums) {
    const n = nums.length;

    // Sort ascending so:
    // 1) we can use two pointers (move l/r based on sum)
    // 2) duplicates become adjacent (easy to skip)
    nums.sort((a, b) => a - b);

    /*
      Comparator explanation:
      sort() calls compare(a, b) repeatedly.
      - return < 0  => a comes before b
      - return > 0  => a comes after b
      - return 0    => order doesn't matter for those two
      For numbers, (a - b) gives the right sign automatically.
    */

    const res = [];

    // Fix the first number at index i, then find pairs (l, r) that complete the triplet.
    for (let i = 0; i < n - 2; i++) {
      // Early stop: if nums[i] > 0, then nums[l] and nums[r] are also >= nums[i] (sorted),
      // so the sum can't be 0 anymore.
      if (nums[i] > 0) break;

      // Skip duplicate "first elements" so we don't repeat the same triplet set.
      if (i > 0 && nums[i] === nums[i - 1]) continue;

      // Two pointers for the remaining two numbers
      let l = i + 1;
      let r = n - 1;

      while (l < r) {
        const sum = nums[i] + nums[l] + nums[r];

        if (sum === 0) {
          // Found a valid triplet
          res.push([nums[i], nums[l], nums[r]]);

          // Move both pointers inward to look for the next possibility
          l++;
          r--;

          // Skip duplicates on the left pointer:
          // if nums[l] is the same as the previous value, it would create the same triplet again.
          while (l < r && nums[l] === nums[l - 1]) l++;

          // Skip duplicates on the right pointer for the same reason.
          while (l < r && nums[r] === nums[r + 1]) r--;

        } else if (sum > 0) {
          // Sum too big => decrease it by moving right pointer left
          r--;
        } else {
          // Sum too small => increase it by moving left pointer right
          l++;
        }
      }
    }

    return res;
  }
}
