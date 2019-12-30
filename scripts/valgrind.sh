export LD_LIBRARY_PATH=./third_party/lib:./build/lib:${LD_LIBRARY_PATH}
chmod +x ./build/bin/unit_test
VALGRIND_OPTS="--leak-check=full --show-leak-kind=definite --log-file=valgrind.log --track-fds=yes"
valgrind "${VALGRIND_OPTS}" ./build/bin/unit_test