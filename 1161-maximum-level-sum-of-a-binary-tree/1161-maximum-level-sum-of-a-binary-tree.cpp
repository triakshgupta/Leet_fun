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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int max=INT_MIN,l=0;
        int sum=0,ans;
        q.push(root);
        while(!q.empty()){
            sum=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                sum+=q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            l++;
            if(sum>max){
                max=sum;
                ans=l;
            }
        }
        return ans;

    }
};