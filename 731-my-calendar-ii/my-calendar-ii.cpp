class MyCalendarTwo {
    vector<pair<int,int>> b;
    vector<pair<int,int>>db;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for(pair<int,int> x: db){
            if(start<x.second && end>x.first) return false;
        }
        for(pair<int,int> x : b){
            if(start<x.second && end>x.first){
                db.push_back({max(start,x.first),min(end,x.second)});
            }
        }
        b.push_back({start,end});
        return true;
        
    }
};