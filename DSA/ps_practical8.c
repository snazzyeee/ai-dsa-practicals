// Practical 8: Binary search tree
//
// insert:
// At an empty position, allocate a node with the value and NULL children.
// Otherwise insert smaller values into the left subtree, larger into right.
// Report duplicates and return the root.
//
// height:
// Return zero for an empty tree.
// Find both subtree heights and return one plus the larger height.
//
// minimum:
// Report empty if there is no root.
// Otherwise follow left pointers to the last node and print its value.
//
// mirror:
// Stop at NULL; otherwise swap the node's left and right children.
// Repeat recursively for both subtrees.
//
// search:
// Return false at NULL and true if the current value matches.
// Otherwise search left for a smaller target, right for a larger one.
//
// freeTree:
// Stop at NULL. Free the left subtree, right subtree and then the node.
//
// main:
// Start with an empty tree and repeat the menu using do-while and switch.
// Call Insert, Height, Minimum, Mirror or Search as selected.
// Track mirroring; require mirroring back before Insert, Minimum or Search.
// Free the tree on exit.
