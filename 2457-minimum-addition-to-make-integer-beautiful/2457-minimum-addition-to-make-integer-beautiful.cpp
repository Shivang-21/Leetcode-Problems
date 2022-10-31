class Solution {
public:
    long long find(long long n) {
        long long sum=0;
        while(n) {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long sum=0,ans=1,num=n;
        if(find(n)>target) {
            while(find(n)>target) {
                n=n/10+1;
                ans*=10;
            }
            return n*ans-num;
        }
        else {
            return 0;
        }
    }
};