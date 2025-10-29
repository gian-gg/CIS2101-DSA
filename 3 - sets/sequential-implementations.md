# 📘 Sets — Sequential Implementations (Array, Linked List, Cursor-Based)

**Sequential implementations** of sets use **linear data structures** to store elements. The **logic remains identical** across array, linked list, and cursor-based approaches — only the **underlying storage mechanism** differs.

---

## 🧩 Overview

**Concept:**

- **Array-based:** Elements stored in a contiguous block of memory with a `count` tracker.
- **Linked list-based:** Elements stored as nodes connected via pointers.
- **Cursor-based:** Simulates linked lists using array indices instead of pointers.

**Key Difference:**

- **Ordered:** Elements maintain a sorted order → enables optimized operations.
- **Unordered:** Elements stored in insertion order → simpler insertion logic.

---

## 🧠 Key Terms

| Term             | Meaning                                           |
| ---------------- | ------------------------------------------------- |
| **SET**          | Collection of unique elements (no duplicates)     |
| **count**        | Number of elements currently in the set           |
| **MAX**          | Maximum capacity of the set                       |
| **member**       | Function to check if an element exists in the set |
| **Union**        | Combines all elements from two sets               |
| **Intersection** | Returns elements common to both sets              |
| **Difference**   | Returns elements in A but not in B (A - B)        |

---

## ⚙️ Core Functions

### `init(SET* S)`

```c
void init(SET* S) {
    S->count = 0;
}
```

- Initializes the set to **empty** by setting `count` to 0.
- In linked list implementations, sets the head to `NULL`.

---

### `insertElem(SET* S, int elem)`

```c
void insertElem(SET* S, int elem) {
    if (!isFull(*S) && member(*S, elem) == -1) {
        S->array[(S->count)++] = elem;
    }
}
```

**Unordered version:**

- Checks if set is not full and element doesn't exist.
- Appends element to the end and increments `count`.

**Ordered version:**

- Finds the correct position to maintain sorted order.
- Shifts elements if necessary before insertion.

---

### `deleteElem(SET* S, int elem)`

```c
void deleteElem(SET* S, int elem) {
    int index = member(*S, elem);

    if (!isEmpty(*S) && index != -1) {
        S->array[index] = S->array[(S->count) - 1];
        (S->count)--;
    }
}
```

**Unordered version:**

- Overwrites the element with the **last element** in the set.
- Decrements `count` (O(1) deletion).

**Ordered version:**

- Shifts all subsequent elements left to maintain order.
- Decrements `count` (O(n) deletion).

---

### `member(SET S, int elem)`

```c
int member(SET S, int elem) {
    int trav;
    for(trav = 0; trav < S.count && S.array[trav] != elem; trav++) {}

    return (trav < S.count) ? trav : -1;
}
```

**Unordered version:**

- Linear search through all elements.
- Returns **index** if found, otherwise **-1**.

**Ordered version:**

- Can use **binary search** for O(log n) lookup.
- Stops early if current element exceeds target (optimization).

---

### `equal(SET A, SET B)`

**Unordered version:**

```c
bool equal(SET A, SET B) {
    if (A.count != B.count) return false;

    for (int i = 0; i < A.count; i++) {
        if (member(B, A.array[i]) == -1) {
            return false;
        }
    }
    return true;
}
```

- Checks if counts match.
- Verifies every element in A exists in B.

**Ordered version:**

```c
bool equal(SET A, SET B) {
    if (A.count != B.count) return false;

    for(int i = 0; i < A.count && A.array[i] == B.array[i]; i++) {}

    return (i == A.count);
}
```

- Since both sets are sorted, direct **element-by-element comparison** works.
- More efficient than unordered version.

---

## 🔀 Set Operations

### `Union(SET A, SET B)`

**Unordered version:**

