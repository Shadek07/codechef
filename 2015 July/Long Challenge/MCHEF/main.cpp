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
 
#define MAX 300009
  
bool lazy[MAX];
int lazy_val[MAX];
int n,K,M;
long long int rating[MAX/3];
int query_value;
struct tr{
    bool single;
    int value;
}tree[MAX];
 
long long int C[MAX/3][505];
long long int Wi[MAX/3];
long long int Vi[MAX/3];
int mncost[MAX/3];

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].value = 501;
        tree[node].single = true;
    }
    else
    {
        init(2*node, b, (b + e)/2);
        init(2*node+1, (b+e)/2 +1, e);
        tree[node].single = true;
        tree[node].value = 501;
    }
}
 
void propagate(int node, int b, int e, int val)
{
    int mid = (b+e)/2;
    int l = 2*node;
    int r = 2*node +1;
    
    lazy[node] = false;    
    if(tree[l].single && tree[l].value > val)
    {
        tree[l].value = val;
        lazy_val[l] = val;     
    }
    if(tree[r].single && tree[r].value > val)
    {
        tree[r].value = val;
        lazy_val[r] = val;
        
    }
    lazy[l] = 1;
    lazy[r] = 1;
    
}
 
void parent_calculate(int node,int left, int right)
{
    if(tree[left].single && tree[right].single)
    {
        if(tree[left].value == tree[right].value)
        {
            tree[node].single = true;
            tree[node].value = tree[left].value;
        }
        else
            tree[node].single = false;
    }
    else
    {
        tree[node].single = false;
        //lazy[node] = false;
    }
    
    //lazy[node] = false;
}
void update(int node,int b,int e, int i, int j, int val)
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
        if(tree[node].value > val)
        {
            tree[node].value = val;
            tree[node].single = true;
        }
        return;
    }
    
    if(b >= i and e <= j)
    {
        if(tree[node].single)
        {
            if(tree[node].value > val)
            {
                tree[node].value = val;
                lazy_val[node] = val;
                lazy[node] = true;
            }
            return;
        }
        update(2*node,b,mid, i, j, val);
        update(2*node+1, mid+1, e, i,j, val);
        parent_calculate(node,left, right);
    }
    else
    {
        if(lazy[node])
        {
            propagate(node, b, e, lazy_val[node]);
        }
        update(2*node,b,mid, i, j, val);
        update(2*node+1, mid+1, e, i,j, val);
        parent_calculate(node, left,right);       
    }       
}

void query(int node, int b, int e, int index)
{
    if(e < index || b > index)
        return;
    if(lazy[node])
    {
        propagate(node, b, e, lazy_val[node]);
    }
    
    if(index >= b && index <= e)
    {
        if(tree[node].single)
        {
            query_value = tree[node].value;
            return;
        }
    }
    int mid = (b+e)/2;
    //&& (index >= b && index <= mid)
    if(query_value == -1 )
        query(2*node, b , (b+e)/2, index);
        //&& (index > mid  && index <= e)
    if(query_value == -1 )
        query(2*node+1, mid+1 , e, index);
}

void all_query(int node, int b, int e)
{
    if(b == e)
    {
        mncost[b] = tree[node].value;
        return;
    }
    int i,j;
    if(lazy[node])
    {
        propagate(node, b, e, lazy_val[node]);
    }
    if(tree[node].single)
    {
        forl(i,b,e+1)
        {
            mncost[i] = tree[node].value;
        }
        return;
    }
    int mid = (b+e)/2;
    all_query(2*node, b , (b+e)/2);
    all_query(2*node+1, mid+1 , e);
}

int main(void)
{
    //freopen("..\\MCHEF_inputGenerator\\input.txt", "r", stdin);
    //freopen("..\\lazy_out.txt", "w", stdout);
    int t,i,j,k,l,r,c,w;
    int n1;
    //cin >> t;
    scanf("%d",&t);
    vector<pii> vpii;
    pii pii1;
    long long int a = -1e9*1e5;
    //cout << a << endl;
    //int mncost[MAX/2];
    while(t--)
    {
        //cin >> n >> K >> M;
        scanf("%d %d %d",&n,&K,&M);
        long long int cost = 0;
        //cout << n << " ";
        n1 = n;
        /*forl(i,0,n){
            mncost[i] = 501;
        }*/
        vpii.clear();
        forl(i,0,n)
        {
            cin >> rating[i];
            cost += rating[i];
            pii1 = make_pair(rating[i],i);
            vpii.push_back(pii1);
        }
        sort(vpii.begin(),vpii.end());
        init(1,0,n-1);
        ms(lazy, false);
        forl(i,0,M)
        {
            //cin >> l >> r >> c;
            scanf("%d %d %d",&l,&r,&c);
            l--,r--;
            /*forl(j,l,r+1){
                if(mncost[j] > c)
                    mncost[j] = c;
            }*/
            update(1,0,n-1, l, r, c);                         
            /*while(true)
            {
                int a;
                cout << "query: ";
                cin >> a;
                if(a == 0)
                    break;
                query_value = -1;
                query(1,0,n-1,a-1);
                cout << query_value << endl; 
            } */   
        }

        int N=0;
        
        //all_query(1, 0, n-1);
        //cout << n1 << " ";
        forl(i,0,n1)
        {
            pii1 = vpii[i];
            if(pii1.first < 0)
            {
                query_value = -1;
                query(1,0,n-1,pii1.second);
                int cst = query_value;
                //int cst = mncost[pii1.second];
                Wi[i+1] = cst;
                Vi[i+1] = -pii1.first; 
                N++;             
            }
            else
            {
                if(i != 0)
                    N = i+1;
                else
                    N = 0;               
                break;
            }
                
        }
        
        int MW = K;
        for (i=0;i<=N ;i++)
			C[i][0] = 0;
		for (w=0;w<=MW;w++) 
			C[0][w] = 0;
 
		long long int one,two;
 
		for(i=1;i<=N;i++)
        for (w=1;w<=MW;w++) 
        {
            if(Wi[i] > w)
            {
                C[i][w] = C[i-1][w];					
            }
            else
            {
                one = C[i-1][w];
                two = C[i-1][w-Wi[i]]+Vi[i];
                if(one > two)
                {
                    C[i][w] = one;                   
                }
                else
                {
                    C[i][w] = two;                    
                }
            }
        }
        if(N != 0)
            cost += C[N][MW];
        //if(N == 0)
        //cout << cost << " " << N << endl;
        //else
            cout << cost << endl;
        
    }
    return 0;
}
  
