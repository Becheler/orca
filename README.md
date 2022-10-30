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
