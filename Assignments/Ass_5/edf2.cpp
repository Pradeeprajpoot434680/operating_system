#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <cstdlib>    // For rand() and srand()
#include <ctime>
#include<string.h>
using namespace std;

struct Process
{
  string process_name;
  int arrival_time;
  int deadline;
  int execution_time;
};

bool comp(const Process &p1, const Process &p2)
{
  return p1.deadline < p2.deadline;
}
int main()
{
  srand(time(NULL));
  int n;
  cout<<"Enter the number of processes: ";
  cin>>n;
  vector<Process> arr(n);

   for(int i = 0; i < n; i++) {
    string process_name = "p" + to_string(i+1);
    arr[i].process_name = process_name;
    arr[i].arrival_time = rand() % 10;
    arr[i].execution_time = rand() % 5 + 1; 
    arr[i].deadline = arr[i].arrival_time + rand() % 5 + 1;  
    cout << "(" << arr[i].process_name << ", "
             << arr[i].arrival_time << ", "
             << arr[i].execution_time << ", "
             << arr[i].deadline << ")" << endl;
  }

   sort(arr.begin(),arr.end(),comp);


  int gantt_chart=0;
   for(int i=0; i<n; i++)
   {
     if(arr[i].arrival_time < gantt_chart)
     {
        cout << "Executing " << arr[i].process_name
             << " [Arrival: " << arr[i].arrival_time 
             << ", Execution: " << arr[i].execution_time 
             << ", Deadline: " << arr[i].deadline 
             << "] at time " <<gantt_chart << endl;


	gantt_chart += arr[i].execution_time;

	if(gantt_chart > arr[i].deadline)
	{
	  cout<<"process "<<arr[i].process_name<<" missed its deadline";
	}else
	{
	  cout<<"Process "<<arr[i].process_name<<" completed on time\n";
	}
     }
     else
     {
       cout<<"procrss "<<arr[i].process_name<<" arrived late\n";
     }

   }
return 0;
}
