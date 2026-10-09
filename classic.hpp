#pragma once

#include <vector>
#include <fstream>
using namespace std;

struct classic {

    struct Vec {
        double x;
        double v;
    };

    struct Point {
        double time;
        Vec value;
        double energy;
    };

    virtual void fragmentation(
        Vec vec,
        double w,
        vector<Point>& points
    );

    virtual void ofs(
        vector<Point>& points
    );

    virtual ~classic() = default;
};