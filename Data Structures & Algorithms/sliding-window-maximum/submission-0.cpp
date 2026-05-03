class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> order_count;
        vector<int> res;
        for(int i=0;i<k;i++){
            order_count[nums[i]]++;
        }
        if(k==nums.size()){
            return {order_count.rbegin()->first};
        }
        int l = 0, r = k-1;
        while(r<nums.size()){
            res.push_back(order_count.rbegin()->first);
            order_count[nums[l]]--;
            if(order_count[nums[l]]==0){
                order_count.erase(nums[l]);
            }
            l++;
            r++;
            order_count[nums[r]]++;
        }
        return res;
    }
};
