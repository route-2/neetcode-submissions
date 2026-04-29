class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp = 0, dp2 = 0;
        int dp1 = 1; //for single digit
        //121
        for(int i = n-1;i>=0;i--){
            //we dont count for 0 not in decode map 
            if(s[i]=='0') {dp = 0;}else{

            dp = dp1;  //single digit
            if(i<=n-1 && s[i]=='1' || s[i] =='2' && s[i+1]<'7'){ //two digit
              
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
