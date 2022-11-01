class Solution {
public:
    long long digsum(long long x){
        long long ans = 0;
        
        while(x>0){
            ans += x%10;
            x/=10;
        }
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        
        if(digsum(n) <= target) return 0;
        long long count=10;
        long long temp=n;
        
        while(digsum(temp)> target){
            long long mod=n%count;
            temp=n+count-mod;
            count*=10;
        }
        
        return temp-n;
    }
};