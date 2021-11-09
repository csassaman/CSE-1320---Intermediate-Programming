#include <iostream>
#include <memory>

using namespace std;

typedef struct {
    int num_wheels;
    int horsepower;
} Car;

// Making new local variable with new shared_ptr pointing to the same data
void print_wheels(shared_ptr<Car> c) {
    cout << "Wheels: " << c->num_wheels << endl;
}

int main() {
    shared_ptr<Car> a {new Car};

    a->num_wheels = 2;

    print_wheels(a);

    ostream& operator<<(ostream& os, const Ship& s) {
        return os << "{\"" << s.name 
    }

    return 0;
}