```c
SET Union(SET A, SET B) {
    SET C;
    init(&C);

    // Copy all elements from A
    for (int i = 0; i < A.count; i++) {
        C.array[C.count++] = A.array[i];
    }

    // Add elements from B that aren't in A
    for (int i = 0; i < B.count; i++) {
        if (member(A, B.array[i]) == -1) {
            C.array[C.count++] = B.array[i];
        }
    }

    return C;
}
```

**Ordered version:**

```c
SET Union(SET A, SET B) {
    SET C;
    init(&C);

    int travA = 0, travB = 0;

    while (travA < A.count && travB < B.count) {
        if (A.array[travA] < B.array[travB]) {
            C.array[C.count++] = A.array[travA++];
        } else if (A.array[travA] > B.array[travB]) {
            C.array[C.count++] = B.array[travB++];
        } else {
            C.array[C.count++] = A.array[travA];
            travA++;
            travB++;
        }
    }

    while (travA < A.count) C.array[C.count++] = A.array[travA++];
    while (travB < B.count) C.array[C.count++] = B.array[travB++];

    return C;
}
```

- **Ordered:** Uses **merge-like technique** → O(n + m).
- **Unordered:** Checks membership for each element → O(n × m).

---

### `Intersection(SET A, SET B)`

**Unordered version:**

```c
SET Intersection(SET A, SET B) {
    SET C;
    init(&C);

    for (int i = 0; i < A.count; i++) {
        if (member(B, A.array[i]) != -1) {
            C.array[C.count++] = A.array[i];
        }
    }

    return C;
}
```

- Iterates through A and adds elements that also exist in B.

**Ordered version:**

- Uses two-pointer technique similar to ordered union.
- Only adds when both pointers point to the **same element**.

---

### `Difference(SET A, SET B)`

**Unordered version:**

```c
SET Difference(SET A, SET B) {
    SET C;
    init(&C);

    for (int i = 0; i < A.count; i++) {
        if (member(B, A.array[i]) == -1) {
            C.array[C.count++] = A.array[i];
        }
    }

    return C;
}
```

- Returns elements in **A** that are **not** in **B**.

**Ordered version:**

- Uses two-pointer technique.
- Advances through A, adding elements not found in B.

---

## ⏱️ Time Complexities

### Unordered Implementation

| Operation        | Time Complexity |
| ---------------- | --------------- |
| **insert**       | O(n)            |
| **delete**       | O(n)            |
| **member**       | O(n)            |
| **Union**        | O(n × m)        |
| **Intersection** | O(n × m)        |
| **Difference**   | O(n × m)        |

### Ordered Implementation

| Operation        | Time Complexity  |
| ---------------- | ---------------- |
| **insert**       | O(n)             |
| **delete**       | O(n)             |
| **member**       | O(log n) or O(n) |
| **Union**        | O(n + m)         |
| **Intersection** | O(n + m)         |
| **Difference**   | O(n + m)         |

> **Note:** Ordered implementations have **better set operation performance** but **same insertion/deletion complexity** due to shifting.

---

## 📊 Implementation Comparison

| Aspect              | Array               | Linked List        | Cursor-Based       |
| ------------------- | ------------------- | ------------------ | ------------------ |
| **Memory**          | Fixed size (MAX)    | Dynamic (per node) | Fixed array        |
| **Access**          | Direct (O(1))       | Sequential (O(n))  | Array-based (O(1)) |
| **Insertion**       | May need shifting   | No shifting needed | Index manipulation |
| **Memory overhead** | Low (just elements) | High (pointers)    | Medium (indices)   |
| **Cache locality**  | Excellent           | Poor               | Good               |

---

## ✅ Summary

- **Sequential implementations** (array, linked list, cursor) share the same **set logic**.
- **Ordered** variants optimize set operations via merge techniques.
- **Unordered** variants simplify insertion but slow down set operations.
- Choice depends on:
  - Frequency of **insertions/deletions** vs **set operations**.
  - Memory constraints.
  - Need for **dynamic sizing**.
