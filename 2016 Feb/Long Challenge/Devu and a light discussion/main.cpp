#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int t;
    string s = "12/23 34/10 110/125";
    istringstream is(s);
    int a,b;
    char c;
    while(is >> a >> c >> b){
        cout << a << " " << b << endl;
    }
    cin >> t;
    int n;
    int i;
    while(t--){
        cin >> n;
        if(n < 7){
            cout << -1 << endl;
            continue;
        }else{
            cout << n << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << " " << 3 << endl;
            cout << 2 << " " << 4 << endl;
            cout << 3 << " " << 4 << endl;
            cout << 4 << " " << 5 << endl;
            cout << 2 << " " << 6 << endl;
            cout << 3 << " " << 7 << endl;
            for(i = 7+1;i<=n;i++){
                cout << 2 << " " << i << endl;
            }
            cout << 1 << endl;
        }
        
    }
    return 0;
}
