class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        if(n==1) return 0;
        int maxP = 0;
        int Oprof = 0;
        int least = INT_MAX;

        for(int i = 0;i<n;i++){
            if(prices[i]<least){
                least = prices[i];
            }
            maxP = prices[i]-least;
            Oprof = max(maxP,Oprof);
 
        }
        return Oprof;


       
        
    }
};
