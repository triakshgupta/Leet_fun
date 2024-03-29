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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int f=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                if(q.front()->left) {
                    if(f==0) q.push(q.front()->left);
                    else return false;
                }
                else f=1;
                if(q.front()->right){
                    if(f==0) q.push(q.front()->right);
                    else return false;
                }
                else f=1;
                q.pop();
            }
        }
        return true;
    }
};