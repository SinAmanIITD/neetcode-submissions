class MedianFinder {
public:
    priority_queue<int> lh;
    priority_queue<int, vector<int>, greater<int>> uh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lh.push(num);

        uh.push(lh.top());
        lh.pop();

        if(lh.size()<uh.size()){
            lh.push(uh.top());
            uh.pop();
        }
    }
    
    double findMedian() {
        if(lh.size()>uh.size()){
            return lh.top();
        } 
        return (lh.top()+uh.top())/2.0;
    }
};
