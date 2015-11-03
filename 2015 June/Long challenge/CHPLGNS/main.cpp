

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
vector<int> v,v1;

int doit(int y, int n)
{
     int low, mid, high;
     low = 0;
     high = n-1;
     int ans=-1;
     while(low <= high)
     {
         mid = (low+high)/2;
         //cout << v1[mid] << endl;
         if(v1[mid] >= y)
         {
             high = mid-1;
         }
         else if(v1[mid] < y)
         {
             low = mid+1;
             ans = max(ans,mid);
         }
     }
     if(ans == -1)
        return 0;
     return ans+1;
     
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int n;
    cin >> t;
    int i,j,k;
    int m,a,b;
    while(t--)
    {
        cin >> n;
        v.clear();
        v1.clear();
        forl(i,0,n)
        {
            cin >> m;
            int maxy = -1000000009;
            forl(j,0,m)
            {
                cin >> a >> b;
                if(a > maxy)
                {
                    maxy = a;
                }
            }
            v.push_back(maxy);
            v1.pb(maxy);
        }
        sort(v1.begin(),v1.end());
        forl(i,0,n)
        {
            int ans = doit(v[i],n);
            if(!i)
                cout << ans;
            else
            cout << " " << ans;
        }
        cout << endl;
        
    }
    return 0;
}
