#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

long long int teamFromation(vector<int> score, int noMember, int m)
{
    long long int ans=0;
    int n=score.size();
    priority_queue<pair<int, int>> memberScore;
    for(int i=0;i<m;i++)memberScore.push({score[i], i});
    for(int i=n-m;i<n;i++)memberScore.push({score[i], i});
    int low=m-1;
    int high=n-m;
    while(high>low && noMember)
    {
        pair<int, int> temp=memberScore.top();
        memberScore.pop();
        ans+=temp.first;
        noMember--;
        if(temp.second<=low)
        {
            low++;
            if(low < high)
                memberScore.push({score[low], low});
        }
        else if(temp.second>=high)
        {
            high--;
            if(high>low)memberScore.push({score[high], high});
        }
    }
    while(!memberScore.empty() && noMember)
    {
        ans+=memberScore.top().first;
        memberScore.pop();
        noMember--;
    }
    return ans;
}


int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        int noSore,noMember, m;
        cin>>noSore>>noMember>>m;
        vector<int> score(noSore);
        for(int i=0;i<noSore;i++)
            cin>>score[i];
        cout<<teamFromation(score, noMember, m)<<endl;
    }
}

#include<bits/stdc++.h>

using namespace std;

int ts(vector<int> a,int nt,int m)
{
    //bruteforce_method
    long long ans=0;
    int n=a.size();
    for(int i=0;i<nt&&a.size()>0;i++)
    {
        int n=a.size();
        int max1=*max_element(a.begin(),a.begin()+min((int)a.size(),m));
        int index1=max_element(a.begin(),a.begin()+min((int)a.size(),m))-a.begin();
        int max2=*max_element(a.begin()+max(0,n-m-2),a.end());
        int index2=max_element(a.begin()+max(0,n-m-2),a.end())-a.begin();
        // for(int i=0;i<a.size();i++)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        // cout<<max1<<" "<<index1<<" "<<max2<<" "<<index2<<" "<<ans<<endl;
        if(max1>=max2)
        {
            ans+=max1;
            a.erase(a.begin()+index1);
        }
        else if(max2>max1)
        {
            ans+=max2;
            a.erase(a.begin()+index2);
        }
    }
    return ans;

}

int pq(vector<int> a,int nt,int m)
{
    //using priority_queue
    int n=a.size();
    priority_queue<pair<int,int> > q;
    for(int i=0;i<m;i++)
        q.push(make_pair(a[i],i));
    int l=m-1;
    int r=n-m;
    if(r>l)
    {
        for(int i=n-m;i<n;i++)
            q.push(make_pair(a[i],i));
    }
    long long ans=0;
    while(l<r&&nt)
    {
        pair<int,int> temp=q.top();
        q.pop();
        // cout<<temp.first<<" "<<temp.second<<endl;
        ans+=temp.first;
        if(temp.second>l)
        {
            r--;
            if(r>l)
                q.push(make_pair(a[r],r));
            nt--;
        }
        else if(temp.second<l)
        {
            l++;
            if(l<r)
                q.push(make_pair(a[l],l));
            nt--;
        }
        // cout<<temp.first<<" "<<temp.second<<" "<<l<<" "<<r<<" "<<nt<<endl;
    }
    while(!q.empty()&&nt)
    {
        // cout<<q.top().first<<" "<<q.top().second<<endl;
        ans+=q.top().first;
        q.pop();
        nt--;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,nt,m;
        cin>>n>>nt>>m;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<ts(a,nt,m)<<endl;
        cout<<pq(a,nt,m)<<endl;
    }
    return 0;
}
