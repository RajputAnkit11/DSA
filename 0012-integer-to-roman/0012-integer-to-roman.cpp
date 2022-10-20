class Solution {
public:
    string intToRoman(int num) {
        int n = num/1000;
        num -= n*1000;
        
        string ans = "";
        for(int i=0; i<n; i++){
            ans += "M";
        }
        
        if (num >= 900){
            ans += "CM";
            num-= 900;
        }else if (num >= 500){
            ans += "D";
            num -= 500;
        }else if (num >= 400){
            ans += "CD";
            num -= 400;
        }
        n = num/100;
        num -= n*100;
        for(int i=0; i<n; i++){
            ans += "C";
        }
        
        
        if (num >= 90){
            ans += "XC";
            num-= 90;
        }else if (num >= 50){
            ans += "L";
            num -= 50;
        }else if (num >= 40){
            ans += "XL";
            num -= 40;
        }
        n = num/10;
        num -= n*10;
        for(int i=0; i<n; i++){
            ans += "X";
        }
        
        
        if (num == 9){
            ans += "IX";
            num-= 9;
        }else if (num >= 5){
            ans += "V";
            num -= 5;
        }else if (num == 4){
            ans += "IV";
            num -= 4;
        }
        for(int i=0; i<num; i++){
            ans += "I";
        }
        
        return ans;

    }
};