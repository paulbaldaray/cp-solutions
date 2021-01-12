#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef vector<string> vs;
vs newspapers;

vs recurse(int index, int size) {
  vs news_list;
  if(size == 1)
    return vs{newspapers[index] + "\n"};
  for(int i = index+1; i <= newspapers.size() - size + 1; ++i)
    for(string& s : recurse(i, size-1))
      news_list.push_back(newspapers[index] + ", " + s);
  return news_list;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int TC;
  cin >> TC;
  string temp;
  getline(cin, temp); getline(cin, temp);
  while(TC--) {
    vector<int> sizes;
    string query, nwspp;
    getline(cin, query);
    stringstream query_stream(query);
    int a, b; 

    while(getline(cin, nwspp) && nwspp != "")
      newspapers.push_back(nwspp); 

    if(query[0] == '*')
      for(int i = 0; i < newspapers.size(); ++i)
        sizes.push_back(i+1);
    else if(query_stream >> a >> b)
      for(; a <= b; ++a)
        sizes.push_back(a);
    else
      sizes.push_back(a);
 
    for(int size : sizes)
    {
      cout << "Size " << size << "\n";
      for(int index = 0; index < newspapers.size(); ++index)
        for(string& news : recurse(index,size))
          cout << news;
      cout << "\n";
    }
    newspapers.clear();
    if(TC) cout << "\n";
  }
  return 0;
}
