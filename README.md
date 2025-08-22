# DIVOC — Console Patient Registry (C)

DIVOC is a small, menu-driven console program to maintain a list of patients, search/discharge them, list by birth year, and flag likely positives based on symptoms. Data persists in a flat file (`patients.txt`) and is loaded into a singly-linked list in memory on startup.

---

## ✨ Features

- **Register** a patient (name, DNI, birth year, fever, cough, extra symptom) with input validation.
- **Search** by DNI and display patient data.
- **Discharge** (delete) a patient by DNI.
- **List** all patients born **on or before** a given year.
- **Mark “Positive”**: displays patients with fever + cough + an extra symptom.
- **Persist** to `patients.txt` when exiting.

---

## 🛠️ Architecture

- **Data structure:** singly-linked list (`struct unPaciente`).
- **File persistence:** flat text file (`patients.txt`).
- **I/O helpers:** validated inputs, Y/N prompts, symptom menu, Spanish DNI verification.

---

## 📂 File Overview

- `divoc.c` → main program (menu loop, startup/shutdown).
- `database.c/.h` → patient struct & linked-list operations (insert, search, delete, list, file I/O).
- `inout.c/.h` → input/output helpers (validated input, DNI check, menus).
- `patients.txt` → data file (sample provided).
- `makefile` → build script.

---

## 🚀 Build & Run

### Build
```bash
gcc -std=c11 -Wall -Wextra -O2 -o divoc divoc.c database.c inout.c
```

Or just run:
```bash
make
```

### Run
```bash
./divoc
```

On startup you’ll see:

```
R) Register a patient
S) Search for a patient
D) Discharge a patient
L) List patients by age
P) Mark Positive

X) Exit the program
```

---

## 📄 Data Format

Each line in `patients.txt` is:

```
<NAME> <DNI> <YEAR> <FEVER> <COUGH> <SYMPTOM>
```

Example:

```
Carlos 44689664C 2002 1 0 T
Maria 20774973Q 1973 0 1 T
```

- `FEVER` and `COUGH` → `0` or `1`
- `SYMPTOM` → one of the menu letters (`F S T M N`)

---

## 🔍 Input Validation

- **DNI**: must be 9 chars, with valid Spanish check letter.
- **Year**: between 1900 and 2020.
- **Symptoms**: selected from menu, must be valid.
- **Names**: up to 24 characters, no spaces.

