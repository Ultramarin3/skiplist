# Skiplist-CPP

 A tiny KV storage based on skiplist written in C++ language

# interface

* insertElement
* updateElement
* deleteElement 
* searchElement
* displayList
* dumpFile 
* loadFile
* getsize

# performance data  


skiplist tree high:20
Operate on random key 

|operation\data size | 10 (w)  | 50 (w)  | 100 (w)  |
|---|---|---|---|
|insert|0.202597 (s) |1.14734 (s) | 2.54344 (s) |
|get|0.282021 (s) |1.79126 (s) | 3.98568 (s) |
|update|0.206573 (s) |1.36355 (s) | 3.09395 (s) |
|delete|0.0851114 (s) |0.589379 (s) | 1.58232 (s) |

qps: 

insert : 41.1w
get    : 26.4W  
update : 34.3w
delete : 70.9w


# USAGE

Just include skiplist.h in your code

```
make            // complie demo main.cpp
./bin/main      // run 
```

Test performance data 

```
sh stress_test_start.sh 
```

# Reference

https://github.com/youngyangyang04/Skiplist-CPP

# License

This library is licensed under GPL-3.0 License. See LICENSE for details.
