class Solution {
public:
   
    int numDecodings(string s) {

        int n = s.size();

        return dfs(0,s);   
    }
private:
   int dfs(int i, string& s){
    if(s[i]=='0') return 0;
    if(i==s.size()) return 1;

    int res = dfs(i+1,s);
    if(i<s.size()-1){
      if(s[i]=='1' || s[i] == '2' && s[i+1]<'7'){
        res+=dfs(i+2,s);
      }
    }
    return res;


   }
};
