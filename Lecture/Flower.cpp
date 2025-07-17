#include <iostream>
#include <string>
using namespace std;

struct Source {
    string subDistrict;
    string province;
};

struct Flower {
    string id;
    string name;
    float price;
    Source location;
};

int main() {
    Flower flowers[3];

    for (int i = 0; i < 3; i++) {
        cout << "Flower seed " << i + 1 << ":\n";
        cout << "Id: ";
        getline(cin, flowers[i].id);
        cout << "Name: ";
        getline(cin, flowers[i].name);
        cout << "Price: ";
        cin >> flowers[i].price;
        cin.ignore();
        cout << "SubDistrict: ";
        getline(cin, flowers[i].location.subDistrict);
        cout << "Province: ";
        getline(cin, flowers[i].location.province);
        cout << endl;
    }

    cout << "\n=== Flower Info ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "Flower seed " << i + 1 << ":\n";
        cout << "Id: " << flowers[i].id << endl;
        cout << "Name: " << flowers[i].name << endl;
        cout << "Price: " << flowers[i].price << " Baht" << endl;
        cout << "Location: " << flowers[i].location.subDistrict << ", "
             << flowers[i].location.province << endl;
        cout << "----------------------\n";
    }

    return 0;
}
