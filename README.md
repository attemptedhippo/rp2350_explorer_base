I'm a beginner programmer, this is probably not the best code.

---

This is a bare minimum working codebase for the pimoroni explorer. NOT to be confused with the pico explorer. (learned the hard way) Only basic printing to the screen and usb serial debug console have been tested. I don't know why but the include directives for the import.cmake files in my CMakeLists only work with absolute paths, otherwise cmake can't find the files.

The included flash.sh must be run with sudo. You should read and understand the script before running. It can be run from anywhere as the script cds itself back to its own directory before running, don't forget to make the script executable. ` chmod +x `

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
I cobbled together an explorer header from the pimoroni micropython github repo into my pico-sdk so I could find the correct pins.
You can also use ` -DPICO_BOARD=pico2 `

```sh
mkdir build
cd build
cmake -DPICO_BOARD=explorer ..
make -j8    # number of build jobs, set equal to the number of cpu cores you have
sudo ../flash.sh
```
