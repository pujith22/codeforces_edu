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

int closest_to_the_right(const vector<int>&arr,const int ele)
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
    return hi;
}

int32_t main()
{
    pujith22();
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    int k,l,r;
    cin>>k;
    while(k--)
    {
        cin>>l>>r;
        // idea is as follows, we need to pointers
        // closest to the right of r+1, ptr b
        // closest to the right of l, ptr a
        // elements between thes pointers [a,b) defines the required set
        int a = closest_to_the_right(arr,l);
        int b = closest_to_the_right(arr,r+1);
        cout<<b-a<<" ";
    }
    return 0;
}