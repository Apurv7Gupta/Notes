#include <iostream>
#include <fstream>
using namespace std;

struct Data {
    int x;
    double y;
};

int main() {
    Data d1 = {42, 3.14};

    // Writing to binary file
    ofstream out("data.bin", ios::binary);
    out.write(reinterpret_cast<char*>(&d1), sizeof(d1));
    out.close();

    // Reading from binary file
    Data d2;
    ifstream in("data.bin", ios::binary);
    in.read(reinterpret_cast<char*>(&d2), sizeof(d2));
    in.close();

    cout << "x = " << d2.x << ", y = " << d2.y << endl;
    return 0;
}