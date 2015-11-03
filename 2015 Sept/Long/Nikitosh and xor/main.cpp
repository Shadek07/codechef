
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

vector<int> bitIndex[27];
int bitCount[27][MAX];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n;
    int arr[MAX];
    int i,j,k;
    cin >> n;
    int a;
    ms(bitCount,0);
    
    forl(i,0,n){
        cin >> a;
        forl(j,0,27){
            if((a&(1<<j))){
                bitIndex[j].pb(i+1);
                bitCount[j][i+1] = bitCount[j][i] + 1;
            }
        }
    }
    long int ans = 0;
    forl(i,1,n+1)
    {
        int mxBit = -1;
        int mxIndex = 0;
        int t1,t2;
        t1 = t2 = 0;
        for(j=26;j>=0;j--)
        {
            if(bitCount[j][i])
            {
                mxBit = j;
                break;
            }
        }
        if(mxBit != -1)
        {
            t1 |= (1<<mxBit);
            mxIndex = bitIndex[mxBit][bitCount[mxBit][i]-1];
            if(bitCount[mxBit][i]%2 == 0)
            {
                mxIndex = bitIndex[mxBit][bitCount[mxBit][i]-2];
            }
            for(mxBit=mxBit-1;mxBit>=0;mxBit--)
            {
                if(bitCount[mxBit][mxIndex] && (bitCount[mxBit][mxIndex]&1))
                {
                    t1 |= (1<<mxBit);
                }
            }
        }
        ans = max(ans, t1+t2);
    }
    
    cout << ans << endl;
    
    return 0;
}

