class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> t,ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==c){
                t.push_back(i);
            }
        }
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(t.size()==1){
                ans.push_back(abs(i-t[0]));
            }
            else{
                if(t.size()>temp+1 && abs(i-t[temp])<abs(i-t[temp+1])){
                    ans.push_back(abs(i-t[temp]));
                }
                else if(t.size()>temp+1 && abs(i-t[temp])>=abs(i-t[temp+1])){
                    temp++;
                    ans.push_back(abs(i-t[temp]));
                }
                else{
                    ans.push_back(abs(i-t[temp]));
                }
            }
        }
        return ans;
    }
};