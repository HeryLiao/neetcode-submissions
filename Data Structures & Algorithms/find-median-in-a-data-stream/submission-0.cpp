class MedianFinder {
private:
    priority_queue<int>maxH;
    priority_queue<int ,vector<int> ,greater<int> >minH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        int c = maxH.top();
        maxH.pop();
        minH.push(c);
        if(maxH.size() < minH.size()){
            c = minH.top();
            minH.pop();
            maxH.push(c);
        }
    }
    
    double findMedian() {
        int a = maxH.size();
        int b = minH.size();
        if( a == b){
            return (maxH.top() + minH.top()) / 2.0;
        }
        else{
            return a > b ? maxH.top() : minH.top();
        }
    }
};
