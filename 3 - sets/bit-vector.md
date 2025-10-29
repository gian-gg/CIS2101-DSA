# 📘 Sets — Bit Vector Implementation

**Bit vector** is a highly efficient set implementation where each **bit** represents the **presence (1)** or **absence (0)** of an element at that index position.

---

## 🧩 Overview

**Concept:**

- The set is represented as an **array of integers** (or booleans).
- Each index `i` corresponds to element `i`.
- `S[i] = 1` → element `i` is **in** the set.
- `S[i] = 0` → element `i` is **not in** the set.

**Limitation:**

- Only works for sets with a **small, known universe** (e.g., 0 to MAX-1).
- Not suitable for sparse sets or large universes.

---

## 🧠 Key Terms

| Term        | Meaning                                          |
| ----------- | ------------------------------------------------ |
| **SET**     | Array of integers where each index is a bit flag |
| **MAX**     | Size of the universe (maximum element value + 1) |
| **Bit = 1** | Element is present in the set                    |
| **Bit = 0** | Element is absent from the set                   |

---

## ⚙️ Core Functions

### `init(SET S)`

```c
void init(SET S) {
    for(int i = 0; i < MAX; i++) {
        S[i] = 0;
    }
}
```

- Initializes all bits to **0** (empty set).
- Sets every index to "not present".

---

### `insertElem(SET S, int elem)`

```c
void insertElem(SET S, int elem) {
    S[elem] = 1;
}
```

- **O(1) operation** — directly sets the bit at index `elem` to `1`.
- No searching or shifting required.

---

### `deleteElem(SET S, int elem)`

```c
void deleteElem(SET S, int elem) {
    S[elem] = 0;
}
```

- **O(1) operation** — directly sets the bit at index `elem` to `0`.

---

### `member(SET S, int elem)`

```c
bool member(SET S, int elem) {
    return (S[elem]);
}
```

- **O(1) membership check** — directly returns the boolean value at `elem`.
- Fastest possible membership test.

---

### `read(SET S)`

```c
void read(SET S) {
    printf("{ ");
    for(int i = 0; i < MAX; i++) {
        if (S[i]) printf("%d, ", i);
    }
    printf("}\n");
}
```

- Iterates through the entire bit vector.
- Prints indices where the bit is set to `1`.

---

### `isEmpty(SET S)`

```c
bool isEmpty(SET S) {
    int i;
    for(i = 0; i < MAX && S[i] == 0; i++) {}

    return (i == MAX);
}
```

- Returns `true` if **all bits are 0**.
- Searches for the first `1` — if none found, set is empty.

---

### `isFull(SET S)`

```c
bool isFull(SET S) {
    int i;
    for(i = 0; i < MAX && S[i] != 0; i++) {}

    return (i == MAX);
}
```

- Returns `true` if **all bits are 1**.
- Searches for the first `0` — if none found, set is full.

---

### `equal(SET A, SET B)`

```c
bool equal(SET A, SET B) {
    int i;
    for(i = 0; i < MAX && A[i] == B[i]; i++) {}

    return (i == MAX);
}
```

- Compares sets **bit by bit**.
- If all bits match, sets are equal.

---

## 🔀 Set Operations

### `Union(SET A, SET B)`

```c
SET* Union(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));

    if (C != NULL) {
        init(*C);

        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] || B[i];
        }
    }

    return C;
}
```

- **Bitwise OR** operation.
- Result has `1` if the bit is in **A**, **B**, or **both**.
- **O(MAX)** time complexity.

---

### `Intersection(SET A, SET B)`

```c
SET* Intersection(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));

    if (C != NULL) {
        init(*C);

        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] && B[i];
        }
    }

    return C;
}
```

- **Bitwise AND** operation.
- Result has `1` only if the bit is in **both A and B**.
- **O(MAX)** time complexity.

---

### `Difference(SET A, SET B)`

```c
SET* Difference(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));

    if (C != NULL) {
        init(*C);

        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] && !(B[i]);
        }
    }

    return C;
}
```

- **A AND (NOT B)** operation.
- Result has `1` only if the bit is in **A** but **not in B**.
- **O(MAX)** time complexity.

---

## ⏱️ Time Complexities

| Operation        | Time Complexity |
| ---------------- | --------------- |
| **insert**       | O(1)            |
| **delete**       | O(1)            |
| **member**       | O(1)            |
| **Union**        | O(MAX)          |
| **Intersection** | O(MAX)          |
| **Difference**   | O(MAX)          |
| **isEmpty**      | O(MAX)          |
| **isFull**       | O(MAX)          |
| **equal**        | O(MAX)          |

> **Note:** Set operations are **independent of the number of elements** — they always iterate through MAX positions.

---

## 🧮 Example

Suppose `MAX = 8` and we want to represent sets:

```
A = {1, 3, 5}
B = {1, 2, 5, 6}
```

**Bit vector representation:**

```
Index:  0  1  2  3  4  5  6  7
A:      0  1  0  1  0  1  0  0
B:      0  1  1  0  0  1  1  0
```

**Union (A | B):**

```
C:      0  1  1  1  0  1  1  0  →  {1, 2, 3, 5, 6}
```

**Intersection (A & B):**

```
C:      0  1  0  0  0  1  0  0  →  {1, 5}
```

**Difference (A - B):**

```
C:      0  0  0  1  0  0  0  0  →  {3}
```

---

## ✅ Summary

- **Bit vector** is ideal for sets with a **small, dense universe**.
- Provides **O(1)** insertion, deletion, and membership testing.
- Set operations use **bitwise logic** for efficiency.
- **Drawback:** Wastes memory for sparse sets (many zeros).
- **Best use case:** Flags, permissions, state tracking with fixed, small domains.
