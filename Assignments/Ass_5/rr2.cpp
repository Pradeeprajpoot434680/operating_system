#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void push_remaining_proc(int &index, int &right_limit, queue<pair<int, int>> &q, vector<pair<int, int>> &arr) {
    while (index < arr.size() && arr[index].first <= right_limit) {
        q.push({index, arr[index].second});
        index++;
    }
}

int main() {
    cout << "Enter the number of processes: ";
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    vector<int> ct(n, 0);
    vector<int> tat(n);
    vector<int> wt(n);

  /*  for (int i = 0; i < n; i++) {
        arr[i].first = rand() % 10;
        arr[i].second = rand() % 20 + 1;
    }*/
    for(int i=0; i<n; i++)
    {
     cout<<"Enter for "<<i<<" th process:";
     cin>>arr[i].first;
     cin>>arr[i].second;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << "   " << arr[i].second << endl;
    }

    cout << endl;

    queue<pair<int, int>> q;
    int quantum_time = 3;
    int gantt_chart = arr[0].first;
    int right_limit = gantt_chart;
    int index = 0;

    push_remaining_proc(index, right_limit, q, arr);
    bool flag =0;
    while (!q.empty()) {
        int process = q.front().first;
        int bt = q.front().second;
        q.pop();

        if (bt <= quantum_time) {
            gantt_chart += bt;
            ct[process] = gantt_chart;
        } else {
            gantt_chart += quantum_time;
            bt -= quantum_time;
            
	    flag=1;
        }

        right_limit = gantt_chart;
	
        push_remaining_proc(index, right_limit, q, arr);
	if(flag)
	{
	   q.push({process, bt});
	}
	flag=0;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - arr[i].first;
        wt[i] = tat[i] - arr[i].second;
    }

    cout << "Completion Times: ";
    for (int i = 0; i < n; i++) {
        cout << ct[i] << " ";
    }
    cout << endl;

    cout << "Turnaround Times: ";
    for (int i = 0; i < n; i++) {
        cout << tat[i] << " ";
    }
    cout << endl;

    cout << "Waiting Times: ";
    for (int i = 0; i < n; i++) {
        cout << wt[i] << " ";
    }
    cout << endl;

    return 0;
}

