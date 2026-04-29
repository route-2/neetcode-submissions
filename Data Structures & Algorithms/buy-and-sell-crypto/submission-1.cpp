class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();

        if(n==0) return 0;
        if(n==1) return 0;
        
        int least = INT_MAX;
        int profit = 0;
        int op = 0;
       
       for(int i=0;i<n;i++){
        if(prices[i]<least){
                least = prices[i];
            }
            profit = prices[i]-least;
            op = max(profit,op);

        
         
       }
       return op;
    }
};
