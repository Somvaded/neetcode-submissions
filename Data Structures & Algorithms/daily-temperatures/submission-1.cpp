class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<temperatures.size(); i++){
            while(!s.empty() && s.top().first < temperatures[i]){
                auto prevTop = s.top();
                s.pop();
                res[prevTop.second] = i - prevTop.second;
            }
            s.push({temperatures[i],i});
        }

        return res;
    }
};
