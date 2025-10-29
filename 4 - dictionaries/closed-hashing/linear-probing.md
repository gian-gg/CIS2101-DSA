# 📘 Closed Hashing (Linear Probing) — Notes

Closed hashing, also known as **open addressing**, stores all elements directly within the hash table itself.
When a **collision** occurs (two keys hash to the same index), **linear probing** is used to find the next available slot.

---

## 🧩 Overview

**Concept:**
In linear probing, if a collision occurs at position `i`, the algorithm searches for the next free position sequentially:

```
i, (i + 1) % MAX, (i + 2) % MAX, ...
```

until it finds an `EMPTY` or `DELETED` slot.

---

## 🧠 Key Terms

| Symbol / Value | Meaning                                      |
| -------------- | -------------------------------------------- |
| `EMPTY`        | Slot has never been used                     |
| `DELETED`      | Slot was previously occupied but now deleted |
| `OCCUPIED`     | Slot currently stores a valid key-value pair |
| `MAX`          | Size of the hash table                       |
| `hv`           | Home address (computed hash value)           |

---

## ⚙️ Functions and Explanations

### `mode()`

```c
void mode() {
    printf("DICT - CLOSED HASHING (LINEAR PROBING)\n\n");
}
```

* Displays the mode or type of hashing used.

---

### `hash(int key)`

```c
int hash(int key) {
    return abs(key) % MAX;
}
```

* **Purpose:** Computes the hash value (index) of the key.
* **Formula:** `hash = |key| % MAX`
* Ensures that all keys map to valid table indices.

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

* Initializes the hash table:

  * Every slot’s `key` is set to `EMPTY`.
  * Every slot’s `value` is set to an empty string.

---

### `insertElem(DICT D, int key, char* value)`

```c
void insertElem(DICT D, int key, char* value) {
    int hv = hash(key);
    int i = hv;
    int count = 0;

    for (i = hv, count = 0;
         count < MAX &&
         D[i].key != EMPTY &&
         D[i].key != DELETED &&
         D[i].key != key;
         i = (i + 1) % MAX, count++) {}

    if (count == MAX) return;  // Table is full
    if (D[i].key == key) return;  // Duplicate key

    D[i].key = key;
    strcpy(D[i].value, value);
}
```

**Steps in insertion:**

1. Compute the **hash value** (`hv`).
2. Probe sequentially until:

   * An `EMPTY` slot is found (available for insertion),
   * A `DELETED` slot is found (reusable), or
   * The same key is found (duplicate; skip).
3. If no slot found after checking all entries, the table is **full**.
4. Otherwise, insert the key-value pair in the available slot.

---

### `deleteElem(DICT D, int key)`

```c
void deleteElem(DICT D, int key) {
    int hv = hash(key);
    int i;

    for (i = hv;
         D[i].key != EMPTY && D[i].key != key;
         i = (i + 1) % MAX) {}

    if (D[i].key == key) {
        D[i].key = DELETED;
        strcpy(D[i].value, "");
    }
}
```

**Steps in deletion:**

1. Probe starting from the home address.
2. Continue probing until:

   * The key is found → mark it as `DELETED`.
   * An `EMPTY` slot is reached → key not found.

---

### `member(DICT D, int key)`

```c
bool member(DICT D, int key) {
    int hv = hash(key);
    int i;

    for (i = hv;
         D[i].key != EMPTY && D[i].key != key;
         i = (i + 1) % MAX) {}

    return (D[i].key == key);
}
```

**Purpose:** Checks whether a given key exists in the table.
**Returns:**

* `true` → key is found
* `false` → key not found (after reaching an `EMPTY` slot)

---

### `getValue(DICT D, int key)`

```c
char* getValue(DICT D, int key) {
    int hv = hash(key);
    int i;

    for (i = hv;
         D[i].key != EMPTY && D[i].key != key;
         i = (i + 1) % MAX) {}

    return (D[i].key == key) ? D[i].value : '\0';
}
```

**Purpose:** Retrieves the value corresponding to the given key.
**Returns:**

* Value string → if key found
* `'\0'` → if key not found

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

**Purpose:** Displays the current state of the hash table.
Shows whether each slot is:

* `EMPTY`
* `DELETED`
* `OCCUPIED` (displays key-value pair)

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

**Purpose:** Prints only **active key-value pairs**, excluding empty or deleted entries.

---

## ⏱️ Time Complexities

| Operation     | Best Case | Average Case                        | Worst Case |
| ------------- | --------- | ----------------------------------- | ---------- |
| **Insertion** | O(1)      | O(1) – O(n) (depends on clustering) | O(n)       |
| **Search**    | O(1)      | O(1) – O(n)                         | O(n)       |
| **Deletion**  | O(1)      | O(1) – O(n)                         | O(n)       |

> As the load factor (α = number of elements / table size) increases, **collisions** and **clustering** slow down performance.

---

## 🧮 Example of Linear Probing

Suppose:

```
MAX = 7
Keys to insert: 23, 44, 68, 92
```

| Key | Hash Value (`key % 7`) | Insertion Position         |
| --- | ---------------------- | -------------------------- |
| 23  | 2                      | 2                          |
| 44  | 2                      | 3 (collision → probe next) |
| 68  | 5                      | 5                          |
| 92  | 1                      | 1                          |

---

## ✅ Summary

* Closed hashing (linear probing) stores data directly in the hash table.
* Collisions are handled by **probing linearly** to find the next available slot.
* Deletion uses a special **DELETED** marker to maintain search continuity.
* Performance degrades as the table gets fuller (load factor ↑).
