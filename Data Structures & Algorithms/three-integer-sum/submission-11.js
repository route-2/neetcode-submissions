class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
       const set = new Set();
        const n = nums.length;
        for(let i = 0;i<n;i++){
            for(let j = i+1;j<n;j++){
               for(let k = j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]===0){
                         const trip = [nums[i], nums[j], nums[k]].sort((a, b) => a - b);
                         set.add(trip.join(",")); 
                }
               }
            }
        }
        return Array.from(set, s => s.split(",").map(Number));
    }
   
}
