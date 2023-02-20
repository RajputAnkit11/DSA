class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        vector<string> v;
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            v.push_back(s);
        }
        
        sort(v.begin(),v.end());
        
        for(string s : v){
            int x = stoi(s);
            ans.push_back(x);
        }
        
        return ans;
    }
};