#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point() {
    m_x = 0;
    m_y = 0;
}

Point::Point(long double a, long double b) {
    m_x = a;
    m_y = b;
}

void Point::set_position(int a, int b) {
    m_x = a;
    m_y = b;
}

void Point::get_position() const {
    cout << m_x << "," << m_y << endl;
}

long double Point::distance(long double x1, long double x2, long double y1, long double y2) {
    long double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return d;
}