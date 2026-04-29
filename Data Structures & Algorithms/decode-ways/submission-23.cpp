class Solution {
public:
   
    int numDecodings(string s) {

        int n = s.size();

        return dfs(0,s);   
    }
private:
   int dfs(int i, string& s){
     if(i==s.size()) return 1;
    if(s[i]=='0') return 0;
   

    int res = dfs(i+1,s);
    if(i<s.size()-1){
      if(s[i]=='1' || s[i] == '2' && s[i+1]<'7'){
        res+=dfs(i+2,s);
      }
    }
    return res;


   }
};

/*
dfs(0) on "226"
│
├── first dfs: dfs(1) on "26"
│   │
│   ├── first dfs: dfs(2) on "6"
│   │   │
│   │   ├── first dfs: dfs(3) on ""
│   │   │   └── returns 1   <- base case
│   │   │
│   │   └── second dfs? NO
│   │       because i = 2, and 2 < 2 is false
│   │
│   │   returns 1
│   │
│   └── second dfs: dfs(3) on ""
│       because "26" is valid
│       └── returns 1   <- base case
│
│   returns 2
│
└── second dfs: dfs(2) on "6"
    because "22" is valid
    │
    ├── first dfs: dfs(3) on ""
    │   └── returns 1   <- base case
    │
    └── second dfs? NO
        because i = 2, and 2 < 2 is false

    returns 1

dfs(0) returns 3
*/
