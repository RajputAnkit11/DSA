//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.length();
        
        int l = -1, r = -1;
        map<char,int> map;
        int max_len = -1;
        
        while(r<n){
            r++;
            map[s[r]]++;
            while(map.size() > k){
                l++;
                map[s[l]]--;
                
                if(map[s[l]] == 0){
                    map.erase(s[l]);
                }
                
                int new_len = r-l;
                max_len = max(max_len,new_len);
            }
        }
        return max_len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends