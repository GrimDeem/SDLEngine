# SDLEngine
Simple 2d game library based on SDL2 with a scene graph and event dispatching.

## Getting Started
Following instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites
To build the project you will need [CMake](https://cmake.org/) to be installed on your PC. Using cmake you can generate [makefiles](https://linux.die.net/man/1/make) for Unix or [Visual Studio](https://visualstudio.microsoft.com) project for Windows. So make sure that you have installed these as well.
 
Also, the project is using [SDL2 library](https://www.libsdl.org/index.php) and [gTest framework](https://github.com/google/googletest), but all required libs are already stored in External/ directory so no need to install them manually.

Also, it is highly recommended to have [Git Bash](https://git-scm.com/downloads) installed if you are using Windows because cmd is disgusting :)

Anyway, all steps are reproducible via cmd so its all up to you.

### Build the project
After cloning/unzipping the repo follow the steps below:

#### Unix/Linux
Change your directory to the project folder and create a build directory.
```
cd SDLEngine; mkdir build; cd build
```

generate makefiles...
```
cmake -G "Unix Makefiles" ../
```

... and finally build the project
```
make -j2
```

#### Windows
All steps below is done via Git Bash, but you can reproduce them using cmd.

Change your directory to the project folder and create a build directory.
```
cd SDLEngine; mkdir build; cd build
```

generate makefiles...
```
cmake -G "Visual Studio 15 2017" ../
```

Open the generated .sln Visual Studio solution file and build the project manually
