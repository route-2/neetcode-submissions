class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        const n = nums.length;
        nums.sort((a,b)=> a-b);

        /**
         * comparator gets called like compare(a, b) 
         * and must return:
negative → put a before b
positive → put a after b
0 → treat them as equal
         */
        const res = []
          for (let i = 0; i < n-2; i++) {
            if(nums[i]>0)break;
            if (i > 0 && nums[i] === nums[i - 1]) continue;
            let l = i+1
            let r = n-1
            while(l<r){
                 const sum = nums[i] + nums[l] + nums[r];
                 
                 if(sum===0){
                    res.push([nums[i], nums[l], nums[r]]);
                    l++;
                    r--;

                     while (l < r && nums[l] === nums[l - 1]) l++;
          while (l < r && nums[r] === nums[r + 1]) r--;
                 } else if (sum>0)r--;
                 else {
                    l++;
                 }
                
          }
          }
          return res;
    

    }
}
