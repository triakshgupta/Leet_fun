class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        int f=0;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                p.push(s[i]);
            }
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(p.empty()){
                    f=1;
                    break;
                }
                else if((s[i]==')' && p.top()=='(') || (s[i]==']' && p.top()=='[') || (s[i]=='}' && p.top()=='{')){
                    p.pop();
                }
                else{
                    f=1;
                    break;
                }
            }
        }
        if(f || !p.empty()){
            return false;
        }
        else{
            return true;
        }
    }
};