class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0,n=s.size();
        for(int i=0;i<n;i++) {            
            if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U' or s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u') {
                if(i<n/2)
                    count++;
                else
                    count--;    
            }
        }
        return count==0;
    }
};