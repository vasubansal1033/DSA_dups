class Solution {
public:
    int calculate(string s) {

        stack<int> numbers, operators;
        // result will store calculations
        // num stores current number
        int result = 0, num = 0;
        int sign = 1;
        for(auto c:s){

            if(c==' ')
                continue;

            if(c>='0' && c<='9')
                num = num*10 + (c-'0');
            else{

                result+= sign*num;
                num = 0;

                if(c=='+')
                    sign = 1;
                if(c=='-')
                    sign = -1;

                if(c=='('){
                    numbers.push(result);
                    operators.push(sign);
                    result = 0; sign = 1;
                }else if(c==')' && operators.size()>0){

                    result = numbers.top() + operators.top()*result;
                    numbers.pop(); operators.pop();

                }

            }

        }
        result+=sign*num;
        return result;

    }
};
