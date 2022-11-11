class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
       stack<pair<int,int>> s;
        vector<int> ans(temp.size());
        s.push({temp[temp.size()-1],temp.size()-1});
        ans[temp.size()-1]=0;
        int i=temp.size()-2;
        while(i>=0){
            if(s.top().first>temp[i]){
                ans[i]=1;
                s.push({temp[i],i});
            }
            else{
                while(!s.empty() && s.top().first<=temp[i]){
                    s.pop();
                }
                if(s.size()==0) ans[i]=0;
                else ans[i]=s.top().second-i;
                s.push({temp[i],i});
            }
            i--;
        }
        return ans;
    }
};