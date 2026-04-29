class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int res = 0;
        unordered_set<int> store(nums.begin(),nums.end());
        int n = nums.size();

        for(int num : nums){
           
            if(store.find(num)!=store.end()){
                int len = 1;

                while(store.find(num+len)!=store.end()){
                    len++;

                }
                res=max(res,len);
            }
    
        }
        return res;


      
    }
};
