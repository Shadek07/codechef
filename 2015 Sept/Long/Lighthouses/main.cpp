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
map< pii, int> pointIndex;
int ans;
vector<string> lightHouses;

vpii allX(vpii vp, int x, bool left)
{
    int sz = vp.size();
    int i;
    vpii vp1;
    forl(i,0,sz)
    {
        if(left)
        {
            if(vp[i].first < x)
            {
                vp1.pb(vp[i]);
            }
        }
        else
        {
            if(vp[i].first > x)
            {
                vp1.pb(vp[i]);
            }
        }
    }
    return vp1;    
}
vpii allY(vpii vp, int y, bool bottom)
{
    int sz = vp.size();
    int i;
    vpii vp1;
    forl(i,0,sz)
    {
        if(bottom)
        {
            if(vp[i].second < y)
            {
                vp1.pb(vp[i]);
            }
        }
        else
        {
            if(vp[i].second > y)
            {
                vp1.pb(vp[i]);
            }
        }
    }
    return vp1;    
}
void maxCheck(int newSZ, int &mxSZ, vpii &vpiiNext, vpii vpiiNew, int ind, int &index)
{
    if(newSZ > mxSZ)
    {
        mxSZ = newSZ;
        index = ind;
        vpiiNext = vpiiNew;
    }
}
void doit(vpii vpii1, vector<string> vs)
{
    int i,sz,mxSZ;
    sz = vpii1.size();
    ostringstream convert;
    forl(i,0,sz)
    {
        //cout << "--" << vpii1[i].first << " " << vpii1[i].second << endl;
    }
    //cout << endl;
    //cout << vpii1.size() << endl;
    if(vpii1.size() == 0)
    {
        if(vs.size() < ans)
        {
            ans = vs.size();
            lightHouses = vs;
        }
        return;
    }
    /*if(vpii1.size() == 1){
        convert << pointIndex[make_pair(vpii1[0].first,vpii1[0].second)];
        vs.pb(convert.str() + " " + "SE");
        if(vs.size() < ans)
        {
            ans = vs.size();
            lightHouses = vs;
        }
        return;
    }*/
    
    pii p1,p2;
    int xLeft,xRight,yTop,yBottom,yLeft1,yLeft2,yRight1, yRight2,xTop1,xTop2,xBottom1,xBottom2;
    
    vpii vpiiNew, vpiiNext;
    vector<string> vsNew;
    
    sz = vpii1.size();
    //left
    xLeft = xRight = vpii1[0].first;
    yLeft1 = yLeft2 = vpii1[0].second;
    yRight1 = yRight2 = vpii1[0].second;
    
    yTop = yBottom = vpii1[0].second;
    xBottom1 = xBottom2 = vpii1[0].first;
    xTop1 = xTop2 = vpii1[0].first;
    forl(i,1,sz)
    {
        if(vpii1[i].first < xLeft)
        {
            xLeft = vpii1[i].first;
            yLeft1 = yLeft2 = vpii1[i].second;
        }
        if(vpii1[i].first > xRight)
        {
            xRight = vpii1[i].first;
            yRight1 = yRight2 = vpii1[i].second;
        }
        if(vpii1[i].second < yBottom)
        {
            yBottom = vpii1[i].second;
            xBottom1 = xBottom2 = vpii1[i].first;
        }
        if(vpii1[i].second > yTop)
        {
            yTop = vpii1[i].second;
            xTop1 = xTop2 = vpii1[i].first;
        }
    }
    forl(i,0,sz)
    {
        if(vpii1[i].first == xLeft)
        {
            yLeft2 = max(yLeft2, vpii1[i].second);
            yLeft1 = min(yLeft1,vpii1[i].second);
        }
        if(vpii1[i].first == xRight)
        {
            yRight2 = max(yRight2, vpii1[i].second);
            yRight1 = min(yRight1, vpii1[i].second);
        }
        if(vpii1[i].second == yBottom)
        {
            xBottom2 = max(xBottom2, vpii1[i].first);
            xBottom1 = min(xBottom1, vpii1[i].first);
        }
    }
    
    mxSZ = 0;
    int index;
    int pointX[16]={xLeft,xLeft,xRight,xRight,xTop1,xTop2,xBottom1,xBottom2};
    int pointY[16]={yLeft1,yLeft2,yRight1,yRight2,yTop,yTop,yBottom,yBottom};
    string dir[16] = {"NE","SE","NE","SE","NW","SW","NW","SW","SE","SW","SE","SW","NE","NW","NE","NW"};
    
    //left
    vpiiNew = allY(vpii1, yLeft1,true);
    
    maxCheck(sz - vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,0,index);
    //doit(vpiiNew, vsNew);   
    vpiiNew = allY(vpii1, yLeft1,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,1,index);
    //doit(vpiiNew, vsNew);    
    vpiiNew = allY(vpii1, yLeft2,true);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,2,index);
    //doit(vpiiNew, vsNew); 
    vpiiNew = allY(vpii1, yLeft2,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,3,index);
    //doit(vpiiNew, vsNew);
    
    //right
    vpiiNew = allY(vpii1, yRight1,true);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,4,index);
    //doit(vpiiNew, vsNew);   
    vpiiNew = allY(vpii1, yRight1,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,5,index);
    //doit(vpiiNew, vsNew);    
    vpiiNew = allY(vpii1, yRight2,true);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,6,index);
    //doit(vpiiNew, vsNew); 
    vpiiNew = allY(vpii1, yRight2,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,7,index);
    //doit(vpiiNew, vsNew);
    
    //top
    vpiiNew = allX(vpii1, xTop1,true);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,8,index);
    //doit(vpiiNew, vsNew);   
    vpiiNew = allX(vpii1, xTop1,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,9,index);
    //doit(vpiiNew, vsNew);    
    vpiiNew = allX(vpii1, xTop2,true);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,10,index);
    //doit(vpiiNew, vsNew); 
    vpiiNew = allX(vpii1, xTop2,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,11,index);
    //doit(vpiiNew, vsNew);
    
    //bottom
    vpiiNew = allX(vpii1, xBottom1,true);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,12,index);
    //doit(vpiiNew, vsNew);   
    vpiiNew = allX(vpii1, xBottom1,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,13,index);
    //doit(vpiiNew, vsNew);    
    vpiiNew = allX(vpii1, xBottom2,true);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,14,index);
    //doit(vpiiNew, vsNew); 
    vpiiNew = allX(vpii1, xBottom2,false);
    
    maxCheck(sz-vpiiNew.size(), mxSZ, vpiiNext,vpiiNew,15,index);
    //doit(vpiiNew, vsNew);
    
    vsNew = vs;
    convert << pointIndex[make_pair(pointX[index/2],pointY[index/2])];
    vsNew.pb(convert.str() + " " + dir[index]);
    doit(vpiiNext, vsNew);
    
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int n;
    cin >> t;
    int i,j,k,a,b;
    vpii vpii1;
    
    while(t--)
    {
        cin >> n;
        vpii1.clear();
        pointIndex.clear();
        forl(i,0,n)
        {
            cin >> a >> b;
            vpii1.pb(make_pair(a,b));
            pointIndex[make_pair(a,b)] = i+1;
        }
        ans = 1000000;
        lightHouses.clear();
        vector<string> vs;
        doit(vpii1, vs);
        cout << ans << endl;
        forl(i,0,ans)
        {
            cout << lightHouses[i] << endl;
        }
        
    }
    return 0;
}
