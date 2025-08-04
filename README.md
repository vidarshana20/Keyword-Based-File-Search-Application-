
# 🔍 Local File Search Engine (C++ + Tcl/Tk GUI)

A lightweight desktop search utility that scans local `.txt` files for keyword matches using a fast C++ backend and displays results via a responsive Tcl/Tk GUI.

### 🚀 Features
- ✅ Case-insensitive keyword search using C++ logic
- 📁 Grouped results by file name for clean display
- 🎯 Keyword highlighting in results using Tcl/Tk tags
- 🖼️ GUI built with `wish` (Tcl/Tk windowing shell)
- 🧹 Includes clear button and user-friendly layout

---

## 🗂️ Project Structure

```
MiniSearchEngine/
├── search_engine.cpp      # C++ backend logic (no filesystem dependency)
├── search_engine.exe      # Compiled executable (built via g++)
├── interface.tcl          # Tcl/Tk GUI with highlighting and control buttons
├── data/                  # Folder containing .txt files to search
│   ├── file1.txt
│   └── file2.txt
```

---

## ⚙️ How It Works

- The GUI (interface.tcl) takes user input (a keyword)
- It uses `exec` to call `search_engine.exe` and pass the keyword
- The C++ program scans all text files in `data/` using a hardcoded file list
- Matching lines (case-insensitive) are printed with file name shown once
- GUI highlights all keyword matches and displays results

---

## 💻 Setup Instructions

### 1. Prerequisites
- Windows machine
- [MinGW](https://osdn.net/projects/mingw/) (G++ compiler)
- [ActiveTcl](https://www.activestate.com/products/tcl/) (Tcl/Tk runtime)

### 2. Compile the C++ backend
```sh
cd /d D:\MiniSearchEngine
g++ -o search_engine.exe search_engine.cpp
```

### 3. Run the GUI
```sh
wish interface.tcl
```

> Note: Use `wish`, not `tclsh`, since this project uses GUI components.

---

## 🧪 Test Example

Sample contents of `file2.txt`:
```
This is a TEST file.
Another line with test in it.
```

Run the GUI and search for `test`. You'll get:
```
[data/file2.txt]
  This is a TEST file.
  Another line with test in it.
```

---

## 💡 Key Learning Highlights

- Integrated C++ search logic with a GUI through command execution
- Handled case-insensitive string search and result formatting
- Used Tcl/Tk text tags to dynamically highlight keywords
- GUI includes font styling, word wrapping, and command buttons

---

## 🔧 Future Work

- [ ] Add scrollbars to result box
- [ ] Let user select folder path dynamically
- [ ] Export results to a text file
- [ ] Package into a `.bat` or `.exe` launcher

---

## 📄 License

Free for educational and personal use.
