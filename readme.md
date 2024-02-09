# Completing and Submitting this Assignment
## Project 1 Changes to Quiz Template
This template provides 2 executables, Main and Tests. Main will run your main.cpp file as it is, while Tests will run Catch tests on your test.cpp and ignore your main.cpp file.

Depending on your editor, you may need to modify the `add_executable()` sections in the CMakeLists.txt file as you add header files that you reference in main. An example is provided within the file. This should be done automatically in CLion.

Choosing the executable differs depending on the editor that you are using. In Clion (and potentially Visual Studio), you should be able to click the dropdown next to the Run button and choose Main or Tests. In VSCode, you should click on the CMake tab in the sidebar, and under Launch, click the edit button to select Main to run your AVL tree.

Please reach out on Slack if you have any questions, and the guide will be updated accordingly.

### Running Main/Tests

#### VSCode/Codespace
To run main, first enter the CMake tab on the left and select Main as your launch target:
![vscode target selection](.github-images/VSCode/select_main.png)

Then to run your main by itself without any tests, click the play button on the bottom of your VSCode window:
![vscode run main](.github-images/VSCode/run_main.png)

To run your tests, navigate to the testing tab as normal, and click the relevant run tests button:
![vscode run tests](.github-images/VSCode/run_tests.png)

#### CLion
Make sure to comment out the lines at the bottom of `CMakeLists.txt` or you will have *a lot* of possible targets. To select whether to run your main or tests, click the dropdown at the top of the window  and select your desired executable:
![clion select target](.github-images/CLion/run_clion.png)


