class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        map<char,char> m;
        set<char> c;
        int i=0,j=0;
        while(i<s.size()){
            if(m.count(s[i])==0){
                if(c.count(t[j])>0){
                    return false;
                }
                else{
                    m[s[i]]=t[j];
                    c.insert(t[j]);
                }
            }
            else{
                if(m[s[i]]!=t[j]){
                    return false;
                }
            }
            i++;
            j++;
        }
        return true;
    }
};