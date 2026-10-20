class CountSquares {
private:
    unordered_map<int, unordered_map<int, int>> mp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;
        for(auto &[x2,ys] : mp){
            if(x==x2) continue;

            int d = abs(x-x2);
            
            for(int sign : {-1,1}){
                int y2 = y + d*sign;
                ans += mp[x][y2]*mp[x2][y]*mp[x2][y2];
            }
        }
        return ans;
    }
};
