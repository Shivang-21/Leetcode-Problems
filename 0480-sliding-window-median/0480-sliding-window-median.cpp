class Solution {
public:
    struct max_comp{
        bool operator()(pair<double,double>& a, pair<double,double>& b){
            return a.second<b.second;
        }  
    };
    struct min_comp{
        bool operator()(pair<double,double>& a, pair<double,double>& b){
            return a.second>b.second;
        }  
    };
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<double,double>,vector<pair<double,double>>,max_comp> max_heap;
        priority_queue<pair<double,double>,vector<pair<double,double>>,min_comp> min_heap;
        vector<double> ans;
        int n=nums.size();
        for(int i=0;i<k;i++) {
            max_heap.push({i,nums[i]});
        }
        while(max_heap.size()>min_heap.size()+1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        for(int i=k;i<n;i++) {
            if(k&1) {
                ans.push_back((double)max_heap.top().second);
            }
            else {
                ans.push_back(((double)max_heap.top().second+(double)min_heap.top().second)/2);
            }        
            double a=nums[i-k],b=nums[i],f=0;
            if(a<max_heap.top().second || (a==max_heap.top().second && max_heap.top().first<=i-k) || (!min_heap.empty() && a<min_heap.top().second))
                f--;
            else
                f++;
            if(b<max_heap.top().second || (b==max_heap.top().second && max_heap.top().first>i-k) ||(!min_heap.empty() && b<min_heap.top().second)) {
                f++;
                max_heap.push({i,nums[i]});
            }
            else {
                f--;
                min_heap.push({i,nums[i]});
            }    
            if(!min_heap.empty() && f<0){
                max_heap.push(min_heap.top());
                min_heap.pop();
                f++;
            }
            else if(!max_heap.empty() && f>0){
                min_heap.push(max_heap.top());
                max_heap.pop();
                f--;
            }
            while(!min_heap.empty() && min_heap.top().first<=i-k)
                min_heap.pop();
            while(!max_heap.empty() && max_heap.top().first<=i-k)
                max_heap.pop();
        }
        if(k&1) {
            ans.push_back((double)max_heap.top().second);
        }
        else {
            ans.push_back(((double)max_heap.top().second+(double)min_heap.top().second)/2);
        }
        return ans;
    }
};