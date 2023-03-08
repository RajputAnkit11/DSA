class Solution {
public:
    bool isPossible(int mid, vector<int>& piles, int h){
        int n = piles.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(piles[i]%mid == 0){
                cnt += piles[i]/mid;
            }
            else{
                cnt += piles[i]/mid + 1;
            }
        }   
        
        if(cnt>h){
            return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int l = 1;
        int r = -1;
        
        for(int i=0;i<n;i++) r = max(r,piles[i]);
        int mid,ans;
        while(l<=r){
            mid =r - (r-l)/2;
            
            if(isPossible(mid,piles,h)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};