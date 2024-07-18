#include <stdio.h>
#include <iostream>
#include <string>
#include <format>
using namespace std::literals;

class Command {
  public:
    int line{0};
    std::string output;
};

auto read_by_char(Command &cmd) {
    int c;
    while((c = fgetc(stdin)) != EOF) {
        if (c == '\n') {
            cmd.line++;
        }
        cmd.output += c;
    }
}

auto read_by_line(Command &cmd) {
    std::string s;
    while(std::getline(std::cin, s)) {
        cmd.line++;
        cmd.output += s + "\n"s;
    }
}

int main(int argc, char* argv[]) {
    Command c;

    if (argc != 2) {
        std::cerr << "Error: specify -c or -h" << std::endl;;
        return 1;
    }
    if ("-c"s == argv[1]) {
        read_by_char(c);
    } else if ("-l"s == argv[1]) {
        read_by_line(c);
    }

    std::cout << std::format("line: {}, characters: {}\n", c.line, c.output.size());
}