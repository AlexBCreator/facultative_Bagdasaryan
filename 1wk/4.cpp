#include <iostream>
#include <fstream> //  библиотека для работы с файлами

using namespace std;

int main() {
    ofstream file("/Users/aleksandr/Documents/VSCode/факультатив/1wk/txt_folder/output.txt"); // output file stream (ofstream)
    

    if (file.is_open()) {
        for (int i = 1; i <= 33; i++) {
            file << i << " "; // Пишем в "file" вместо "cout"
        }
        file.close(); 
    }
    
    return 0;
}
