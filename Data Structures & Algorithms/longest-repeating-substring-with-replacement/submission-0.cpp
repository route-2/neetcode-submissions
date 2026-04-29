class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> freq;
        int left = 0;
        int maxf = 0;
        int res = 0;

       
      for(int right = 0;right<n;right++){
            freq[s[right]]++;
            maxf = max(maxf,freq[s[right]]);

            while((right-left+1)- maxf > k){
                freq[s[left]]--;
                left++;

            }
            res = max(res,right-left+1);
            
        
       
       
      }
      return res;

        
    }
};
