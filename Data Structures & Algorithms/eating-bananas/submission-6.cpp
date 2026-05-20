class Solution {
public:
    bool canEat(vector<int> &piles, int k, int h){
        for(int i = 0;i < piles.size() ;i++){
            int hoursTaken = piles[i] / k + (piles[i] % k != 0);
            h-=hoursTaken;
            if(h < 0){
                return false;
            }
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = INT_MIN;
        int l = 1;
        for(auto x : piles){
            r = max(r, x);
        }
        while(l < r){
            int kTemp = (r + l)/2;
            bool can = canEat(piles, kTemp, h);
            if(can){
                r = kTemp;
            } else{
                l = kTemp+1;
            }
        }
        return l;
    }
};
