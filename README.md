# IoT-Shield App

QT-App used for communicating with the SmartParkinglot example of the [IoT-Shield-Firmware].

## Features

* Display current state of the parking lot
* Simulate the fsm of the SmartParkinglot to compensate Thingspeak API limits
* Send `pay` and `start` commands to the parking lot

## Build

The project can be built using `qmake`. You can also use the QTCreator IDE.

```
$ qmake
$ make
```

[IoT-Shield-Firmware]: https://github.com/iotl/IoT-Shield-Firmware
