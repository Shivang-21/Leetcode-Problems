class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string max="";
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) {
            dp[i][i]=1;
            if(max.size()<1) {
                max=s.substr(i,1);
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=0,k=i;k<n;k++,j++) {
                if(i==1 and s[j]==s[k]) {
                    dp[j][k]=2;
                }
                else {
                    if(s[j]==s[k] and dp[j+1][k-1]) {
                        dp[j][k]=dp[j+1][k-1];
                    }                    
                }
                if(dp[j][k]) {
                    if(max.size()<k-j+1) {
                        max=s.substr(j,k-j+1);
                    }
                }
            }
        }
        return max;
    }
};