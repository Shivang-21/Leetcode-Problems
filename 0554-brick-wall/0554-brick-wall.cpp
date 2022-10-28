class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m=wall.size(),Max=0;
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++) {
            int edge=0;
            for(int j=0;j<wall[i].size()-1;j++) {
                edge+=wall[i][j];
                mp[edge]++;
                Max=max(Max,mp[edge]);
            }
        }        
        return m-Max;
    }
};