//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool fun(vector<int>& nums,int n,int k,int x){
        int seg = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum + nums[i] < x){
                sum += nums[i];
            }
            else{
                seg++;
                sum = 0;
            }
        }
        if(seg >= k){
            return true;
        }
        return false;
    }
    
    int maxSweetness(vector<int>& nums, int n, int k) {
    // Write your code here.
        int lo = *min_element(nums.begin(),nums.end());
        int hi = 0;
        for(auto &i : nums) hi+=i;
        // debug(hi);
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(fun(nums,n,k+1,mid)){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        
        return hi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends