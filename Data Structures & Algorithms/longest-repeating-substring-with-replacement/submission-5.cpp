class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> freq(26,0);
        int maxC = 0;
        int res = 0;

        /*
Grow the window one character at a time (right++).
Update the count for that character.
Update maxC = the highest count of any letter in the window.
Check if window is still valid
        */

        for(right = 0;right<n;right++){
            freq[s[right]-'A']++;
            maxC = max(maxC,freq[s[right]-'A']);

//The number of characters to replace (window_size - maxC) is ≤ k.
            if((right - left + 1) - maxC > k){
                freq[s[left] - 'A']--;
                left++; // shrink window
            }
            res = max(res, right - left + 1); 

        }
        return res;
        
    }
};
