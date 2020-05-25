# gtestExamples

## 1. What is This?

This is a granny guide to installing googletest and googlemock and a few examples on how to use them.

## 2. How to Install Google Test

```
git clone https://github.com/google/googletest.git
cd googletest
cmake CMakeLists.txt
make
sudo cp -r lib/ /usr/local/lib/
sudo cp -r googletest/include/gtest/ /usr/local/include/
sudo cp -r googlemock/include/gmock/ /usr/local/include/
```

NOTE! If you copy libraries or includes to a different directory, don't forget to edit the test/Makefile accordingly!

## 3. How to Run Example Tests

```
cd path/to/gtestExamples/test
make
```

## 4. How to Run Tests With Leak Detection Using Valgrind Tool

```
cd path/to/gtestExamples/test
make memcheck
```

## 5. For More Testing Options

```
cd path/to/gtestExamples/test
make
./testAll --help
```
