# FRenamer Radare2 plugin

Function renamer plugin for [Radare2](https://github.com/radareorg/radare2).

The plugin rename analysed functions with a random sequence of two words. The transformation is deterministic, based on the function adress.  
Three artifacts are added at the end of the function name. First a letter that gives a hint on the function size.
- s for functions with less than 100 instructions
- m for functions with 100 to 500 instructions
- l for functions with more than 500 instructions
Then the number of time the function is referenced. And Finaly the number of call instruction in the function.  
This plugin can generate up to 46,200 different names (adjective_noun), and more if the length artifact and the reference numbers are different.  
Two functions cannot have the same name. If two functions appears to have the same name, length artifact and references numbers the plugin will refuse to rename the function and notify you.  

The plugin has been written and tested under Ubuntu 18.04.4 LTS.

## Build and Installation

This section describes a local build and installation of frenamer Radare2 plugin.

### Requirements

* A compiler supporting c++17
* CMake (version >= 3.6)
* Existing Radare2 installation (version >= 4.2.0)

### Process

* Clone the repository:
  * `git clone https://github.com/NatanTALON/frenamer-r2plugin.git`
* Linux and MacOS:
  * `cd frenamer-r2plugin`
  * `mkdir build && cd build`
  * `cmake .. -DCMAKE_INSTALL_PREFIX=<path>`
  * `make -jN` (`N` is the number of processes to use for parallel build, typically number of cores + 1 gives fastest compilation time)
  * `make install`

You have to pass the following parameters to `cmake`:
* `-DCMAKE_INSTALL_PREFIX=<path>` to set the installation path to `<path>`. It is important to set the `<path>` to a location where Radare2 can load plugins from (for example `~/.local`).

## How to use

This plugin runs on the analysis done by r2. Launch r2, load the program you want to analyse and analyse it (`aa` command).  
You can now rename all unamed function using the command `frnm`.  
If you prefer to rename only a specific function, you can use `frnma <addr>`. This command works on every function (not only the unamed ones).
