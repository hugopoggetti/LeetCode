class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int c=0;
        for(char ch:word){
            if(isupper(ch)){
                c++;
            }}
        if(c==0||c==n||(c==1&&isupper(word[0]))){
            return true;

        }
        return false;
    }
};
