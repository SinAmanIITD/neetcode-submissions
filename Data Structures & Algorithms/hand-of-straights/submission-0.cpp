class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        map<int, int> mp;
        for(int h : hand){
            mp[h]++;
        }
        while(!mp.empty()){
            int start = mp.begin()->first;
            for(int i = start; i<start+groupSize; i++){
                if(mp[i]==0){
                    return false;
                }
                mp[i]--;
                if(mp[i]==0){
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};
