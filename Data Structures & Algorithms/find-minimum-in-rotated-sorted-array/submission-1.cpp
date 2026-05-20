class Solution {
public:
    int findMin(vector<int> &nums) {
        int bk = 0;
        int n = nums.size();
        for(int i = 1 ;i < n; i++){
            if(nums[i] < nums[i-1]){
                bk = i;
                break;
            }
        }
        return nums[bk];
    }
};
