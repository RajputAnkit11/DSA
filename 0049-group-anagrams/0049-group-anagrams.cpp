class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
//         unordered_map<unordered_map<char,int>,vector<string>> map;
        
//         for(int j=0;j<strs.size();j++){
//             unordered_map<char,int> m;
//             for(int i=0;i<strs[j].length();i++){
//                 m[s[i]]++;
//             }

//             if(map.count(m)){
//                 map[m].push_back(strs[j]);
//             }
//             else{
//                 map[m];
//             } 
//         }
        
//         vector<vector<string>> ans;
        
        
        
        
        unordered_map<string,vector<string> > mymap;
        int n = strs.size();
        string temp;
        
        for(int i =0;i<n;++i)
        {
            temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        
        vector<vector<string> > result;
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr)
            result.push_back(itr->second);
        
        return result;
    }
};