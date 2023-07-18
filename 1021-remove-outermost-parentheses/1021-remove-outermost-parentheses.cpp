class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";

        for(int i=0;i<s.size();i++){

            if(s[i]=='(' && st.empty()){
                st.push(i);
            }
            else if(s[i]=='(' && !st.empty()){
                st.push(s[i]);
                ans+=s[i];
            }
            else{
                st.pop();
                if(!st.empty()) ans+=s[i];
            }
        }

        // for(int i=0;i<helper.size();i++){
        //     cout << helper[i] << " ";
        // }


        return ans;
    }
};