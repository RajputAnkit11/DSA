class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <vector <vector <int>>> g(n);
        for (int i=0; i<flights.size(); i++)
            g[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        vector <int> dist(n, -1);
        queue <vector <int>> q;
        q.push({src, 0});
        for (int i=0; i<=k+1; i++)
        {
            int s = q.size();
            while (s--)
            {
                int v = q.front()[0];
                int d = q.front()[1];
                q.pop();
                if (dist[v]!=-1 && d>dist[v])
                    continue;
                dist[v] = d;
                for (int j=0; j<g[v].size(); j++)
                    q.push({g[v][j][0], g[v][j][1]+d});
            }
        }
        
        return dist[dst];
    }
};