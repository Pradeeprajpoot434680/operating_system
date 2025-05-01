#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <cstdlib>    // For rand() and srand()
#include <ctime>
#include<string.h>
using namespace std;

int main()
{
   srand(time(NULL));
  int n;
  cout<<"Enter the number of processes:";
  cin>>n;
  vector<pair<string,pair<int,int>>>arr(n);
  float sum=0;
  for(int i=0; i<n; i++)
  {
    string process_name = "p" + to_string(i+1);
    arr[i].first = process_name;
    arr[i].second.first = rand() % 10;
    arr[i].second.second = rand() % 20;
    sum+=((float) arr[i].second.first/ arr[i].second.second);

     cout << "(" << arr[i].first << ", "
             << arr[i].second.first << ", "
             << arr[i].second.second<< ")" << endl;
   }
 
  if(sum>1)
  {
    cout<<"According to this data Earlier deadline first algorithm cann't be applied\n";
    retrun 1;
  }


 return 0;

  
}
