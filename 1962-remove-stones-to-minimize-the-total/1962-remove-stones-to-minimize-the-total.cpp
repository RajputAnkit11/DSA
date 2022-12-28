class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        
        priority_queue<int> q;
        
        for(int i=0;i<n;i++){
            q.push(piles[i]);
        }
        
        while(k--){
            int x = q.top();
            if(x % 2 == 0){
                q.pop();
                q.push(x/2);
            }
            else{
                q.pop();
                q.push(x/2 + 1);
            }
        }
        int sum = 0;
        while(q.size()){
            // cout<<q.top()<<" ";
            sum += q.top();
            q.pop();
        }
        return sum;
    }
};