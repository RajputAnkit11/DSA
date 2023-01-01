class Solution {
public:
    bool wordPattern(string pattern, string s) {

        //checking if the lengths match
        int a = pattern.size();
        int b = 1;

        for(char c : s){
            if(c == ' ')
                b++;
        }

        if(a!=b) return false;

        //storing words from s into an array
        vector<string> v;
        string p="";

        for(int i=0; i<s.size() ; i++){
            if(s[i]!=' ')
                p+=s[i];
            if(s[i]==' ')
            {
                v.push_back(p);
                p="";
            }
            if(i==s.size()-1) //storing the last word
                v.push_back(p);
        }

        vector<pair<char,string>>res; //made a pair to combine                                           pattern with s

        for(int i=0 ; i<pattern.size(); i++){
            res.push_back({pattern[i],v[i]});
        }

        //loops to check each element in vector of pair

        for(int i=0 ; i<res.size(); i++){
            for(int j=i+1 ; j<res.size() ; j++){
                // conditions :
                if(res[i].first==res[j].first &&            res[i].second!=res[j].second)
                    return false;

                if(res[i].first!=res[j].first and           res[i].second==res[j].second)
                    return false;
            }
        }
        return true;
    }
};