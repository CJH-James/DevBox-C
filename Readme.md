## Build this project

The docker files can help you setup the build environment, please check the `docker_envir`

```shell
### CMake 3.13+ ###
# Create the build scripts and store into the target folder "build"
cmake -S . -B build
# Compile the project in the target folder "build"
cmake --build build/
# The final compiled files -> [build/output/]


### Before CMake 3.13 ###
mkdir build
cd build
cmake ..
make

```
## Project Folder Structure

- Repository Folder

  | **_Folder_** | **_Description_**                               |
  |--------------|-------------------------------------------------|
  | docker_envir | The docker files for creating build environment |
  | include      | The library files                               |
  | src          | The application files                           |

- CMake Build Folder
  | **_Folder_** | **_Description_**                               |
  |--------------|-------------------------------------------------|
  | CMakeFiles   | Stores essential files for CMake’s operations   |
  | include      | Build-related files for library                 |
  | src          | Build-related files for application             |
  | output       | Final compiled files (include executables and libraries)|


- Example
  ```shell
  ├── build
  │   ├── CMakeFiles
  │   ├── include
  │   ├── src
  │   └── output
  │       ├── hello_dynamic
  │       ├── hello_static
  │       └── lib
  │           ├── dynamic
  │           │   ├── libbasic.so
  │           │   └── liblog.so
  │           └── static
  │               ├── libbasic.a
  │               └── liblog.a
  ├── docker_envir
  ├── include
  │   ├── basic
  │   └── log
  ├── src
  │   └── helloWorld
  └── tools
  ```
