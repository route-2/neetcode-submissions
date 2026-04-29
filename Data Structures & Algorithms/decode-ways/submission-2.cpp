class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1);
        int n = s.size();
        dp[n] = 1;

        for(int i = n-1;i>=0;i--){
            if(s[i]=='0') {
                dp[i]=0;
            } else {
                dp[i] = dp[i+1];
                if(i<n-1&& s[i] == '1' || s[i]=='2' && s[i+1]<'7'){
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
        
    }
};
