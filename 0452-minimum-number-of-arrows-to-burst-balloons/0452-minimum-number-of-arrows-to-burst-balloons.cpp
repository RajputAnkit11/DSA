class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
            return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points){
        
        sort(points.begin(),points.end(),comp);
        
        int count = 0;
        int pos=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=pos){
                pos=min(points[i][1],pos);
            }else{
                count+=1;
                pos=points[i][1];
            }
        }
        count+=1;
        return count;
    }
};