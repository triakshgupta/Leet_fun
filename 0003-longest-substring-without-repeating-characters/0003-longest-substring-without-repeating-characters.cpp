class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int ans=0;
        map<char,int> m;
        while(j<s.size()){
            m[s[j]]++;
            if(m[s[j]]==1){
                ans=max(ans,j-i+1);
            }
            else{
                while(m[s[j]]!=1){
                    m[s[i]]--;
                    i++;
                }
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};