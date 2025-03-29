#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
void push_remaining_proc(int &index,int &right_limit,queue<pair<int,int>>&q,vector<pair<int,int>>&arr)
{
  while(arr[i].first <= right_limit)
  {
    q.push({index,arr[i].second});
    index++;
  }
}
int main()
{
  cout<<"Enter the number of processes:";
  int n ;
  cin>>n;
  vector<pair<int,int>>arr(n);
  vector<int>ct(n,0);
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
  std::queue<pair<int,int>>q;
  int quantum_time=5;
  int gantt_chart=0;
  int right_limit=0;
  int index=0;
  push_remaining_proc(index,right_limit,q,arr);
  while(!q.empty())
  {
    int process = q.front().first;
    int bt = q.front().second;
    if(bt<=q)
    {
	gantt_chart += bt;
    }
    else
    {
       gantt_chart += quantum_time;
       bt -= quantum_time;
       q.push({process,bt});
    }
    ct[process] = std::max(gantt_chart,ct[process]);
    right_limit+=q;
    push_remaining_proc(index,right_limit,q,arr);
  }

  for(int i=0; i<n; i++)
  {
    cout<<ct[i]<<"  ";
  }
  return 0;
}
