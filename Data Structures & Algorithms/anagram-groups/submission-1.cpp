class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n = strs.size();
       unordered_map<string,vector<string>> mp;

       for(string word : strs){
        //pots
         string sortedWord = word;
         //opst
         sort(sortedWord.begin(),sortedWord.end());
         //opst -> pots
         mp[sortedWord].push_back(word);
       }
        vector<vector<string>> result;
        for(auto &group : mp){
             result.push_back(group.second);
        }

        return result;

    }
};
