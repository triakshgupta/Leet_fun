class Solution {
public:
    void para(vector<string>& ans,string s,int count,int total,int n){
        if(total==2*n){
            ans.push_back(s);
            return;
        }
        if(count<n){
            para(ans,s+'(',count+1,total+1,n);
        }
        if(total-count<count){
            para(ans,s+')',count,total+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        para(ans,"",0,0,n);
        return ans;
    }
};