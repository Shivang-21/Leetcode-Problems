class Solution {
public:
    bool isHappy(int n) {
        int sum,r;
        while(n!=1 and n!=4){
            sum=0;
            while(n) {
                r=n%10;
                sum+=(r*r);
                n/=10;
            }
            n=sum;
        }
        if(n==1)
            return 1;
        else
            return 0;
    }
};