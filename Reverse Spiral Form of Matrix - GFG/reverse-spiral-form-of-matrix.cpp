//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>> &mat)  {
        // code here
        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;
        
        vector<int> ans;
        
        int direction = 1;
        while(left<=right and top<=bottom){
            
            if(direction == 1){
                for(int i=left;i<=right;i++){
                    ans.push_back(mat[top][i]);
                }
                direction = 2;
                top++;
            }
            
            else if(direction == 2){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(mat[i][right]);
                }
                direction = 3;
                right--;;
            }
            
            else if(direction == 3){
                for(int i=right;i>=left;i--){
                    ans.push_back(mat[bottom][i]);
                }
                direction = 4;
                bottom--;
            }
            
            else if(direction == 4){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(mat[i][left]);
                }
                direction = 1;
                left++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends