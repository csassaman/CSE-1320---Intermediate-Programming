#include <iostream>
#include <memory>

using namespace std;
struct Car {
    int num_wheels;
    int horsepower;
};

bool has_equal_wheels(unique_ptr<Car>& a, unique_ptr<Car>& b) {
    return a->num_wheels == b->num_wheels;
}

int main() {
    // Car *c = new Car;
    unique_ptr<Car> a {new Car};
    unique_ptr<Car> b {new Car};

    // cout << "How many wheels does the car have?" << endl;
    // cin >> c->num_wheels;

    // if (c->num_wheels > 4) {
    //     delete c;
    //     cout <<"deleting..." << endl;
    // }

    

    return 0;
}