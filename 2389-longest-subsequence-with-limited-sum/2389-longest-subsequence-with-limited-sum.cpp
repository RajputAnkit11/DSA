class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        
        sort(nums.begin(),nums.end());
        
        vector<long long> v;
        int n = nums.size();
        int m = q.size();
        
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            long long x = v[i-1] + nums[i];
            v.push_back(x);
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        vector<int> ans;
        for(int i=0;i<m;i++){
            int a = upper_bound(v.begin(),v.end(),q[i]) - v.begin();
            ans.push_back(a);
        }
        return ans;
    }
};