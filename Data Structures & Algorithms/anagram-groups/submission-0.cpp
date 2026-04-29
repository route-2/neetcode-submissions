class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n = strs.size();
        vector<bool> used(n, false); // Track grouped words
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue; // Skip if already grouped
            
            vector<string> group;
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            group.push_back(strs[i]);
            used[i] = true;

            for (int j = i + 1; j < n; j++) {
                string sortedComp = strs[j];
                sort(sortedComp.begin(), sortedComp.end());

                if (sortedWord == sortedComp) {
                    group.push_back(strs[j]);
                    used[j] = true;
                }
            }
            result.push_back(group);
        }

        return result; 
    }
};
