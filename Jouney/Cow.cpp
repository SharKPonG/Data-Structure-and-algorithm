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

    for (int i = 0; i < days; i++){
        int cow;
        cin >> cow;

        double today = cow * P;
        Nutrient += today;

        if (fabs(today - milkTarget) < 1e-9){
            proMaxMilk++;
        }
        if (fabs(today - milkTarget) < 1e-9 || today > milkTarget){
            milk++;
        }
    }

    cout << "Milk : " << milk << endl;
    cout << "Promax Milk : " << proMaxMilk << endl;
    cout << "Nutrient : " << fixed << setprecision(17) << Nutrient << endl;

    return 0;
}
