#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include<fstream>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 31625
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];

unsigned long long int res;
unsigned long int ans[1000001];
set<unsigned long long int> st;
multiset<unsigned long long int> st1;
set<unsigned long long int>::iterator it;
void sieve ()
{

	unsigned long int i,j;

	memset (mark, true, sizeof (mark));

	mark [0] = mark [1] = false;

	for (  i = 4; i < N; i += 2 ) mark [i] = false;

	for (  i = 3; i * i <= N; i += 2 ) {
		if ( mark [i] ) {
			for ( j = i * i; j < N; j += 2 * i ) mark [j] = false;
		}
	}

	primeList.clear ();
	primeList.push_back (2);

	for (  i = 3; i < N; i += 2 ) 
	{
		if ( mark [i] ) primeList.push_back (i);
	}

}

void prime_factors(unsigned long n)
{
		  int i = 0;
		  unsigned long long int temp = n;
		  int sz = primeList.size();
		  unsigned long  long int pr;
		  unsigned long long int n1 = n;
		  unsigned long long int base;
		  res = 0;
		  bool ch;
		  base = sqrt(n1);
		  while(i<sz && primeList[i] <= base)
		  {
			  pr = primeList[i];
			  ch = false;
			  while(n1%pr == 0)
			  {
				  n1 /= pr;	
				  st1.insert(pr);
				  ch = true;
			  }
			  base = sqrt(n1);
			  i++;
			  if(ch)
				  st.insert(pr);

		  }
		  if(n1>1)
		  {
			  st.insert(n1);
			  st1.insert(n1);
		  }		  
}

unsigned long long int process(int m){
    st.clear();
    st1.clear();
    prime_factors(m);
    unsigned long long int n = m;
    for(it = st.begin();it != st.end();it++)
    {
        n/= *it;
    }
    for(it = st.begin();it != st.end();it++)
    {
        n *= (*it-1);
    }
    return n;
}
int main(void)
{	
 	 unsigned long  long int n,i,temp,m,a,b,n1;	
 	 sieve();
	 int t;
	 int ca = 1;
	 //unsigned long  int 
	 //ofstream cout("2.txt");
	 cin >> t;
	 while(t--)
	 {
		cin >> m;
		if(m == 1){
            cout << 1 << endl;
            continue;
		}
		if(m == 2){
            cout << 3 << endl;
            continue;
		}
	    unsigned long long int ans=0;
	    a = process(m);
	    ans += a*m;
		for(i=2; i*i <= m;i++){
		    if(m%i == 0){
                ans += m/i;
                if(i*i < m)
                ans += i;
		    } 
		}
		cout << ans+1 << endl;
		
	 }
 	return 0;
}

