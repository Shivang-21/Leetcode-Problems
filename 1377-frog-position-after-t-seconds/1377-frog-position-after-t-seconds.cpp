class Solution {
public:
    void DFS(vector<vector<int>>& adj,vector<int>& state,int t,int target,double& ans,int child,int u,int p=1) {
        if(t==0) {
            if(u==target) {
                ans=1.0/(p*child);                
            }
            return;
        }
        if(u==target) {
            if(adj[u].size()-1==0) {
                ans=1.0/(p*child);
            }
            else {
                ans=0.0;
            }
            return;
        }
        state[u]=1;
        for(auto v:adj[u]) {
            if(!state[v]) {
                DFS(adj,state,t-1,target,ans,adj[u].size()-1,v,p*child);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
        vector<int> state(n+1,0);        
        double ans=0.0;        
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        if(target==1) {
            if(t==0 or adj[1].size()==0)
                return 1.0;
            else
                return 0.0;
        }
        state[1]=1;
        for(auto v:adj[1]) {
            DFS(adj,state,t-1,target,ans,adj[1].size(),v);
        }
        return ans;
    }
};