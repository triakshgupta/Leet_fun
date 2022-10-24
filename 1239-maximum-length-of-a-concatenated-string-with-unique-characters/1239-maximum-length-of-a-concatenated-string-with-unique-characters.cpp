class Solution {
public:
    bool p(map<char,int> m,string t){
        set<char> s;
        for(int i=0;i<t.size();i++){
            if(m.count(t[i])>0 || s.count(t[i])>0){
                return false;
            }
            s.insert(t[i]);
        }
        return true;
    }
    int length(vector<string> arr,string& t,int i,map<char,int>& m){
        if(i==arr.size()){
            return t.size();
        }
        int pick=INT_MIN;
        if(p(m,arr[i])){
            for(int j=0;j<arr[i].size();j++){
                m[arr[i][j]]++;
            }
            t+=arr[i];
            pick=length(arr,t,i+1,m);
            for(int j=0;j<arr[i].size();j++){
                t.pop_back();
                m[arr[i][j]]--;
                if(m[arr[i][j]]==0){
                    m.erase(arr[i][j]);
                }
            }
        }
        int notpick=length(arr,t,i+1,m);
        return max(pick,notpick);
    }
    int maxLength(vector<string>& arr) {
        string t="";
        map<char,int> m;
        return length(arr,t,0,m);
    }
};