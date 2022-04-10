# htpp_server
Simple http server


## Feature suppported
    * handle at least 100000 concurrent connections.
    * serve at least 100000 request per second on modern machine
    * serve a simple one pages for demo.


## Build
``` 
git clone 
mkdir build && cd build 
make

```

## Test
    * use https://github.com/wg/wrk
### setup
``` 
git clone https://github.com/wg/wrk
cd wrk
make

```

### run

server: 
```
./wrk -t10 -c10000 -d60s http://0.0.0.0:8080/

```