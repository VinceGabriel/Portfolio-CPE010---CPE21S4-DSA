#include <iostream>
#include <queue>
#include <string>
using namespace std;


class Job {
public:
    int id;
    string user;
    int pages;

    Job(int i, string u, int p) {
        id = i;
        user = u;
        pages = p;
    }
};


class Printer {
private:
    queue<Job> jobList; 

public:
    void addJob(Job j) {
        jobList.push(j);
        cout << "Job " << j.id << " submitted by " << j.user 
             << " (" << j.pages << " pages)" << endl;
    }

    void processJobs() {
        while (!jobList.empty()) {
            Job cur = jobList.front();
            cout << "Printing Job " << cur.id << " from " 
                 << cur.user << " with " << cur.pages << " pages..." << endl;
            jobList.pop(); 
        }
        cout << "All print jobs are done." << endl;
    }
};

int main() {
    Printer printer;

    
    printer.addJob(Job(1, "Alex", 8));
    printer.addJob(Job(2, "Maya", 12));
    printer.addJob(Job(3, "Jordan", 5));
    printer.addJob(Job(4, "Ella", 9));
    printer.addJob(Job(5, "Noah", 6));
    printer.addJob(Job(6, "Liam", 15));

    cout << "\n--- Processing Queue ---\n";
    printer.processJobs();

    return 0;
}
