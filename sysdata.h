#ifndef SYSDATA_H
#define SYSDATA_H

#include <vector>
using std::vector;

// Declaring variables with data
// that is necessary for banker's algorithm
int num_processes = 5; // rows
int res_types = 3; // columns
vector<vector<int>> allocation = {
    { 0, 1, 0 },
    { 2, 0, 0 },
    { 3, 0, 2 },
    { 2, 1, 1 },
    { 0, 0, 2 }
};
vector<vector<int>> max_res = {
    { 7, 5, 3 },
    { 3, 2, 2 },
    { 9, 0, 2 },
    { 2, 2, 2 },
    { 4, 3, 3 },
};
vector<int> availability = { 3, 3, 2 };
vector<vector<int>> need(num_processes, vector<int>(res_types));

bool isSafe(const vector<int>&);

#endif
