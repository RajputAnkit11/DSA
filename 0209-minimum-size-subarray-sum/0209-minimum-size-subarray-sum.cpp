class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0, r = 0;
        long long int sum = 0;
        int ans = INT_MAX;
        
        // while(r<n){
        //     sum += nums[r];
        //     r++;
        //     while(sum>=target){
        //         sum -= nums[l];
        //         ans = min(ans,r-l+2);
        //         l--;
        //     }
        // }
        
        while(true){
            bool f1 = false;
            bool f2 = false;
            while(r<n){
                f1 = true;
                sum += nums[r];
                r++;
                cout<<sum<<endl;
                if(sum>=target){
                    break;
                }
                f1 = false;
            }
            cout<<"here\n";
            while(l<r){
                if(f1 == false) break;
                f2 = true;
                sum -= nums[l];
                cout<<"sum 2 = "<<sum<<endl;
                l++;
                if(sum<target){
                    ans = min(ans,r-l+1);
                    cout<<"ans "<<ans<<endl;
                    break;
                }
                else{
                    continue;
                }
            }
            
            if(!f1 and !f2){
                break;
            }
        }
        
        return ans==INT_MAX? 0 : ans;
    }
};