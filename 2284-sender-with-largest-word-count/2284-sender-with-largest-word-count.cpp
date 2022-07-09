class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m;
        for(int i=0;i<senders.size();i++){
            int j=0;
            while(messages[i][j]!='\0'){
                if(messages[i][j]==' '){
                    m[senders[i]]++;
                }
                j++;
            }
            m[senders[i]]++;
        }
        int max=0;
        string ans;
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second>=max){
                max=i->second;
                ans=i->first;
            }
        }
        return ans;
    }
};