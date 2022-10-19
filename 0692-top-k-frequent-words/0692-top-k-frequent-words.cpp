class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> m;
        priority_queue<pair<int,string>> pq;
        stack<pair<int,string>> s;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            pq.push({i->second,i->first});
        }
        while(!pq.empty()){
           if(s.empty()){
               s.push(pq.top());
               pq.pop();
           }
           else{
               if(pq.top().first!=s.top().first){
                   while(!s.empty()){
                       ans.push_back(s.top().second);
                       s.pop();
                   }
                   s.push(pq.top());
                   pq.pop();
               }
               else{
                   s.push(pq.top());
                   pq.pop();
               }
           }
        
        }
        while(!s.empty()){
            ans.push_back(s.top().second);
            s.pop();
        }
        vector<string> ans1(k);
        for(int i=0;i<k;i++){
            ans1[i]=ans[i];
        }
        return ans1;
    }
};