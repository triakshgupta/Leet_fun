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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* t=new TreeNode(val,root,NULL);
            return t;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(depth>2){
            int s=q.size();
            for(int i=0;i<s;i++){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            depth--;
        }
        while(!q.empty()){
            TreeNode* l=q.front()->left;
            TreeNode* r=q.front()->right;
            TreeNode* x=new TreeNode(val,l,NULL);
            TreeNode* y=new TreeNode(val,NULL,r);
            q.front()->left=x;
            q.front()->right=y;
            q.pop();
        }
        return root;
    }
};