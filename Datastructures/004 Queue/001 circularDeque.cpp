class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int> v;
    int start, last, size=0, count=0;
    MyCircularDeque(int k) {

        v.resize(k);
        start = 0;
        last = k-1;
        size = k;

    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {

        if(!isFull()){
            v[start] = value;
            start = (start+1)%size;
            count++;
            return true;
        }
        return false;

    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {

        if(!isFull()){
            v[last] = value;
            last = (last-1+size)%size;
            count++;
            return true;
        }
        return false;

    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {

        if(!isEmpty()){
            start = (start-1+size)%size;
            count--;
            return true;
        }
        return false;

    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {

         if(!isEmpty()){
            last = (last+1)%size;
            count--;
            return true;
        }
        return false;
    }


    /** Get the front item from the deque. */
    int getFront() {
        return !isEmpty()?v[(start-1+size)%size]:-1;
    }

    /** Get the last item from the deque. */
    int getRear() {
        return !isEmpty()?v[(last+1)%size]:-1;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count==0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
