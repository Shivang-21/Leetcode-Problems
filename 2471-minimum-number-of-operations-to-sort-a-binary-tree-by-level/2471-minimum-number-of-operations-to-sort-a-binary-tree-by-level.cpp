/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> arr,temp;
        int s;
        int ans=0;
        q.push(root);
        while(!q.empty()) {
            s=q.size();
            int count=0;
            unordered_map<int,int> mp;
            for(int i=0;i<s;i++) {
                TreeNode*  f=q.front();                
                q.pop();
                arr.push_back(f->val);
                if(f->left!=NULL) {
                    q.push(f->left);
                }
                if(f->right!=NULL) {
                    q.push(f->right);
                }                
            } 
            temp=arr;
            for(int i=0;i<s;i++) {
                mp[arr[i]]=i;
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<s;i++) {                
                if(arr[i]!=temp[i]) {
                    arr[mp[temp[i]]]=arr[i];
                    mp[arr[i]]=mp[temp[i]];
                    mp[temp[i]]=i;
                    arr[i]=temp[i];
                    count++;    
                }
                
            }
            ans+=count;
            arr.clear();
            temp.clear();
        }
        return ans;
    }
};