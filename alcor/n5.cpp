#include <iostream>


using namespace std;


int main() {
    int n;
    std::cin >> n;
    string line;
    cin >> line;
    int size = line.size();
    while (size >= 4) {
        for (int i = 0; line.size() < 4; i++)
        line.erase(remove(line.begin(), line.end(), 'e'), line.end());
        size = line.size();
    }
    
}