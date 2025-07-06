/*

██████████████                   ██████████████

▌║█║▌│║▌│║▌║▌█║                 ▌│║▌║▌│║║▌█║▌║█
▌║█║▌│║▌│║▌║▌█║ Youssouf Faisal ▌│║▌║▌│║║▌█║▌║█
▌║█║▌│║▌│║▌║▌█║                 ▌│║▌║▌│║║▌█║▌║█

██████████████                   ██████████████

*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
#define INF 2000000000000000000 // 2e18
#define ndl cout << "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define sor(s) sort(s.begin(), s.end());

void FAST()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}


int main()
{
  FAST();
  int t; cin >> t;
  while(t--){
    string p, s;
    cin >> p >> s;
    int itp = 0;
    int its = 0;
    bool ok = true;
    for(int i = 0; i < s.size(); i++){
      if(p[itp] == s[its]){
        if(p[itp] == s[its + 1]) {
          its++;
        }
        itp++;
        its++;
      } else {
        ok = false;
        break;
      }
    }
    (ok == true) ? yes : no;
  }
}





// out  __builtin_popcount(3);
// Search
// __builtin_ fucntions
// bitset < 32 >
