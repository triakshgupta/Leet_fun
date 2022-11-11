class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
       stack<int> s;
        vector<int> ans(temp.size());
        s.push(temp.size()-1);
        ans[temp.size()-1]=0;
        int i=temp.size()-2;
        while(i>=0){
            if(temp[s.top()]>temp[i]){
                ans[i]=1;
                s.push(i);
            }
            else{
                while(!s.empty() && temp[s.top()]<=temp[i]){
                    s.pop();
                }
                if(s.size()==0) ans[i]=0;
                else ans[i]=s.top()-i;
                s.push(i);
            }
            i--;
        }
        return ans;
    }
};