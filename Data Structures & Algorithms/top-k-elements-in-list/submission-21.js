class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const count = {};
        for(let n of nums){
            count[n] = (count[n] || 0) +1;

        }

         const buckets = Array.from({ length: nums.length + 1 }, () => []);
         for(let [num, freq] of Object.entries(count)){
            buckets[freq].push(Number(num));
         }

         const result = [];
         for (let i = buckets.length - 1; i >= 0 && result.length < k; i--) {
        result.push(...buckets[i]);
    }
    return result;

    }
}
