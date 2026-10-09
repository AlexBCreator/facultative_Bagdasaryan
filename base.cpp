#include <iostream>
#include <vector>

#include "classic.hpp"
#include "eiler.hpp"
#include "hoin.hpp"
#include "analytic.hpp"

using namespace std;

int main() {

    double x_0, v_0, w;

    cout << "x_0 = ";
    cin >> x_0;

    cout << "v_0 = ";
    cin >> v_0;

    cout << "w = ";
    cin >> w;

    classic::Vec vec = {x_0, v_0};

    analytic analytical_solver;
    eiler eiler_solver;
    hoin heun_solver;

    vector<classic::Point> analytical_points;
    vector<classic::Point> eiler_points;
    vector<classic::Point> heun_points;

    analytical_solver.fragmentation(
        vec, w, analytical_points
    );

    eiler_solver.fragmentation(
        vec, w, eiler_points
    );

    heun_solver.fragmentation(
        vec, w, heun_points
    );

    analytical_solver.ofs(analytical_points);
    eiler_solver.ofs(eiler_points);
    heun_solver.ofs(heun_points);

    return 0;
}