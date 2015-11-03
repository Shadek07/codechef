
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
int r,c;
int tel1,tel2;
int mx;
int D;

int dist(int a, int b, int c,int d)
{
    return abs(a-c) + abs(b-d);
}

int doit()
{
    int i,j,k;
    int t1x,t1y,t2x,t2y;
    t1x = tel1/c;
    t1y = tel1%r;
    
    t2x = tel2/c;
    t2y = tel2%r;
    int d = 0;
    forl(i,0,mx)
    {
        forl(j,i,mx)
        {
            int ax,ay,bx,by;
            ax = i/c;
            ay = i%r;
                        
            bx = j/c;
            by = j%r;
            int t = dist(ax,ay, bx,by);
            t = min(t, dist(ax,ay, t1x,t1y) + dist(t2x,t2y, bx, by));
            t = min(t, dist(ax,ay, t2x,t2y) + dist(t1x,t1y, bx, by));
            d = max(d,t);
        }
    }
    return d;
}
class PublicTransit {
    public:
    int minimumLongestDistance(int R, int C) 
    {
        mx = R*C;
        D = 999999;
        int i,j,k;
        r = R;
        c = C;
        forl(i,0,mx)
        {
            forl(j,i,mx)
            {
                tel1 = i;
                tel2 = j;
                D = min(D, doit());
            }
        }

        return D;
    }
};

int main()
{
    int a,b,n,i,j;
    cout << "Hello Sami and Rafi\n" << endl;
    /*while(cin >> a >> b)
    {
        cout << a+b << endl;
    }*/
    PublicTransit muta;
    vector<int> v;
    
    //v.pb(1);
    cout << muta.minimumLongestDistance(4,1) << endl;
    while(cin >> n)
    {
        forl(j,0,n)
        {
            forl(i,0,n)
            {
                cout << i+1;
            }
            cout << endl;
        }
        
    }
    return 0;
}
