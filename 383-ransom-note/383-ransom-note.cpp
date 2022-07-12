class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for(int i=0;i<magazine.length();i++){
            m[magazine[i]]++;
        }
        int f=0;
        for(int i=0;i<ransomNote.length();i++){
            if(m.count(ransomNote[i])==0 || m[ransomNote[i]]<=0){
                f=1;
                break;
            }
            else{
                m[ransomNote[i]]--;
            }
        }
        if(f){
            return false;
        }
        return true;
        
    }
};