#include <bits/stdc++.h>
#include <iomanip>
 
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DECIMAL(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define fi first 
#define se second
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define endl "\n"
#define maxc(v) max_element(all(v))
#define minc(v) min_element(all(v))
#define GCD(m,n) __gcd(m,n)
#define debug cerr<<"bhau"<<endl
#define debugv(x) cerr<<x<<endl
#define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
#define printarr(a,n) for(int i=0;i<n;++i) cout<<a[i]<<" "
#define initarr(a,n,x) for (int i=0;i<n;++i) a[i]=x
 
#define ll long long
#define ld long double 
#define pii pair<int, int> 
#define pll pair<ll, ll>  
#define vi vector<int>  
#define vvi vector<vi > 
#define vii vector<pii >
using namespace std;
struct node1{
    int value;
    int id;
}tree[400000];
typedef struct node1 node1;
int a[100005];
void build(int p,int start,int end)
{
    if(start==end)
    {tree[p].value=a[start];
      tree[p].id=start;}
    else
    {
        int mid=(start+end)/2;
        build(2*p,start,mid);
        build(2*p+1,mid+1,end);
        
        
        tree[p]=(tree[2*p].value<tree[2*p+1].value)?tree[2*p]:tree[2*p+1];
        
        
    }
    
}
/*void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {a[idx]=val;
    tree[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(start<=idx && idx<=mid)
        update(2*node,start,mid,idx,val);
        else
        update(2*node+1,mid+1,end,idx,val);
        
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}*/
node1 query(int node,int start,int end,int l,int r)
{
    node1 tmp;
    if(l>end || r<start)
    {tmp.value=mod;
    tmp.id=-1;
        return tmp;
    }
    if(l<=start && end<=r)
    return tree[node];
    
    int mid=(start+end)/2;
    node1 p1=query(2*node,start,mid,l,r);
    node1 p2=query(2*node+1,mid+1,end,l,r);
     tmp=(p1.value<p2.value)?p1:p2;
     return tmp;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>a[i];
        build(1,1,n);
        int q;
        cin>>q;
        node1 temp;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            temp=query(1,1,n,l,r);
            cout<<temp.id<<endl;
        }
    }
}
