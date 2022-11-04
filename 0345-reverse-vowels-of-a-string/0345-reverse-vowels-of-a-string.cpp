class Solution {
public:
    bool isVowel(char c){
        if(c =='a' or  c=='e' or c =='i' or c=='o' or c=='u'){
            return true;
        }
        if(c =='A' or  c=='E' or c =='I' or c=='O' or c=='U'){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {

        int n = s.length();

        int i = 0;
        int j = n-1;

        while(i<j){
            if(isVowel(s[i]) and isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            if(!isVowel(s[i])){

                i++;
            }
            if(!isVowel(s[j])){
                j--;
            }
        }
        return s;
    }
};