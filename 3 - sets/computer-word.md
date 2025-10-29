# 📘 Sets — Computer Word Implementation

**Computer word** implementation uses **bitwise operations** on a single integer (or `unsigned char`) to represent a set. Each **bit position** in the word corresponds to an element.

---

## 🧩 Overview

**Concept:**

- A set is represented as a **single integer** (e.g., `unsigned char`, `unsigned int`).
- Each bit position represents whether an element is in the set.
- Bit position `n` represents element `2^n` (or just index `n`).
- Uses **bit manipulation** (shifts, masks, AND, OR, NOT) for all operations.

**Advantage:**

- **Extremely compact** — single word stores multiple elements.
- **Very fast** — operations use CPU-level bitwise instructions.

**Limitation:**

- Maximum set size = number of bits in the data type.
- For `unsigned char`: max 8 elements (0-7).
- For `unsigned int`: max 32 elements (0-31).
- For `unsigned long long`: max 64 elements (0-63).

---

## 🧠 Key Terms

| Symbol / Term   | Meaning                                            |
| --------------- | -------------------------------------------------- |
| **SET**         | `unsigned char` (or other unsigned integer type)   |
| **BIT_MASK(x)** | `1 << x` — creates a mask with bit `x` set to 1    |
| **MAX_BITS**    | `sizeof(SET) * 8` — total number of bits available |
| **Bit = 1**     | Element is present in the set                      |
| **Bit = 0**     | Element is absent from the set                     |

---

## 🔧 Macro Definitions

```c
#define BIT_MASK(x) (1 << (x))
#define MAX_BITS (sizeof(SET) * 8)
```

- **`BIT_MASK(x)`** — shifts `1` left by `x` positions to create a mask.

  - Example: `BIT_MASK(3)` = `0000 1000` (binary) = 8 (decimal).

- **`MAX_BITS`** — calculates the total number of bits in the `SET` type.
  - For `unsigned char`: `1 * 8 = 8 bits`.

---

## ⚙️ Core Functions

### `init(SET* A)`

```c
void init(SET* A) {
    *A = 0;
}
```

- Sets all bits to **0** — creates an **empty set**.
- Single assignment operation → **O(1)**.

---

### `insertElem(SET* A, int data)`

```c
void insertElem(SET* A, int data) {
    if (data < MAX_BITS) *A |= (BIT_MASK(data));
}
```

**How it works:**

```
      data = 0
         A = 0110 0010
   mask(0) = 0000 0001
A | mask(0) = 0110 0011
```

- Uses **bitwise OR** to set bit at position `data` to `1`.
- **O(1)** operation.

---

### `deleteElem(SET* A, int data)`

```c
void deleteElem(SET* A, int data) {
    if (data < MAX_BITS) *A &= ~(BIT_MASK(data));
}
```

**How it works:**

```
   data = 2
mask(2) = 0000 0100
      A = 0110 0011
~mask(2)= 1111 1011
A & ~mask=0110 0011
```

- Uses **bitwise AND** with the **complement** of the mask.
- Sets bit at position `data` to `0`.
- **O(1)** operation.

---

### `member(SET A, int data)`

```c
bool member(SET A, int data) {
    if (data < MAX_BITS) {
        return ((A & BIT_MASK(data)) != 0) ? true : false;
    }
    return false;
}
```

**How it works:**

```
    data = 4
       A = 0110 0011
 mask(4) = 0001 0000
A & mask = 0000 0000 (not in set)
```

- Uses **bitwise AND** with the mask.
- If result is **non-zero**, element exists.
- **O(1)** operation.

---

### `read(SET A)`

```c
void read(SET A) {
    printf("{ ");
    for(int idx = 0; idx < MAX_BITS; idx++) {
        if ((A & BIT_MASK(idx)) != 0) printf("%d, ", idx);
    }
    printf("}\n");
}
```

- Iterates through all bit positions.
- Prints index `idx` if bit is set to `1`.
- **O(MAX_BITS)** time complexity.

---

### `equal(SET A, SET B)`

```c
bool equal(SET A, SET B) {
    return (A == B);
}
```

- **Single comparison** operation.
- Compares the entire integer value.
- **O(1)** operation.

---

## 🔀 Set Operations

### `Union(SET A, SET B)`

```c
SET Union(SET A, SET B) {
    return A | B;
}
```

**How it works:**

```
A = 0010 0101
B = 1101 0001
A | B = 1111 0101
```

- **Bitwise OR** combines all set bits from both sets.
- **O(1)** operation — single CPU instruction.

---

### `Intersection(SET A, SET B)`

```c
SET Intersection(SET A, SET B) {
    return A & B;
}
```

**How it works:**

```
A = 0010 0101
B = 1101 0001
A & B = 0000 0001
```

- **Bitwise AND** keeps only bits set in **both** sets.
- **O(1)** operation — single CPU instruction.

---

### `Difference(SET A, SET B)`

```c
SET Difference(SET A, SET B) {
    return A & ~B;
}
```

**How it works:**

```
B = 1101 0001
A = 0010 0101
~B = 0010 1110
A & ~B = 0010 0100
```

- **A AND (NOT B)** — keeps bits in A that are **not** in B.
- **O(1)** operation — two CPU instructions.

---

## ⏱️ Time Complexities

| Operation        | Time Complexity |
| ---------------- | --------------- |
| **insert**       | O(1)            |
| **delete**       | O(1)            |
| **member**       | O(1)            |
| **Union**        | O(1)            |
| **Intersection** | O(1)            |
| **Difference**   | O(1)            |
| **equal**        | O(1)            |
| **read**         | O(MAX_BITS)     |

> **Note:** All operations (except `read`) are **constant time** — this is the **fastest** set implementation possible.

---

## 🧮 Example

Using `unsigned char` (8 bits), represent sets:

```
A = {1, 2, 5}
B = {0, 1, 4, 5}
```

**Binary representation:**

```
Bit position:  7  6  5  4  3  2  1  0
A:             0  0  1  0  0  1  1  0  = 38 (decimal)
B:             0  0  1  1  0  0  1  1  = 51 (decimal)
```

**Union (A | B):**

```
Result:        0  0  1  1  0  1  1  1  = 55  →  {0, 1, 2, 4, 5}
```

**Intersection (A & B):**

```
Result:        0  0  1  0  0  0  1  0  = 34  →  {1, 5}
```

**Difference (A & ~B):**

```
~B:            1  1  0  0  1  1  0  0  = 204
Result:        0  0  0  0  0  1  0  0  = 4   →  {2}
```

---

## 💡 Extending to Larger Sets

For sets larger than the word size, use an **array of words**:

```c
#define WORD_SIZE 64
#define NUM_WORDS 4  // supports up to 256 elements

typedef unsigned long long WORD;
typedef WORD SET[NUM_WORDS];
```

Operations become:

```c
void insertElem(SET A, int elem) {
    int wordIndex = elem / WORD_SIZE;
    int bitIndex = elem % WORD_SIZE;
    A[wordIndex] |= (1ULL << bitIndex);
}
```

---

## ✅ Summary

- **Computer word** implementation uses **bitwise operations** on a single integer.
- Provides **O(1) time complexity** for all major operations.
- **Most efficient** set implementation when:
  - Universe size ≤ word size (8, 16, 32, 64 bits).
  - Operations are frequent.
  - Memory is extremely limited.
- **Best use case:** Flags, permissions, state machines, embedded systems.
- Can be extended to **multiple words** for larger universes.
