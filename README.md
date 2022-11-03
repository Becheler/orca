# orca
Orbit Counting Algorithm

Build the project using conan dependency manager and run test

```
pip install conan==1.49.0
```

```
conan install conan/conanfile.txt --build=missing --install-folder=build -pr:b=conan/profiles/clang_13 -pr:h=conan/profiles/clang_13
cd build
cmake -D CMAKE_TOOLCHAIN_FILE=conan_paths.cmake ..
cmake --build .
ctest
```

## How to use

```cpp
orca::Parser p;
// read in file
p.parse(input_file);
// empty parser from its content
ORCA orca(p.n(), p.m(), std::move(p.take_edges()), std::move(p.take_degrees()));
// count orbits
orca.count_orbits();
// output
computer.write_results_to(output_file);
```
