class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<double,double>> pairs(n);
        for(int i= 0;i<n ;i++){
            pairs[i]={position[i],speed[i]};
        }
        sort(pairs.begin(),pairs.end(),[](const pair<double,double> &a, const pair<double,double> &b  ){
            return b.first<a.first;
        });
        int fleet=0;
        vector<double> time(n);
        for(int i=0;i<n;i++){
            time[i]=(target-pairs[i].first)/pairs[i].second;
            if(i>0 && time[i]<=time[i-1]){
                time[i]=time[i-1];
            }
            else{
                fleet++;
            }
        }
        return fleet;
    }
};
