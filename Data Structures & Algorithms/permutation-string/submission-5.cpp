class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();
        if (m > n) return false;

        vector<int> s1count(26, 0);
        vector<int> s2count(26, 0);

        // Count letters in s1 and in the first window of s2 (size m)
        for (int i = 0; i < m; i++) {
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }

        // matches = number of letters whose counts match exactly
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1count[i] == s2count[i]) matches++;
        }

        int l = 0;

        // Slide a window of length m across s2
        for (int r = m; r < n; r++) {

            // If all 26 letters match, current window is a permutation
            if (matches == 26) return true;

            // Add the new right character into the window
            int ind = s2[r] - 'a';
            s2count[ind]++;

            // If this letter becomes equal now, we gained a match
            if (s1count[ind] == s2count[ind]) {
                matches++;
            }
            // If it was equal before, then we just made it too large, so we lost a match
            else if (s1count[ind] + 1 == s2count[ind]) {
                matches--;
            }

            // Remove the left character from the window
            ind = s2[l] - 'a';
            s2count[ind]--;

            // If this letter becomes equal now, we gained a match
            if (s1count[ind] == s2count[ind]) {
                matches++;
            }
            // If it was equal before, then we just made it too small, so we lost a match
            else if (s1count[ind] - 1 == s2count[ind]) {
                matches--;
            }

            // Move left forward to keep window size m
            l++;
        }

        // Check the last window
        return matches == 26;
    }
};