## Video Tutorial
<!-- Setting up embed: -->
<!-- https://ardalis.com/how-to-embed-youtube-video-in-github-readme-markdown/ -->
[![Thumbnail for tutorial video](https://img.youtube.com/vi/R8-glh-Twh4/maxresdefault.jpg)](https://www.youtube.com/watch?v=R8-glh-Twh4)

## Which method should I choose?

Method 1 will have you set up with a working programming environment the quickest, and requires no set up on your computer by using cloud containers. You are limited to using VSCode, however, and there is a limit to the amount of time you can spend programming with it, although you are unlikely to run into it. Still, it enables you to work on your project anywhere and on any device, so long as you have a web browser.

Method 2 takes a bit more work as you might have to install some dependencies, but it enables you to use CLion (which tends to have better C++-specific features) in addition to a local VSCode instance with your preferred settings and extensions. If you want to work on your project on multiple devices, however, you need to make sure to sync your project with Git.

Method 3 is the simplest - it will work with any editor and on any computer so long as you have g++ installed, but you miss out on GUI integration as you have to run your tests and builds from the command line.

## Method 1: Github Codespaces (Easiest)
Provided with this Github page is a Codespaces template that allows you to develop, compile, debug, and test this programming quiz from the cloud, either in your browser or through VSCode on your desktop. It includes a provided installation of Catch2 so that you do not need to install any additional software or libraries to start working. 

To get started, simply click "Use this template" in the top right of the GitHub window, and then select the "Create a new repository" option to make a personal (private!) copy of the template to work in. From there, click the green "Code" button, then click the "Codespaces" tab, and then "Create codespace on main". This will then generate your very own Codespace to work with which operates much the same as VSCode. 

From here, you can either work in your browser, or open your Codespace through VSCode on your desktop and use any extra themes, settings, or extensions you might have installed.

**IMPORTANT: Watch the video if you have trouble running your tests! You must run your tests through the testing tab or CMake tab for VSCode to recognize Catch, *not* the play button in the top right of the editing window!**
See [this link](https://youtu.be/R8-glh-Twh4) for a video tutorial of the above and more detail on using the development environment in case you are unfamiliar with VSCode and CMake.

Note that you get 120 "core hours" per month by default, and 180 with a GitHub Premium account, included with the free [GitHub Student Developer Pack](https://education.github.com/pack). "Core hours" are calculated by multiplying the number of CPU cores in your virtual by the actual number of hours you use the software for. So, with the (perfectly sufficient) 2-core default, you get 60/90 hours of actual use, which should be plenty for this course. 

In the case that you do run out of hours or you simply no longer wish to use Codespaces, as long as you've been regularly committing to your GitHub repo, you can simply clone your work to your local machine and work on it the regular way, detailed below.

## Method 2: Local Development Environment
This is the "regular" way to work on programming quizzes and projects, and lets you use any IDE of your choosing, like CLion (my personal favorite). However, it depends on your local environment having all of the required packages and libraries, namely Git. Instructions are provided below, and you are welcome to ask any TA for help in setting up your computer, but if for whatever reason you are absolutely unable to get the toolchain set up, you should fall back on the Codespaces option, which is guaranteed to work.

Catch2 is automatically pulled in to your project by our CMakeLists.txt configuration, and should require no extra work on your part (given that you have git installed and working).

<!-- ### Installing Catch2 -->
<!-- The provided CMakeLists.txt build file assumes that you are using Catch2 v3, which has much improved testing speeds over the previous versions. Instructions for installing the library system-wide are provided below, partially adapted from [Catch2's documentation](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md). -->

<!-- #### Windows (Currently Untested) -->
<!-- You can use the vcpkg package manager to install the library systemwide. Install instructions for vcpkg are provided [here](docs/cmake-integration.md), but in short, run the following commands from within your project directory: -->

<!-- ```cmd -->
<!-- > git clone https://github.com/microsoft/vcpkg -->
<!-- > .\vcpkg\bootstrap-vcpkg.bat -->
<!-- > .\vcpkg\vcpkg install catch2:x64-windows -->
<!-- ``` -->

<!-- This *should* make Catch2 avaiable to use within your project, but note that I do not have a Windows device to test this on. See the CMake install method below if this doesn't work. -->

<!-- #### MacOS (Also Untested) -->
<!-- Catch2 is available from [homebrew](https://brew.sh/), so making Catch2 available should be as simple as  -->

<!-- ```sh -->
<!-- brew install catch2 -->
<!-- ``` -->

<!-- , given that you have homebrew already installed and set up. -->

<!-- #### Linux -->
<!-- If available, you can install Catch2 with your distro's package manager, although it is likely to be fairly to extremely out of date. If the version is lower than 3, you should install from source like so (make sure you have cmake installed): -->

<!-- ```sh -->
<!-- #catch2 local install source: https://github.com/catchorg/Catch2/issues/1383#issuecomment-421548807 -->
<!-- cd -->
<!-- git clone https://github.com/catchorg/Catch2.git -->
<!-- cd Catch2 -->

<!-- #note that catch needs to be compiled against C++17, see here: https://stackoverflow.com/questions/66227246/catch2-undefined-reference-to-catchstringmaker -->
<!-- cmake -Bbuild -H. -DBUILD_TESTING=OFF -DCMAKE_CXX_STANDARD=17 -->
<!-- sudo cmake --build build/ --target install  -->
<!-- ``` -->

<!-- #### Platform-Independent CMake method -->
<!-- This method requires using CMake features to pull Catch2 in from GitHub and attach it to your project. This method involves changing the provided CMakeLists.txt file. A detailed written and video guide is available [here](https://github.com/COP3530/catch-with-cmake), but note that it is written with Project 1 in mind, so you'll have to translate some of the CMake content to the quiz setup instead.  -->

<!-- This method is more or less guaranteed to work, but takes some time to set up, and you may run into issues along the way. Treat this as a last resort if you can't get any of the easier methods above working for you.  -->

### IDE/Editor Setup

#### CLion
CLion works with Catch2 out of the box and as such requires no extra set up in your environment. Make sure your CLion is as up to date as possible, however, as there have been issues with older versions of CLion and newer versions of Catch 2.

At the bottom of the CMakeLists.txt file are some extra lines of setup code to integrate testing in VSCode. 

```cmake
include(CTest)
include(Catch)
catch_discover_tests(Tests) # must be named the same as your test executable
```

In case they cause issues with CLion, simply comment them out and reload your CMake configuration. 

See [here](https://github.com/COP3530/catch-with-cmake#part-3-integrating-with-clion) for more detail.

#### VSCode
Make sure that you have the following extensions installed on your VSCode.

- C/C++ (Microsoft)
- C/C++ Extension Pack (Microsoft)
- CMake Tools (Microsoft)
- CMake Language Support (either twxs or Jose Torres)

You must also install CMake itself to your system. CLion bundles a version of CMake with itself so this step is unnecessary if on CLion. Note that the version you install may be older that what CLion would package - if you get an error in your CMakeLists.txt about your CMake being too old, simply change this line

``` cmake
cmake_minimum_required(VERSION 3.24)
```

to have whichever version of CMake that you have installed.

Beyond this setup, the editing/testing process should be the same as outlined in the Codespaces tutorial video. More details are avaiable [here](https://github.com/COP3530/catch-with-cmake#part-3-alternate-integrating-with-vscode), although note that the suggested edits to the CMakeLists.txt file are already present in the template.

#### Visual Studio
This template has also been confirmed working with Visual Studio. Make sure you have the **Desktop Development with C++** "workload" installed ([guide](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170)). Choose the Tests.exe executable from the Run button, and it should pop open a command prompt window with your test results after compiling. Currently I haven't gotten it to integrate with the testing UI yet - if you figure this out, please reach out!

You may run into an error where it says the /Werror flag is unrecognized. If this is the case, remove the `-Werror` flag from line 7 of CMakeLists.txt, like so:
```cmake
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
# becomes
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
```

## Method 3: Commandline Testing (Simplest)

In test/test.cpp, replace the line at the top that reads `#include <catch2/catch_test_macros.hpp>` with this line:
```cpp
#include "catch/catch_amalgamated.hpp"
```

Also change the include for `interquartile_range.h` with a relative path, like so:
```cpp
#include "../src/interquartile_range.h"
```

Run this command once from your project directory:
```sh
g++ -std=c++14 -Werror -Wuninitialized -g -c test/catch/catch_amalgamated.cpp -o build/catch_amalgamated.o
```

Next, run these commands to build and view your tests:
```sh
g++ -std=c++14 -Werror -Wuninitialized -g build/catch_amalgamated.o test/test.cpp -o build/test
./build/test
```
If you make any changes to your files, you can run the last two commands again.
You do not need to run the first command again.

