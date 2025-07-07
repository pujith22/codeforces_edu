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

bool check(long double x,long double c)
{
    return x*x + sqrt(x) >= c;
}


int32_t main()
{
    pujith22();
    long double c;
    cin>>c;
    long double lo = 0.0;
    long double hi = 1e6;
    for(int i=0;i<100;i++)
    {
        long double mid = lo + (hi-lo)/2.0;
        if(check(mid,c))
            hi = mid;
        else
            lo = mid;
    }
    cout<<setprecision(20)<<hi;
    return 0;
}