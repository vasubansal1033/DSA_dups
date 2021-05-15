class MyCalendarTwo {
public:
    map<int, int> m;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {

        // following the logic used in interval questions
        m[start]++; m[end]--;

        int bookings = 0;
        for(auto i:m){
            bookings += i.second;
            if(bookings==3){

                m[start]--; m[end]++;
                return false;

            }
        }

        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
