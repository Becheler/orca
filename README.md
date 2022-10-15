# orca
Orbit Counting Algorithm

Build the project using conan dependency managemer
```
python3 -m venv virtual-env
source virtual-env/bin/activate
pip install conan==1.49.0
conan install conan/conanfile.txt --build=missing --install-folder=build
cd build
cmake -D CMAKE_TOOLCHAIN_FILE=conan_paths.cmake ..
```
