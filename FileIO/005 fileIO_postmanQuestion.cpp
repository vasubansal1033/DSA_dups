//https://leetcode.com/discuss/interview-question/860505/Postman-File-System-Online-Assesment-Question


#include<bits/stdc++.h>
using namespace std;

int stoi(string &temp){
    int res = 0;
    for(int i = 0; i < temp.size(); i++)
        res = res * 10 + (temp[i] - '0');
    return res;
}

int solve(string &s){
    int n = s.length();
    string res;

    n--;
    while(isdigit(s[n]))
        res = s[n] + res, n--;
    return stoi(res);
}

int main(){
    ifstream fin;
    ofstream fout;
    string filename, line;
    int count = 0, sum = 0;

    cin >> filename;

    fin.open(filename, ios::in);
    while(fin){
        getline(fin, line);
        int x = solve(line);
        if(x > 5000)
            count++, sum += x;
    }
    fin.close();

    fout.open("bytes_" + filename);
    fout << count << endl;
    fout << sum << endl;
    fout.close();
    return 0;
}
