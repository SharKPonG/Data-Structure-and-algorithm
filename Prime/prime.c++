#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int number;
    cin >> number;


    if (number < 0){
        cout << "ERROR!";
        return 0;
    }

    int count = 0;
    for (int i = 2; i <= number; i++) {
        if (isPrime(i)) {
            count++;
            if (i == number) {
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
        }
    }
    cout << "Unrelated";
    return 0;
}
