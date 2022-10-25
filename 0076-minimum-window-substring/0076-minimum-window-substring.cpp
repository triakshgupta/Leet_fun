class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        int i=0,j=0;
        int count=m.size();
        string ans="";
        string temp="";
        while(j<s.size()){
            if(m.count(s[j])>0){
                m[s[j]]--;
                if(m[s[j]]==0){
                    count--;
                }
            }
            temp.push_back(s[j]);
            if(count>0){
                j++;
            }
            else{
                if(ans.size()>temp.size() || ans=="") ans=temp;
                while(count==0){
                    if(m.count(s[i])>0){
                        m[s[i]]++;
                        if(m[s[i]]>0){
                            count++;
                        }
                    }
                    temp=temp.substr(1);
                    if(count==0 && temp.size()<ans.size()){
                        ans=temp;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};