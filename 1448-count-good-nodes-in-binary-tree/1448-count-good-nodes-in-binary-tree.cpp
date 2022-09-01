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
    void solve(TreeNode* x,int curr_max,int& count){
        if(x==NULL){
            return;
        }
        if(x->val>=curr_max){
            count++;
        }
        if(x->left){
            solve(x->left,max(curr_max,x->val),count);
        }
        if(x->right){
            solve(x->right,max(curr_max,x->val),count);
        }
    }
    int goodNodes(TreeNode* root) {
        int curr_max=INT_MIN;
        int count=0;
        solve(root,curr_max,count);
        return count;
    }
};