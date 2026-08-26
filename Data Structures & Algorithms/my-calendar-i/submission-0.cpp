class MyCalendar {
private:
    vector<pair<int , int>> books;

public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto b : books){
            if(startTime < b.second && endTime > b.first){
                return false;
            }

        }
        books.push_back({startTime , endTime});
        return true;
    
    }     
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */