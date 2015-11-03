
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
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005

bool path[201][201];


bool condition_satisfied(int prev ,int cur, int a)
{
    if(cur <= a && cur >= prev)
        return true;
    return false;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    int m,p,n;
    int i,j,k;
    int a,b;
    set<int> link[201];
    //set<int> st;
    //st.insert(1);
    //st.insert(2);
    //st.insert(5);
    //cout << *(st.lower_bound(2)) << endl;
    set<int>::iterator it;
    int arr[200002];
    int suf[200002];
    while(t--)
    {
        cin >> m >> p >> n;
        ms(path,false);
        forl(i,0,p)
        {
            cin >> a >> b;
            path[a][b] = true;
            path[b][a] = true;
        }
        forl(k,1,m+1)
        {
            forl(i,1,m+1)
            {
                forl(j,1,m+1)
                {
                    if(i != j && k != i && k != j)
                    path[i][j] |= (path[i][k] && path[k][j]);
                }
            }
        }
        forl(i,1,m+1)
        {
            forl(j,1,m+1)
            {
                if(path[i][j])
                    link[i].insert(j);
            }
        }
        
        forl(i,0,n)
        {
            cin >> arr[i];
        }
        suf[n] = m;
        for(i=n-1;i>=0;i--)
        {
            a = arr[i];
            //cout << link[a].size() << endl;
            
            if(link[a].size() == 0)
                b = a;
            else
                b = max(*link[a].rbegin(), a);
            suf[i] = min(b, suf[i+1]);
        }
        int prev = 1;
        int cur;
        bool ok=true;
        int ans=0;
        forl(i,0,n)
        {
            bool ok1 = condition_satisfied(prev, arr[i], suf[i+1]);
            cur = arr[i];
            if(ok1)
            {
                prev = arr[i];
            }
            else
            {
                it = link[cur].lower_bound(prev);
                if(it == link[cur].end())
                {
                    ok = false;
                    break;
                }
                else
                {
                    b = *it;
                    a = suf[i+1];
                    if(b > a)
                    {
                        ok = false;
                        break;
                    }
                    else
                    {
                        prev = b;
                        ans++;
                    }
                }
            }
        }
        if(ok==false)
            cout << -1 << endl;
        else
            cout << ans << endl;
        forl(i,1,m+1)
            link[i].clear();
    }
    return 0;
}
