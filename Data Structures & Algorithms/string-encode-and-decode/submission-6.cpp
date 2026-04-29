class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string enc = "";
        for ( auto& word : strs){
            enc += to_string(word.size()) + "#" + word;
        }
        return enc;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i<s.size()){
            int j = i+1;
            while(s[j]!='#')j++;
            int len = stoi(s.substr(i,j-i));
            result.push_back(s.substr(j+1,len));
            i = j+1+len;
        }
        return result;

    }
};
