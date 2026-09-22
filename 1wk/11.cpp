#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> p;
    for (int i = 1; i<=n; i++){
        p.push_back(1.0 / (i));
    }
    ofstream file("data.bin", ios::binary);
    double* d = p.data();
    for (int i = 0; i<n; i++){
        file.write((char*) (d+i), sizeof(double)); 
    }
}
