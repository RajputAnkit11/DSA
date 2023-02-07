class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        unordered_map<int,int> mp;
        int ans = 0;
        
        int i = 0;
        int j = 0;
        int c = 0; //fruit_count in map

        while(j<n){
            mp[f[j]]++;
            c++;
            if(mp.size() == 2){
                ans = max(ans,c);
            }
            while(mp.size()>2){
                mp[f[i]]--;
                c--;
                if(mp[f[i]] == 0){
                    mp.erase(f[i]); // to remove (3,0) example 4
                }
                i++;
            }
            j++;
        }
        
        if(ans==0) return c;
        
        return ans;
    }
};