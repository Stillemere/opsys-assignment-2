#include <iostream>
#include "sysdata.h"

int main(){
   std::cout << "initiated program" << std::endl;
   // note: still need to retrieve data for alloc_matrix, etc
   // and number of processes, res types
   
   // calculate need matrix (N = M - A)
   for(int i = 0; i < num_processes; ++i){
       for(int j = 0; j < res_types; ++j){
           need[i][j] = max_res[i][j] - alloc[i][j];
       }
   }
   isSafe(availability);
}

bool isSafe(const std::vector<int>& available_t){
   vector<int> work(res_types); // work vector
   vector<bool> finished(num_processes); // initialized to false
   // initialize tmp array (work = available)
   for(int i = 0; i < res_types + 1; ++i){
      work[i] = available_t[i];
      std::cout << "[" << available_t[i] << "]";
   }
   std::cout << '\n';
   // find a process i for which the process is avalable
   // if so, set finished[i] to true and assign the input from the
   // availablility vector into the allocation matrix
   int safe_count = 0; 
   for(int i = 0; i < num_processes + 1; ++i){
       for(int j = 0; j < res_types + 1; ++j){
           if(finished[i] == 0 && need[i][j] <= available_t[i]){
               alloc[i][j] = available_t[i];
               finished[i] == 1;
               safe_count++;
           }
           else return 0; // found an unsafe element, therefore the state is unsafe
       }
   }
   return 1;
}
