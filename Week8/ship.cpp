#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct City {
    int id;
    int troops;
    vector<City*> children;
};

map<int, City*> cities;
vector<City*> roots;
vector<int> capturedCities;

int myTroops;

bool attack(City* city) {
    if (!city) return false;

    int enemy = city->troops;
    int gain = 0;
    int loss = 0;


    if (myTroops >= enemy) { 
        gain = (enemy * 70) / 100;
        myTroops += gain;
        capturedCities.push_back(city->id);
        cout << "#" << city->id << " - " << myTroops - gain << ", " << enemy << "\n";
        cout << "(+" << gain << ", " << myTroops << ")\n";
    } else { // แพ้
        loss = (myTroops * 30) / 100;
        myTroops -= loss;
        cout << "#" << city->id << " - " << myTroops + loss << ", " << enemy << "\n";
        cout << "(-" << loss << ", " << myTroops << ")\n";
        if (myTroops <= 0) return false;
    }


    for (City* child : city->children) {
        if (myTroops == 0) return false;
        attack(child);
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    myTroops = m;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (!cities[x]) cities[x] = new City{x, z};
        else cities[x]->troops = z;

        if (y == 0) roots.push_back(cities[x]);
        else {
            if (!cities[y]) cities[y] = new City{y, 0};
            cities[y]->children.push_back(cities[x]);
        }
    }

    for (City* root : roots) {
        if (myTroops == 0) break;
        attack(root);
    }

    cout << myTroops << "\n";
    if (capturedCities.empty()) cout << "IMPOSSIBLE\n";
    else {
        for (size_t i = 0; i < capturedCities.size(); i++) {
            if (i > 0) cout << " ";
            cout << capturedCities[i];
        }
        cout << "\n";
    }


    for (auto it : cities) delete it.second;

    return 0;
}
