#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> p;
    for (int i = 1; i<=n; i++){
        p.push_back(1.0 / (i + 1));
    }
    double* d = p.data();
    for (int i = 1; i<=n; i++){
        cout << scientific << *(d + i) << ' ';
    }
}
