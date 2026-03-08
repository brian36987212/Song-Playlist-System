# Song Playlist System 🎵

> 以 C 語言實作的命令列歌曲播放清單管理系統

A command-line song playlist management system implemented in C, featuring full CRUD operations, favorite list management, and CSV-based persistent storage.

---

## 📌 Project Overview

This project was developed as a C programming course assignment. It implements a complete song management system from scratch using two different data structure approaches, demonstrating the practical difference between array-based and linked-list-based implementations.

---

## 🗂️ Files

| File | Description |
|---|---|
| `SongPlayer 3.c` | Main implementation using **Linked List** |
| `team.c` | Alternative implementation using **Array** |
| `songlist.csv` | Main song database |
| `new-songlist.csv` | Updated song list |
| `favorite-songlist.csv` | Saved favorite songs |

---

## ✨ Features

- ➕ **Add** — Add a new song (name, singer, duration)
- ❌ **Delete** — Remove a song by name or singer
- ✏️ **Modify** — Update existing song information
- 🔍 **Search** — Search songs by singer name
- 📋 **Show All** — Display all songs in the playlist
- 🔀 **Random** — Randomly pick a song to play
- ❤️ **Favorite List** — Add songs to / view personal favorite playlist
- 💾 **Persistent Storage** — All data read from and written to `.csv` files

---

## 🛠️ Tech Stack

- **Language**: C (Standard C)
- **Data Structures**: Linked List (`SongPlayer 3.c`) / Array (`team.c`)
- **Storage**: CSV file I/O (`fopen`, `fscanf`, `fprintf`)
- **Compiler**: GCC

---

## 🚀 How to Build & Run

```bash
# Compile
gcc "SongPlayer 3.c" -o SongPlayer

# Run
./SongPlayer
```

Make sure `songlist.csv` is in the same directory as the executable.

---

## 📊 Data Structure Comparison

| | `team.c` | `SongPlayer 3.c` |
|---|---|---|
| Structure | Array | Singly Linked List |
| Insert | O(1) append | O(1) head insert |
| Delete | O(n) shift | O(n) traverse |
| Memory | Fixed size | Dynamic allocation |
