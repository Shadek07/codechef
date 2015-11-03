
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
#define MX 505
#define SZ 505
#define MOD 1000000007
int n;
int q;
char s[MAX];
int nxt[MAX][27];
int tot[MAX][27];
int occ[MAX];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t,i,j,k;
    cin >> t;
    int ind;
    long long int **ncr = new long  long int*[SZ];
    forl(i,0,SZ)
    {
        ncr[i] = new long long int[SZ];
    }
    forl(i,0,SZ)
    {
        forl(j,0,SZ)
        ncr[i][j] = 0;
    }
    ncr[0][0] = 1;
    
    forl(i,1,SZ)
    {
        ncr[i][0] = 1;
        forl(j,1,SZ)
        {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
        }
    }
    while(t--)
    {
        cin >> n >> q;
        getchar();
        cin >> s;
        long long int cnt = 1;
        int now;
        ms(nxt,-1);
        forl(i,0,n)
        {
            now = 0;
            forl(j,i,n)
            {
                char c = s[j];
                ind = 10;
                ind = (c - 'a');
                if(nxt[now][ind] == -1)
                {
                    nxt[now][ind] = cnt++;
                    tot[now][ind] = 1;
                }
                else
                {
                    tot[now][ind]++;
                }
                //cout << " " << tot[now][ind];
                //cout << now << " ->" << nxt[now][ind] << " " << tot[now][ind] << endl;
                now = nxt[now][ind];
            }
            //cout << endl;
        }
        ms(occ,0);
        stack<int> st;
        forl(i,0,26)
        {
            if(nxt[0][i] != -1)
            {
                st.push(0);           
                st.push(i);
                //cout << 0 << " " << nxt[0][i] << endl;
            }
            
        }
        while(!st.empty())
        {
            ind = 5;
            ind = st.top();
            st.pop();
            now = st.top();
            st.pop();
            int value = tot[now][ind];
            occ[value]++;
            int base = nxt[now][ind];
            forl(i,0,26)
            {
                if(nxt[base][i] != -1)
                {
                    st.push(base);
                    st.push(i);
                }
            }
        }
        
        //cout << occ[1] << " " << occ[2] << " " << occ[3] << endl;
        long long int *arr = new long long int [MX];
        if(n < 501)
        {
            forl(i,0,n+1)
            {
                arr[i] = 0;
            }
            forl(i,1,n+1)
            {
                cnt = -4;
                cnt = occ[i];
                forl(j,1,min(i+1,j+1))
                {
                    arr[j] += ((cnt%MOD)*(ncr[i][j]%MOD))%MOD;
                }
            }
        }
        forl(i,0,q)
        {
            //cin >> k;
            scanf("%d",&k);
            if(n > 500)
                cout << 0 << endl;
            else
            {
                if(k > n)
                    cout << 0 << endl;
                else
               cout << arr[k] << endl; 
            }              
        }
    }
    return 0;
}
