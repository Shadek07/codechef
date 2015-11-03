#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<sstream>
#include<stack>
#include<list>
#include <bitset>
#include<iomanip>
#include <fstream>
#include<ctime>
 
using namespace std;
 
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
 
#define MX 1000000
 
#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))
 
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<long long int,int> pii;
typedef vector<pii> vpii;
 
string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MOD 1000000007
#define MAX 300009
#define ADD 1
#define ASSIGN 3
#define MULT 2

int n,q;
ull val[MAX/3];
int query_value;
struct tr{
    ull  sum;
    ull addsum;
    ull assig;
}tree[MAX];
 
void add(ull &a, ull b)
{
    a = (a + b)%MOD;
}

ull mult_mod(ull x, ull y)
{
    return ((x%MOD)*(y%MOD))%MOD;
}
void init(int node, int b, int e)
{
    tree[node].addsum = 0;
    tree[node].assig = 0;
    if(b == e)
    {
        tree[node].sum = val[b];
    }
    else
    {
        init(2*node, b, (b + e)/2);
        init(2*node+1, (b+e)/2 +1, e);
        tree[node].sum = (tree[2*node].sum + tree[2*node + 1].sum)%MOD;
    }
}
 
void propagate(int node, int b, int e)
{
    int mid = (b+e)/2;
    int l = 2*node;
    int r = 2*node +1;
      
    if(tree[node].addsum)
    {
        if(b != e && (tree[l].addsum || tree[l].assig))
        {
            propagate(l, b, mid);
        }
        if(b != e && (tree[r].addsum || tree[r].assig))
        {
            propagate(r, mid+1, e);
        }
        add(tree[l].addsum, tree[node].addsum);
        add(tree[r].addsum, tree[node].addsum);
        add(tree[l].sum, mult_mod(tree[node].addsum,(mid-b+1)));
        add(tree[r].sum, mult_mod(tree[node].addsum, e-mid));
        tree[node].addsum = 0;
    }
    else if(tree[node].assig)
    {
        if(b != e && (tree[l].addsum || tree[l].assig))
        {
            propagate(l, b, mid);
        }
        if(b != e && (tree[r].addsum || tree[r].assig))
        {
            propagate(r, mid+1, e);
        }
        
        tree[l].sum = mult_mod(mid-b+1, tree[node].assig);
        tree[r].sum = mult_mod(e-mid, tree[node].assig);
        tree[node].assig = 0;
    }
    
}
 

void update(int node,int b,int e, int i, int j, ull val, int type)
{
    int mid = (b+e)/2;
    int left = 2*node;
    int right = 2*node+1;
    if(b > j || e < i)
    {
        return;
    }
    if(b == e)
    {
        if(type == 1)
        {
            add(tree[node].sum, val);
            
        }
        else if(type == 3)
        {
            tree[node].sum = val;
        }
        return;
    }
    
    if(b >= i and e <= j)
    {       
        if(type == 1)
        {
            add(tree[node].addsum,val);
            add(tree[node].sum, mult_mod(e-b+1,val));
            tree[node].assig = 0;
        }
        else if(type == 3)
        {
            tree[node].sum = mult_mod(e-b+1, val);
            tree[node].assig = val;
            tree[node].addsum = 0;
        }
        
        
        return;
    }
    
    if(tree[node].addsum || tree[node].assig)
    {
        propagate(node, b, e);
    }
    
    if(!(mid < i || b > j))   
       update(2*node,b,mid, i, j, val, type);
    if(!(e < i || mid+1 > j))
        update(2*node+1, mid+1, e, i,j, val, type);
    
    tree[node].sum = 0;
    add(tree[node].sum, (tree[left].sum + tree[right].sum)%MOD );
    
             
}

ull query(int node, int b, int e, int i, int j)
{
    if(e < i || b > j)
        return 0;
    
    if(b >= i && e <= j)
    {
        return tree[node].sum;
    }
    if(tree[node].addsum || tree[node].assig)
    {
        propagate(node, b, e);
    }
    
    int mid = (b+e)/2;
    
    ull x = query(2*node, b , (b+e)/2, i,j);
    ull y = query(2*node+1, mid+1 , e, i,j);
    add(x,y);
    return x;
}

int main(void)
{
    //freopen("..\\MCHEF_inputGenerator\\input.txt", "r", stdin);
    //freopen("..\\lazy_out.txt", "w", stdout);
    cin >> n >> q;
    int t,x,y;
    ull v;
    int i;
    forl(i,0,n)
    {
        scanf("%llu",&val[i]);
    }
    init(1,0,n-1);
    forl(i,0,q)
    {
        scanf("%d %d %d",&t,&x,&y);
        x--,y--;
        if(t == 4)
        {
            long long int ans = query(1,0,n-1,x,y);
            cout << ans << endl;
        }
        else
        {
            scanf("%llu",&v);
            update(1,0,n-1,x,y,v,t);
        }       
        
    }
    return 0;
}
  
