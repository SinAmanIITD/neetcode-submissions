class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int cur = 0;
        int start = 0;
        for(int i = 0; i<n; i++){
            int diff = gas[i]-cost[i];
            total += diff;
            cur += diff;
            if(cur<0){
                start = i+1;
                cur = 0;
            }
        }
        if(total<0){
            start = -1;
        }
        return start;
    }
};

//1-2 = -1
//-1+2-2 = -1
//-1+3-4 = -2
//-2+4-1 = 1

//2-2 = 0
//0+3-4 = -1
//-1+4-1 = 2
//2+1-2 = 1

//3-4 = -1
//-1+4-1 = 2
//2+1-2 = 1
//1+2-2 = 1

//4-1 = 3
//3+1-2 = 2
//2+2-2 = 2
//2+3-4 = 1

//1-2 = -1
//-1+2-3 = -2
//-2+3-2 = -1

//2-3 = -1
//-1+3-2 = 0
//3-2 = 1

