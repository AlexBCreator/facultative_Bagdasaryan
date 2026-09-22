#include <iostream>
using namespace std;

int fibonachi(int a, int b) { return (a + b);}


int main(){
    int n;
    cin >> n;
    int* p = new int[n];
    int n_1, n_2;
    n_1 = -1;
    n_2 = 1;
    for (int i = 0; i<n; i++){
        *(p + i) = fibonachi(n_1, n_2);
        n_1 = n_2;
        n_2 = *(p + i);
    }
    for (int i = 0; i<n; i++){
        cout << *(p+i) << ' ';
    }
    delete[] p;
    
}
