class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0 ;
        int r = s.length()-1;

        while(l<r){
            //ignoring non-alphanumeric characters (like spaces, commas, :, ?, etc.).
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(r>l && !isalnum(s[r])){
                r--;
            }
            if(tolower(s[l])!=tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;

        
    }
};
