class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s;
        int n=heights.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int start_index=i;            
            while(!s.empty() && heights[i]<s.top().second){
                ans=max((i-s.top().first)*s.top().second,ans);
                start_index=s.top().first;
                s.pop();
            }
            s.push({start_index, heights[i]});
        }
        while(!s.empty()){
            ans=max((n-s.top().first)*s.top().second,ans);
            s.pop();
        }

        return ans;
    }
};
