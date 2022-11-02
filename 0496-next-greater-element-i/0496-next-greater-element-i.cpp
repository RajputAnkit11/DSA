class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        stack<int> s;

        unordered_map<int,int> nge;
        
        for(int i=0;i<n;i++){
            while(s.size()>0 and s.top()<nums2[i]){
                nge[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        // for(auto i: nge){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        vector<int> ans;
        for(auto i: nums1){
            if(nge.count(i) == 1){
                ans.push_back(nge[i]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};