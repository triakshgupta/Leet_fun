class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a="";
        string b="";
        int i=0;
        while(i<word1.size() && i<word2.size()){
            a+=word1[i];
            b+=word2[i];
            i++;
        }
        if(word1.size()>word2.size()){
            for(int j=i;j<word1.size();j++){
                a+=word1[j];
            }
        }
        if(word1.size()<word2.size()){
            for(int j=i;j<word2.size();j++){
                b+=word2[j];
            }
        }
        if(a==b){
            return true;
        }
        return false;
    }
};