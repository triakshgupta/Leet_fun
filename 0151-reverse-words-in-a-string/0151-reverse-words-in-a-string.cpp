class Solution {
public:
    string reverseWords(string s) {
        stack<string> w;
        string temp="";
        for(int i=0;i<s.size();i++){
            
            if(s[i]==' '){
                if(temp.length()!=0){
                    w.push(temp);
                    temp.clear();
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }
        if(temp.size()!=0) w.push(temp);
        temp.clear();
        while(w.size()){
            if(w.size()==1){
                temp+=w.top();
            }
            else{
                temp+=w.top();
                temp+=' ';
            }
            w.pop();
        }
        return temp;
    }
};