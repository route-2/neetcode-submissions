class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> mp;
      int n = strs.size();

     for(string word : strs){
        //ex: act
        vector<int> freq(26,0);
        //[0,0,0,0,.......]
        // a in act
        for(char c : word){
            //increment in index
            freq[c-'a']++;
        }
        string key = "";
        // iterate thru freq array
        for(int f : freq){
            // append string + the count + #
            key += to_string(f) + "#";
        }
        //at key position we push the word
        //"1#0#1#...1#..." → ["act", "cat", "tac"]

        mp[key].push_back(word);
     }
vector<vector<string>> result;
//gather all groups in map
//[ ["act", "cat", "tac"],
 // ["dog", "god"],
 // ["bat"] ]

for(auto &group : mp){
    result.push_back(group.second);
}
return result;

    
    }
};
