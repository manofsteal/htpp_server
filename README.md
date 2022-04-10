# htpp_server
Simple http server for the interview


## Feature suppported
    * handle at least 100000 concurrent connections.
    * serve at least 100000 request per second on modern machine
    * serve a simple one pages for demo.

## Tested on Macbook air 2020 16G RAM, 256 SSD, docker image: ubuntu 18.04

## Build
``` 
git clone https://github.com/manofsteal/htpp_server.git
cd htpp_server
mkdir build && cd build 
make -j8

```

## Test
    * use https://github.com/wg/wrk
### setup
``` 
git clone https://github.com/wg/wrk
cd wrk
make -j8

```

### run

server: 
```
cd ...http_server/build
./http_server > /dev/null 2>&1

```

test tool: 
```
cd ...wrk

./wrk -t10 -c10000 -d60s http://0.0.0.0:8080/

```
