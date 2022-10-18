class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        n--;
        while (n--){
            cout<<n<<endl;
            string t;
            int count=0;
            for(int i=0;i<temp.size();i++){
                count++;
                if(i>0 && temp[i]!=temp[i-1]){
                    t+=to_string(count-1);
                    t.push_back(temp[i-1]);
                    count=1;
                }
            }
            t+=to_string(count);
            t.push_back(temp[temp.size()-1]);
            temp=t;
        }
        return temp;
    }
};