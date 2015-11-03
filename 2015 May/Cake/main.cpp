
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    
    cin >> t;
    getchar();
    char in[MAX];
    int cnt[26];
    int i,j,k;
    
    while(t--)
    {
        gets(in);
        int n = strlen(in);
        ms(cnt,0);
        forl(i,0,n)
        {
            cnt[in[i]-'a']++;
        }
        bool ok=true;
        string ans = "-";
        int len = 0;
        int mx;
        while(true)
        {
            mx = 0;
            int ind=-1;
            bool found=false;
            forl(i,0,26)
            {
                if(cnt[i] > mx and ans[len] != ('a' + i))
                {
                    mx = cnt[i];
                    ind = i;
                }
                if(cnt[i] > 0)
                {
                    found = true;
                }
            }
            if(!found)
                break;
            
            if(mx==0)
            {
                ok=false;
                break;
            }
            ans += ('a' + ind);
            cnt[ind]--;
            len++;
        }
        if(!ok)
            cout << -1 << endl;
        else
        {
            string s = ans.substr(1);
            cout << s << endl;
        }
            
    }
    return 0;
}
