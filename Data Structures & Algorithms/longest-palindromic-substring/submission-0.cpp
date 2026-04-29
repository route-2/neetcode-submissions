class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
       int reslen,resIdx = 0;
        //odd length
       for(int i = 0;i<n;i++){
        int l = i;
        int r = i;
        while(l>=0 && r<n && s[l]==s[r]){
              if(r-l+1>reslen){
                reslen = r-l+1;
                resIdx=l;
              }
               l--;
        r++;
        }
       

        l = i;
        r = i+1;
        //even length
        while(l>=0 && r<n && s[l]==s[r]){
              if(r-l+1>reslen){
                reslen = r-l+1;
                resIdx = l;
              }
              l--;
              r++;
        }
       }

       return s.substr(resIdx,reslen);
  
   
        
    }
};
