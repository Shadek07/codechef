#include <iostream>

using namespace std;

int main()
{
    int j,s,m;
    while(cin >> j >> s >> m){
        m = m-j;
        int cnt = m/s;
        if(cnt&1){
            cout << "Unlucky Chef\n";
        }else{
            cout << "Lucky Chef\n";
        }
    }
    return 0;
}
