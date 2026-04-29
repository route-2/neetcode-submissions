class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
         queue<int> q;
         int res = 0;
         if (amount == 0) return 0;
         vector<bool> seen(amount+1,false);

         q.push(0);
         seen[0]=true;

         while(!q.empty()){
            
             res++;
             int qsize = q.size();
            for(int i=0;i<qsize;i++){
                int curr = q.front();
               q.pop();

                for(int coin : coins){
                   
                      int nxt = curr+coin;
                      if(nxt==amount) return res;
                      if(nxt>amount || seen[nxt]) continue;
                      seen[nxt]=true;
                      q.push(nxt);
                      
                }
                

            }
         }
         return -1;

    }
};
