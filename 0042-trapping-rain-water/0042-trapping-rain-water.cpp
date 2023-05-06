class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0;
        int r = height.size()-1;
        
        int leftMaxHeight = 0;
        int rightMaxHeight = 0;
        
        int ans = 0;
        
        while(l<r){
            if(height[l]<=height[r]){
                
                if(leftMaxHeight <= height[l]){
                    leftMaxHeight = height[l];
                }
                else{
                    ans += leftMaxHeight - height[l];
                }
                
                l++;
            }
            else{
                
                if(rightMaxHeight <= height[r]){
                    rightMaxHeight = height[r];
                }
                else{
                    ans += rightMaxHeight - height[r];
                }
                
                r--;
            }
        }
        
        return ans;
    }
};