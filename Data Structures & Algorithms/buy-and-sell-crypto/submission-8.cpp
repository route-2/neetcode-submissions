class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        if(n==1) return 0;

        int prof = 0;
        int op = 0;
        int least = INT_MAX;

        for(int num : prices){
             if(least>num){
                least = num;
             }
             op = num - least;
             prof = max(op,prof);
        }
        return prof;
        
    }
};
