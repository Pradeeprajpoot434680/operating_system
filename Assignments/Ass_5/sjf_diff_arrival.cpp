#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include <unordered_map>
using namespace std;

bool comp(pair<string, pair<int, int>>a,pair<string, pair<int, int>>b)
{
    return a.second.second < b.second.second;
}
int main()
{
   cout<<"Enter the num of processes:";
   int n;
   cin>>n;
    vector<pair<string, pair<int, int>>> arr(n);
      
   for(int i=0; i<n; i++)
   {
     string process_name = "p" + to_string(i+1);
     arr[i].first=process_name;
     arr[i].second.first = rand() % 10;
     arr[i].second.second = rand() % 20;
     //cout<<"("<< arr[i].first<<","<<arr[i].second.first<<","<<arr[i].second.second<<")"<<endl;
   }
   sort(arr.begin(),arr.end(),comp);
   for(int i=0; i<n; i++)
   {
      cout<<"("<< arr[i].first<<","<<arr[i].second.first<<","<<arr[i].second.second<<")"<<endl;
   }
   int rl = 0;
   unordered_map<string,bool>visited;
   unordered_map<string,int>ct;
   bool run = true;
   while(run)
   {
      bool flag =0,all_visited=1;
      for(int i=0; i<n; i++)
      {
         string p_name = arr[i].first;
	 int at= arr[i].second.first;
	 int bt = arr[i].second.second;
	 if(visited[p_name]==0)
	 {
	   all_visited=0;
	   if(rl >= at)
	   {
	     flag = 1;
	     rl+=bt;
	     ct[p_name] = rl;
	     visited[p_name] = 1;
	     break;
	   }
	 }
      }

      if(flag==0)
      {
      	rl++;
      }
      if(all_visited)
      {
        run=0;
      }
   }
   for(auto it:ct)
   {
      cout<<it.first<<" -> "<<it.second<<endl;
   }
   unordered_map<string,int>wt;
   unordered_map<string,int>tat;

   float avg_ct,avg_tat,avg_wt;
   int sum_ct=0,sum_tat=0,sum_wt=0;

   for(int i=0; i<n; i++)
   {
     string process_name = arr[i].first;
     int art  = arr[i].second.first;
     int brt = arr[i].second.second;
     tat[process_name] = ct[process_name] - art ;
     wt[process_name] = tat[process_name] - brt;
     sum_ct+=ct[process_name];
     sum_wt += wt[process_name];
     sum_tat+=tat[process_name];

   }
   cout<<"process | "<<"arr time |"<<"Brust_time |"<<"Waiting time |"<<"turn Aro time |"<<"comp time\n"; 
   for(int i=0; i<n; i++)
   {
     cout<<arr[i].first<<"      |      "<<arr[i].second.first<<"     |     "<<arr[i].second.second<<"      |       "<<wt[arr[i].first] <<"     |     "<<tat[arr[i].first]<<"      |      "<<ct[arr[i].first]<<endl; 
   }
   
   return 0;
}
