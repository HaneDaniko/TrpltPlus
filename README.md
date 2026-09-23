**Trplt beta now has already been released!**

# trplt Game Interactive Interface

An interactive game interface based on the Luogu problem [U498948 trplt](https://www.luogu.com.cn/problem/U498948).

## Introduction

This project turns Luogu problem U498948 — an "output-only" (submission-answer) problem — into a visualized, interactive game. In the original problem, you play as a tree that must wisely allocate **Nutrients** and **Sunlight** to grow roots, leaves, and fruits, and harvest enough ripe fruits within a given number of days.

This project faithfully recreates the original rules while adding a graphical interface and real-time feedback, letting players experience the problem in a more intuitive way.

## Game Rules

### Basic Setup

You are a tree that must survive for a number of days. Each day you have a certain amount of **Nutrients** and **Sunlight**, and you must spend these resources to take actions.

### Available Actions

| Action | Description |
|--------|-------------|
| Grow Roots | Spend resources, root size +1 |
| Grow Leaves | Spend resources, leaf count +1 (leaf count cannot exceed height) |
| Grow Fruit | Spend resources, fruit count +1 (fruit count, including ripe ones, cannot exceed height) |
| Ripen Fruit | Spend resources, choose one unripe fruit and make it ripe |
| Grow Taller | Spend resources, height +1 |
| Next Day | End the current day's actions |

### Resource Gain

- At the start of a new day, gain `1 + root size` Nutrients
- At the start of a new day, gain `1 + leaf count` Sunlight

### Survival Goal

By the end of day $i$, you must have harvested at least $a_i$ **ripe** fruits in total, or the game is lost.

## Features

- 🎮 Graphical interactive interface with a clear view of the tree's current state
- 📊 Real-time display of Nutrients, Sunlight, Roots, Leaves, Fruits, Height, and more
- ✅ Automatic validation of action legality (resource sufficiency, leaf/fruit not exceeding height, etc.)
- 📅 Day progress and daily goal indicators
- 🔄 Support for restarting and switching levels
- 🎯 Support for loading test data from the problem's attachment

## Getting Started

### How to Run

Simply run `trplt.exe` to start the game.

## Project Structure

```
.
├── trplt.exe       # Executable game
├── trplt.info      # Player's Game File
├── main.cpp        # Source Code
└── README.md       # Documentation
```

## License

This project is for learning and exchange purposes only. The problem's copyright belongs to its original author.
