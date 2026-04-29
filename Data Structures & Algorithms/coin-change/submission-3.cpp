class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0 ) return 0;

        queue<int> q;
        q.push(0);

        vector<bool> seen(amount+1,false);
        seen[0] = true;
        int res = 0;

        while(!q.empty()){
            
            res++;
            int size = q.size();
         
            for(int i = 0;i<size;i++){
               
                int curr = q.front();
                q.pop();
                for(int coin:coins){
                    
                    int nxt = curr + coin;
                    if(nxt==amount) return res;

                    if(nxt>amount || seen[nxt]) continue;

                    seen[nxt] = true; 
                    q.push(nxt); 
                }
            }

        }
        return -1;
        
    }
};
