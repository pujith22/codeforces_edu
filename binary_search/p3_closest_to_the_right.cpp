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

int closest_to_the_right(vector<int>&arr,int ele)
{
    int lo = -1;
    int hi = arr.size();
    while(lo+1<hi)
    {
        int mid = lo+(hi-lo)/2;
        if(arr[mid]>=ele)
            hi = mid;
        else
            lo = mid;
    }
    return hi+1;
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
        cout<<closest_to_the_right(arr,inp)<<"\n";
    }
    return 0;
}