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
/* Here the idea is following, if we sort the groups based on no of people in descending
order, if we have to make p such councils. we can always keep on filling the grid of 
kxp i.e p no of councils of k people each from distinct groups picking each from available
group trimming it size if its size exceeds p, put the diagram on paper and you can easily prove. Basically you choose a group
at some ith council, the tail won't touch its head in the next row if at all it spills to 
next row since we we assumed we haved sorted the list according to its cardinality*/

bool check(int p, vector<int>&arr, int k)
{
    int maxgirdsizeoflengthp = 0;
    for(int i: arr)
        maxgirdsizeoflengthp += min(i,p);
    return maxgirdsizeoflengthp >= k*p;
}

int32_t main()
{ 
    pujith22();
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int lo = 0;
    int hi = 1e12;
    while(lo+1<hi)
    {
        int mid = lo + (hi-lo)/2;
        if(check(mid,arr,k))
            lo = mid;
        else
            hi = mid;
    }
    cout<<lo;
    return 0;
}