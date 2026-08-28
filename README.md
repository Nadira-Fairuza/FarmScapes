# FarmScape 🌾

**FarmScape** is a 2D farming and ranching simulation game built in **C** using the **iGraphics** framework. Grow crops, raise livestock, manage resources, and sell goods in town to build your agricultural empire.

<img width="795" height="597" alt="image" src="https://github.com/user-attachments/assets/5280e980-f41b-4edc-a051-14e3aea0fc3d" />

<img width="789" height="597" alt="image" src="https://github.com/user-attachments/assets/99293994-8a16-48a6-b90b-201950134cf9" />

<img width="806" height="602" alt="787760314_1084271547323854_2017972907693148324_n" src="https://github.com/user-attachments/assets/88cc8be0-70d3-4ad0-9776-1357fc0f2246" />

<img width="798" height="601" alt="image" src="https://github.com/user-attachments/assets/1a8134ff-9ed0-4ecf-a89d-0c5083ba0d4d" />

## 🎮 Game Features

* **Town Center:** Travel between different areas and access farming and ranching levels.
* **Level 1 — Farming:** Plant **Rice** and **Tomatoes**, manage crop growth cycles, harvest crops, and sell produce.
* **Level 2 — Ranching:** Buy and care for **Hens**, **Cows**, and **Sheep**. Feed animals, collect **Eggs**, **Milk**, and **Wool**, and manage livestock lifecycles.
* **In-Game Economy:** Earn Gold by harvesting crops and collecting animal produce. Spend Gold on seeds, feed, and new animals through the Ranch Market.
* **Interactive Gameplay:** Use mouse controls and keyboard shortcuts to navigate between game states and interact with the farm.

## 🛠️ Project Structure

```text
├── bitmap_loader.h      # Loads 2D sprites and textures
├── animalgrowth.h       # Animal growth logic and state definitions
├── drawlevel1.h         # Level 1 farming rendering routines
├── drawlevel2.h         # Level 2 ranch rendering routines
├── drawTown.h           # Town center UI rendering
├── updatecropgrowth.h   # Crop timer and growth management
├── loading.h            # Loading screen graphics
└── main.c               # Main loop, event handling, and game state machine
```

## 🕹️ Controls & Navigation

### Mouse Controls

* **UI Navigation:** Click on-screen buttons to open menus, switch levels, or return to Town.
* **Ranch Market:** Click the market button (`mx: 430–530, my: 552–586`) to open or close the market.

  * **Sell Produce:** Sell Eggs, Milk, and Wool for Gold.
  * **Buy Supplies:** Purchase Animal Feed, Hens, Cows, and Sheep.
* **Tool Selection:**

  * **Feed Tool (1):** Feed ranch animals.
  * **Collect Tool (2):** Collect animal produce.

### Keyboard Shortcuts

| Key | Game State         |
| --- | ------------------ |
| `1` | Menu               |
| `2` | Loading            |
| `3` | Town               |
| `4` | Level 1 — Farming  |
| `5` | Level 2 — Ranching |
| `6` | Settings           |

## 💰 In-Game Economy

| Category          | Item         | Buy Price | Sell Price |
| ----------------- | ------------ | --------: | ---------: |
| Crops             | Rice         |        $5 |        $10 |
| Crops             | Tomato       |       $15 |        $20 |
| Supplies          | Feed         |        $5 |          — |
| Animals / Produce | Hen / Egg    |       $30 |        $15 |
| Animals / Produce | Cow / Milk   |      $100 |        $30 |
| Animals / Produce | Sheep / Wool |       $70 |        $45 |

## 🚀 Building & Running

### Prerequisites

* **Windows OS**
* **Visual Studio** with C/C++ Desktop Development tools, or another C/C++ compiler with Win32 API support
* **OpenGL / GLUT** runtime required by iGraphics

### Setup

1. Clone or download the repository.
2. Open the project in **Visual Studio**.
3. Make sure the required libraries are linked:

   * `winmm.lib`
   * `opengl32.lib`
   * `glu32.lib`
4. Build the project in **x86 / Win32** mode.
5. Run the game.

## 🌱 Gameplay Loop

```text
Town
  ↓
Choose Farming or Ranching
  ↓
Manage Crops / Livestock
  ↓
Harvest / Collect Produce
  ↓
Sell Goods for Gold
  ↓
Buy Seeds / Feed / Animals
  ↓
Expand Your Farm
```

## 🎯 Objective

Build a successful agricultural empire by efficiently managing your crops, livestock, resources, and Gold. Grow your farm, take care of your animals, and become the ultimate farmer in **FarmScape**.
Happy farming!!

## 📜 License

This project was created as a game development project using the **iGraphics** framework.

