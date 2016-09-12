
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

#define MAX 1005
int score[MAX];

//array reference
void decr(int (&arr)[6], int mn, int ind){
    int i;
    forl(i,0,ind){
        arr[i]--;
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int n;
    int i,j,k;
    cin >> t;
    int c;
    while(t--){
        cin >> n;
        forl(i,0,n){
            cin >> c;
            int cnt[6];
            ms(cnt,0);
            forl(j,0,c){
                cin >> k;
                cnt[k-1]++;
            }
            int sc = c;
            while(true){
                sort(cnt,cnt+6,greater<int>());
                if(cnt[5] > 0){
                    sc += 4;
                    decr(cnt,cnt[5],6);
                }else if(cnt[4] > 0){
                    sc += 2;
                    decr(cnt,cnt[4],5);
                }else if(cnt[3] >0){
                    sc += 1;
                    decr(cnt,cnt[3],4);
                }else{
                    break;
                }
            }
            score[i] = sc;
        }

        int mx=0;
        int mn=999999;
        int ind=-1;
        vector<int> v;
        forl(i,0,n){
            v.pb(score[i]);
        }
        sort(all(v),greater<int>());
        if(n==1){
            cout << "chef\n";
            continue;
        }
        if(v[0] == v[1]){
            cout << "tie\n";
            continue;
        }
        forl(i,0,n){
            if(mx< score[i]){
                mx = score[i];
                ind = i;
            }
        }

        if(ind==0){
            cout << "chef\n";
        }else{
            cout << ind+1 << endl;
        }

    }
    return 0;
}
