class Solution {
public:
    int findIntegers(int num){

        int fb[32];
        fb[0] = 1;
        fb[1] = 2;

        // if we consider n bit numbers. 10(number of n-2 bit such numbers)
        //                               0(number of n-1 bit such numbers)

        for(int i=2;i<31;i++) fb[i]=fb[i-1]+fb[i-2];

        int count = 0;
        for(int i=30;i>=0;i--)
            if(num&(1<<i)) {
                count += fb[i];
                if(num&(1<<(i+1))) return count;

            }
        return count+1;
    }
};
