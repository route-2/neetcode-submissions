class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.length();
        int m = t.length();

        if(m!=n) return false;

        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;  // Increment for s
            freq[t[i] - 'a']--;  // Decrement for t
        }

         for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;  // Step 3: Check if all are zero
        }
        return true;


        
    }
};
