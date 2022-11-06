class Solution {
public:    
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost=0,a,b;
        int start=0,end=costs.size()-1,n=costs.size(),count=0;        
        priority_queue<int,vector<int>,greater<int>> begin,dest; 
        for(;start<candidates and count<n;start++,count++)
            begin.push(costs[start]);
        for(;end>=n-candidates and count<n;end--,count++)
            dest.push(costs[end]);
        while(k--) {
            a=INT_MAX,b=INT_MAX;
            if(!begin.empty())
                a=begin.top();
            if(!dest.empty())
                b=dest.top();
            if(a<=b) {
                cost+=a;
                begin.pop();
                if(start<=end and count<n) {
                    begin.push(costs[start++]);
                    count++;
                }
            }
            else {
                cost+=b;
                dest.pop();
                if(start<=end and count<n) {
                    dest.push({costs[end--]});
                    count++;
                }
            }
        }
        return cost;
    }
};