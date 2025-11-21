# Binary Search Tree: Deletion Algorithm

This module implements the deletion logic for a Binary Search Tree (BST). It handles the traversal to locate the target node and manages the three specific structural cases required to maintain BST properties after removal.

## 1\. The Algorithm

### Phase 1: Traversal & Search

Before deletion can occur, the target node must be located.

1.  **Start at Root:** Begin the search at the top of the tree (`*T`).
2.  **Compare & Traverse:**
      * If `Target > Current Node`: Traverse **Right**.
      * If `Target < Current Node`: Traverse **Left**.
3.  **Action:** Stop when the pointer is `NULL` (not found) or when `Current Node Data == Target` (found).

### Phase 2: Deletion Cases

Once the target node (`*trav`) is found, the deletion strategy depends on the node's structure:

#### Case 1: Leaf Node

*The node has no children.*

  * **Action:** Set the parent's pointer to this node to `NULL`.
  * **Memory:** `free` the node.

#### Case 2: One Child

*The node has either a Left child OR a Right child, but not both.*

  * **Action:** The parent's pointer is updated to point directly to the node's **single child**, effectively "bypassing" the node to be deleted.
  * **Memory:** `free` the node.

#### Case 3: Two Children

*The node has both Left and Right children.*

  * **Strategy:** To preserve the BST order, we cannot simply delete the node. We must replace it.
  * **Action:**
    1.  Identify the **In-order Predecessor** (The rightmost node of the left subtree).
    2.  **Replace** the target node's data with the Predecessor's data.
    3.  **Target the Predecessor** for deletion instead of the original node.
    4.  The Predecessor is guaranteed to be either a Leaf or have only a Left child, reducing this back to *Case 1* or *Case 2*.

  - In-order successor (leftmost node of right subtree) can also be used similarly.
