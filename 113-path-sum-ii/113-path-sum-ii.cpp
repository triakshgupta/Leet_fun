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
    bool isleaf(TreeNode* x){
        if(!x->left && !x->right){
            return true;
        }
        return false;
    }
    void sum(TreeNode* x,vector<vector<int>>& ans,int& s,vector<int>& path,int target){
        if(isleaf(x) && s==target){
            ans.push_back(path);
            return;
        }
        if(x->left){
            path.push_back(x->left->val);
            s+=x->left->val;
            sum(x->left,ans,s,path,target);
            s-=x->left->val;
            path.pop_back();
        }
        if(x->right){
            path.push_back(x->right->val);
            s+=x->right->val;
            sum(x->right,ans,s,path,target);
            s-=x->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> path;
        path.push_back(root->val);
        int s=root->val;
        sum(root,ans,s,path,target);
        return ans;
    }
};