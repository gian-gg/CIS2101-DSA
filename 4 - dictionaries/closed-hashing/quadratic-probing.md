# 📘 Closed Hashing (Quadratic Probing) — Notes

**Quadratic probing** is a type of **closed hashing (open addressing)** technique used to resolve collisions.
Instead of checking the **next** slot linearly (as in linear probing), it probes in **quadratic steps** to reduce clustering.

---

## 🧩 Overview

**Concept:**
When a collision occurs at hash index `h`, the next index is calculated using:

```
(h + i²) % MAX, where i = 0, 1, 2, 3, ...
```

This spreads out probes more evenly than linear probing, helping to minimize **primary clustering**.

---

## 🧠 Key Concepts and Terminology

| Symbol / Term | Meaning                                     |
| ------------- | ------------------------------------------- |
| `EMPTY`       | Slot has never been used                    |
| `DELETED`     | Slot was used but item removed              |
| `OCCUPIED`    | Slot currently holds a valid key-value pair |
| `hv`          | Home address (hash value)                   |
| `MAX`         | Maximum table size                          |
| `i`           | Probe number (used for quadratic offset)    |

---

## ⚙️ Functions and Explanations

### `mode()`

```c
void mode() {
    printf("DICT - CLOSED HASHING (QUADRATIC PROBING)\n\n");
}
```

Displays the dictionary mode being used — in this case, **Closed Hashing with Quadratic Probing**.

---

### `hash(int key)`

```c
int hash(int key) {
    return abs(key) % MAX;
}
```

* **Purpose:** Generates the base (home) index for a given key.
* Uses modulo operation to ensure the index is within table bounds.
* **Formula:**
  `hv = |key| % MAX`

---

### `init(DICT D)`

```c
void init(DICT D) {
    for (int i = 0; i < MAX; i++) {
        D[i].key = EMPTY;
        strcpy(D[i].value, "");
    }
}
```

* Initializes the hash table to empty:

  * All slots have key = `EMPTY`.
  * Value strings are cleared (`""`).

---

### `insertElem(DICT D, int key, char* value)`

```c
void insertElem(DICT D, int key, char* value) {
    int hv = hash(key);

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == key) return; // Duplicate key
        if (D[pos].key == EMPTY || D[pos].key == DELETED) {
            D[pos].key = key;
            strcpy(D[pos].value, value);
            return;
        }
    }

    printf("Insertion failed: Table is full.\n");
}
```

#### 🧮 How It Works:

1. Compute the **home address** (`hv`).
2. Use **quadratic probing** to find an available slot:

   * Probe sequence:
     `hv, (hv + 1²) % MAX, (hv + 2²) % MAX, ...`
3. Insert key-value pair when an `EMPTY` or `DELETED` slot is found.
4. If all slots are checked and none is available → **Table is full**.

---

### `deleteElem(DICT D, int key)`

```c
void deleteElem(DICT D, int key) {
    int hv = hash(key);

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == EMPTY) return; // Key not found
        if (D[pos].key == key) {
            D[pos].key = DELETED;
            strcpy(D[pos].value, "");
            return;
        }
    }
}
```

#### 🧮 How It Works:

* Probes using quadratic offsets until it:

  * Finds the target key → marks slot as `DELETED`
  * Reaches an `EMPTY` slot → key not found, stop searching

---

### `member(DICT D, int key)`

```c
bool member(DICT D, int key) {
    int hv = hash(key);

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == EMPTY) return false;
        if (D[pos].key == key) return true;
    }

    return false;
}
```

#### 🧮 How It Works:

* Checks if a given key exists in the table.
* Returns:

  * `true` → key found
  * `false` → reached an `EMPTY` slot or end of table without match

---

### `getValue(DICT D, int key)`

```c
char* getValue(DICT D, int key) {
    int hv = hash(key);

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == EMPTY) break;
        if (D[pos].key == key) return D[pos].value;
    }

    return "\0";
}
```

#### 🧮 How It Works:

* Uses the same probing formula `(hv + i²) % MAX` to search.
* Returns:

  * Value of the key if found
  * Null string (`"\0"`) if not found

---

### `visualize(DICT D)`

```c
void visualize(DICT D) {
    for (int i = 0; i < MAX; i++) {
        printf("[ %d ] ", i);
        if (D[i].key == EMPTY)
            printf("[EMP]\n");
        else if (D[i].key == DELETED)
            printf("[DEL]\n");
        else
            printf("{ %d: \"%s\" }\n", D[i].key, D[i].value);
    }
    printf("\n");
}
```

* Displays each slot’s state in the hash table:

  * `[EMP]` → Empty
  * `[DEL]` → Deleted
  * `{ key: "value" }` → Occupied

---

### `display(DICT D)`

```c
void display(DICT D) {
    printf("[");
    for (int i = 0; i < MAX; i++) {
        if (D[i].key != EMPTY && D[i].key != DELETED)
            printf("\n   { %d: \"%s\"},", D[i].key, D[i].value);
    }
    printf("\n]\n");
}
```

* Displays only valid (non-empty, non-deleted) entries in a clean format.

---

## ⏱️ Time Complexities

| Operation     | Best Case | Average Case | Worst Case |
| ------------- | --------- | ------------ | ---------- |
| **Insertion** | O(1)      | O(1) – O(n)  | O(n)       |
| **Search**    | O(1)      | O(1) – O(n)  | O(n)       |
| **Deletion**  | O(1)      | O(1) – O(n)  | O(n)       |

> ⏳ Efficiency depends on the **load factor (α)**.
> Quadratic probing reduces clustering compared to linear probing, improving average performance.

---

## 🧮 Example of Quadratic Probing

Assume:

```
MAX = 7
Keys to insert: 23, 44, 68, 92
```

| Key | Hash Value (`key % 7`) | Probe Sequence (`(hv + i²) % 7`) | Insertion Position |
| --- | ---------------------- | -------------------------------- | ------------------ |
| 23  | 2                      | 2                                | 2                  |
| 44  | 2                      | 2 → 3 → 6 → 4                    | 3                  |
| 68  | 5                      | 5                                | 5                  |
| 92  | 1                      | 1                                | 1                  |

---

## ✅ Summary

* Quadratic probing resolves collisions by **jumping in quadratic steps**.
* Formula:
  `new_index = (hash(key) + i²) % MAX`
* Prevents **primary clustering** but can still suffer from **secondary clustering**.
* Requires careful table size selection (preferably prime) to ensure full table coverage.
