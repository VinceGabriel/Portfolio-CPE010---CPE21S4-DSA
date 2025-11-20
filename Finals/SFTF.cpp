#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    bool completed = false; 
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for(int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time and burst time for P" << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    int completed = 0;
    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    while(completed != n) {
        int idx = -1;
        int minBurst = 1e9; 

        for(int i = 0; i < n; i++) {
            if(!processes[i].completed && processes[i].arrivalTime <= currentTime) {
                if(processes[i].burstTime < minBurst) {
                    minBurst = processes[i].burstTime;
                    idx = i; 
                }
            }
        }

        if(idx != -1) {
            
            if(currentTime < processes[idx].arrivalTime)
                currentTime = processes[idx].arrivalTime;

            processes[idx].waitingTime = currentTime - processes[idx].arrivalTime;
            processes[idx].turnAroundTime = processes[idx].waitingTime + processes[idx].burstTime;

            currentTime += processes[idx].burstTime;
            
            processes[idx].completed = true;
            completed++;

            totalWT += processes[idx].waitingTime;
            totalTAT += processes[idx].turnAroundTime;

        } else {
            currentTime++;
        }
    }

    cout << "\nP\tAT\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
        cout << "P" << processes[i].pid << "\t"
             << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t"
             << processes[i].waitingTime << "\t"
             << processes[i].turnAroundTime << "\n";

    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << "\n";

    return 0;
}