class MyCalendarTwo {
    map<int,int> m1, m2;
	bool isDoubleBooked(int start, int end) {
		auto it = m2.upper_bound(start);
		if (it != m2.end() && it->first < end) return true;		
		if (it != m2.begin() && start < prev(it)->second) return true;		
		return false;
	}		
    void addDoubleBooking(int start, int end) {
        if (start >= end) return;
        
        auto it = m2.upper_bound(start);
        if (it != m2.begin() && start < (--it)->second) {
            end = it->second = max(it->second, end);
        } else {
            it = m2.emplace(start, end).first;
        }
    
        while (++it != m2.end() && end > it->first) {
            if (end < it->second) {
                m2[end] = it->second;
            }            
            it = m2.erase(it);
        }
    }
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        if (isDoubleBooked(start, end)) return false;
        
        auto it = m1.upper_bound(start);
        if (it != m1.begin() && start < (--it)->second) {
            addDoubleBooking(start, min(it->second, end));
            end = it->second = max(it->second, end);
        } else {
            it = m1.emplace(start, end).first;
        }

        auto itErase = next(it);
        while (itErase != m1.end() && end >= itErase->first) {    
            addDoubleBooking(itErase->first, min(itErase->second, end));
            end = it->second = max(end, itErase->second);
            itErase = m1.erase(itErase);
        }

        return true;        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */