class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp2 = 0;
        int dp1 = 0;
        int dp = 0;
        dp1 = 1;
        for (int i = n - 1; i >= 0; i--) 
        {
            if (s[i] == '0') {
                dp = 0;
            } else {
                dp = dp1;
                 if (i + 1 < n && stoi(s.substr(i, 2)) <= 26) {
                   dp+=dp2;
                 }
            }
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        } 
        return dp1;
        
    }
};
