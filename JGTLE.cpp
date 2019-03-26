#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    int cs = 1;
    ll a, b, c;
    
    cin >> T;
    
    while (T --)
    {
        cin >> a >> b >> c;
        
        ll result = a * (b * (b + 1) / 2) * (c * (c + 1) / 2);
        
        cout << "Case " << cs++ << ": " << result << endl;
    }
    
    return 0;
}