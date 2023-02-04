class Solution {
public:
    
    bool isSame(int a[],int b[]){
        for(int i=0;i<26;i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
    
        int freq1[26] = {0};
        int freq2[26] = {0};
        
        int n = s1.length();
        int m = s2.length();
        if(n>m) return false;
        for(int i=0;i<n;i++){
            freq1[s1[i] - 'a']++;
        }
        
        
        int i = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            freq2[s2[i] - 'a']++;
            j = i;
        }
        j++;
        // cout<<i<<" "<<j;
        if(isSame(freq1,freq2)) return true;
        
        while(j<m){
            freq2[s2[j++]-'a']++;
            freq2[s2[i++]-'a']--;
            if(isSame(freq1,freq2)) return true;
        }
        
        return false;
    }
};