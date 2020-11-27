# mini-jvm-c

基于 [build-jvm-from-scratch](https://github.com/guxingke/build-jvm-from-scratch) 项目的实现思路，用 C 语言来实现 mini-jvm。

# 目标

- 可读
- 可测

# 开发环境

- macos x86_64
- jdk 8
- c99
- cmake
- clion 2020.2

# 目录说明

```properties
├── CMakeLists.txt        --- .
├── README.md             --- .
├── docs                  --- 文档
├── misc                  --- 杂项文件
├── src                   --- 源码
│         ├── hello.c     
│         └── main.c      --- main
├── test                  --- 白盒测试
│         ├── assert.c    --- 断言
│         └── test.c      --- test main
└── tests                 --- 黑盒测试
```

# 开发

## build

```bash
mkdir build && cd build
cmake ../
make
```

## run

```bash
./jvm 
```

## test

```bash
./test
```

# 约束

- 不支持跨平台

# 其他

- 随时夭折
