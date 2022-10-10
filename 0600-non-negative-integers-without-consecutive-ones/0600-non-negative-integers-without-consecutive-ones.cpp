class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32,0);
        int j=30,ans=0,p=0;
        f[0]=1,f[1]=2;
        for(int i=2;i<32;i++) {
            f[i]=f[i-1]+f[i-2];
        }
        while(j>=0) {
            if((n&(1<<j))) {
                ans+=f[j];
                if(p) {
                    ans--;
                    break;
                } 
                p=1;
            }
            else {
                p=0;
            }
            j--;
        }
        return ++ans;
    }
};