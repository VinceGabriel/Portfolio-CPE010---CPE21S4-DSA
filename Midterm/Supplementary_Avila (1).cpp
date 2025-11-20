#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int A[100];
    int n = 100;

    srand(time(0));

    // Generate random votes from 1 to 5
    for (int i = 0; i < n; i++) {
        A[i] = (rand() % 5) + 1;
    }

    // Insertion sort
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

    // Count votes
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) c1++;
        else if (A[i] == 2) c2++;
        else if (A[i] == 3) c3++;
        else if (A[i] == 4) c4++;
        else if (A[i] == 5) c5++;
    }

    // Print sorted array
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Print vote counts
    cout << "\nManual Count:" << endl;
    cout << "GABRIEL: " << c1 << endl;
    cout << "JOHNSON: " << c2 << endl;
    cout << "ODETTE: " << c3 << endl;
    cout << "LANCELOT: " << c4 << endl;
    cout << "GROCK: " << c5 << endl;

    // Find winner
    int winner = 1;
    int maxVotes = c1;

    if (c2 > maxVotes) { maxVotes = c2; winner = 2; }
    if (c3 > maxVotes) { maxVotes = c3; winner = 3; }
    if (c4 > maxVotes) { maxVotes = c4; winner = 4; }
    if (c5 > maxVotes) { maxVotes = c5; winner = 5; }

    cout << "\nWinner is Candidate " << winner
         << " with " << maxVotes << " votes!" << endl;

    return 0;
}