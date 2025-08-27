#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> students;
    int num;
    while (cin.peek() != '\n' && cin >> num) {
        students.push_back(num);
    }

    int target;
    cin >> target;

    int left = 0, right = students.size() - 1, rounds = 0;
    bool found = false;

    while (left <= right) {
        rounds++;
        int mid = left + (right - left) / 2;
        if (students[mid] == target) {
            found = true;
            break;
        } else if (students[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found)
        cout << "Present - " << rounds << endl;
    else
        cout << "Absent" << endl;

    return 0;
}
