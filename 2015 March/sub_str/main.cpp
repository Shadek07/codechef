
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

int n,K,q;
int dp[100002][2];
int far[100002];
map<pii,unsigned long long int> mp;

int get_farthest_index(int start)
{
    int low,high,mid;
    low = start;
    high = n;
    int num_0,num_1;
    int ind=0;
    while(low <= high)
    {
        mid = (low+high)/2;
        num_0 = dp[mid][0] - dp[start-1][0];
        num_1 = dp[mid][1] - dp[start-1][1];
        if(num_0 > K or num_1 > K)
        {
            high = mid-1;
        }
        else
        {
            ind = max(ind,mid);
            low = mid+1;
        }
    }
    return ind;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char in[100002];
    unsigned long long int pref[100002];
    int t;
    int k;
    int a,b,i,j;
    cin >> t;
    unsigned long long int lst;
    while(t--)
    {
        scanf("%d %d %d",&n,&K,&q);
        mp.clear();
        getchar();
        gets(in+1);
        dp[0][0] = 0;
        dp[0][1] = 0;
        forl(i,1,n+1)
        {
            a = in[i]-'0';
            dp[i][a] = dp[i-1][a]+1;
            dp[i][1-a] = dp[i-1][1-a]; 
        }
        pref[0] = 0;
        forl(i,1,n+1)
        {
            j = n - i+1;
            if(j <= K)
                far[i] = n;
            else
            {
                far[i] = get_farthest_index(i);
            }
            pref[i] = pref[i-1] + (far[i] - i + 1);
        }
        while(q--)
        {
            scanf("%d %d",&a,&b);
            unsigned long long int ans = 0;
            pii var = make_pair(a,b);
            int a1,b1;
            a1 = dp[b][0] - dp[a-1][0];
            b1 = dp[b][1] - dp[a-1][1];
            if(a1 <= K && b1 <= K)
            {
                lst = b -a +1;
                ans += ((lst)*(lst+1))/2;
                printf("%llu\n",ans);
                continue;
            }
            if(mp[var])
            {
                cout << mp[var] << endl;
                continue;
            }
            
            if(b-a+1 <= K)
            {
                ans = b-a+1;
                printf("%llu\n",(ans*(ans+1))/2);
                continue;
            }
            
            
            int mid = max(a-1,b - 2*K + 1);
            ans += pref[mid] - pref[a-1];
            lst = b-K+1;
            
            forl(i,mid+1,lst)
            {
                if(far[i] > b)
                {
                    j = b;                    
                    unsigned long long int terms = (lst - i);
                    ans += (terms*(b-i+1 + b - lst + 2))/2;
                    break; 
                }                   
                else
                    j = far[i];
                ans += j - i + 1;
            }
            
            lst = b - lst + 1;
            ans += ((lst)*(lst+1))/2;
            printf("%llu\n",ans);
            mp[var] = ans;
        }
    }
    return 0;
}
