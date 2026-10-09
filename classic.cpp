#include "classic.hpp"
using namespace std;

void classic::fragmentation(Vec vec, double w, vector<Point>& points) {
    auto v_0 = vec.v;
    auto x_0 = vec.x;

    for (double t = 0.0; t < 100.0; t += 0.01) {
        Vec corr{
            x_0 * cos(w * t) + v_0/w * sin(w*t),
            v_0 * cos(w * t) - x_0*w*sin(w*t)
        };

        double energy = corr.x * corr.x * w * w / 2
                      + corr.v * corr.v / 2;

        Point p = {t, corr, energy};
        points.push_back(p);
    }
}

void classic::ofs(vector<Point>& points) {
    ofstream file("/Users/aleksandr/Documents/VSCode/факультатив/4wk/data.txt");

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