FROM ubuntu:24.04
ARG LLVM_VERSION=22
WORKDIR /tmp
# Install Packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    gnupg2 ca-certificates software-properties-common \
    cppcheck valgrind ccache cmake wget git nano jq \
    # required by Visual Studio
    gdb make ninja-build rsync zip sudo \
    # required by VCPKG
    openssh-server tar curl unzip pkg-config bash-completion aria2 mono-complete \
    # required by LLVM
    lsb-release zlib1g-dev \
    # shell
    zsh

RUN wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh ${LLVM_VERSION} all && \
    rm ./llvm.sh

# add llvm to path
ENV PATH="/usr/lib/llvm-${LLVM_VERSION}/bin:/usr/lib/llvm-${LLVM_VERSION}/include:${PATH}"
ENV LD_LIBRARY_PATH="/usr/lib/llvm-${LLVM_VERSION}/lib:${LD_LIBRARY_PATH}"

# unversionize the binaries
RUN ln -s /usr/bin/clang-${LLVM_VERSION} /usr/bin/clang && \
    ln -s /usr/bin/clang++-${LLVM_VERSION} /usr/bin/clang++ && \
    ln -s /usr/bin/clang-format-${LLVM_VERSION} /usr/bin/clang-format

# update compiler environment vars
ENV CC=/usr/bin/clang \
    CXX=/usr/bin/clang++

# update alternatives
RUN update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100 && \
    update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100


RUN apt-get update && apt-get install -y \
    git python3 python3-pip \
    gcc-avr binutils-avr avr-libc \
    gcc-arm-none-eabi \
    dfu-util dfu-programmer avrdude curl sudo\
    && rm -rf /var/lib/apt/lists/*

RUN echo "ALL ALL=(ALL:ALL) NOPASSWD: ALL" > /etc/sudoers
RUN wget https://github.com/raspberrypi/pico-sdk-tools/releases/download/v2.2.0-3/picotool-2.2.0-a4-x86_64-lin.tar.gz && \
    tar -xzf picotool-2.2.0-a4-x86_64-lin.tar.gz && \
    cp picotool/picotool /bin/ && \
    rm /tmp/picotool-2.2.0-a4-x86_64-lin.tar.gz && \
    rm -rf picotool
USER ubuntu
ENV USER=ubuntu
RUN curl -fsSL https://install.qmk.fm | bash
RUN echo -e "3\n" | ~/.local/bin/qmk setup
WORKDIR /workspaces
