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

bool check(int time, int m,const vector<int>& t,const vector<int>& z,const vector<int>&y, vector<int>& arr)
{
    if(time<0)
        return false;
    if(m==0)
        return true;
    int total_balloons = 0;
    for(int i=0;i<t.size();i++)
    {
        int ptime = time;
        int baloons = 0;
        while(ptime>=t[i])
        {
            int bal_in_this_round = min(z[i],ptime/t[i]);
            baloons += bal_in_this_round;
            ptime -= bal_in_this_round*t[i];
            if(bal_in_this_round==z[i])
                ptime -= y[i];
        }
        arr[i] = baloons;
        total_balloons += baloons;
    }
    return total_balloons>=m;
}

int32_t main()
{
    pujith22();
    int m,n;
    cin>>m>>n;
    vector<int>t(n);
    vector<int>z(n);
    vector<int>y(n);
    for(int i=0;i<n;i++)
        cin>>t[i]>>z[i]>>y[i];
    int lo = -1;
    int hi = 1;
    vector<int>arr(n,0);
    while(!check(hi,m,t,z,y,arr))
        hi = hi*2;
    while(lo+1<hi)
    {
        int mid = lo + (hi-lo)/2;
        if(check(mid,m,t,z,y,arr))
            hi = mid;
        else
            lo = mid;
    }
    // recomputing the ballons at this optimal time
    // pointed by variable hi.
    check(hi,m,t,z,y,arr);
    cout<<hi<<"\n";
    int count = 0;
    /*
    Because of this I got many errors, we have to make sure
    that total baloons shouldn't exceed m. It may be the case
    that the optimal time achieved some guy might blew some extra
    baloons i.e at hi, total baloons over shot k and hi-1 undershot
    k, hence make sure that the total printed shouldn't exceed k.
    */
    for(int i: arr)
    {
        if(count+i<=m)
        {
            cout<<i<<" ";
        }
        else
        {
            cout<<max(0LL,m-count)<<" ";
        }
        count += i;
    }
    return 0;
}