class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3){
            return 0;
        }
        map<int,char> m;
        int i=0,j=0;
        string temp;
        int count=0;
        while(j<s.size()){
            m[j]=s[j];
            if(j-i+1==3){
                if(m[i]!=m[i+1] && m[i]!=m[i+2] && m[i+1]!=m[i+2]){
                    count++;
                }
                m.erase(m.begin());
                i++;
            }
            j++;
        }
        return count;
    }
};