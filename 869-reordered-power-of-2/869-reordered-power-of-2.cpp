class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string> power;
        for(int i=0;i<=29;i++){
            int x=pow(2,i);
            string temp=to_string(x);
            sort(temp.begin(),temp.end());
            power.insert(temp);
            cout<<temp<<endl;
        }
        string num=to_string(n);
        sort(num.begin(),num.end());
        if(power.count(num)>0){
            return true;
        }
        return false;
    }
};