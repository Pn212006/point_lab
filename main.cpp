#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double operator-(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        return Point((x + other.x) / 2.0, (y + other.y) / 2.0);
    }

    Point operator*(double scalar) const {
        return Point(x * scalar, y * scalar);
    }

    double operator[](int index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        throw invalid_argument("Invalid index. Use 0 for x or 1 for y.");
    }

    // Pre-increment (++point): increments x
    Point& operator++() {
        ++x;
        return *this;
    }

    // Post-increment (point++): increments y
    Point operator++(int) {
        Point temp = *this;
        y++;
        return temp;
    }

    // Pre-decrement (--point): decrements x
    Point& operator--() {
        --x;
        return *this;
    }

    // Post-decrement (point--): decrements y
    Point operator--(int) {
        Point temp = *this;
        y--;
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

int main() {
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    cout << p1 - p2 << endl;
    cout << (p1 == p2) << endl;
    cout << (p1 != p2) << endl;
    cout << p1 / p2 << endl;
    cout << p1 * 2 << endl;
    cout << p1[0] << ", " << p1[1] << endl;

    ++p1;
    cout << p1 << endl;

    p1++;
    cout << p1 << endl;

    --p1;
    cout << p1 << endl;

    p1--;
    cout << p1 << endl;

    Point inputPoint;
    cout << "Enter a point (x y): ";
    cin >> inputPoint;
    cout << "You entered: " << inputPoint << endl;

    return 0;
}
