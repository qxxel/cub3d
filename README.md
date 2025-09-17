# cub3d
![42 Project](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/C-0E7FC0?logo=c)

---

## 📌 Summary
- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Exemples](#exemples)
- [Directories structure](#directories-structure)
- [Author](#author)

---

<a id="about"></a>
## 📖 About

**cub3d** is a team project of 42 school.
It's a 3D game (2.5D), made with raytracing, inspired by the famous game named [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D).

---

<a id="features"></a>
## ✨ Features

✅ Raytracing  
✅ Take parameters in a file `.cub` given as argument like color of the sky and floor or walls textures
✅ Take and display a map given in the `.cub`  
✅ Player movements (WASD and directional arrows)  
✅ Collisions management  
✅ Minimap (on top left)
✅ Different sprites according to the direction of the wall

---

<a id="installation"></a>
## ⚙️ Installation

**1. Clone the repository**
```bash
git clone git@github.com:qxxel/cub3d.git;
cd cub3d
```

**2. Compile the project**
```bash
make
```

---

<a id="utilisation"></a>
## 🕹️ Utilisation

**1. Build your own map `.cub` or use those provited**

A valid map is closed, wich as many parameters given next to this paragraph.

The file il build like this:
- 1 = `wall`
- 0 = `floor`
- E, W, N, S = `player spawn looking to the direction (ex: S = south)`

Exemple of a map `.cub`:
```
NO ./assets/42.xpm
SO ./assets/42.xpm
WE ./assets/42.xpm
EA ./assets/42.xpm

F 0,0,255
C 0,255,0

11111111
1000001011
100010001
1111100001
    11111

```

**2. Lauch the program**

```bash
./cub3d [map.cub]
```

---

<a id="exemples"></a>
## 📸 Exemples

**Comming soon...**

![exemple1]()  
![exemple2]()  
![exemple3]()  

<a id="directories-structure"></a>
## 📂 Directories structure

```plaintext
📂 cub3d
 ┣ 📂 assets            → sprites
 ┣ 📂 include           → headers files (.h)
 ┣ 📂 libft             → my own C library
 ┣ 📂 maps              → test maps
 ┣ 📂 minilibx-linux    → linux graphical library (42 ressource)
 ┣ 📂 sources           → sources files (.c)
 ┣ Makefile
 ┣ README.md
 ┗ src.mk
```

<a id="author"></a>
## 👤 Author

* Axel – [GitHub](https://gitub.com/qxxel)
* 42 student - login: *agerbaud*