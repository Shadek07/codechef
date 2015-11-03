
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
typedef pair<double,double> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005

double sqr(double a)
{
    return a*a;
}
/**
in counter-clockwise order
*/
double polygon_area(vpii vp)
{
    int n = vp.size();
    double a = 0.0,b=0.0;
    int i;
    forl(i,0,n-1)
    {
        a += vp[i].first*vp[i+1].second;
        a -= vp[i].second*vp[i+1].first;
    }
    if(a < 0)
        a = -a;
    //a = a/2.0;
    return a;
}

double find_x(double x1, double y1, double x2, double y2, double y)
{
    /*double x1 = vp1[0].first;
    double y1 = vp1[0].second;
    double x2 = vp1[1].first;
    double y2 = vp1[1].second;*/
    double x;
    x =  y1*(x2-x1) + x1*(y1-y2) + y*(x1-x2);
    x /= (y1-y2);
    return x;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    double T1,T2,t1,t2;
    cin >> t;
    double a,b;
    vpii vp1;
    while(t--)
    {
        cin >> T1 >> T2 >> t1 >> t2;
        vp1.clear();
        double total = T1*T2;
        //cout << total << endl;
        double meet;
        if(t1 == 0 && t2 == 0)
        {
            printf("%.9lf\n",0.0);
            continue;
        }
        else if(t2 == 0 || t1 == 0)
        {
            if(t1 == 0)
            {
                swap(t1,t2);
                swap(T1,T2);
            }
            double second_y;
            vp1.pb(make_pair(0,0));
            if(T2 >= T1)
            {
                vp1.pb(make_pair(T1,T1));
                second_y = T1;
            }
            else
            {
                vp1.pb(make_pair(T2,T2));
                second_y = T2;
            }
            if(t1 >= T2) //whole cover
            {
                //vp1.pb(make_pair(T1,T2));
                if(T1 < T2)
                {
                    vp1.pb(make_pair(T1,T2));
                }
                    
                vp1.pb(make_pair(0,T2));
            }
            else
            {
                if(T1+t1 <= T2)
                {
                    //vp1.pb(make_pair(find_x(0,t1,T1,T1+t1,second_y),second_y));
                    vp1.pb(make_pair(T1,T1+t1));
                    vp1.pb(make_pair(0,t1));
                }
                else
                {
                    vp1.pb(make_pair(T1,T2));
                    vp1.pb(make_pair(T2-t1,T2));
                    vp1.pb(make_pair(0,t1));
                }
            }
            
            vp1.pb(make_pair(0,0));
            meet = polygon_area(vp1);
            printf("%.9lf\n",meet/(total*2.0));
            continue;
        }
        
        vp1.pb(make_pair(0,0));
        if(t2 >= T1)
        {
            vp1.pb(make_pair(T1,0));
        }
        else
        {
            vp1.pb(make_pair(t2,0));
            vp1.pb(make_pair(T1,T1-t2));
        }
        
        if(t1 >= T2)
        {
             vp1.pb(make_pair(T1,T2));
             vp1.pb(make_pair(0,T2));           
        }
        else
        {
            if(T1+t1 <= T2)
            {
                 vp1.pb(make_pair(T1,T1+t1));
                 vp1.pb(make_pair(0,t1));
            }
            else
            {
                vp1.pb(make_pair(T1,T2));
                vp1.pb(make_pair(T2-t1,T2));
                vp1.pb(make_pair(0,t1));
            }
        }
        
        vp1.pb(make_pair(0,0));
        
        meet = polygon_area(vp1);
        printf("%.9lf\n",meet/(total*2.0));
        
        
    }
    return 0;
}
