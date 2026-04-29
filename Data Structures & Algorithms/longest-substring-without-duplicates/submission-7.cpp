class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;

        for(int i = 0;i<n;i++){

             unordered_set<char> ch;
             for(int j = i;j<n;j++){
                if(ch.find(s[j])!=ch.end()){
                    break;
                }
                ch.insert(s[j]);
             }
            res = max(res,(int)ch.size());

        }
        return res;

        
    }
};
