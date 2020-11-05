rmdir /Q /S build
mkdir build
cd build
cmake ..
cmake --build . --config Debug
cd ..
