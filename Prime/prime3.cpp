#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    cin >> number;

    if (number < 0) {
        cout << "ERROR!";
        return 0;
    }

    vector<bool> isPrime(number + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= number; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= number; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= number; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    if (!isPrime[number]) {
        cout << "Unrelated";
        return 0;
    }

    cout << count;
    if (count % 100 >= 11 && count % 100 <= 13) {
        cout << "th";
    } else if (count % 10 == 1) {
        cout << "st";
    } else if (count % 10 == 2) {
        cout << "nd";
    } else if (count % 10 == 3) {
        cout << "rd";
    } else {
        cout << "th";
    }

    return 0;
}
