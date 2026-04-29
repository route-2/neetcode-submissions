class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int prof = 0;
       for(int i=0;i<n;i++){
           for(int j = i+1;j<n;j++){
            prof = max(prof,prices[j]-prices[i]);
           }
       }
       return prof;
    }
};
