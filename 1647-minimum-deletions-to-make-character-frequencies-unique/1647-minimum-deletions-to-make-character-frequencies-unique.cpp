class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<int> pq;
        auto i=mp.begin();
        while(i!=mp.end()){
            pq.push(i->second);
            i++;
        }
        int c=0;
        if(pq.size()==1){
            return 0;
        }
        while(pq.size()!=0){
            int temp=pq.top();
            pq.pop();
            if(pq.top()==temp && pq.size()!=0){
                temp--;
                c++;
                if(temp!=0){
                    pq.push(temp);
                }
            }
        }
        return c;
    }
};