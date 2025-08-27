#include <iostream>
#include <cstdlib>
using namespace std;
int binarySearchSenior(int arr[], int size, int target, int& count) {
    count = 0;
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        count++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return -1; 
}

int main() {

    int array = 10;
    int size = 0;
    int* students = (int*)malloc(array * sizeof(int));


    if (students == NULL) {
        return 1; 
    }


    int num;
    while (cin >> num) {

        if (size == array) {
            array *= 2;
            int* temp = (int*)realloc(students, array * sizeof(int));
            if (temp == NULL) {
                free(students);
                return 1;
            }
            students = temp;
        }
        students[size++] = num;


        if (cin.peek() == '\n') {
            break;
        }
    }


    int target;
    cin >> target;

  
    int count = 0;
    int result = binarySearchSenior(students, size, target, count);


    if (result != -1) {
       cout << "Present - " << count << endl;
    } else {
        cout << "Absent" <<endl;
    }

 
    free(students);

    return 0;
}