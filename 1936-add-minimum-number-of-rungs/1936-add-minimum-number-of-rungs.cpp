class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int c_min=0,n=rungs.size();
        for(int i=0;i<n;i++) {
            c_min+=(rungs[i]-(i==0?0:rungs[i-1])-1)/dist;
        }
        return c_min;
    }
};