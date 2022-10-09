class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> mp;
       int start=0,end=0,max_len=0,n=s.size();
       while(end!=n)
       {           
           if(mp[s[end]]+1>1)
           {
               mp[s[start]]--;
               start++;
           }
           else
           {
               mp[s[end]]++;
               max_len=max(max_len,end-start+1);
               end++;
           }
       }
        return max_len;
    }
};