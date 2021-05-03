# keyzz
Terminal game to practice keyboard typing. It's a runner. The idea is to be faster than you were before. Up to four of your previous tries are visible, so you can see your rivals.

# How to install and run

1. Download [deb package](https://github.com/DmitryDzz/keyzz/releases).
1. Install: `sudo apt install ./keyzz_x.x.x-x_amd64.deb`
1. Run: `keyzz <text file>`

# How to build

## To be installed

### CXX
```
sudo apt install cmake build-essential libncurses5-dev
```

### cpplint installation (optional)
```
sudo apt install python3-pip
pip3 install cpplint
```
Restart computer or source the `.profile` file.

## Build

### Clone repository
```
cd <projects directory>
git clone git@github.com:DmitryDzz/keyzz.git
cd keyzz
```

### Debug version
```
mkdir debug
cd debug

cmake -DCMAKE_BUILD_TYPE=Debug ..
or
cmake -DCMAKE_CXX_CPPLINT=cpplint -DCMAKE_BUILD_TYPE=Debug ..

cmake --build .
./keyzz/keyzz
```

### Release version
```
mkdir release
cd release

cmake -DCMAKE_BUILD_TYPE=Release ..
or
cmake -DCMAKE_CXX_CPPLINT=cpplint -DCMAKE_BUILD_TYPE=Release ..

cmake --build .
./keyzz/keyzz
```
