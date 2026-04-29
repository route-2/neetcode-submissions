class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        auto expand = [&](int l,int r){
            
                while(l>=0 && r<n && s[l]==s[r]){
                    count++;
                    l--;
                    r++;
                }
                
            };
        

        for(int i = 0;i<s.size();i++){
            expand(i,i);
            expand(i,i+1);
        }
        return count;
        
    }
};
