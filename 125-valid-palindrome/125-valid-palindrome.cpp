class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1,f=0;
        while(i<j){
            if(int(s[i])<48 || (int(s[i])>57 && int(s[i])<65) || (int(s[i])>90 && int(s[i])<97) || int(s[i])>122){
                i++;
            }
            else{
                if(int(s[j])<48 || (int(s[j])>57 && int(s[j])<65) || (int(s[j])>90 && int(s[j])<97) || int(s[j])>122){
                   j--;
                }
                else if((s[i]==s[j]) || (int(s[i])==32+int(s[j]) && int(s[i])>57 && int(s[j])>57) || (int(s[i])+32==int(s[j]) && int(s[i])>57 && int(s[j])>57)){
                   i++;
                   j--;
                }
                else{
                    f=1;
                    break;
                }
            }
        }
        //cout<<int('p');
        if(f){
            return false;
        }
        return true;
    }
};