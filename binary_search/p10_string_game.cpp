#include<bits/stdc++.h>
#define int long long

using namespace std;

void pujith22()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
}

bool check(int k,const vector<int>&arr, string& t,string& p)
{
    int ptr = 0;
    vector<bool> hash(arr.size(),true);
    for(int i=0;i<=k;i++)
        hash[arr[i]] = false;
    for(int i=0;i<t.size();i++)
    {
        if(hash[i] && ptr<p.size() && t[i]==p[ptr])
            ptr++;
    }
    return ptr==p.size();
}

int32_t main()
{
    pujith22();
    string t,p;
    cin>>t;
    cin>>p;
    vector<int>arr(t.size());
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
        arr[i]--;
    }
    int lo = -1;
    int hi = arr.size();
    while(lo+1<hi)
    {
        int mid = lo + (hi-lo)/2;
        if(check(mid,arr,t,p))
            lo = mid;
        else
            hi = mid;
    }
    cout<<lo+1;
    return 0;
}