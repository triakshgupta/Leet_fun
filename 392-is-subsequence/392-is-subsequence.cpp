class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0){
            return true;
        }
        int i=0,j=0;
        while(j<t.size()){
            if(s[i]==t[j] && i==s.size()-1){
                return true;
            }
            else if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return false;
    }
};