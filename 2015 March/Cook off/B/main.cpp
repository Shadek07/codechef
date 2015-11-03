
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


int main()
{
    int t;
    int n,k,i,j,j1;
    cin >> t;
    char in[100001];
    int latest_r[100001];
    while(t--)
    {
        cin >> n >> k;
        getchar();
        gets(in);
        int g=0;
        int mint;
        forl(i,0,n)
        {
            if(in[i] == 'G')
                g++;
        }
        
        mint = g;
        
        /*if(in[n-1] =='R')
            latest_r[n-1] = n-1;
        else
            latest_r[n-1] = -1;
        for(i = n-2;i>=0;i--)
        {
            if(in[i] == 'R')
            {
                latest_r[i] = i;
            }
            else
                latest_r[i] = latest_r[i+1];
        }
        
        i = 0;
        int mint=0;
        
        while(i < n && in[i] == 'G')
        {
            i++;
        }
        if(i == n)
        {
            cout << mint << endl;
            continue;
        }
        while(true)
        {
            bool fnd = false;
            int ind = -1;
            mint++;
            for(j = i+1;j<=min(n-1,i+k-1);j++)
            {
                if(in[j] == 'G')
                {
                    if(!fnd)
                    {
                        ind = j;
                    }
                    in[j] = 'R';
                    fnd = true;
                }
                else
                {
                    in[j] = 'G';
                }
            }
            
            if(ind != -1)
            i = ind;
            else
            {
                if(i+k >= n)
                    break;
                if(latest_r[i+k] == -1)
                    break;
                i = latest_r[i+k];
                
            }
            
        }*/
        cout << mint << endl;
    }
    return 0;
}
