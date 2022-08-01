class Solution {
public:
    char st(int x){
        switch(x){
            case 0:
                return '0';
            case 1:
                return '1';
            case 2:
                return '2';
            case 3:
                return '3';
            case 4:
                return '4';
            case 5:
                return '5';
            case 6:
                return '6';
            case 7:
                return '7';
            case 8:
                return '8';
            case 9:
                return '9';
        }
        return '0';
    }
    void digit(stack<int>& s,int c){
        while(c){
            s.push(c-(c/10)*10);
            c/=10;
        }
        return;
    }
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        int i=0,j=1,k=0;
        int count=1,ans=0;
        while(j<chars.size()){
            if(chars[i]==chars[j]){
                count++;
            }
            else{
                if(count==1){
                    chars[k]=chars[i];
                    k++;
                    ans++;
                }
                else{
                    chars[k]=chars[i];
                    k++;
                    ans++;
                    stack<int> s;
                    digit(s,count);
                    while(s.size()){
                        chars[k]=st(s.top());
                        s.pop();
                        k++;
                        ans++;
                    }
                }
                count=1;
                i=j;
            }
            j++;
        }
        if(count==1){
                    chars[k]=chars[i];
                    k++;
                    ans++;
                }
                else{
                    chars[k]=chars[i];
                    k++;
                    ans++;
                    stack<int> s;
                    digit(s,count);
                    while(s.size()){
                        chars[k]=st(s.top());
                        s.pop();
                        k++;
                        ans++;
                    }
                }
        return ans;
    }
};