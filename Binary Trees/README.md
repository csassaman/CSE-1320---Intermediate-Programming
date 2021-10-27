# Binary Trees

- Graph-based data structure
- Defines as a hierarchical tree of nodes in which each node has at most two sub-nodes
  - can have one or zero nodes
- Look like upside-down trees
- Some common definitions of binary trees
  - The __size__ of a tree _T_ is determined by the total number of nodes in _T_
  - The __root__ of a tree _T_ is the starting point of _T_
  - A __leaf node__ in a tree _T_ is a node that has no sub-nodes
  - The __height__ of a tree _T_ is determined by the _length_ of the shortest path between the root of _T_ and the lowest leaf node _T_
- Each node in a binary tree contains the following information:
  - A reference to the __left__ sub-node
  - A reference to the __right__ sub-node
  - A __key__ representing some value
- Binary trees are espically useful for sorting and searching data efficiently
- The data can be as simple as a single scalar value or as complex as a mulit-membered `struct` as long as a suitable __key__ can be chosen to represent each node

## Creating a Binary Tree

- In general, a binary tree can be constructed in any fashion as long as each node has __at most__ two sub-nodes
- Although the usefullness of a binary tree comes from utilizing their hierarchical nature, there is no requirement that the data need to be sorted in any particular way

## Binary Search Tree

- Defined by the following property:
  > If _x_ is a node in a binary search tree and _y_ is a sub-node of _x_, then _y_ is a _left sub-node_ if _y.key_ <= _x.key_ and _y_ is a _right sub-node_ if _y.key_ >= _x.key_

## Operations

1. [Traversal](README.md?plain=1#L36)
2. Search
3. Inseration
4. Deletion

### Traversal

- Several different ways to traverse the nodes of a binary tree
    1. Depth First Search (Preorder)
        - To preform a preorder DFS, the _key_ of the current node is printed _before_ moving to the sub-nodes
    2. Depth First Search (Inorder)
        - To preform an inorder DFS, the _key_ of the current node is printed _between_ the sub-nodes 
        - Can swap order (smallest to largest or largest to smallest) by swapping recursive function calls
    3. Depth First Search (Postorder)
        - Prints key last
    4. Breadth First Search


