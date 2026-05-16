class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        stack<float> st;
        int res = position.size();
        for(int i = 0; i<position.size(); i++){
            vec.push_back({position[i],speed[i]});
        }

        sort(vec.begin(), vec.end());

        for(int i =vec.size()-1 ; i>=0 ;i--){
            float t = (float)(target-vec[i].first)/(float)vec[i].second;
            if(st.empty() || st.top() < t){
                st.push(t);
            }
        }

        return st.size(); 
    }
};