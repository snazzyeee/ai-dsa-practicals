# ai-dsa-practicals

Academics: C programs and English algorithms for 9 DSA practical sessions, alongside theory and viva notes for 10 AI practical sessions. Prepared for SPPU practical revision, with simple implementations focused on the problem statements.

## DSA practicals

The `DSA/` folder contains `practical1.c` through `practical9.c`. Each program has a matching `ps_practicalN.c` file containing short, commented English algorithms for its functions.

| No. | Topic |
| --- | --- |
| 1 | Linear and binary search |
| 2 | Selection sort and bubble sort |
| 3 | Hash table telephone directory with collision handling |
| 4 | Pinnacle Club management using a singly linked list |
| 5 | Theatre seat booking using doubly linked lists |
| 6 | Infix-to-postfix conversion and evaluation using stacks |
| 7 | Pizza order management using a circular queue |
| 8 | Binary search tree operations |
| 9 | Flight graph representation and connectivity |

The programs use `do...while` menus with `switch` cases. They assume valid input within the stated limits; binary search requires ascending roll numbers. The pseudocode files are revision notes, not executable programs.

## AI theory and viva

The `AI/` folder contains `practical_1_theory.txt` through `practical_10_theory.txt`, based on `SE_AI_LAB_MANUAL.pdf`.

| No. | Topic |
| --- | --- |
| 1 | Rule-based expert systems |
| 2 | BFS and DFS maze solving |
| 3 | A* search |
| 4 | Constraint satisfaction, backtracking, MRV and AC-3 |
| 5 | Minimax |
| 6 | Alpha-beta pruning |
| 7 | ChatGPT and its usage |
| 8 | AI video generation |
| 9 | AI image generation |
| 10 | Prompt engineering |

Each text file includes the aim, core theory, working steps, examples, viva questions with answers, and a quick memory cue. The AI section contains theory only; no Python implementations are included. The questions are revision aids, not a confirmed examiner question list.

## Running a C practical

A C compiler such as GCC is required. For example, on Ubuntu:

```bash
gcc DSA/practical7.c -o practical7
./practical7
```

In Windows PowerShell with GCC available:

```powershell
gcc DSA/practical7.c -o practical7.exe
.\practical7.exe
```

Change the practical number to run another program. For practical 6, add `-lm` at the end of the GCC command to link the math library where required.

## Checks

The `tests/` folder contains sample checks for the DSA programs. Running them requires Python and GCC:

```text
python -m unittest discover -s tests
```
