#include <tuple>
class date {
    int y, m, d;
    public:
    date ()
        : y{1776}, m{7}, d{4}
    { }
    date (int y, int m, int d);
    std::tuple<int,int,int> as_tuple ();
    int year ();
    int month ();
    int day ();
};

