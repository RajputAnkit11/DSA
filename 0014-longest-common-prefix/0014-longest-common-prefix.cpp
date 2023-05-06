class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        int n = str.size();
        string ans = "";
        
        sort(str.begin(),str.end());
        
        string l = str[0];
        string r = str[n-1];
        int m1 = l.size(), m2 = r.size();
        for(int i=0;i<min(m1,m2);i++){
            if(l[i] == r[i]){
                ans += l[i];
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};