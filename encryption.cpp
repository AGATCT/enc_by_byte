/*,其它的如int/long/short等不指定signed/unsigned时都默认是signed。 
    但char在标准中是unsigned,编译器可以实现为带符号的,也可以实现为不带符号的*/

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <ctime>
// #include "bstream.h"

using namespace std;

void generate_file(string input_file, string output_file)
{
    char bytes;
    
    ifstream ifs(input_file, ifstream::in | ifstream::binary);
    ofstream ofs(output_file, ifstream::out | ifstream::binary);
    while (true) {
        bytes = ifs.get();
        if (ifs.eof())
            break;
        else {
            bytes+=1;
            ofs.put(bytes);
        }
    }
    ifs.close();
    ofs.close();
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);

    if (argc != 2 && argc != 3) {
        cout << "Error: Invalid argument\n";
        cout << "Usage: \[.\\\]enc input_file output_file";
        return 0;
    }

    if (argc == 2)
        generate_file(argv[1], string(argv[1]) + ".enc");
    else
        generate_file(argv[1], argv[2]);
    return 0;
}
