# ↩️ clsMyString — Undo / Redo String Class (C++)

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)
![Type](https://img.shields.io/badge/Type-Header--Only%20Class-teal?style=flat-square)
![OOP](https://img.shields.io/badge/Paradigm-OOP-blueviolet?style=flat-square)
![Pattern](https://img.shields.io/badge/Pattern-Command%20%2F%20Memento-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)

A minimal C++ string wrapper class that implements **Undo / Redo** functionality using two stacks — the same pattern used inside text editors like VS Code, Notepad, and Word.

---

## 💡 The Idea

Every time you assign a new value to the string, the previous value is pushed onto an **Undo stack**. Calling `Undo()` restores the previous value and pushes the current one onto a **Redo stack** — so you can go forward and backward through the history freely.

```
Assign "Mohammed"  → Undo: [""]
Assign "Mohammed2" → Undo: ["", "Mohammed"]
Assign "Mohammed3" → Undo: ["", "Mohammed", "Mohammed2"]

Undo() → Value = "Mohammed2"  | Redo: ["Mohammed3"]
Undo() → Value = "Mohammed"   | Redo: ["Mohammed3", "Mohammed2"]
Undo() → Value = ""           | Redo: ["Mohammed3", "Mohammed2", "Mohammed"]

Redo() → Value = "Mohammed"   | Undo: ["", ...]
Redo() → Value = "Mohammed2"  | Undo: ["", "Mohammed", ...]
Redo() → Value = "Mohammed3"  | Undo restored fully
```

---

## 📸 Output Preview

```
                     Undo/Redo Project

S1 =
S1 = Mohammed
S1 = Mohammed2
S1 = Mohammed3


Undo :
------------------------

S1 After Undo = Mohammed2

S1 After Undo = Mohammed

S1 After Undo =


Redo :
------------------------

S1 After Redo = Mohammed

S1 After Redo = Mohammed2

S1 After Redo = Mohammed3
```

---

## 🗂️ Project Structure

```
clsMyString-UndoRedo/
│
├── clsMyString.h    # String class with Undo/Redo logic
├── main.cpp         # Demo usage
└── README.md        # Documentation
```

---

## 🧱 How It Works

The class maintains **three internal members**:

| Member | Type | Role |
|---|---|---|
| `_Value` | `string` | The current string value |
| `_Undo` | `stack<string>` | History of past values (go backward) |
| `_Redo` | `stack<string>` | History of undone values (go forward) |

### SetValue (via `Value` property)

```cpp
void SetValue(string Value) {
    _Undo.push(_Value);   // save current before overwriting
    _Value = Value;
    // Note: assigning a new value clears Redo history in full editors
}
```

### Undo

```cpp
void Undo() {
    if (!_Undo.empty()) {
        _Redo.push(_Value);      // save current so we can Redo
        _Value = _Undo.top();    // restore previous
        _Undo.pop();
    }
}
```

### Redo

```cpp
void Redo() {
    if (!_Redo.empty()) {
        _Undo.push(_Value);      // save current so we can Undo again
        _Value = _Redo.top();    // restore the undone value
        _Redo.pop();
    }
}
```

---

## 🧠 Design Pattern

This implements two classic patterns:

**Memento Pattern** — the state (string value) is saved before each change, allowing restoration without exposing internal structure.

**Command Pattern** — each assignment is treated as a reversible command, stored in a stack for sequential undo/redo traversal.

This is the exact same mechanism behind:
- Text editors (VS Code, Notepad++, Word)
- Image editors (Photoshop `Ctrl+Z`)
- IDEs (undo refactoring)
- Databases (transaction rollback logs)

---

## 🚀 Getting Started

### Compile & Run

```bash
g++ main.cpp -o UndoRedo
./UndoRedo
```

**Or in Visual Studio:** Add both files → `Ctrl + F5`

### Use in Your Project

```cpp
#include "clsMyString.h"

clsMyString s;

s.Value = "Hello";
s.Value = "Hello World";
s.Value = "Hello World!";

s.Undo();   // "Hello World"
s.Undo();   // "Hello"
s.Redo();   // "Hello World"
```

---

## 📊 Complexity

| Operation | Time | Space |
|---|---|---|
| Assign new value | O(1) | O(1) per push |
| `Undo()` | O(1) | O(1) per push |
| `Redo()` | O(1) | O(1) per push |
| Total history space | — | O(n) — n = number of assignments |

Every operation is **O(1)** — stacks give constant-time push/pop/top.

---

## 🔮 Possible Improvements

- [ ] Clear `_Redo` stack when a **new value is assigned after an undo** (standard editor behavior)
- [ ] Add `UndoAll()` / `RedoAll()` to jump to start/end of history
- [ ] Add `HistorySize()` to query how many steps are stored
- [ ] Add a **max history limit** to cap memory usage
- [ ] Template the class → `clsMyType<T>` to support Undo/Redo on any data type

---

## 👨‍💻 Author

> Built with ❤️ as part of a C++ OOP & Data Structures learning journey.

Feel free to fork, star ⭐, or contribute!

---

## 📄 License

This project is licensed under the **MIT License** — free to use and modify.
