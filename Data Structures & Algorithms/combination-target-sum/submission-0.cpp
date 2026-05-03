class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        helper(nums , 0 , target , {});
        return result;
    }

    void helper(vector<int> nums ,int i, int target , vector<int> temp){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if( target <0 || i>=nums.size()){
            return;
        }
        temp.push_back(nums[i]);
        helper(nums , i , target-nums[i] , temp);
        temp.pop_back();
        helper(nums,i+1 , target , temp);
    }
};
