#include<bits/stdc++.h>
#define int long long
#define double long double

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

bool check(const vector<double>&arr,int k,double mid)
{
    // checking if we cut pieces of length mid
    // can we make atleast k of them
    int sol = 0;
    for(double i: arr)
        sol += i/mid;
    return sol>=k;
}

int32_t main()
{
    pujith22();
    int n,k;
    cin>>n>>k;
    vector<double>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    double lo = 0;
    double hi = 1e7+1;
    double eps = 1e-8;
    // while(lo+eps<hi)
    // the above code too work
    // but better to use just use iteration
    // when dealing with real numbers in binary_search
    for(int i=0;i<100;i++)
    {
        double mid = lo + (hi-lo)/2.0;
        if(check(arr,k,mid))
            lo = mid;
        else
            hi = mid;
    }
    cout<<setprecision(20)<<lo;
    return 0;
}