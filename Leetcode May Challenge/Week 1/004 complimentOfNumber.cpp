class Solution {
public:
    int findComplement(int num) {

        int comp = 0;
        int power = 0;
        while(num!=0){

            int bit = num%2;
            num = num/2;
            if(bit==0){
                comp = comp+pow(2, power);
            }
            power++;

        }

        return comp;

    }
};
