class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int>s;
        vector<int>v;
        while(n--){
            if(s.empty()){
                v.push_back(0);
                s.push(n);
            }
            else{
                int f=0;
                while(!s.empty()){
                    if(t[s.top()]>t[n]){
                        f=1;
                        break;
                    }
                    s.pop();
                    
                }
                if(f==1)
                v.push_back(s.top()-n);
                else
                v.push_back(0);
                s.push(n);

            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};