# FRenamer Radare2 plugin

Function renamer plugin for [Radare2](https://github.com/radareorg/radare2).

The plugin rename analysed functions with a random sequence of two words. The transformation is deterministic, based on the function adress.  
Three artifacts are added at the end of the function name. First a letter that gives a hint on the function size.
- s for functions with less than 100 instructions
- m for functions with 100 to 500 instructions
- l for functions with more than 500 instructions
Then the number of time the function is referenced. And Finaly the number of call instruction in the function.

The plugin has been written and tested under Ubuntu 18.04.4 LTS.

## Build and Installation

This section describes a local build and installation of frenamer Radare2 plugin.

### Requirements

* A compiler supporting c++17
* CMake (version >= 3.6)
* Existing Radare2 installation (version >= 4.2.0)

### Process

* Clone the repository:
  * `git clone https://github.com/avast/retdec-r2plugin`
* Linux and MacOS:
  * `cd retdec-r2plugin`
  * `mkdir build && cd build`
  * `cmake .. -DCMAKE_INSTALL_PREFIX=<path>`
  * `make -jN` (`N` is the number of processes to use for parallel build, typically number of cores + 1 gives fastest compilation time)
  * `make install`

You have to pass the following parameters to `cmake`:
* `-DCMAKE_INSTALL_PREFIX=<path>` to set the installation path to `<path>`. It is important to set the `<path>` to a location where Radare2 can load plugins from (for example `~/.local`).