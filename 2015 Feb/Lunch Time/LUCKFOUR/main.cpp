#include <iostream>

using namespace std;

int main()
{
    int t,a;
    cin >> t;
    while(t--)
	{
		cin >> a;
		int cnt=0;
		while(a)
		{
			cnt += (a%10) == 4;
			a/= 10;
		}
		cout << cnt << endl;
	}
    return 0;
}
