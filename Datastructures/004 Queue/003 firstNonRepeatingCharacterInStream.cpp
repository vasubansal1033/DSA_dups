// clean code
string Solution::solve(string A) {

    string res = "";
    queue<char> q;
    unordered_map<char, int> seen;

    for(int i=0; i<A.size(); i++){

        seen[A[i]]++;
        q.push(A[i]);
        while(!q.empty() && seen[q.front()]>1) q.pop();


        if(!q.empty()) res+=q.front();
        else res+='#';

    }

    return res;

}



string Solution::solve(string A) {

    string res = "";
    deque<char> dq;
    unordered_set<char> seen;
    unordered_set<char> dups;

    res+=A[0];
    dq.push_front(A[0]);
    for(int i=1; i<A.size(); i++){



        if(dq.front()==A[i] || seen.find(A[i])!=seen.end()) dups.insert(A[i]);
        while(!dq.empty() && (dq.front()==A[i] || dups.find(dq.front())!=dups.end() )) dq.pop_front();

        if(seen.find(A[i])==seen.end())
            seen.insert(A[i]);
        else
            dups.insert(A[i]);

        if(dups.find(A[i])==dups.end() && A[i]!=dq.front())
            dq.push_back(A[i]);

        if(dq.empty()) res+='#';
        else{
            res+=dq.front();
        }


    }

    return res;

}
