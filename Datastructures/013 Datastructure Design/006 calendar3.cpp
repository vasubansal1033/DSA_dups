class MyCalendarThree {
public:

    map<int, int> m;
    MyCalendarThree() {

    }

    int book(int start, int end) {

        m[start]++; m[end]--;

        int booking = 0;
        int res = 0;
        for(auto i=m.begin(); i!=m.end(); i++){

            booking+=i->second;
            res = max(res, booking);
        }



        return res;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
