class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        if(n%3==2) {
            return 2*pow(3,n/3);
        }
        else if(n%3==1) {
            return 4*pow(3,n/3-1);
        }
        else{
            return pow(3,n/3);
        }
    }
};
