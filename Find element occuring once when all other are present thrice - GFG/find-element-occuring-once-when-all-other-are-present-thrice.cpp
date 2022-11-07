//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int n) {
        // code here
        
        int bits[32] = {0};
        
        for(int i=0;i<n;i++){
            int x = arr[i];
            for(int j=31;j>=0;j--){
                int temp = x>>j;
                if(temp&1){
                    bits[j]++;
                    bits[j] = bits[j]%3;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<32;i++){
            if(bits[i] == 1){
                ans += 1<<i;
                // cout<<i<<" ans "<<ans<<"\n";
            }
            // cout<<bits[i]<<" ";
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends