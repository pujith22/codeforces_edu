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

bool check(int time,int x,int y,int n)
{
    // if time is less than to print the first paper
    if(time<min(x,y))
        return false;
    // print a copy using machine that take less time
    time -= min(x,y);
    n -= 1;
    // check if no of copies that can be printed in 
    // remaining time is atleast as required.
    return time/x + time/y >= n;
}

int32_t main()
{
    pujith22();
    int n,x,y;
    cin>>n>>x>>y;
    // as n is atleast 1, 0 seconds is never possible
    // lo always points to not possible answer
    int lo = 0;
    // at max it will take this much time if we use
    // the machine that takes highest time for copy.
    int hi = max(x,y)*n;
    while(lo+1<hi)
    {
        int mid = lo + (hi-lo)/2;
        if(check(mid,x,y,n))
            hi = mid;
        else
            lo = mid;
    }
    cout<<hi;
    return 0;
}