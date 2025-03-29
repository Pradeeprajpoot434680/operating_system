#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
int main()
{
  cout<<"Enter the number of processes:";
  int n ;
  cin>>n;
  vector<pair<int,int>>arr(n);
  vector<int>ct(n);
  vector<int>tat(n);
  vector<int>wt(n);
  for(int i=0; i<n; i++)
  {
    arr[i].first = rand() % 10;
    arr[i].second = rand() % 20 + 1;
  }
  sort(arr.begin(),arr.end());
  for(int i=0; i<n; i++)
  {
    cout<<arr[i].first<< "   "<<arr[i].second;
    cout<<endl;
  }
  cout<<endl;
  
  int c=0;
  for(int i=0; i<n; i++)
  {
    if(c < arr[i].first)
    {
      if(i>=1)
      {
	ct[i] = arr[i].second + (arr[i].first - c) + ct[i-1];
      }else
      {
        ct[i] = arr[i].second + (arr[i].first - c);
      }
    }
    else
    {
      ct[i] = arr[i].second + ct[i-1];
    }
    c = ct[i];
  }
  cout<<"Complete time table:\n";
  float avg_complete_time =0;
  int sum_ct=0;
  for(int i=0; i<n; i++)
  {
     sum_ct+=ct[i];
     cout<<ct[i]<<"  ";
  }
  cout<<endl;
  float avg_tat;
  int sum_tat =0;
  float avg_wt;
  int sum_wt=0;
  //for cpu utilization
  //cpu_util = sum_of_brust_time/last process complete time * 100
  int sum_cpu=0;
  int last_ct;
  for(int i=0; i<n; i++)
  {
    tat[i] = ct[i] - arr[i].first;
    sum_tat += tat[i];
    wt[i] = tat[i] - arr[i].second;
    sum_wt+= wt[i];
    sum_cpu += arr[i].second;
  }
  //avg complete time
  avg_complete_time = (float)sum_ct/n;
  //avg turn around time
  avg_tat = (float)sum_tat/n;
  //avg waiting time
  avg_wt = (float)sum_wt/n;
  //for waiting time
  cout<<"turnaround time:\n";
  for(int i=0; i<n; i++)
  {
     cout<<tat[i]<<"  ";
  }
  last_ct = ct[n-1];
  cout<<"response time and waiting time both are same for FCFS\n";
  cout<<"waiting time:\n";
  
  for(int i=0; i<n; i++)
  {
     cout<<wt[i]<<"  ";
  }
  cout<<endl;

  cout<<"Avg complete time:"<<avg_complete_time<<endl;
  cout<<"Avg Turn aroung time:"<<avg_tat<<endl;
  cout<<"Avg waiting time:"<<avg_wt<<endl;
  float cpu_uti = ((float)sum_cpu/last_ct)*100;
  cout<<"CPU Utilization:"<<cpu_uti<<endl;
  
  return 0;

}
