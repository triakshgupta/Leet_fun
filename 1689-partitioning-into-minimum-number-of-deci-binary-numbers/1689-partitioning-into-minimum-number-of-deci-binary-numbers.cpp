class Solution {
public:
    int in(char s){
       if(s=='0'){
           return 0;
       }
       if(s=='1'){
           return 1;
       }
       if(s=='2'){
           return 2;
       }
       if(s=='3'){
           return 3;
       }
       if(s=='4'){
           return 4;
       }
       if(s=='5'){
           return 5;
       }
       if(s=='6'){
           return 6;
       }
       if(s=='7'){
           return 7;
       }
       if(s=='8'){
           return 8;
       }
       return 9;
    }
    int minPartitions(string n) {
        int max=0;
        for(int i=0;i<n.length();i++){
            if(in(n[i])>max){
                max=in(n[i]);
            }
        }
        if(max==1 || max==0){
            return 1;
        }
        return max;
    }
};