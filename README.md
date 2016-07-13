# APPARATVS ROMANVS

Implementation of the Roman Numeral Calculator. Depends on the the [Check unit testing framework](https://libcheck.github.io/check/).

## Installation

     $> make
     $> make test 

## Docker Container

 A [Dockerfile](https://www.docker.com/) has been included to facilitate running the appplication.

     $> cd docker
     $> docker build -t ubuntu-apparatus .
     $> docker run -it ubuntu-apparatus /bin/bash
		 $> cd /tmp

## Usage

For addition:

    $> apparatus XI IX
       SVMMA: XX

For subtraction:

    $> apparatus -s XI IX
           SVMMA: II

Chris Baker <ignatz@gmail.com>

# SPQR
