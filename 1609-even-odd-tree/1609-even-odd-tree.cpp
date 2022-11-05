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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int s=q.size();
            int temp;
            for(int i=0;i<s;i++){
                //cout<<q.front()->val<<endl;
                if(q.front()->val%2==0 && l%2==0) return false;
                if(q.front()->val%2!=0 && l%2!=0) return false;
                if(i!=0 && l%2==0 && q.front()->val<=temp) return false;
                if(i!=0 && l%2!=0 && q.front()->val>=temp) return false;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                temp=q.front()->val;
                q.pop();
            }
            l++;
        }
        return true;
    }
};