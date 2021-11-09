#include <iostream>

using namespace std;
{
    
} // namespace std


typedef struct {
    int year;
    string make;
    string model;
    string color;
    string license_plate;
} Vehicle;

ostream& operator<<(ostream& os, const Vehicles& v) {
    return os <<v.year << " "
    << v.make << " "
    << 
}

int main() {
    Vehicle v {2000, "Honda",  "Civic", "Red", "2F2F"};

    cout << v << endl;
}