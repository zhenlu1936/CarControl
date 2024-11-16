cd build
rm rf ./*
cmake ..
make
cd tests
lldb -s ../../debug.lldb executorTestsRun 
