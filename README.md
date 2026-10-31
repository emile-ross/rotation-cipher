# rotation-cipher

This project converts a string from encoded text over to human readable text.

Supported platforms:

Linux, FreeBSD, OpenBSD, Windows


## building instructions 

### install build dependencies

dependencies: **git & make**

Arch Linux: 

(AUR package maybe one day)

``sudo pacman -S git base-devel``

Debian: 
``sudo apt-get install git build-essential ``

Fedora:
``sudo dnf install make git``

openSUSE:
``sudo zypper in make git``

### Download & compile

```sh
git clone https://github.com/emile-ross/rotation-cipher.git
cd rotation-cipher/
sudo make install
```


## configuring

The program works out of the box but configuration might help you use it faster or tailor the program to your needs.  

The configuration is in a header file (``src/config.h``) therefore, recompiling the program is needed in order to apply the changes.  


## Contributions:

Feel free to make pull requests even if you're not sure about what you've done.  




The project is licensed under the GPL-V2 license except for the src/base64.c source file
(BSD‑2‑Clause see src/base64.c)
