class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<char> st;
        string ans="";
        int n = s.size();
//         for(int i=0;i<s.size();i++){

//             if(s[i]=='(' && st.empty()){
//                 st.push(i);
//             }
//             else if(s[i]=='(' && !st.empty()){
//                 st.push(s[i]);
//                 ans+=s[i];
//             }
//             else{
//                 st.pop();
//                 if(!st.empty()) ans+=s[i];
//             }
//         }
        
        
        vector<pair<int,char>> v;
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                c++;
                v.push_back({c,'('});
            }
            else{
                v.push_back({c,')'});
                c--;
            }
        }
        
        for(int i=0;i<n;i++){
            // cout<<v[i].first<<" "<<v[i].second<<"\n";
            if(v[i].first != 1){
                ans += v[i].second;
            }
        }

        
        return ans;
    }
};