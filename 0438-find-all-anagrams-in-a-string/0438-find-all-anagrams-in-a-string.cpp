class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0;
        int k=p.size();
        map<char,int> m;
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
        }
        vector<int> ans;
        int count=m.size();
        while(j<s.size()){
            if(m.count(s[j])>0){
                m[s[j]]--;
                if(m[s[j]]==0){
                    count--;
                }
                if(m[s[j]]==-1){
                    count++;
                }
            }
            if(j-i+1<k){
                j++;
            }
            else{
                if(count==0){
                    ans.push_back(i);
                }
                if(m.count(s[i])>0){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }
                    if(m[s[i]]==0){
                        count--;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};