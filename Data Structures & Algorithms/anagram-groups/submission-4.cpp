class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> mp;
      int n = strs.size();

     for(string word : strs){
        vector<int> freq(26,0);
        for(char c : word){
            freq[c-'a']++;
        }
        string key = "";
        for(int f : freq){
            key += to_string(f) + "#";
        }
        mp[key].push_back(word);
     }
vector<vector<string>> result;
for(auto &group : mp){
    result.push_back(group.second);
}
return result;

    
    }
};
