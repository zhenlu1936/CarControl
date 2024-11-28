rm -rf build/*
mkdir build
cd build
cmake ..
make
cd tests
lldb -s ../../debug.lldb executorTestsRun 
