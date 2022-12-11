class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int,int> map;
        
        for(int i=0;i<n;i++){
            int x = ((nums[i]%k)+k)%k;
            map[x]++;
        }
        
        for(auto i:map){
            int temp = k-i.first;
            
            if(i.first == 0){
                if(i.second%2 == 1) return false;
            }
            else if(map.count(temp)){
                if(map[temp] != i.second){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};