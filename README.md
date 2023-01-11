# Getting Started
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