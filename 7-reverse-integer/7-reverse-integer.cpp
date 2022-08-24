class Solution {
public:
    int reverse(int x) {
        int f=0;
        if(x<0){
            f=1;
            x=abs(x);
        }
        int temp=x,count=0;
        while(temp!=0){
            count++;
            temp/=10;
        }
        int ans=0,c=1,prev=0;
        while(x!=0){
            long long int digit=pow(10,count-c)*(x%10);
            ans+=digit;
            if(ans-digit!=prev){
                return 0;
            }
            prev=ans;
            cout<<prev<<endl;
            x/=10;
            c++;
        }
        if(f){
            ans=-ans;
        }
        return ans;
    }
};