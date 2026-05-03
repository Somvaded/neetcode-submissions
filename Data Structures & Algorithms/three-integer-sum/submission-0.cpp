class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>0){
                break;
            }
            if( i > 0 && nums[i] == nums[i-1]) continue;
            int start = i+1 , end = nums.size()-1;
            while(start<end){
                int sum = nums[start]+nums[end] + nums[i];
                if(sum>0){
                    
                    end--;
                }
                else if(sum<0){
                    start++;
                }
                else{
                    ans.push_back({nums[start],nums[end],nums[i]});
                    start++;end--;
                    while( start < end && nums[start] == nums[start-1]){
                        start++;
                    }
                }
            }

        }
        if(ans.size()==0){
            return {};
        }
        return ans;
    }
};
