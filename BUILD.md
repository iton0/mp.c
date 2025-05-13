# Prerequisites
1. Download dependencies explained here https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#dependencies
    - cmake is also needed
2. After cloning the repo add the raylib submodule:
`git submodule update --init --recursive`
3. Finally make the build directory:
`mkdir -p build`

# Building
Run the following commands in the terminal:
```sh
cd build
cmake ..
make     # option 1: build executable
make run # option 2: build and run executable
```
