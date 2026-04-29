class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int num = 0;
         for (int i = n - 1; i >= 0; i--){
             if (digits[i] < 9) {      // no carry needed
                digits[i]++;
                return digits;
            }
             digits[i] = 0;   

         }
         digits.insert(digits.begin(), 1);
        return digits;
        
        


    }
};
