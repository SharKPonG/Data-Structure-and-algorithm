#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int TABLE_SIZE = 20;

class Item{
public:
    string name;
    float x, y, z;
    bool usedItem;

    Item() : name(""), x(0), y(0), z(0), usedItem(false) {}
    Item(string name, float x, float y, float z, bool usedItem) {
        this->name = name;
        this->x = x;
        this->y = y;
        this->z = z;
        this->usedItem = usedItem;
    }
};
class HashTable{    
private:
    static const int TABLE_SIZE = 20;
    Item table[TABLE_SIZE];

    int hashFunction(const string &s){
        int sum = 0;
        for (char c : s ){
            sum += c;
        }
        return sum % TABLE_SIZE;
        }
public:
    void insert(const Item &item){
        int index = hashFunction(item.name);
        for(int i = 0; i < TABLE_SIZE; i++){
            int posi = (index + i) % TABLE_SIZE;
            if(!table[posi].usedItem){
                table[posi] = item;
                table[posi].usedItem = true;
                break;
            }
        }
    }

    Item* search(const string &name){
        int index = hashFunction(name);
        for (int i = 0; i < TABLE_SIZE; i++){
            int posi = (index + i) % TABLE_SIZE;
            if(!table[posi].usedItem) return nullptr;
            if(table[posi].name == name ) return &table[posi];
        }

        return nullptr;
    }
};

int main(){
    HashTable hTable; 
    string name;
    float x, y, z;


    while(cin >> name) {
        if(name == "--------------------") break;
        if(!(cin >> x >> y >> z)) break;
        hTable.insert(Item(name, x, y, z, true));
    }

    vector<string> output;
    while(cin >> name) {
        Item* found = hTable.search(name);
        ostringstream oss;
        if(found){
            oss << fixed << setprecision(2);
            oss << "( " << found->x << ", " << found->y << ", " << found->z << " )";
        } else {
            oss << "Item not found.";
        }
        output.push_back(oss.str());
    }

    for(const string &s : output){
        cout << s << endl;
    }

    return 0;
}