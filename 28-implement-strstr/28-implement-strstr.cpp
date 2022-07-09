class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        for(int i=0;i<haystack.length();i++){
            int f=0;
            if(haystack[i]==needle[0]){
                f=1;
                for(int j=1;j<needle.length();j++){
                    if(haystack[i+j]!=needle[j]){
                        f=0;
                        break;
                    }
                }
                if(f){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
    }
};