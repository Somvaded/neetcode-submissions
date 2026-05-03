class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>> monoDec;
        vector<int> result(temperatures.size());
        
        for(int i=0;i<temperatures.size();i++){
            int t = temperatures[i];
            while(!monoDec.empty() && t > monoDec.top()[0]){
                vector<int> temp = monoDec.top();
                monoDec.pop();
                result[temp[1]] = i - temp[1]; 
            }
            monoDec.push({temperatures[i],i});
        }
        return result;
    }
};
