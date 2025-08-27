#include <iostream>
using namespace std;

int main(){
    int array[100000];
    int n = 0;
    int target;
    char c;

    while(cin >> array[n]){
        n++;
        c = getchar();
        if (c == '\n') break;
    }

    cin >> target;
    

    bool counted = false;
    for(int i=0; i < n; i++){
        if (array[i] == target){
            cout << "Present - " << i + 1 << endl;
            counted = true;
            break;
        }
    }
    if (!counted){
        cout << "Absent" << endl;
    }

    return 0;
}
