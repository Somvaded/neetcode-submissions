class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       sort(piles.begin(),piles.end());
       int n = piles.size();
       int l = 1;
       int r = piles[n-1];
       int ans=INT_MAX;
       while(l<=r){
        int k = (l+r)/2;
        int time=0;
        for(auto x: piles){
            time+=x/k + (x%k!=0 ? 1 : 0);
            if(time>h){
                break;
            }
        }
        if(time>h){
            l=k+1;
        }
        else{
            ans= min(ans,k);
            r=k-1;
        }
       }
       return ans;
    }
};
