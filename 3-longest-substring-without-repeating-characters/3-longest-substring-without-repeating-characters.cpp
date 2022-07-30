class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0;
        set<char> ch;
        int mc=0,i=0,j=0;
        while(j<s.length()){
            if(ch.count(s[j])==0){
                ch.insert(s[j]);
                count++;
                j++;
            }
            else{
                mc=max(mc,count);
                ch.erase(s[i]);
                count--;
                i++;
            }
            mc=max(mc,count);
        }
        return mc;
    }
};