# X-ray State Machine

## Building and Running Applications

### Building C++ CLI-Application

```
git clone https://github.com/hendrikboeck/XRay_State_Machine.git
cd XRay_State_Machine/cpp
mkdir build && cd build
cmake ..
make all
```

### Building C CLI-Application

```
git clone https://github.com/hendrikboeck/XRay_State_Machine.git
cd XRay_State_Machine/c
mkdir build && cd build
cmake ..
make all
```

### Running Python3 CLI-Application

```
git clone https://github.com/hendrikboeck/XRay_State_Machine.git
cd XRay_State_Machine/python3/src
python3 unittest.py
```

### Runnning P5.js Graphical-Application

Repository von Github klonen oder als .zip herunterladen.
```
git clone https://github.com/hendrikboeck/XRay_State_Machine.git
```
In den Ordner `p5_javascript` navigieren und die Datei `index.html` mit ihrem Webbrowser aufrufen.

## Overview

This Projects tries to emulate a very simplified version of a X-ray machine. The Software Engineering Pattern State is used for programming this machine.

### State diagram

![](.github/md/StateD_XRayMachine.png)

### Class diagram

![](.github/md/XRayMachine.png)
