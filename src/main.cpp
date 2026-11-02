#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    const std::string name = argc > 1 ? argv[1] : "world";
    std::cout << "Hello, " << name << "!\n";
    return 0;
}
