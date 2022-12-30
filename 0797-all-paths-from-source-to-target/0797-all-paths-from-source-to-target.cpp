class Solution {
public:
    void dfs(int i,int n,vector<int>& temp,vector<vector<int>>& ans,vector<vector<int>>& graph){
        
        if(i == n-1){
            ans.push_back(temp);
        }
        if(i == 0){
            temp.push_back(0);
        }
        for(auto &it: graph[i]){
            temp.push_back(it);
            dfs(it,n,temp,ans,graph);
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        dfs(0,n,temp,ans,graph);
        
        return ans;
    }
};