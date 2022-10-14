class Solution {
public:
    int dir[5]={-1,0,1,0,-1};    
    void DFS(int i,int j,int m,int n,vector<vector<int>>& ocean,vector<vector<int>>& heights) {
        ocean[i][j]=1;
        for(int k=0;k<4;k++) {
            int x=dir[k]+i,y=dir[k+1]+j;
            if(x>=0 and x<m and y>=0 and y<n and heights[x][y]>=heights[i][j] and ocean[x][y]==0) {
                DFS(x,y,m,n,ocean,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> p(m,vector<int>(n,0)),a(m,vector<int>(n,0)),ans;
        for(int i=0;i<m;i++) {
            DFS(i,0,m,n,p,heights);
        }
        for(int i=0;i<n;i++) {
            DFS(0,i,m,n,p,heights);
        }
        for(int i=0;i<m;i++) {
            DFS(i,n-1,m,n,a,heights);
        }
        for(int i=0;i<n;i++) {
            DFS(m-1,i,m,n,a,heights);
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(p[i][j]==1 and a[i][j]==1) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};