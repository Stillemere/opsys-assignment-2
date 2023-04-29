# opsys-assignment-2
The second programming assignment of the Operating Systems course.

This program demonstrates the banker's algorithm given the data of a system.
It determines whether the system is safe (i.e. there will not be deadlock).

Aspects of the program:

- The allocation matrix shows the resources allocated to each process.

- The maximum resource (max_res) matrix represents the maximum resources each process can request.

- The availability vector represents the available resources of the system.

- The need matrix is calculated from the max matrix and allocation matrix (N = M - A).

Checking whether the system is in a safe state:
- Find a process i such that need[i][j] <= work[j] and finished[i] is false.
- For each such process, add the corresponding entry in the allocation matrix to the work vector.
- Set each element of the finished vector to true for each such process.
- If all elements in the finished vector are true, the system is in a safe state.
