rm build/tests/executorTestsRun
cd build
cmake ..
make
cd tests
./executorTestsRun