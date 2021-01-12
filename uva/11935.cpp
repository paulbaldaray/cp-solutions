#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
double d0, d1, fc, req_fuel, curr_fuel;
int leak = 0;
inline void reset() { d0 = d1 = fc = req_fuel = leak = curr_fuel = 0; }
inline void drive()
{
  int d = d1-d0;
  curr_fuel -= d / 100.0 * fc + leak * d;
  req_fuel = min(req_fuel, curr_fuel);
  d0 = d1;
}
int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);
  string cmd;
  reset();
  while(cin >> d1 >> cmd)
  {
    drive();
    if(cmd == "Fuel")
    {
      cin >> cmd >> fc;
      if(fc==0) break;
    }
    else if(cmd == "Leak") 
      ++leak;
    else if(cmd == "Mechanic")
      leak = 0;
    else if(cmd == "Gas")
    {
      cin >> cmd;
      curr_fuel = 0;
    }
    else if(cmd == "Goal")
    {
      cout << fixed << showpoint << setprecision(3) << -req_fuel << "\n";
      reset(); continue;
    }
  }
}
