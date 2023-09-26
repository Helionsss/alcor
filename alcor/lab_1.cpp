#include <iostream>
#include <fstream>
#include <string>


void print(std::string filename, int lines, bool tail, char delimiter) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string temp;
        
        if (lines >= 0) {
            int count = 0;
            while (std::getline(file, temp, delimiter)) {
                if (count == lines) {
                    break;
                }
                std::cout << temp;
                if (!file.eof()) {
                    std::cout << delimiter;
                }
                count += 1;
            }
        }
        else {
            while (std::getline(file, temp, delimiter)) {
                std::cout << temp;
                if (!file.eof()) {
                    std::cout << delimiter;
                }
            }
        }
    }
    file.close();
}

int main(int argc, char* argv[]) {
    std::string filename = "";
    int lines = -1;
    bool tail = false;
    char delimiter = '\n';

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-l") {
            if (stoi(arg.substr(8)) < 0) {
                std::cout << "Error: --lines value must be only positive number";
                exit(0);
            }
            else {
                lines = stoi(std::string(argv[++i]));
            }
        }
        else if (arg == "--lines=") {
            if (stoi(arg.substr(8)) < 0) {
                std::cout << "Error: --lines value must be only positive number";
                exit(0);
            }
            else {
                lines = stoi(arg.substr(8));
            }
        }
        else if ((arg == "-t") or (arg == "--tail")) {
            tail = true;
        }
        else if (arg == "-d") {
            i++;
            if (std::string(argv[i]) == "-l" or argv[i] == "-t" or argv[i] == "--tail" or argv[i] == "--lines=") {
                std::cout << "Error: set the values of all arguments";
                exit(0);
            }
            else {
                if (argv[i][0] == '\'' or argv[i][0] == '"') {
                    if (argv[i][1] == '\'' or argv[i][1] == '"') {
                        std::cout << "Error: wrong input format";
                        exit(0);
                    }
                    else {
                        delimiter = argv[i][1];
                    }
                }
                else if (argv[i][0] == '\\') {
                    delimiter = argv[i][0] + argv[i][1];
                }
                else {
                    delimiter = argv[i][0];
                }
            }
        }
        else if (arg == "--delimiter="){
            std::cout << 1;
            if (std::string(argv[i]) == "-l" or argv[i] == "-t" or argv[i] == "--tail" or argv[i] == "--lines=") {
                std::cout << "Error: set the values of all arguments";
                exit(0);
            }
            else {
                std::cout << 1;
                delimiter = arg.data()[12];
            }
        }
        else {
            std::cout << argv[i][0];
            filename = argv[i];
        }
    }

    std::cout << "/ " << delimiter << " " << ((tail == 1) ? ("true ") : ("false ")) << lines << " /" << "\n";

    print(filename, lines, tail, delimiter);

    return 0;
}
