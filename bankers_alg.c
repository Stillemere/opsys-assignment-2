#include <iostream>
#include "sysdata.h"

int safe_sequence[5] = {-1,-1,-1,-1,-1};

int main(){
   // note: still need to retrieve data for allocation matrix, etc
   // and number of processes, res types

   // calculate need matrix (N = M - A)
   std::cout << "Need matrix: " << std::endl;
   for(int i = 0; i < num_processes; ++i){
       for(int j = 0; j < res_types; ++j){
           need[i][j] = max_res[i][j] - allocation[i][j];
           std::cout << '[' << need[i][j] << ']';
       }
       std::cout << '\n';
   }
   if(isSafe(availability)){
       std::cout << "The system is in a safe state" << std::endl;
       std::cout << "Safe sequence: " << std::endl;
       for(int i = 0; i < 5; ++i){
           if(safe_sequence[i] == -1) continue; // unfilled slot
           std::cout << 'P' << safe_sequence[i];
           if(i<4) std::cout << ", ";
           else std::cout << '\n';
       }
   }
   else std::cout << "The system is not in a safe state." << std::endl;
}

bool isSafe(const std::vector<int>& available_t){
   vector<int> work(res_types); // work vector
   vector<bool> finished(num_processes); // initialized to false
   // initialize tmp array (work = available)
   std::cout << "work[]: ";
   for(int i = 0; i < res_types; ++i){
      work[i] = available_t[i];
      std::cout << '[' << work[i] << ']';
   }
   std::cout << '\n';
   // find a process i for which the process is avalable
   // if so, set finished[i] to true and assign the input from the
   // availablility vector into the allocation matrix
   int k = 0; // safe sequence index
   for(int i = 0; i < num_processes; ++i){
       for(int j = 0; j < res_types; ++j){
           if(need[i][j] <= work[j] && finished[i] == 0){
               work[j] += allocation[i][j];
               finished[i] = 1;
               safe_sequence[k] = i;
           }
       }
       ++k;
   }
   std::cout << "Finished vector: \n";
   for(int i = 0; i < num_processes; ++i) std::cout << '[' << finished[i] << ']';
   std::cout << '\n';

   int safe_count;
   for(int i = 0; i < finished.size(); i++) if(finished[i]) ++safe_count;
   if(safe_count == num_processes) return 1; // all elements in the finished vector are true therefore it is in a safe state
   return 0;
}
