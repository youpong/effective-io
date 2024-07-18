#include <stdio.h>
#include <iostream>
#include <string>
#include <format>
using namespace std::literals;

class Command {
  public:
    int line{0};
    std::string output{};
};

auto read_by_char(Command &cmd) {
    int c{};
    while((c = fgetc(stdin)) != EOF) {
        if (c == '\n') {
            cmd.line++;
        }
        cmd.output += c;
    }
}

auto read_by_line(Command &cmd) {
    std::string s{};
    while(std::getline(std::cin, s)) {
        if ((std::cin.rdstate() & std::ios_base::eofbit) == false) {
            cmd.output += s + "\n"s;
            cmd.line++;
        } else {
            cmd.output += s;
        }
    }
}

[[noreturn]] auto show_usage() {
        std::cerr << "Error: specify -c or -h" << std::endl;;
        exit(1);
}

int main(int argc, char* argv[]) {
    Command c{};

    if (argc != 2) {
        show_usage();
    }
    if ("-c"s == argv[1]) {
        read_by_char(c);
    } else if ("-l"s == argv[1]) {
        read_by_line(c);
    } else {
        show_usage();
    }

    std::cout << std::format("line: {}, characters: {}\n", c.line, c.output.size());
}