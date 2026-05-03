class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preMultiply(nums.size());
        vector<int> sufMultiply(nums.size());
        vector<int> ans(nums.size());

        int temp1=1,temp2=1;
        int n=nums.size();
        for(int i=0;i< nums.size();i++){
            preMultiply[i] = temp1*nums[i];
            temp1=temp1*nums[i];
            sufMultiply[n-i-1]=temp2*nums[n-i-1];
            temp2=temp2*nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            cout<< preMultiply[i]<< " "<<sufMultiply[i]<<endl;
        }
        for(int i=0;i<nums.size();i++){
            if(i==0 || i==n-1){
               if(i==0){
                ans[i] = sufMultiply[i+1];
               }
               else{
                ans[i] = preMultiply[i-1];
               }
                continue;
            }
            ans[i] = preMultiply[i-1]*sufMultiply[i+1];
        }
        return ans;
        
        
    
        

    }
};
