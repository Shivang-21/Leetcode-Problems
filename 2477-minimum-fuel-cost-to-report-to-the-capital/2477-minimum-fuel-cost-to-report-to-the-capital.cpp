class Solution {
public:
    long long DFS(int u,vector<int>& state,vector<vector<int>>& adj,int seats,long long& ans) {
        state[u]=1;
        long long count=1;
        for(auto v:adj[u]) {
            if(!state[v])
                count+=DFS(v,state,adj,seats,ans);
        }
        ans+=ceil((double)count/seats);
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        long long ans=0;
        vector<vector<int>> adj(n+1);
        for(auto i:roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> state(n+1,0);
        state[0]=1;
        for(auto v:adj[0]) {
            DFS(v,state,adj,seats,ans);
        }
        return ans;
    }
};