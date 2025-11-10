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

    double operator[](char coord) const {
        if (coord == 'x' || coord == 'X') return x;
        if (coord == 'y' || coord == 'Y') return y;
        throw invalid_argument("Invalid coordinate. Use 'x' or 'y'.");
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
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
    cout << p1['x'] << ", " << p1['y'] << endl;

    return 0;
}
