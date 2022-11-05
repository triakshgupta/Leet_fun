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
    int depth(TreeNode* x,TreeNode* root){
        queue<TreeNode*> q;
        int d=0,f=0;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                if(q.front()==x){
                    f=1;
                    break;
                }
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            d++;
            if(f){
                break;
            }
        }
        return d;
        
    }
    TreeNode* find(int a,TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        if(root->left && root->left->val==a || (root->right && root->right->val==a)){
            return root;
        }      
        if(find(a,root->left)){
            return find(a,root->left);
        }
        return find(a,root->right);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int l=depth(find(x,root),root);
        int r=depth(find(y,root),root);
        TreeNode* pl=find(x,root);
        TreeNode* pr=find(y,root);
        if(l==r && pl!=pr) return true;
        return false;
        
        
    }
};