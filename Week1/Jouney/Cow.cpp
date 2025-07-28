#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int milk = 0, proMaxMilk = 0;
    int n, days;
    double milkTarget;
    double Nutrient = 0.0; 
    cin >> n >> milkTarget >> days;

    double P = pow(10, n);
    double cow;

    for (int i = 0; i < days; i++){
        int count;
        cin >> count;

        cow = 0;
        for (int j = 0; j < count; j++){
            cow += P;
        }

        Nutrient += cow;

        if (fabs((cow + cow) - milkTarget) < 1e-9){
            proMaxMilk++;
        }
        else if (fabs(cow - milkTarget) < 1e-9 || cow > milkTarget){
            milk++;
        }
    }

    cout << "Milk : " << milk << endl;
    cout << "ProMax Milk : " << proMaxMilk << endl;
    cout << "Nutrient : " << fixed << setprecision(17) << Nutrient << endl;

    return 0;
}
