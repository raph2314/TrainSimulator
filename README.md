# TrainSimulator
Simulation of a train signalling system written in primarily in C++. 

### Built With
- [CMake](https://cmake.org/)
- [ncurses](https://linux.die.net/man/3/ncurses)

## Getting Started
Follow the steps below to get a clone of the repo and to begin simulating train traffic flow!

### Prerequisites
The only requirement to build this library is CMake. You can verify if you already have it installed as follows.  
`cmake --version`  

If you don't have it already installed, you can download the source distribution [here](cmake.org/download). Once extracted, simply run the following commands inside the directory:
```
./bootstrap
make
make install
```
  
### Installation
1. Clone the repo  
`git clone https://github.com/raph2314/TrainSimulator.git`
2. Following steps coming soon...

### Usage
Upon running the TrainSimulator executable, you will be prompted with the following message:  
```
Enter track below
```  
To configure the track, the following components are available:
1. Track (`-`)
2. Junction (`=`)
3. Green Signal (`o`)
4. Red Signal (`x`)
5. Train (`T`)

A simple example of a track system with junctions is shown below:
```
---=---=---\
\
   -----
```
The first backslash command (`\`) indicates that the current lane is terminated. This would normally indicate that a new lane should be branched from the last junction. However, a second backslash is used, to indicate that the most recent junction should be skipped. 



