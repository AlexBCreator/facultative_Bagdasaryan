#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    double *p = new double[n];
    for (int i = 1; i<=n; i++){
        *(p + i) = 1.0/i;
    }
    for (int i = 1; i<=n; i++){
        cout << scientific << *(p + i) << ' ';
    }
    delete[] p;
}
