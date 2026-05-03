class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin() ,candidates.end());
       helper(candidates,target , 0 , {}); 
        return result;
    }
     void helper(vector<int> nums , int target , int i, vector<int> temp){
        if(target == 0 ){
            result.push_back(temp);
            return;
        }
        if( target <0 || i >= nums.size()){
            return;
        }
        temp.push_back(nums[i]);
        helper(nums, target - nums[i] , i+1 , temp);
        temp.pop_back();
        while( i+1 < nums.size() && nums[i] == nums[i+1] ){
            i++;
        }
        helper(nums, target , i+1 , temp);
        
    }
};
