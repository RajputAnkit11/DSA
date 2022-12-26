class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        
        vector<int> a;int mn=INT_MAX;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==target)
                a.push_back(i);
        }
        if(a.size()==0)
            return -1;
        int n=words.size();
        for(int i=0;i<a.size();i++)
        {
            int temp=abs(a[i]-startIndex);
            int t=n-temp;
            int x=min(t,temp);
            mn=min(mn,x);
        }
        return mn;
        
        
    }
};