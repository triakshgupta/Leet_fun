class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> s;
        for(int i=0;i<dictionary.size();i++){
            s.insert(dictionary[i]);
        }
        string temp="";
        int f=0;
        vector<string> st;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                if(!f) st.push_back(temp);
                temp="";
                f=0;
            }
            else{
                if(f){
                    continue;
                }
                temp+=sentence[i];
                if(s.count(temp)>0){
                    f=1;
                    st.push_back(temp);
                }
            }
        }
        if(f==0){
            st.push_back(temp);
        }
        string ans;
        for(int i=0;i<st.size();i++){
            if(i!=0){
                ans.push_back(' ');
            }
            ans+=st[i];
        }
        return ans;
    }
};