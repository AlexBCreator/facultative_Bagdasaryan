#pragma once

#include "classic.hpp"
using namespace std;
struct eiler : classic {
    void fragmentation(
        Vec vec,
        double w,
        vector<Point>& points
    ) override;

    void ofs(
        vector<Point>& points
    ) override;
};