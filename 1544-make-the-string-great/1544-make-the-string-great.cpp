class Solution {
public:
    string makeGood(string s) {
        
        int n = s.length();
        if(n == 2 and (s[0] == s[1]-32 or s[0] == s[1]+32))  return "";
        int i = 0;
        while(i<n){
            if(s[i] == s[i+1]-32 or s[i] == s[i+1]+32){
                s = s.substr(0,i) + s.substr(i+2);
                n = s.length();
                i = 0;
            }
            else{
                i++;
            }
        }
        
        return s;
        
//         stack<char> stk;
//         int i = 0;
//         while(i<n){
            
//             while(i<n and stk.size() and (stk.top() == s[i]+32 or stk.top() == s[i]-32)){
//                 stk.pop();
//                 i++;
//             }
            
//             if(stk.size() == 0){
//                 stk.push(s[i]);
//                 i++;
//             }
            
//             while(i<n and stk.size() and (stk.top() != s[i]+32 and stk.top() != s[i]-32)){
//                 stk.push(s[i]);
//                 i++;
//             }
//         }
//         s = "";
//         if(stk.top() == ' '){
//             return s;
//         }
//         while(stk.size()){
//             s += stk.top();
//             stk.pop();
//         }
        
//         reverse(s.begin(), s.end());
//         return s;
    }
};