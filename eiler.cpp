#include "eiler.hpp"

#include <fstream>
#include <cmath>


void eiler::fragmentation(
    Vec vec,
    double w,
    vector<Point>& points
) {
    auto v_0 = vec.v;
    auto x_0 = vec.x;

    Vec corr{x_0, v_0};

    for (double t = 0.0; t < 100.0; t += 0.01) {
        double old_vec_x = corr.x;
        double old_vec_v = corr.v;

        corr = {
            old_vec_x + 0.01 * old_vec_v,
            old_vec_v - 0.01 * w * w * old_vec_x
        };

        double energy =
            corr.x * corr.x * w * w / 2
            + corr.v * corr.v / 2;

        Point p = {t, corr, energy};
        points.push_back(p);
    }
}

void eiler::ofs(vector<Point>& points) {
    ofstream file(
        "/Users/aleksandr/Documents/VSCode/факультатив/4wk/data2.txt"
    );

    for (int i = 0; i < points.size(); i++) {
        if (file.is_open()) {
            file << points[i].time << " "
                 << points[i].value.x << " "
                 << points[i].value.v << " "
                 << points[i].energy << endl;
        }
    }

    file.close();
}