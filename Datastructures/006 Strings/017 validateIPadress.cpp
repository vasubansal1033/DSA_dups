class Solution {
public:
    bool isNumber(char c){

        if(c-'0'>=0 && c-'0'<=9) return true;
        else return false;

    }
    bool isLetter(char c){

        if((c>='A' && c<='F') || (c>='a' && c<='f')) return true;
        else return false;

    }
    string validIPAddress(string IP) {

        if(IP[IP.size()-1]=='.' || IP[IP.size()-1]==':') return "Neither";

        for(int i=0; i<5; i++){

            if(IP[i]=='.'){

                stringstream ss(IP);
                IP = "";

                // count also
                int cnt=0;
                while(getline(ss, IP, '.')){

                    if(IP[0]=='0' && IP.size()>1 || IP.size()>3||cnt>=4||IP.size()==0) return "Neither";
                    for(int j=0; j<IP.size(); j++)
                        if(!isNumber(IP[j])) return "Neither";

                    int temp = stoi(IP);
                    cnt++;
                    if(temp>=0 && temp<=255) continue;
                    else
                        return "Neither";

                }

                return cnt==4?"IPv4":"Neither";

            }
            if(IP[i]==':'){

                stringstream ss(IP);
                IP = "";

                int cnt = 0;
                while(getline(ss, IP, ':')){

                    if(IP.size()>4 || cnt>=8||IP.size()==0) return "Neither";
                    for(int j=0; j<IP.size(); j++)
                        if(!(isNumber(IP[j]) || isLetter(IP[j]))){

                            return "Neither";
                        }

                    cnt++;

                }

                return cnt==8?"IPv6":"Neither";

            }

        }

        return "Neither";

    }
};
