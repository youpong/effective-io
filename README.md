# effective-io

Compare how differently efficient fgetc() and std::getline().

Standard: C++20

## Usage

```sh
$ make run
c++ -O3 -std=c++20 -Wall -Wextra --pedantic-errors   -c -o read.o read.cpp
c++ -o read read.o
dd if=/dev/random count=131072 > data
131072+0 records in
131072+0 records out
67108864 bytes transferred in 0.383765 secs (174869683 bytes/sec)
READ BY std::getline() [1]
time ./read -l <data
line: 262496, characters: 67108864

real    0m2.044s
user    0m1.339s
sys     0m0.035s
READ BY std::getline() [2]
time ./read -l2 <data
line: 262497, characters: 67108865

real    0m1.363s
user    0m1.326s
sys     0m0.028s
READ BY fgetc()
time ./read -c <data
line: 262496, characters: 67108864

real    0m1.115s
user    0m1.086s
sys     0m0.026s
```