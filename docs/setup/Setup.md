 ## How to run project?

 **To setup and run project you must have to do some steps:**
 1. Unzip the appropriate version of the SFML library to `./lib/` directory.
 2. You need to install the cmake and gcc compiler if you don't have them installed.
 3. Run "cmake -DCMAKE_BUILD_TYPE=Release -G "CodeBlocks - Unix Makefiles" ." in directory with source code to generate cache.
 4. Run "cmake --build . --target Flash" in directory with source code to build target binary file.
 5. Move `data` and `config` to directory with target binary file. An archive with application data will be in release.
