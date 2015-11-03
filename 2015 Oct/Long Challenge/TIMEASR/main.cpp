
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

double findAngle(double h, double m)
{
    double hour_angle = 0.5 * (h*60 + m);
    double minute_angle = 6*m;
    double angle = abs(hour_angle - minute_angle);
    angle = min(360.0-angle, angle);
    return angle;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    double angle;
    scanf("%d",&t);
    int h,m;
    int a,b;
    while(t--){
        cin >> angle;
        h = m =0;
        if(angle == 0){
            printf("%02d:%02d\n",h,m);
        }
        else if(angle == 90){
            h = 3;
            m = 0;
            printf("%02d:%02d\n",h,m);
            h = 9;
            m = 0;
            printf("%02d:%02d\n",h,m);
        }else if(angle == 180){
            h = 6;
            m = 0;
            printf("%02d:%02d\n",h,m);
        }
        else{
            
            forl(h,0,12){
                forl(m,0,60){
                    a = m / 5;
                    b = m%5;
                    double c = findAngle(h*1.0,m*1.0);
                    if(fabs(c-angle) < 0.00833){
                        printf("%02d:%02d\n",h,m);
                    }
                }
            }
        }
    }
    return 0;
}
