class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        unordered_map<string,int> c;
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1]){ 
                if(c.count(words[i])>0){
                    c[words[i]]--;
                    if(c[words[i]]==0) c.erase(words[i]);
                    ans+=4;
                }
                else{
                    c[words[i]]++;
                }
            }
            else{
                string temp="";
                temp+=words[i][1];
                temp+=words[i][0];
                if(m.count(temp)>0){
                    m[temp]--;
                    if(m[temp]==0) m.erase(temp);
                    ans+=4;
                }
                else{
                    m[words[i]]++;
                }
            }
        }
        if(c.size()!=0) ans+=2;
        return ans;
    }
};