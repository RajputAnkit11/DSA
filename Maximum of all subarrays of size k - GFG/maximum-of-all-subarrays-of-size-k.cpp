//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *nums, int n, int k)
    {
        // your code here
        priority_queue<pair<int,int>> heap; //Max_Heap to find maximum in a sliding window
        vector<int> ans;    //Stores all maximum values for all sliding windows
        
        for(int i=0;i<n;++i)
        {
            while(!heap.empty() and heap.top().second<=(i-k))  //Pop the root (max_element),if it is out of sliding window
                heap.pop();
            heap.push(make_pair(nums[i],i));    //Push current element (along with its index) into the heap
            if(i>=k-1)      //Store max in the window if we have a valid window (based on size K)
                ans.push_back(heap.top().first);       
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends