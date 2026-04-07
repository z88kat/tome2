ToME is a [rogue-like](https://en.wikipedia.org/wiki/Roguelike) game.

![Screenshot](/doc/images/screenshot.png)

For help playing the game, see the [Player Guide](PLAYER_GUIDE.md).

## Getting Started

### Prerequisites

See below for specific distribution-specific hints, if needed.

You will need to have the following libraries installed on your system
somewhere where CMake can find them:

- [Boost](https://www.boost.org/)

Version requirements may vary somewhat, but usually you should be
aiming for having at least a **recent** version of the above libraries.

### Option 1: Running In-Place

**This is currently the recommended option**, but it means that you
don't 'install' ToME as such, you just run it from the build
directory.

To configure for your system, run

    $ cmake -B build
    $ cmake --build build

You should now be able to run one of the executables in ./build
to run ToME. For example, you'd run

    $ ./build/tome-x11

to start ToME with the X11 frontend.

**Important:** The current working directory must be at the root of
the source tree for the above command to run -- if it isn't, then
you'll get mysterious errors about ToME not being able to find files
(at best).


### Option 2: Installing System-Wide

To configure for your system, run

    $ cmake -DSYSTEM_INSTALL:BOOL=true .
    $ make
    $ sudo make install

You can now run ToME from anywhere and it will always use the files
installed in the system-specific location.


## Compiling on Ubuntu

To compile on an Ubuntu install, you'll need at least the 

- `cmake`
- `build-essential`
- `libboost-all-dev`

If the following are not installed, they'll be downloaded automatically:
- `libpcg-cpp-dev`
- `libjsoncons-dev`
- `libfmt-dev`

packages.

Note for package maintainers: `-DCPM_LOCAL_PACKAGES_ONLY=yes -DUSE_SYSTEM_PCG_RANDOM=yes` will avoid downloading deps automatically.
See [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) for more details.

Each frontend requires the additional packages listed below:

- X11: `libx11-dev`
- ncurses: `libncurses5-dev`


## Compiling on macOS

Install the required dependencies via [Homebrew](https://brew.sh/):

    $ brew install cmake boost

macOS does not ship X11, so the `tome-x11` frontend requires
[XQuartz](https://www.xquartz.org/). Install it with:

    $ brew install --cask xquartz

After installing XQuartz, **log out and back in** so that the `DISPLAY`
environment variable is set correctly.

The `tome-gcu` (ncurses) frontend uses the system ncurses, which is
present on macOS by default. No extra install is needed for it.

Once dependencies are in place, build normally:

    $ cmake -B build
    $ cmake --build build

CMake will automatically detect which frontends are available and build
only those. To check which executables were produced, list `./build/`.
Typically you will see `tome-gcu` (ncurses terminal) and, if XQuartz
is installed, `tome-x11`.

**Note:** The project requires a C++17-capable compiler. Apple Clang
(included with Xcode Command Line Tools) satisfies this. Install the
tools if needed:

    $ xcode-select --install


## Compiling on OpenBSD

As of February 2010, the OpenBSD package cmake-2.4.8p2 is too old for
building ToME. You may need to compile a newer version of CMake.

If you have X11, then a bug in CMake may cause a linker error when
linking the executable. As a workaround, set the environment variable
`LDFLAGS` when running CMake. Example:

    $ env LDFLAGS=-L/usr/X11R6/lib cmake -B build
    $ cmake --build build


## Compiling on Windows using MinGW

The source **MUST** be unpacked in a directory without spaces in the
name.

To configure and compile on Windows using MinGW, use the commands

    $ cmake -G "MinGW Makefiles"
    $ mingw32-make
