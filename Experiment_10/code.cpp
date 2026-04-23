class Solution {
public:
    int dp[1001][1001];
    int n,m;
    int solve(int i,int j,string &s,string &t){
        if(dp[i][j] != -1) return dp[i][j];
        if(j>=m) return dp[i][j]= 1;
        if(i>=n) return dp[i][j] = 0;

        if(s[i] == t[j]) return dp[i][j] = solve(i+1,j+1,s,t) + solve(i+1,j,s,t);
        return dp[i][j]=solve(i+1,j,s,t);
    }
    int numDistinct(string s, string t) {
        n= s.size(), m = t.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
        
    }
};
