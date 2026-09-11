#include <iostream>
#include <fstream> 

using namespace std;

int main() {
    ofstream file("/Users/aleksandr/Documents/VSCode/факультатив/1wk/txt_folder/output.txt"); // output file stream (ofstream)
    
    int n;
    cin >> n;
    if (file.is_open()) {
        for (int i = 1; i <= n; i++) {
            file << i << " "; // Пишем в "file" вместо "cout"
        }
        file.close(); 
    }
    
    return 0;
}
