class Solution {
public:
    int DFS(int u,int sum,vector<int>& nums,vector<vector<int>>& adj,vector<int>& visited) {
        visited[u]=nums[u];
        for(auto v:adj[u]) {
            if(!visited[v]) {
                visited[u]+=DFS(v,sum,nums,adj,visited);
            }
            if(visited[u]>sum) {
                return 1000000007;
            }
        }
        if(visited[u]==sum) {
            return 0;
        }
        return visited[u];
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size(),Max=*max_element(nums.begin(),nums.end()),sum=accumulate(nums.begin(),nums.end(),0);
        int Max_element=0;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            
        }               
        for(int i=1;i<=sum/Max;i++) {
            if(sum%i==0) {
                vector<int> visited(n,0);
                if(!DFS(0,sum/i,nums,adj,visited)) {
                    Max_element=max(Max_element,i-1);                  
                }
            }
        }        
        return Max_element;
    }
};