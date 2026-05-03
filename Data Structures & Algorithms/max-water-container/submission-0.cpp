class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int ans=0;
        while(l<r){
            int curr_Max = (r-l)*min(heights[l],heights[r]);
            ans= max(ans,curr_Max);
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
