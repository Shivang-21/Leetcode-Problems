class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) {
            if(p[i-1]=='*') {
                if(i>=2)
                    dp[i][0]=dp[i-2][0];
                else
                    dp[i][0]=0; 
            }
            else
                dp[i][0]=0;
        }
        for(int i=1;i<=m;i++) {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(p[i-1]==s[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='.') {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*') {
                    dp[i][j]=dp[i-2][j];
                    if(p[i-2]=='.' or p[i-2]==s[j-1])
                        dp[i][j]=dp[i][j] or dp[i][j-1];
                }
                
            }
        }
        return dp[n][m];
    }
};