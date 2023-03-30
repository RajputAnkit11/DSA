class Solution {
public:
unordered_map<string,bool> mp;
bool rec(string s1,string &s2,int s,int e)
{   if(s1==s2.substr(s,e-s+1)){return 1;}
    if(e-s<=0){return 0;}
    string save=s1+"|"+to_string(s)+"|"+to_string(e);
    if(mp.find(save)!=mp.end()){return mp[save];}
    for(int i=s;i<e;i++)
    {
        int l2=i-s+1,l1=(e-s)+1-l2;
//l2 is the length of first halve
string x=s1.substr(0,l2),y=s1.substr(l2,l1);
        if(rec(x,s2,s,i)&&rec(y,s2,i+1,e)||(rec(y,s2,s,s+l1-1)&&rec(x,s2,s+l1,e))){return mp[save]=1;}
    }
    return mp[save]=0;
}
    bool isScramble(string s1, string s2) {
        return rec(s1,s2,0,s1.size()-1);
    }

};