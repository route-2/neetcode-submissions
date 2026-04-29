class Solution {
public:

    string encode(vector<string>& strs) {
         string res;
          for (const string& s : strs) {
            res += to_string(s.size())+"#"+s;
          }
          return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while(i<s.size()){
            int j = i;
            while (s[j] != '#') {
                j++;
            } //breaks once # is found
            int len = stoi(s.substr(i,j-i));
            i = j+1; //move past delimitter start of new string
            j = i+len; // to the next number
            res.push_back(s.substr(i,len));
            i = j;

        }
        return res;

    }
};
