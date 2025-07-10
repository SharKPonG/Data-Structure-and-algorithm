#include <iostream>
#include <bitset>
using namespace std;

const int MAX = 100000000;
bitset<MAX + 1> isPrime;

int main() {
    int number;
    cin >> number;

    if (number < 0) {
        cout << "ERROR!";
        return 0;
    }

    isPrime.set();
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * 1LL * i <= number; i++) {
        if (isPrime[i]) {
            for (int j = i * 1LL * i; j <= number; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= number; i++) {
        if (isPrime[i]) {
            count++;
            if (i == number) {
                cout << count;
                if (count % 100 >= 11 && count % 100 <= 13) cout << "th";
                else if (count % 10 == 1) cout << "st";
                else if (count % 10 == 2) cout << "nd";
                else if (count % 10 == 3) cout << "rd";
                else cout << "th";
                return 0;
            }
        }
    }

    cout << "Unrelated";
    return 0;
}
