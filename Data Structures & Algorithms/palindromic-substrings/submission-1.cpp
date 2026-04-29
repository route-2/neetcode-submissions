class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        int l = 0,r=0;

        int resIdx = 0, resLen = 0;

        for(int i = 0;i<n;i++){
            l = i;
            r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                count++;
                l--;
                r++;
            }

            
        }
        return count;

       
    }
};
