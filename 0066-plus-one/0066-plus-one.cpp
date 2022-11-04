class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry,sum,n=digits.size(),r;
        for(int i=n-1;i>=0;i--) {
            sum=digits[i]+1;
            carry=sum/10;
            sum%=10;
            digits[i]=sum;
            if(!carry)
                return digits;
        }
        if(carry) {
            digits.insert(digits.begin(),carry);
        }            
        return digits;
    }
};