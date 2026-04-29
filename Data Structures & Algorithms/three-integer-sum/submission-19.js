class Solution {
  /**
   * Brute-force 3Sum (O(n^3)) + Set for de-duplication
   * @param {number[]} nums
   * @return {number[][]}
   */
  threeSum(nums) {
    // We'll store unique triplets in a Set, but as STRINGS (because JS Sets
    // don't dedupe arrays by content—only by reference).
    const set = new Set();

    const n = nums.length;

    // Try every combination of 3 indices i < j < k
    for (let i = 0; i < n; i++) {
      for (let j = i + 1; j < n; j++) {
        for (let k = j + 1; k < n; k++) {

          // Check if this triplet sums to 0
          if (nums[i] + nums[j] + nums[k] === 0) {

            // Normalize the triplet by sorting it so the same values always look identical.

            // Example: [-1, 2, -1] -> [-1, -1, 2]
            const trip = [nums[i], nums[j], nums[k]].sort((a, b) => a - b);

            // Convert the triplet to a string key so Set can dedupe by VALUE.
            // Example: [-1, -1, 2] -> "-1,-1,2"
            /**
             * Set {
  "-1,-1,2",
  "-1,0,1" }


             */
            set.add(trip.join(","));
          }
        }
      }
    }

    // Convert Set<string> back into number[][]:
    // "-1,-1,2" -> ["-1","-1","2"] -> [-1,-1,2]
    return Array.from(set, s => s.split(",").map(Number));
  }
}
