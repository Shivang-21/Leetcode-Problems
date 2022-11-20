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
    void inorder(vector<int>& arr,TreeNode* root) {
        if(!root)
            return;
        inorder(arr,root->left);
        arr.push_back(root->val);
        inorder(arr,root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> arr;
        vector<vector<int>> ans;
        inorder(arr,root);
        int n=arr.size();
        for(auto i:queries) {
            int Max=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            int Min_ele=-1,Max_ele=-1;
            if(Max==n) {
                Min_ele=arr[Max-1];
            }
            else {
                if(arr[Max]==i) {
                    Min_ele=i;
                    Max_ele=i;
                }
                else {
                    Max_ele=arr[Max];
                    if(Max!=0) {
                        Min_ele=arr[Max-1];
                    }
                }
            }
            ans.push_back({Min_ele,Max_ele});
        }
        return ans;
    }
};