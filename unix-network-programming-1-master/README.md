# Unix Network Programming V1 Source Code #

This is a folk of [source code](http://unpbook.com/src.html) in
book
_UNIX Network Programming Volume 1: The Sockets Networking API, Thrid Edition_
with some bug fixing due to the change of Unix(-like) and gcc

Test on Debian

## Usage ##

clone this repo

```bash
git clone https://github.com/TylerTemp/unix-network-programming-1.git
```

and see the `README` file for compiling

You may also need some build tools

```bash
sudo apt-get install build-essential
```

```bash
cd unix-network-programming-1
./configure
sudo cp if_dl.h /usr/include/net
sudo chmod +r /usr/include/net/if_dl.h
cd lib
make
cd ../libfree
make
cd ../libgai
make
cd ../libroute  # this might fail. But doesn't matter
make
cd ..
sudo cp libunp.a /usr/lib
sudo cp libunp.a /usr/lib32
sudo cp lib_unp_mod.h /usr/include/unp.h
```

## Test ##

```bash
$ cd intro
$ make daytimetcpsrv
$ make daytimetcpcli
$ sudo ./daytimetcpsrv  &  # remember this number
[1] 804  
$ ./daytimetcpcli 127.0.0.1
Fri Aug 12 02:09:07 2016
$ sudo kill 804  # use the number above
[1]  + 804 exit 143   sudo ./daytimetcpsrv
```

## Diff ##

`inet_ntop.c`, line 44: `size_t` -> `socklen_t`

`inet_ntop.c`, line 45: `size_t` -> `socklen_t`

`inet_ntop.c`, line 60: `size_t` -> `socklen_t`

`inet_ntop.c`, line 89: `size_t` -> `socklen_t`

`inet_ntop.c`, line 113: `size_t` -> `socklen_t`

`libroute/unproute.h`, line 11: insert `#define RTAX_MAX 1024`

new file: `if_dl.h`, `lib_unp_mod.h`
