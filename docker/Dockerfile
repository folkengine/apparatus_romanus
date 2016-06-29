FROM ubuntu:14.04

RUN apt-get update && apt-get install -y \
    build-essential \
    autoconf \
    libtool \
    libreadline6 \
    libreadline6-dev \
    check \
    git \
    nano \
    pkg-config

RUN git clone https://github.com/folkengine/apparatus_romanus.git /tmp

CMD ["/bin/bash"]
