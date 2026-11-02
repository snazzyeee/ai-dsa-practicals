// Practical 4: Pinnacle Club singly linked list
//
// addMember:
// Require a president before a secretary, and both before a regular member.
// Allocate a node and store its PRN and name.
// Insert a president at the beginning, a secretary at the end,
// or a regular member just before the secretary. Return the head.
//
// deleteMember:
// Find the PRN while tracking the previous node.
// If absent, report not found.
// Update head when deleting the first node; otherwise bypass the node.
// Free the deleted node and return the head.
//
// displayMembers:
// Traverse the list, print each member and count the nodes.
// Label the first as president and the last as secretary; print the count.
//
// concatenate:
// If the first list is empty, return the second list.
// Otherwise connect the first list's last node to the second list's head.
// Return the combined head.
//
// freeList:
// Save the next pointer, free the current node, and move to the saved node.
// Repeat until the list ends.
//
// main:
// Start with two empty division lists.
// Repeat the menu using do-while and switch.
// Select a division for adding, deleting or displaying members.
// To join divisions, concatenate into list 1 and clear list 2's head.
// On exit, free both lists.
