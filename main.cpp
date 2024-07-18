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


int main() {
    Command c;
    read_by_line(c);
    std::cout << std::format("line: {}, characters: {}\n", c.line, c.output.size());
}