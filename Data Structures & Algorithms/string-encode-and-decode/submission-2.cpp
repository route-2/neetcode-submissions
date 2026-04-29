class Solution {
public:
    //"5#hello5#world4#leet4#code"

    string encode(vector<string>& strs) {
        string encoded = "";

       
       for(auto& word: strs){
        
         encoded += to_string(word.size()) + "#" + word;
       }
       return encoded;
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
