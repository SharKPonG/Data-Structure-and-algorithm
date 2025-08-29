#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> students;


        int x;
    while (cin >> x) {
        students.push_back(x);
        int ch = cin.peek();
        if (ch == '\n' || ch == '\r' || ch == EOF) {
            if (ch == '\r') { cin.get(); ch = cin.peek(); }
        break;
    }
}
    int target;
    if (!(cin >> target)) return 0;

    int left = 0, right = students.size() - 1, rounds = 0;
    bool found = false;

    
    while (left <= right) {
        rounds++;
        int mid = left + (right - left) / 2;
        if (students[mid] == target) { found = true; break; }
        else if (students[mid] < target) left = mid + 1;
        else right = mid - 1;
    }


    if (found)
        cout << "Present - " << rounds << endl;
    else
        cout << "Absent" << endl;

    return 0;
}
