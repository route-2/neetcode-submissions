class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
       vector<int> chars(128,0);
        int res = 0;
        int left , right = 0;

        while(right<n){
            char ch = s[right];
            if(chars[ch]==0){
                chars[ch]++;
                res = max(res,right-left+1);
                right++;
            }
            else {
                chars[s[left]]--;
                left++;
            }
        }
        return res;

        
    }
};
