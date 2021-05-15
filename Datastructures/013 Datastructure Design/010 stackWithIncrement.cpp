class CustomStack {
public:
    vector<int> stk, inc;
    int n;
    CustomStack(int maxSize) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        n = maxSize;
    }

    void push(int x) {

        if(stk.size()==n) return;
        stk.push_back(x);
        inc.push_back(0);

    }
    int pop() {

        int idx = stk.size()-1;
        if(idx<0) return -1;
        if(idx>0) inc[idx-1]+=inc[idx]; // lazy propagation

        int res = stk[idx]+inc[idx];
        stk.pop_back(); inc.pop_back();

        return res;
    }

    void increment(int k, int val) {
        int idx = min(k, (int)stk.size())-1;

        if(idx>=0) inc[idx]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 */
 * obj->increment(k,val);


class CustomStack {
public:
    vector<int> v;
    int idx;
    CustomStack(int maxSize) {
        v.resize(maxSize+1);
        idx = 0;
    }

    void push(int x) {

        idx++;
        if(idx<v.size()){
            v[idx] = x;
        }else idx--;

    }

    int pop() {


        int temp = v[idx];
        if(idx==0){
            return -1;
        }
        idx--;

        return temp;

    }

    void increment(int k, int val) {

        int last = min(k, min((int)v.size()-1, idx));
        for(int i=1; i<=last; i++)
            v[i]+=val;

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
