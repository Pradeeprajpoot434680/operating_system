// non preemtive priority scheduling
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <cstdlib>    // For rand() and srand()
#include <ctime> 
#include<string.h>
using namespace std;
//sort by priorities
bool comp(pair<string,pair<int,pair<int,int>>> a, pair<string,pair<int,pair<int,int>>> b)
{
    return a.second.second.second < b.second.second.second;  
}
//sort using arrival time
bool comp2(pair<string,pair<int,pair<int,int>>> a, pair<string,pair<int,pair<int,int>>> b)
{
    return a.second.first < b.second.first; 
}

int main()
{ 
    srand(time(NULL));
    cout << "Enter the number of processes: ";
    int n;
    cin >> n;

    vector<pair<string,pair<int,pair<int,int>>>> arr(n);

    for(int i = 0; i < n; i++)
    {
        string process_name = "p" + to_string(i+1);
        arr[i].first = process_name;
        arr[i].second.first = rand() % 10;  
        arr[i].second.second.first = rand() % 20;  
        arr[i].second.second.second = rand() % 10;
        cout << "(" << arr[i].first << ", "
             << arr[i].second.first << ", "
             << arr[i].second.second.first << ", "
             << arr[i].second.second.second << ")" << endl;
    }

    cout << "\nPriority order:\n";
    vector<pair<string,pair<int,pair<int,int>>>> temp = arr;
    sort(arr.begin(), arr.end(), comp);  // sort according to priority (burst time)
    sort(temp.begin(), temp.end(), comp2);  // sort by arrival time

    // Print sorted arrays
    for(int i = 0; i < n; i++)
    {
        cout << "(" << arr[i].first << ", "
             << arr[i].second.first << ", "
             << arr[i].second.second.first << ", "
             << arr[i].second.second.second << ")" << endl;
    }

    cout << "Arrival time sorted arr:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "(" << temp[i].first << ", "
             << temp[i].second.first << ", "
             << temp[i].second.second.first << ", "
             << temp[i].second.second.second << ")" << endl;
    }

    int first = 0;  // for iteration in arr 
    int second = 0; // for iteration in temp 
    unordered_map<string, bool> visited;
    unordered_map<string, int> ct; //complete time store datatype 
    int gt = temp[0].second.first; //from where first process starts

    while (first < n || second < n)
    {
        if (first < n && arr[first].second.first <= gt)  
        {
            string process_name = arr[first].first;
            int at = arr[first].second.first;
            int bt = arr[first].second.second.first;

            if (!visited[process_name])  // if process is already visited
            {
                visited[process_name] = true;
                gt += bt; 
                ct[process_name] = gt;  
            }
            first++;  
        }
        else if (second < n && temp[second].second.first <= gt)
        {
            string process_name = temp[second].first;
            int at = temp[second].second.first;
            int bt = temp[second].second.second.first;

            if (!visited[process_name])  
            {
                visited[process_name] = true;
                gt += bt;  
                ct[process_name] = gt;  
            }
            second++; 
        }
        else  
        {
            gt++;  
        }
    }

    cout << "\nCompletion time for processes:\n";
    for (auto it : ct)
    {
        cout << it.first << " -> " << it.second << endl;
    }
    unordered_map<string,int>wt;
   unordered_map<string,int>tat;

   float avg_ct,avg_tat,avg_wt;
   int sum_ct=0,sum_tat=0,sum_wt=0;

   for(int i=0; i<n; i++)
   {
     string process_name = arr[i].first;
     int art  = arr[i].second.first;
     int brt = arr[i].second.second.first;
     tat[process_name] = ct[process_name] - art ;
     wt[process_name] = tat[process_name] - brt;
     sum_ct+=ct[process_name];
     sum_wt += wt[process_name];
     sum_tat+=tat[process_name];

   }
   cout<<"process | "<<"arr time |"<<"Brust_time |"<<"Waiting time |"<<"turn Aro time |"<<"comp time\n";
   for(int i=0; i<n; i++)
   {
     cout<<arr[i].first<<"      |      "<<arr[i].second.first<<"     |     "<<arr[i].second.second.first<<"      |       "<<wt[arr[i].first] <<"     |     "<<tat[arr[i].first]<<"      |      "<<ct[arr[i].first]<<endl;
   }

    return 0;
}

