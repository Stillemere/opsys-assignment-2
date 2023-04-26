#include <iostream>
#include <vector>

using std::vector;

// Declaring global variables and data structures
int num_processes, res_types;
vector<vector<int>> alloc_matrix;
vector<vector<int>> max_res_matrix;
vector<bool> availability_vec;
vector<vector<int> need_matrix;

bool isSafe(const vector<bool>&);

int main(){
   std::cout << "initiated program" << std::endl;
   // note: still need to retrieve data for alloc_matrix, etc
   // and number of processes, res types
   isSafe(availability_vec);
}

bool isSafe(const std::vector<bool>& input){
   vector<bool> tmp;
   vector<bool> finished(num_processes); // initialized to false
   // initialize tmp array
   for(int i = 0; i < input.size(); ++i){
      tmp[i] = input[i];
   }
   // find a process i for which the process is avalable
   // if so, set finished[i] to true and assign the input from the
   // availablility vector into the allocation matrix
   int safe_count = 0; 
   for(int i = 0; i < tmp.size(); ++i){
       if(finished[i] == 0 && need_matrix[i] <= tmp[i]){
           alloc_matrix[i] = tmp[i];
           finished[i] == 1;
           safe_count++;
       }
       else return 0; // found an unsafe element, therefore the state is unsafe
   }
   return 1;
}
