#ifndef PCH_H
#define PCH_H

class Point
{
public:
    Point();
    Point(long double, long double);
    void set_position(int, int);
    void get_position() const;
    long double distance(long double, long double, long double, long double);

private:
    long double m_x;
    long double m_y;
};

#endif //PCH_H