class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        

        auto expand = [&](int l , int r){
           while(l>=0&&r<n&&s[l]==s[r]){
             l--;
             r++;
             count++;
           }
        };

        for(int i = 0;i<n;i++){
          expand(i,i);
          expand(i,i+1);
        }
        return count;
        
    }
};
