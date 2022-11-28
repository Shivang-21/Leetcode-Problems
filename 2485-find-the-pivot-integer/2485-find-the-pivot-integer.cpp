class Solution {
public:
    int pivotInteger(int n) {
        int sum=(n*(n+1))/2,csum=0;
        for(int i=1;i<=n;i++) {
            csum+=i;
            if((sum-csum+i)==csum) {
                return i;
            }
        }
        return -1;
    }
};