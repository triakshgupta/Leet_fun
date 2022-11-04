class Solution {
public:
    bool check(char a){
        if(a=='a') return true;
        else if(a=='e') return true;
        else if(a=='i') return true;
        else if(a=='o') return true;
        else if(a=='u') return true;
        else if(a=='A') return true;
        else if(a=='E') return true;
        else if(a=='I') return true;
        else if(a=='O') return true;
        else if(a=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(check(s[i]) && check(s[j])){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
            else if(check(s[i])){
                j--;
            }
            else if(check(s[j])){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};