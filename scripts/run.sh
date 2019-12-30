export LD_LIBRARY_PATH=./third_party/lib:./build/lib:${LD_LIBRARY_PATH}
chmod +x ./build/bin/unit_test
./build/bin/unit_test