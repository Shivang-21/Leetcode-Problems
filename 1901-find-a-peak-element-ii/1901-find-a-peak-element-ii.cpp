class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),l=0,u=n-1,mid,index;
        while(l<=u) {
            mid=l+(u-l)/2;
            index=0;
            for(int i=0;i<m;i++) {
                if(mat[index][mid]<mat[i][mid]) {
                    index=i;
                }
            }
            if((mid==0 or mat[index][mid-1]<mat[index][mid]) and (mid==n-1 or mat[index][mid+1]<mat[index][mid])) {
                return {index,mid};
            }
            else if(mid>0 and mat[index][mid-1]>mat[index][mid]) {
                u=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};