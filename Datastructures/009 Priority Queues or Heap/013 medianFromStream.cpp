class MedianFinder {
public:
    /** initialize your data structure here. */

    bool isEven = false;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {

    }

    // empty and -1
    //
    //

    void addNum(int num) {

        if(isEven){
            minHeap.push(num);
            maxHeap.push(minHeap.top()); minHeap.pop();
        }else{

            maxHeap.push(num);
            minHeap.push(maxHeap.top()); maxHeap.pop();

        }

        isEven = !isEven;

    }

    double findMedian() {

        if(isEven){
            return minHeap.top();
        }else{
            return (double)((minHeap.top()+maxHeap.top())/2.0);
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
