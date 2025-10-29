# 📘 Open Hashing (Separate Chaining) — Notes

**Open hashing**, also known as **separate chaining**, is a collision-resolution technique where each index in the hash table stores a **linked list** (or chain) of elements that hash to the same index.

---

## 🧩 Overview

**Concept:**

* Each slot in the hash table points to a **linked list** of nodes.
* When two or more keys hash to the same index, they are **inserted into the same chain**.
* This avoids the need for probing or table resizing, unlike closed hashing.

---

## 🧠 Key Terms

| Term          | Meaning                                                            |
| ------------- | ------------------------------------------------------------------ |
| **Bucket**    | A linked list that stores all elements sharing the same hash index |
| **Collision** | Occurs when two keys hash to the same index                        |
| **Chain**     | The sequence of nodes connected through links within a bucket      |
| **MAX**       | The maximum size (number of buckets) in the hash table             |

---

## ⚙️ Functions and Explanations

### `mode()`

```c
void mode() {
    printf("DICT - OPEN HASHING\n\n");
}
```

Displays the current hashing mode — **Open Hashing (Separate Chaining)**.

---

### `hash(int key)`

```c
int hash(int key) {
    return abs(key) % MAX;
}
```

* **Purpose:** Computes the index for a given key.
* **Formula:**
  `hv = |key| % MAX`
* Ensures that all keys map to a valid table index between `0` and `MAX - 1`.

---

### `init(DICT D)`

```c
void init(DICT D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}
```

* Initializes all buckets in the hash table.
* Each index (`bucket`) starts as `NULL` — meaning no chain exists yet.

---

### `insertElem(DICT D, int key, char* value)`

```c
void insertElem(DICT D, int key, char* value) {
    nodetype* trav;

    for (trav = &D[hash(key)]; *trav != NULL; trav = &((*trav)->link)) {}

    nodetype newNode = (nodetype)malloc(sizeof(struct node));
    if (newNode) {
        newNode->key = key;
        strcpy(newNode->value, value);
        newNode->link = NULL;
        *trav = newNode;
    }
}
```

#### 🧮 How It Works:

1. Compute the hash value (`hv`) to get the target **bucket**.
2. Traverse to the **end of the linked list** in that bucket.
3. Create a new node with the key-value pair.
4. Append it to the end of the chain.

> ✅ Each bucket acts as a **linked list**, allowing multiple elements per hash index.

---

### `deleteElem(DICT D, int key)`

```c
void deleteElem(DICT D, int key) {
    nodetype* trav;

    for (trav = &D[hash(key)]; *trav != NULL && (*trav)->key != key; trav = &((*trav)->link)) {}

    if (*trav != NULL) {
        nodetype temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}
```

#### 🧮 How It Works:

1. Traverse the linked list in the corresponding bucket.
2. Stop when:

   * The key is found → delete it.
   * The chain ends → key not found.
3. Update links to remove the node cleanly and free memory.

---

### `member(DICT D, int key)`

```c
bool member(DICT D, int key) {
    nodetype trav;

    for (trav = D[hash(key)]; trav != NULL && trav->key != key; trav = trav->link) {}

    return (trav != NULL);
}
```

**Purpose:** Checks whether a specific key exists in the dictionary.
**Returns:**

* `true` → key found in the chain
* `false` → key not found (reached end of chain)

---

### `getValue(DICT D, int key)`

```c
char* getValue(DICT D, int key) {
    nodetype trav;

    for (trav = D[hash(key)]; trav != NULL && trav->key != key; trav = trav->link) {}

    return (trav != NULL) ? trav->value : NULL;
}
```

**Purpose:** Retrieves the value associated with a key.
**Returns:**

* `trav->value` → if key is found
* `NULL` → if key doesn’t exist in the table

---

### `visualize(DICT D)`

```c
void visualize(DICT D) {
    printf("\n");
    for (int i = 0; i < MAX; i++) {
        printf("[] -> [ ");
        for (nodetype trav = D[i]; trav != NULL; trav = trav->link) {
            printf("{ %d: \"%s\" }, ", trav->key, trav->value);
        }
        printf("]\n");
    }
    printf("\n");
}
```

**Purpose:** Displays the **structure** of each hash bucket.
Shows how keys are stored within linked lists:

Example output:

```
[] -> [ { 12: "apple" }, { 19: "banana" } ]
[] -> [ ]
[] -> [ { 5: "grape" } ]
```

---

### `display(DICT D)`

```c
void display(DICT D) {
    printf("[\n");
    for (int i = 0; i < MAX; i++) {
        for (nodetype trav = D[i]; trav != NULL; trav = trav->link) {
            printf("    { %d: \"%s\" },\n", trav->key, trav->value);
        }
    }
    printf("]\n");
}
```

**Purpose:** Displays all **key-value pairs** in a single, flat list format.
Useful for quickly viewing all stored elements.

---

## ⏱️ Time Complexities

| Operation     | Best Case | Average Case | Worst Case                                  |
| ------------- | --------- | ------------ | ------------------------------------------- |
| **Insertion** | O(1)      | O(1)         | O(n) *(if all elements hash to same index)* |
| **Search**    | O(1)      | O(1)         | O(n)                                        |
| **Deletion**  | O(1)      | O(1)         | O(n)                                        |

> ⏳ Average case remains efficient **if load factor (α)** = `n / MAX` is kept low.
> Performance depends on **hash function quality** and **bucket size distribution**.

---

## 🧮 Example of Open Hashing (Separate Chaining)

Suppose:

```
MAX = 5
Keys: 10, 15, 20, 25
```

| Key | Hash Value (`key % 5`) | Insertion Position (Chain)      |
| --- | ---------------------- | ------------------------------- |
| 10  | 0                      | → bucket 0                      |
| 15  | 0                      | → appended to chain in bucket 0 |
| 20  | 0                      | → appended to chain in bucket 0 |
| 25  | 0                      | → appended to chain in bucket 0 |

**Result:**

```
[0] -> [ {10}, {15}, {20}, {25} ]
[1] -> [ ]
[2] -> [ ]
[3] -> [ ]
[4] -> [ ]
```

---

## ✅ Summary

* **Open hashing** handles collisions using **linked lists** per bucket.
* No need for rehashing or probing.
* Performance is stable if load factor is controlled.
* Suitable when:

  * Frequent insertions and deletions occur.
  * Memory overhead (pointers) is acceptable.
