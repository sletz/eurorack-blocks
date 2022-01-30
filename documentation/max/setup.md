# Setting up the Environment

## Requirements

Make sure you have the following requirements before starting:

- A [GitHub account](https://github.com/join)
- [`git`](https://git-scm.com/download)
- [Python 3](https://www.python.org/downloads/)
- [Homebrew](https://brew.sh) on macOS X
- [Xcode](https://developer.apple.com/xcode/) on macOS X
- [Max](https://cycling74.com/products/max)

You then only need minimum knowledge on how the terminal works to get going.


## Cloning

First, clone the repository. This will create a `eurorack-blocks` directory **into the current working directory**, with all dependencies.


```shell-session
~$ git clone --recurse-submodules git@github.com:ohmtech-rdi/eurorack-blocks.git
~$ cd eurorack-blocks
~/eurorack-blocks$
```


## Setting up

Install by running the script below:

```shell-session
~/eurorack-blocks$ ./build-system/install.py
```

This will add the `erbb` script to your `PATH`.

```shell-session
~/eurorack-blocks$ erbb setup
```

This will install all the needed dependencies. You would typically re-run this command when
upgrading `eurorack-blocks`.

In particular, this will install VCV Rack and Kicad. Don't worry if you already have installed those
applications! The setup script won't overwrite your installation.

You can now start to use `eurorack-blocks`  with Max 🎉


## Testing a Sample

Let's test a sample. We'll use the Max sample.

```shell-session
~/eurorack-blocks$ cd samples/max
~/eurorack-blocks/samples/max$ erbb configure
```

If you inspect the `max` folder, it now contains an `artifacts` directory, with a lot of files.

```{image} setup-configure.png
:width: 100%
:align: center
```

## Building in Xcode

If you are using Xcode, a `project_vcvrack.xcodeproj` has been created,
which is the project to use to develop and test in the VCV Rack simulator.

This will open the project in Xcode:

```shell-session
~/eurorack-blocks/samples/max$ open artifacts/project_vcvrack.xcodeproj
```

```{image} setup-xcode.png
:width: 100%
:align: center
```

Press {guilabel}`⌘B` to build.

The build process will output the VCV Rack module in the `Rack/plugins-v1` folder.

## Building from the command line

Alternatively, you can build the VCV Rack module using the command line.

```shell-session
~/eurorack-blocks/samples/max$ erbb build simulator
Build settings from command line:
    SYMROOT = /Users/raf/dev/eurorack-blocks/samples/max/artifacts/build
...
** BUILD SUCCEEDED **
```

The build process will output the VCV Rack module in the `Rack/plugins-v1` folder.

## Testing in VCV Rack

Now run VCV Rack, and the `Max` module will appear in the library when right-clicking
in the rack empty space.

```{image} setup-rack.png
:width: 100%
:align: center
```

```{important}
Before starting to play with it, make sure to setup your audio device,
and set the sample rate to 48kHz!
This requirement will be explained later in the tutorial.
```

```{image} setup-rack-audio.png
:align: center
```
