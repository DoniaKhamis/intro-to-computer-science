# Homework 6: Exploding Universes (2D Arrays)

## 📝 Description
This project implements a cellular automaton simulation called "Exploding Universes." The "world" is represented by a 2D grid where each cell (universe) can be New ('N'), Blowing up ('B'), or Dead ('D').

In each generation, the state of the universe changes based on specific rules:
* New universes near blowing-up ones begin to blow up.
* Blowing-up universes with few neighbors become dead.
* Dead universes are eventually reborn as new.

## 🧠 Concepts Applied
* Dynamic memory allocation for 2D matrices (`malloc` and `free`)
* Matrix traversal and neighbor-checking logic (8-neighbor proximity)
* Generation-based state simulation
* Error handling for memory and input failures
