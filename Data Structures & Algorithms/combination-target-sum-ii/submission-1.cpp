class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> s;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin() ,candidates.end());
       helper(candidates,target , 0 , {}); 
        return result;
    }
     void helper(vector<int> nums , int target , int i, vector<int> temp){
        if(target == 0 ){
            if(s.find(temp) == s.end()){
                s.insert(temp);
                result.push_back(temp);
            }
            return;
        }
        if( target <0 || i >= nums.size()){
            return;
        }
        temp.push_back(nums[i]);
        helper(nums, target - nums[i] , i+1 , temp);
        temp.pop_back();
        helper(nums, target , i+1 , temp);
        
    }
};
