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

string func(vector<int>&arr,int ele)
{
    int lo = -1;
    int hi = arr.size();
    while(lo+1<hi)
    {
        int mid = lo + (hi-lo)/2;
        if(arr[mid]<=ele)
            lo = mid;
        else
            hi = mid;
    }
    if(lo!=-1 && arr[lo]==ele)
        return "YES";
    return "NO";
}

int32_t main()
{
    pujith22();
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    while(k--)
    {
        int inp;
        cin>>inp;
        cout<<func(arr,inp)<<"\n";
    }
    return 0;
}