class Solution {
public:
    
    int find(int i,int j,int sum,vector<vector<int>>& grid,int k,int m,int n,vector<vector<vector<int>>> &dp) {
        if(i==m or j==n) {
            return 0;
        }
        if(i==m-1 and j==n-1) {
            if((sum+grid[i][j])%k==0)
                return 1;
            return 0;
        }
        if(dp[i][j][sum]!=-1) {
            return dp[i][j][sum];
        }
        int a=find(i+1,j,(sum+grid[i][j])%k,grid,k,m,n,dp);
        int b=find(i,j+1,(sum+grid[i][j])%k,grid,k,m,n,dp);        
        return dp[i][j][sum]=(a+b)%1000000007;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(); 
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return find(0,0,0,grid,k,m,n,dp);
    }
};