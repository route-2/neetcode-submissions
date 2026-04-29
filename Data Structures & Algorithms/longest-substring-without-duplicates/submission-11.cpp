class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        //maps the char to the last index where it was found
        unordered_map<char,int> mp;
        int res = 0;
        int left , right = 0;

        for(right = 0;right<n;right++){
            char ch = s[right];
            if(mp.find(ch)!=mp.end() && mp[ch]>=left){
                       left = mp[ch]+1;
            }
            mp[ch] = right;
            res = max(res,right-left+1);
        }
        return res;
    }
};
