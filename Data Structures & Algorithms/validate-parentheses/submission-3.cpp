class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n==0 || n==1 ) return false;
        stack<char> st;
        unordered_map<char,char> matching={{')', '('}, {'}', '{'}, {']', '['}};

        for(char c : s){
            if(matching.count(c)){
                if(!st.empty()&&st.top()==matching[c]){
                    st.pop();
                } else {
                    return false;
                } 
            } else {
                st.push(c);
            }

            }
            return st.empty();
        }
        

    };