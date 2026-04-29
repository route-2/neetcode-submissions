class Solution {
public:
    //"5#hello5#world4#leet4#code"

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string& s : strs) {
            encoded += to_string(s.size()) + "#" + s; 
        }
        return encoded;
}

    vector<string> decode(string s) {
       vector<string> result;
        int i = 0;
        while(i<s.size()){
            int j = i+1;
            while (s[j] != '#') j++;
            //till we reach #
            //extract //"5 from 5#hello
            int len = stoi(s.substr(i,j-i));
            //using len get hello from 5#hello
            result.push_back(s.substr(j+1,len));
            //move to next string world
            // j is pos of #
            // plus 1 takes me to the word
            //to the next 5#world to decode
            i = j+1+len;  
        }
        return result;



    }
};
