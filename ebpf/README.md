# Execve

### Prerequisites
- Linux kernel version 5.7 or later, for bpf_link support
- LLVM 11 or later (clang and llvm-strip)
    - Use `clang --version` to check which version of LLVM you have installed. Refer to your distribution's package index to finding the right packages to install, as this tends to vary wildly across distributions. Some distributions ship `clang` and `llvm-strip` in separate packages.
- libbpf headers
    - For Debian/Ubuntu, you'll typically need `libbpf-dev`. On Fedora, it's `libbpf-devel`.
- Linux kernel headers
    - On AMD64 Debian/Ubuntu, install `linux-headers-amd64`. On Fedora, install `kernel-devel`. <br>
        On Debian, you may also need `ln -sf /usr/include/asm-generic/ /usr/include/asm` since the example expects to find `<asm/types.h>`.
- Go compiler version supported by ebpf-go's Go module

### My setup on MacOS M1 chip.
For creating a linux virtual machine I'm using [Lima](https://github.com/lima-vm/lima) with default Ubuntu configuration and then ssh from Visual Studio Code.
#### Steps
1. `brew install lima`
2. `limactl start` choose `Proceed with the current configuration` <br>
    Virtual machine will be created, by default Ubuntu<br>
    To connect from terminal to VM just run `lima`. <br>
    To stop VM `limactl stop`. <br>
    More info [here](https://lima-vm.io/docs/usage/).
3. To connect Visual Studio Code or other IDE, add ssh config found at `$HOME/.lima/default/ssh.config`. Atention VS Code will user your host git.
4. Install ***clang*** and ***llvm***.
    1. `sudo apt install llvm`
    2. `sudo apt install clang`
5. Install ***libbpf headers***
    1. `sudo apt install libbpf-dev`
6. Install Linux kernel headers.
    1. `sudo apt-get install linux-headers-$(uname -r)`
    2. `sudo ln -sf /usr/include/asm-generic/ /usr/include/asm`
7. Install ***go***
    1. `wget https://go.dev/dl/go1.22.3.linux-arm64.tar.gz` or other version
    2. run as ***root*** `rm -rf /usr/local/go && tar -C /usr/local -xzf go1.22.3.linux-arm64.tar.gz`
    3. add `/usr/local/go/bin` to your path by adding `export PATH=$PATH:/usr/local/go/bin` to `$HOME/.profile`
    2. More info about install steps [here](https://go.dev/doc/install).

### Building and running
#### Streps
1. enter to `go` folder
2. run `go generate`
3. `go build -o execve_ebpf`
4. `sudo ./execve_ebpf`
5. `Ctrl-C` to exit.

### Reference
1. [Edge Delta - An Applied Introduction to eBPF with Go](https://edgedelta.com/company/blog/applied-introduction-ebpf-go)
2. [celium/ebpf - Documentation](https://ebpf-go.dev/guides/getting-started/)
3. [celium/ebpf - examples/ringbuffer](https://github.com/cilium/ebpf/tree/main/examples/ringbuffer)