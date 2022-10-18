class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string prev=countAndSay(n-1);
        string ans="";
        int count=1;
        for(int i=0;i<prev.size();i++) {
            if(i!=prev.size()-1 and prev[i]==prev[i+1]) {
                count++;
            }
            else {
                ans+=to_string(count)+prev[i];
                count=1;
            }
        }
        return ans;
    }
};