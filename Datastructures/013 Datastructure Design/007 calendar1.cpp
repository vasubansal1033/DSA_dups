class MyCalendar {
public:
    map<int, int> m;
    MyCalendar() {

    }

    bool book(int start, int end) {

        auto it = m.lower_bound(start); // lower bound returns first element >= given element

        if(it!=m.begin()){

            // cout<<it->first<<" "<<it->second<<endl;
            // auto prev = --it; // wrong as we are changing decrementing it and then assigning it to prev
            auto prev = it;
            prev--;

            if((prev->second)>start) // overlaps
                return false;

        }

        if(it!=m.end()){

            if((it->first)<end){
                return false;
            }

        }

        // doesnot overlap now
        m[start] = end;
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
