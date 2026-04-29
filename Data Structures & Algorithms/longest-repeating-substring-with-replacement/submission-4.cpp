class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> freq(26,0);
        int maxC = 0;
        int res = 0;

        for(right = 0;right<n;right++){
            freq[s[right]-'A']++;
            maxC = max(maxC,freq[s[right]-'A']);

            if((right - left + 1) - maxC > k){
                freq[s[left] - 'A']--;
                left++; // shrink window
            }
            res = max(res, right - left + 1); 

        }
        return res;
        
    }
};
