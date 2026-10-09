#include "hoin.hpp"

#include <fstream>
#include <cmath>


void hoin::fragmentation(
    Vec vec,
    double w,
    vector<Point>& points
) {
    auto v_0 = vec.v;
    auto x_0 = vec.x;

    Vec corr{x_0, v_0};

    for (double t = 0.0; t < 100.0; t += 0.01) {
        double old_vec_x1 = corr.x;
        double old_vec_v1 = corr.v;

        double old_vec_x2 =
            old_vec_x1 + 0.01 * old_vec_v1;

        double old_vec_v2 =
            old_vec_v1 - 0.01 * w * w * old_vec_x1;

        corr = {
            old_vec_x1
                + 0.01 * (old_vec_v2 + old_vec_v1) / 2,

            old_vec_v1
                - 0.01 * w * w * (old_vec_x1 + old_vec_x2) / 2
        };

        double energy =
            corr.x * corr.x * w * w / 2
            + corr.v * corr.v / 2;

        Point p = {t, corr, energy};
        points.push_back(p);
    }
}

void hoin::ofs(vector<Point>& points) {
    ofstream file(
        "/Users/aleksandr/Documents/VSCode/факультатив/4wk/data3.txt"
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