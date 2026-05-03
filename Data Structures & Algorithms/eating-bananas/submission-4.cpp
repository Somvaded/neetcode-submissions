class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r = INT_MIN;
        
        for(int i = 0;i<piles.size();i++){
            if(r<piles[i]){
                r= piles[i];
            }
        }
        int res = r;
        while(l<=r){
            int mid = (l+r)/2;
            long long totalTime = 0;
            for(auto x: piles){
                long long div =  x/mid;
                long long remain = 1 ? x%mid>0 : 0;  
                totalTime += div+remain;
                
            }
            if(totalTime<=h){
                res = mid;
                r = mid-1;
            }
            else{
                l =  mid+1;
            }
            
        }
        return res;
    }
};
