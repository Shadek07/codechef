
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
typedef pair< unsigned long long int,int> piu;
string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define ull unsigned long long int 

void doit(ull &a, ull &k, ull &ans, ull &sum, ull &cnt)
{
    if(a < k)
    {
        ans++;
        sum += k-a;
        cnt++;
    }
    else
    {
        unsigned long long int tmp = a/k,t2;
        ans += tmp;
        t2 = tmp*k;
        if(t2 < a)
        {
            ans++;
            tmp++;
            cnt++;
        }
        sum += (tmp*k - a);
        //cnt += tmp;
    }
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int n;
    unsigned long long int k,a,sum,ans,cnt;
    int i,j;
    cin >> t;
    set<piu> st;
    set<pit>::iterator it;
    piu puu;
    while(t--)
    {
        cin >> n >> k;
        st.clear();
        sum = 0;
        cnt = 0;
        ans = 0;
        forl(i,0,n)
        {
            cin >> a;
            if(st.size() > 0)
            {
                for(it = st.begin(); it != st.end();it++)
                {
                    
                }
            }
            else
            {
                if(a < k)
                {
                    ans++;
                    sum = k-a-1;
                    if(sum > 0)
                    {
                        puu = make_pair(sum,i);
                        st.insert(piu); 
                    }
                }
                else
                {
                    unsigned long long int tmp = a/k,t2;
                    ans += tmp;
                    t2 = tmp*k;
                    if(t2 < a)
                    {
                        ans++;
                        tmp++;
                        cnt++;
                    }
                    sum = (tmp*k - a)-1;
                    if(sum > 0)
                    {
                        puu = make_pair(sum,i);
                        st.insert(piu);
                    }
                }
            }
        }
        
        cout << ans << endl;
        
    }
    return 0;
}
