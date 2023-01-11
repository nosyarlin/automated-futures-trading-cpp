# Getting Started
## Requirements
Ubuntu 18.04
Cmake 3.25.1

## Build
You may choose to rebuild from scratch. If so, do the following
```
rm -rf ./build          # reset build
mkdir ./build

cmake -S . -B ./build   # generate make file
make -C ./build         # compile project
```

Once the build is ready, run the code using
```
./build/connect_to_ctp
```