class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        int resLen = 0;
        int l=0,r=0;

      
        
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                l = i;r = j;
                while(l<=r && s[l]==s[r]){
                    l++;
                    r--;
                }

                if(l>=r && resLen<j-i+1){
                    resLen = j-i+1;
                    res = s.substr(i,j-i+1);
                }
                
            }
        }
       
      return res;
   
        
    }
};
