# effective-io

Compare how differently efficient fgetc() and std::getline().

Standard: C++20

## Usage

```sh
$ make run
READ BY fgetc()
time dd if=/dev/random count=131072 2>/dev/null | ./read -c
line: 261090, characters: 67108864

real    0m1.294s
user    0m1.282s
sys     0m0.154s
READ BY std::getline()
time dd if=/dev/random count=131072 2>/dev/null | ./read -l
line: 261326, characters: 67108865

real    0m2.604s
user    0m2.597s
sys     0m0.156s
```