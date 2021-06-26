From ubuntu:latest
ARG DEBIAN_FRONTEND=noninteractive
WORKDIR /root
RUN apt-get update \
    && apt-get -y upgrade \
    && apt-get -y install curl gnupg sudo git vim tmux pip \
    && apt-get -y install build-essential cmake gdb cppcheck\
    && curl -sL https://deb.nodesource.com/setup_13.x | sudo -E bash - \
    && apt-get -y install nodejs \
    && npm install -g leetcode-tools/leetcode-cli \
    && pip install cpplint \
    && cd /root \
    && git clone https://github.com/MingRuey/dotfiles \
    && bash /root/dotfiles/install.sh \
    && git clone https://github.com/google/googletest.git -b release-1.11.0 \
    && cd googletest \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && make install 

COPY cookie.txt /root/cookie.txt
