typedef long long int lli;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        if(n==1)
            return 1;

        priority_queue<lli, vector<lli>, greater<lli> > minHeap;

        // add all the primes in heap
        for(auto i:primes)
            minHeap.push(i);


        while(n-2>0){

            lli temp = minHeap.top(); minHeap.pop();

            for(int i=primes.size()-1; i>=0; i--){

                if(temp%primes[i]==0){

                    for(int k=primes.size()-1; k>=i; k--)
                        minHeap.push(temp*primes[k]);
                    break;
                }

            }

            n--;

        }

        cout<<minHeap.size();
        return minHeap.top();

    }
};
