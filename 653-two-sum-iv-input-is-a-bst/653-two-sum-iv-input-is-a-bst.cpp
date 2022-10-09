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
    void inorder(TreeNode* x,vector<int>& a){
        if(x==NULL){
            return;
        }
        inorder(x->left,a);
        a.push_back(x->val);
        inorder(x->right,a);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        inorder(root,a);
        int i=0,j=a.size()-1;
        while(i<j){
            if(a[i]+a[j]==k){
                return true;
            }
            else if(k>a[i]+a[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};