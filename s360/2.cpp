#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
  string input;
  while (getline(cin, input)) {
    if (input.size() > 0) {
      stringstream stringin(input);
      int num;
      vector<int> aa;
      while (stringin >> num) {
        aa.push_back(num);
      }
      int a = aa[0];
      int b = aa[1];
      int k = aa[2];
      int v = aa[3];
      int thing = ((a-1) / v) + 1;
        int ans = 0;
        while(thing > 0){
            ans++;
            if(b >= k-1){
                thing -= k;
                b -= (k-1);
            }else{
                thing -= (b+1);
                b = 0;
            }
        }
        cout << ans << endl;
    }
  }
  return 0;
}