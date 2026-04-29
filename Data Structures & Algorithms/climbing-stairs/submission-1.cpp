class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
      
      
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
        return left + right;
       
        
    }
};
