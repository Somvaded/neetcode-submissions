class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto x: nums ){
            count[x]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for(auto x : count){
            freq[x.second].push_back(x.first);
        }

        vector<int> res;
        for(int i=freq.size()-1;i>0;i--){
            for(int j=0;j<freq[i].size() && freq[i].size()>0;j++){
                if(k==0){
                    return res;
                }
                k--;
                res.push_back(freq[i][j]); 
            }
        }
        return res;
    
    }
};
