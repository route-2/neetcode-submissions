class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       
       int n = s.size();
       vector<bool> visited(n+1,false);
       queue<int> q;
       
       q.push(0);

       while(!q.empty()){
        int start = 0,end = 0;
        start = q.front();
        q.pop();
        if(!visited[start]){

        
        for(const auto& word : wordDict){
          end = start + word.size();
          if(end<=n && s.substr(start,word.size())==word){
            q.push(end);
            if(end==n){
                return true;
            }
          }
        }
        visited[start] = true;
        }
       }
       return false;


      
    } 
    };
    

