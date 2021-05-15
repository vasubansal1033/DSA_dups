// using list
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> result;
        list<vector<int>> lst;
        list<vector<int>>::iterator it;
        int temp;
        for(auto& p: people) {
                it = lst.begin();
                temp = p[1];
                while(temp--) ++it;
                lst.insert(it, p);
        }
        std::move(lst.begin(), lst.end(), std::back_inserter(result));
        return result;
    }
};

// Using BIT
class Solution {
public:
    void update(int* BIT, int i, int val, int sz){
        i++;
        for(; i<=sz; i+=i&-i){
            BIT[i]+=val;
        }
    }
    int getSum(int* BIT, int i, int sz){
        i++;
        int sum = 0;
        for(; i>0; i-=i&-i){
            sum+=BIT[i];
        }
        return sum;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        // first sort people according to heights
        sort(people.begin(), people.end(), [&](vector<int> a, vector<int> b){

            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];

        });

        // for(int i=0; i<people.size(); i++) cout<<people[i][0]<<'|'<<people[i][1]<<" ";

        int BIT[people.size()+1];
        memset(BIT, 0, sizeof(int)*(people.size()+1));

        // first element is 0 so for the element which will be first in answer, since its second part is 0
        for(int i=1; i<people.size(); i++) update(BIT, i, 1, people.size()); // starts from 1 and not 0. (not due to BIT)

        vector<vector<int> > res(people.size());
        for(int i=0; i<people.size(); i++){

            int lo = 0, hi = people.size()-1;
            while(lo<hi){
                int mid = lo+(hi-lo)/2;
                if(getSum(BIT, mid, people.size())>=people[i][1]) hi = mid;
                else lo = mid+1;
            }

            res[lo] = people[i];
            update(BIT, lo, -1, people.size());

        }



        return res;
    }
};


// On2. insertion process can be optimized by using a BIT
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), [&](vector<int> a, vector<int> b){

            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];

        });

        vector<vector<int> > res;
        for(int i=0; i<people.size(); i++)
            res.insert(res.begin()+people[i][1], people[i]);

        return res;
    }
};
