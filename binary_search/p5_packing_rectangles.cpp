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


bool check(int w,int h,int n,int x)
{
    //if square of side x can fit all the n wxh rectangles.
    return (x/w)*(x/h) >= n;
}

int32_t main()
{
    pujith22();
    int w,h,n;
    cin>>w>>h>>n;
    int lo = 0;
    int hi = 1;
    // finding lowest upperbound the is power of 2
    // that would fit the answer
    // this done to overcome integer overflows that may
    // occur in check function
    while(!check(w,h,n,hi))
        hi *= 2;
    // invarient is as follows:
    // lo always point to bad answer and hi points to
    // good answer.
    while(lo+1<hi)
    {
        int mid = lo + (hi-lo)/2;
        if(check(w,h,n,mid))
            hi = mid;
        else
            lo = mid;
    }
    cout<<hi;
    return 0;
}