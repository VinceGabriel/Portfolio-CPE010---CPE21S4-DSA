#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
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

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(processes[j].arrivalTime < processes[i].arrivalTime)
                swap(processes[i], processes[j]);
        }
    }

    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;
    
    for(int i = 0; i < n; i++) {
        if(currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;
            
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
        
        currentTime += processes[i].burstTime;

        totalWT += processes[i].waitingTime;
        totalTAT += processes[i].turnAroundTime;
    }

    cout << "\n--- FCFS Scheduling Results ---\n";
    cout << "P\tAT\tBT\tWT\tTAT\n";
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