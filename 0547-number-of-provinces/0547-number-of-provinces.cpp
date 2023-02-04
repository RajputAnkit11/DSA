class Solution {
public:
    void dfs(int ind,vector<int> &vis, vector<vector<int>> &adj){
        vis[ind] = 1;
        
        for(int i=0;i<adj[ind].size();i++){
            if(adj[ind][i] == 1 and vis[i] == 0){
                dfs(i,vis,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> visited(n,0);
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                dfs(i,visited,isConnected);
                cnt++;
            }
        }
        
        return cnt;
    }
};