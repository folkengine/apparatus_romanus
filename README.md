# APPARATVS ROMANVS

Implementation of a Roman Numeral Calculator. Depends on the the [Check unit testing framework](https://libcheck.github.io/check/).

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

    $> ./apparatus XI IX
       SVMMA: XX

One can add more than one number together.

    $> ./apparatus VI IX LX
       SVMMA: LXXV

For subtraction:

    $> ./apparatus -s XI IX
           SVMMA: II

One can subtract more than one number from the initial number.

    $> ./apparatus -s XXX I IV X
           SVMMA: XV

## A note on forms

The apparatus supports Alternative forms of Roman Numerals as described in [Wikipedia](https://en.wikipedia.org/wiki/Roman_numerals#Alternative_forms):

> The "standard" forms described above reflect typical modern usage rather than a universally 
> accepted convention. Usage in ancient Rome varied greatly and remained inconsistent in 
> medieval and modern times.
>
> Roman inscriptions, especially in official contexts, seem to show a preference for additive 
> forms such as IIII and VIIII instead of (or even as well as) subtractive forms such as IV and 
> IX. Both methods appear in documents from the Roman era, even within the same document. 
> "Double subtractives" also occur, such as XIIX or even IIXX instead of XVIII. Sometimes V and 
> L are not used, with instances such as IIIIII and XXXXXX rather than VI or LX.

Chris Baker <ignatz@gmail.com>

# SPQR
