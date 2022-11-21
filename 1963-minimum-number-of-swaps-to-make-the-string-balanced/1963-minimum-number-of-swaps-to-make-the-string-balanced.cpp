class Solution {
public:
    int minSwaps(string s) {        
        int n=s.size(),count_op=0,count_cl=0,end=n-1,Swap=0,start=0;
        while(s[end]!='[') {
            end--;
        }
        while(start<end) {
            if(s[start]=='[')
                count_op++;
            else
                count_cl++;
            if(count_cl>count_op) {
                swap(s[start],s[end]);
                Swap++;
                count_op++;
                count_cl--;
                end--;
                while(s[end]!='[')
                    end--;
            }
            start++;
        }
        return Swap;
    }
};