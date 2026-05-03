class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            vector<int> A = nums1;
            nums1=nums2;
            nums2=A;
        }
        int x = nums1.size();
        int y = nums2.size();

        int l = 0, r = x;
        while(l<=r){
            int partX = (l+r)/2;
            int partY = (x+y+1)/2 - partX;

            int XleftMax = partX == 0 ? INT_MIN : nums1[partX-1];
            int XrightMin = partX == x ? INT_MAX : nums1[partX];

            int YleftMax = partY == 0 ? INT_MIN : nums2[partY-1];
            int YrightMin = partY == y ? INT_MAX : nums2[partY];

            if(XleftMax <= YrightMin && XrightMin >= YleftMax){
                if((x+y)%2==0){
                    return (max(XleftMax,YleftMax)+min(YrightMin,XrightMin))/2.0;
                }
                else{
                    return max(XleftMax,YleftMax);
                }
            }
            else if(XleftMax> YrightMin){
                r = partX-1;
            }
            else{
                l = partX+1;
            }
        }
        return -1;

    }
};
