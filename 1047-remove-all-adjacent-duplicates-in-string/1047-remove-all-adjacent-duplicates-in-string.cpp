class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(st.size()>0  and st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        } 
        
        for(int i=0;i<ans.length()/2;i++){
            swap(ans[i],ans[ans.length()-1-i]);
        }
        return ans;
    }
};