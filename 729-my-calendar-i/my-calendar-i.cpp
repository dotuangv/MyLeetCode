class MyCalendar {
public:
    set<pair<int, int>> se;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(se.find({start, end}) != se.end()) return false;
        se.insert({start, end});
        auto it = se.find({start, end});
        bool ok = true;
        if(it != se.begin())
            ok &= ((*prev(it)).second <= start);
        if(next(it) != se.end())
            ok &= ((*next(it)).first >= end);
        if(!ok) se.erase(it);
        return ok;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */