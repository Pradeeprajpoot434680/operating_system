#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string.h>
using namespace std;

bool comp(pair<string,pair<int,pair<int,int>>>a,pair<string,pair<int,pair<int,int>>>b)
{
    return a.second.second.second < b.second.second.second;
}
bool comp2(pair<string,pair<int,pair<int,int>>>a,pair<string,pair<int,pair<int,int>>>b)
{
  return a.second.first < b.second.first;
  
}
int main()
{
   cout<<"Enter the num of processes:";
   int n;
   cin>>n;
    vector<pair<string,pair<int,pair<int,int>>>>arr(n);

   for(int i=0; i<n; i++)
   {
     string process_name = "p" + to_string(i+1);
     arr[i].first=process_name;
     arr[i].second.first = rand() % 10;
     arr[i].second.second.first = rand() % 20;
     arr[i].second.second.second = rand() % 10;
    cout<<"("<< arr[i].first<<","<<arr[i].second.first<<","<<arr[i].second.second.first<<","<<arr[i].second.second.second<<")"<<endl;
   }
   cout<<"\nProirity order\n";
    vector<pair<string,pair<int,pair<int,int>>>> temp = arr;
   sort(arr.begin(),arr.end(),comp);
   sort(temp.begin(),temp.end(),comp2);
   for(int i=0; i<n; i++)
   {
          cout<<"("<< arr[i].first<<","<<arr[i].second.first<<","<<arr[i].second.second.first<<","<<arr[i].second.second.second<<")"<<endl;
   }
   cout<<"Arrival time sorted arr\n";

   for(int i=0; i<n; i++)
   {
          cout<<"("<< temp[i].first<<","<<temp[i].second.first<<","<<temp[i].second.second.first<<","<<temp[i].second.second.second<<")"<<endl;
   }

   int first=0;//for iteration in arr 
   int second=0; // for iteration in temp
   unordered_map<string,bool>visited;
   unordered_map<string,int>ct;
   int gt= temp[0].second.first;
   while(first<n && second<n)
   {
      if(arr[first].second.first > gt)
      {
        string process_name = temp[second].first;
	int at = temp[second].second.first;
	int bt = temp[second].second.second.first;
	if(!visited[process_name])
	{
	  visited[process_name]=1;
	  gt+=bt;
	  ct[process_name] = bt;
	}
	second++;
      }
      else
      {
        string process_name = temp[second].first;
        int at = arr[first].second.first;
        int bt = arr[first].second.second.first;
	if(!visited[process_name])
	{
	  visited[process_name]=1;
	  gt+=bt;
	  ct[process_name] = bt;
	}
	first++;
      }
   }
  cout<<"\n complete time for processes\n";
   for(auto it:ct)
   {
     cout<<it.first <<" -> "<<it.second<<endl;
   }
   return 0;
}
