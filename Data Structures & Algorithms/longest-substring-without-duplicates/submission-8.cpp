class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        unordered_map<char,int> mp;
        int left = 0;

        for(int r = 0;r<n;r++){

            char ch = s[r];

            if(mp.find(s[r])!=mp.end() && mp[ch]>=left){
                left = mp[ch]+1;
            }
            mp[ch] = r;
            res = max(res,r-left+1);

        }
        return res;

        
    }
};
