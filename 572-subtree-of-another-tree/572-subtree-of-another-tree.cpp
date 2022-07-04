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
    bool check(TreeNode* r,TreeNode* sr){
        if(r==NULL || sr==NULL){
            if(r==NULL && sr==NULL){
                return true;
            }
            return false;
        }
        if(r->val!=sr->val){
            return false;
        }
        return (check(r->left,sr->left) && check(r->right,sr->right));
    } 
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            if(q.front()->val==subRoot->val){
                temp.push_back(q.front());
            }
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        if(temp.size()==0){
            return false;
        }
        for(int i=0;i<temp.size();i++){
            if(check(temp[i],subRoot)){
                return true;
            }
        }
        return false;
    }
};