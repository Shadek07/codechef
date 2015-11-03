
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
#define isPowerOfTwo(S) (!(S & (S - 1)))
int cnt;
long long int highestPower(long long a)
{
    if(isPowerOfTwo(a))
        return a;
    else if(a%2==0)
    {
        cnt++;
        return highestPower(a/2);
    }
    else
    {
        cnt++;
        return highestPower((a-1)/2);
    }
        
        
}
void p_to_p(long long int a, long long int b)
{
    while(a < b)
    {
        a *=2;
        cnt++;
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    long long int A,B;
    while(t--)
    {
        cin >> A >> B;
        if(A == B)
        {
            cout << 0 << endl;
            continue;
        }
        cnt = 0;
        long long int hp = highestPower(A);
        if(hp > B)
        {
            p_to_p(B,hp);
        }
        else
        {
            p_to_p(hp,B);
        }
        cout << cnt << endl;
    }
    return 0;
}

