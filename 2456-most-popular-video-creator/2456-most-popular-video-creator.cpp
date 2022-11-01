class Solution {
public:
     static bool cmp(pair<string, int>p1, pair<string, int>p2 ){
          if(p1.second!=p2.second) return p1.second>p2.second; 
           return p1.first<p2.first;
    }
    
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        unordered_map<string,vector<pair<string,int>>> mp1;
        unordered_map<string,long long> mp2;
        
        int n = creators.size();
        for(int i=0;i<n;i++){
            mp1[creators[i]].push_back({ids[i], views[i]});
            mp2[creators[i]] += views[i];
        }
        
        long long mx = 0;
        for(auto i: mp2){
            mx = max(mx,i.second);
        }
        
        vector<string> ans;
        for(auto i: mp2){
            if(i.second == mx){
                ans.push_back(i.first);
            }
        }
        
        vector<vector<string>> ans1;
        for(auto i: ans){
            vector<string> v;
            vector<pair<string,int>> temp;
            temp = mp1[i];
            
            sort(temp.begin(), temp.end(), cmp);
            v.push_back(i);
            v.push_back(temp[0].first);
            
            ans1.push_back(v);
        }
        return ans1;
    }
};