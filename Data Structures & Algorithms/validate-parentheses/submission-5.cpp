class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
         if(n==0 || n==1 ) return false;
        stack<char> st;
        unordered_map<char,char> sym = {{')','('},{'}','{'},{']','['}};

        for(char c : s){
            if(sym.count(c)){
                if(!st.empty() && st.top()==sym[c]){
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                st.push(c);
            }
        }
        return st.empty();

        
    }
};
