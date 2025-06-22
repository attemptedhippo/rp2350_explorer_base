Hey! This repo is provided as is, I offer no warranty or any of that other stuff.
I'm a very beginner hobbiest coder and I barely have any clue what I'm doing. Good Luck!

---

This is a bare minimum working codebase for the pimoroni explorer. NOT to be confused with the pico explorer. (learned the hard way after many hours of hair pulling) Only basic printing to the screen and usb serial debug console have been tested. Also, I don't know why but the include directives for the import.cmake files in my CMakeLists only work with absolute paths, otherwise cmake can't find the files, you'll have to change this to point to yours.

The included flash.sh must be run with sudo. You should REALLY read and understand the script before running. It can be run from anywhere as the script cds itself back to its own directory before running, don't forget to use ` chmod +x ` first! (not to be confused with -x because that removes the executable flag, also learned after an unreasonable amount of hair pulling) Obviously this assumes you're on linux and the directories line up with mine.

The directory structure for the project and libraries is as follows:
```
> workspace
|
|-> pico-sdk
|
|-> pimoroni    #sdk
|
|-> {Project}
  |
  |-> build
```

---

### to build:
I mangled(copied) the explorer header from the micropython github repo into my pico-sdk so I could get some of the correct pins.
You could just use ` -DPICO_BOARD=pico2 ` otherwise follow these steps:

```sh
mkdir build
cd build
cmake -DPICO_BOARD=explorer ..
make -j8    # number of build jobs, set equal to the number of cpu cores you have
sudo ../flash.sh
```

the only reason this isn't a script is out of violent laziness.
