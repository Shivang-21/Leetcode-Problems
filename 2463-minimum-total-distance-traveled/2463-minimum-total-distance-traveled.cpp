class Solution {
public:
    #define ll long long
    long long find(int i,int j,int s,vector<int>& robot, vector<vector<int>>& factory,vector<vector<vector<ll>>>& dp,int& n,int& m) {
        if(i==n)
            return 0;
        if(j==m)
            return 1e18;
        if(dp[i][j][s]!=-1)
            return dp[i][j][s];
        ll take=1e18;
        if(s) {
            take=find(i+1,j,s-1,robot,factory,dp,n,m)+abs(robot[i]-factory[j][0]);
        }
        if(j!=m-1) {
            take=min(take,find(i,j+1,factory[j+1][1],robot,factory,dp,n,m));
        }
        return dp[i][j][s]=take;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int i=0,j=0,rem=0,n=robot.size(),m=factory.size();
        long long min_cost=0;
        vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(m+1,vector<ll>(n+1,-1)));
        return find(0,0,factory[0][1],robot,factory,dp,n,m);
    }
};