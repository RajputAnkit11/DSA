class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int add) {
        
        int n = cap.size();
        int ans = 0;
        vector<int> v;
        
        for(int i=0;i<n;i++){
            int x = cap[i]-rocks[i];
            if(x == 0){
                ans++;
                continue;
            }
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++){
            if(add >= v[i]){
                ans++;
                add -= v[i];
            }
        }
        
        return ans;
    }
};