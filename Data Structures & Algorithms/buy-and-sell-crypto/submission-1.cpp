class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int res = 0;
        for(auto x : prices){
            mi = min(mi, x);
            res = max(res, x-mi);
        }
        return res;
    }
};
