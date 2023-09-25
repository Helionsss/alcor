#include <iostream>
#include <string>
#include <fstream>
#include <vector>


void print(std::string filename, int lines, bool tail, char delimiter) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::vector<std::string> outputs;
        std::string temp;

        while (std::getline(file, temp, delimiter)) {
            outputs.push_back(temp);
        }

        if (tail) {
            for (int i = 0; i < lines; i++) {
                std::cout << outputs[-i] << std::endl;
            }
        }
        else {
            for (int i = 0; i < lines; i++) {
                std::cout << outputs[i] << std::endl;
            }
        }    
    }
}

int main(int argc, char* argv[]) {
    std::string filename = "";
    int lines = 0;
    bool tail = false;
    char delimiter = '\n';

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if ((arg == "-l") or (arg == "--lines=")) {
            if (arg == "-l") {
                lines = stoi(std::string(argv[++i]));
            }
            else {
                lines = stoi(arg.substr(8));
            }
        }
        else if ((arg == "-t") or (arg == "--tail")) {
            tail = true;
        }
        else if ((arg == "-d") or (arg == "--delimiter=")) { // t, 't', "t"
            if (arg == "-d") {
                i++;
                if (std::string(argv[i]) == "-l" or argv[i] == "-t" or argv[i] == "--tail" or argv[i] == "--lines=") {
                    std::cout << "Error";
                    exit(0);
                }
                else {
                    delimiter = argv[i][0];
                }
            }
        }
        else {
            filename = argv[i];
        }
    }

    std::cout << "/ " << delimiter << " " << ((tail == 1) ? ("true ") : ("false ")) << lines << " /" << "\n";
    print(filename, lines, tail, delimiter);
    return 0;
}
