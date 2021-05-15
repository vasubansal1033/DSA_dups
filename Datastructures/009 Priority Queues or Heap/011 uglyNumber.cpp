typedef long long int lli;
class Solution {
public:
    int nthUglyNumber(int n) {

        if(n==1)
            return 1;
        priority_queue<lli, vector<lli>, greater<lli> > minHeap;

        minHeap.push(2); minHeap.push(3); minHeap.push(5);

        while(n-2>0){

            lli temp = minHeap.top(); minHeap.pop();
            if(temp%5==0){
                minHeap.push(temp*5);
            }else if(temp%3==0){
                minHeap.push(temp*5); minHeap.push(temp*3);
            }else{
                minHeap.push(temp*5); minHeap.push(temp*3); minHeap.push(temp*2);
            }

            n--;

        }


        return minHeap.top();

    }
};
