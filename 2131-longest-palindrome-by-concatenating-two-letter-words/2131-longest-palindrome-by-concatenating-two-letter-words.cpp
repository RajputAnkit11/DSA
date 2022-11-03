class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int a=0;
        int b=0;
        int n=words.size();
        map<string,int> mp;
        for(int i=0;i<n;i++){
        	mp[words[i]]++;
        }
       for(auto k:mp){
        	string t=k.first;
        	if(t[0]==t[1]){
               a+=(k.second/2)*4;
               if((k.second%2 != 0)) b=1;
        	}
        	else{
        	reverse(t.begin(),t.end());
        	if(mp.find(t)!=mp.end()){
        		a+=min(k.second,mp[t])*2;
        	}
           }
		}
		if(b==1) a+=2;
		return a;
    }
};