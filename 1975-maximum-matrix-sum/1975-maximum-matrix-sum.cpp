class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int m=matrix.size(),n=matrix[0].size(),Min=INT_MAX,count=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) {
                    count++;                    
                }
                Min=min(Min,abs(matrix[i][j]));
            }
        }
        if(count&1) {
            sum-=Min*2;
        }
        return sum;        
    }
};