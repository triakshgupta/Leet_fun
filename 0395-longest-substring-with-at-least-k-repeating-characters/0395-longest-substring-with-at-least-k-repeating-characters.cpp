class Solution {
public:
    int longestSubstring(string s, int k) {
        map<char,int> w;
        for(int i=0;i<s.size();i++){
            w[s[i]]++;
        }
        int c=w.size();
        int ans=0;
        for(int x=1;x<=c;x++){
            map<char,int> m;
            int i=0,j=0;
            int count=0;
            while(j<s.size()){
                m[s[j]]++;
                if(m[s[j]]==k){
                    count++;
                }
                if(m.size()<x) j++;
                else if(m.size()==x){
                    if(count==m.size()){
                        ans=max(ans,j-i+1);
                    }
                    j++;
                }
                else{
                    while(m.size()>x){
                        m[s[i]]--;
                        if(m[s[i]]==k-1) count--;
                        if(m[s[i]]==0) m.erase(s[i]);
                        i++;
                    }
                    if(count==m.size()){
                        ans=max(ans,j-i+1);
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};