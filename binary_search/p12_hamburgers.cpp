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

bool check(int rb,int rs,int rc,int nb,int ns,int nc,int pb,int ps,int pc,int r,int n)
{
    // required no of ingredients to make n sausages
    rb = rb*n;
    rs = rs*n;
    rc = rc*n;
    // no of ingredients of each type to be bought
    nb = max(0LL,rb-nb);
    ns = max(0LL,rs-ns);
    nc = max(0LL,rc-nc);

    return nb*pb + ns*ps + nc*pc <= r;
}

int32_t main()
{ 
    pujith22();
    string s;
    cin>>s;
    int nb,ns,nc,pb,ps,pc;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    int r;
    cin>>r;
    int lo = 0;
    int hi = 1;
    int rb=0,rs=0,rc=0;
    for(char ch: s)
    {
        if(ch=='B')
            rb++;
        else if(ch=='S')
            rs++;
        else
            rc++;
    }
    // hi should always point to non-feasible value
    while(check(rb,rs,rc,nb,ns,nc,pb,ps,pc,r,hi))
        hi = hi*2;
    while(lo+1<hi)
    {
        int mid = lo+ (hi-lo)/2;
        if(check(rb,rs,rc,nb,ns,nc,pb,ps,pc,r,mid))
            lo = mid;
        else
            hi = mid;
    }
    cout<<lo;
    return 0;
}