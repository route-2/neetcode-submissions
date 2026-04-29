class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int start = q.front();
            q.pop();
             if(!visited[start]){
                for(const auto &w:wordDict){
                    int end = start + w.size();
                    if(end<=n && s.substr(start,w.size())==w){
                       q.push(end);
                       if(end==n){
                        return true;
                       }
                    }

                }
                visited[start]=true;
             }
        }
        return false;

        //in the end if its true we found the words in string
        
    } 
    };
    

