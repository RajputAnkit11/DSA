class Solution {
public:
    
    void dfs(int cur, int n, vector<int> &ans){
        if(cur > n){
            return ;
        }
        else{
            ans.push_back(cur);
            for(int i=0;i<10;i++){
                int x = cur*10 + i;
                
                if(x>n) return ;
                else dfs(x,n,ans);
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        for(int i=1;i<=9;i++){
            dfs(i,n,ans);
        }
        
        return ans;
    }
};