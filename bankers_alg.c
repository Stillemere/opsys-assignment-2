#include <iostream>
#include "sysdata.h"

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
   }
   else std::cout << "The system is not in a safe state." << std::endl;
}

bool isSafe(const std::vector<int>& available_t){
   vector<int> work(res_types); // work vector
   vector<bool> finished(num_processes); // initialized to false
   // initialize tmp array (work = available)
   std::cout << "work[]: ";
   for(int i = 0; i < res_types; ++i){
      work[i] = available_t[i]; // debug note: this code's good
      std::cout << '[' << work[i] << ']';
   }
   std::cout << '\n';
   // find a process i for which the process is avalable
   // if so, set finished[i] to true and assign the input from the
   // availablility vector into the allocation matrix
   for(int i = 0; i < num_processes; ++i){
       for(int j = 0; j < res_types; ++j){
           //std::cout << i << ',' << j << " | ";
           if(need[i][j] <= work[j]){
               //std::cout << need[i][j] << " <= " << work[i] << " | ";
	       //std::cout << work[j] << " | ";
               work[j] += allocation[i][j];
               //std::cout << work[j] << std::endl;
               finished[i] = 1;
           }
           //std::cout << '\n';
           //else { std::cout << need[i][j] << " !<= " << work[i] << " | "; }
           /*
           if(finished[i] == 0 && need[i][j] <= available_t[i]){
               allocation[i][j] = available_t[i];
               finished[i] == 1;
               safe_count++;
           }
           */
       }
       //std::cout << '\n';
   }
   std::cout << "Finished vector: \n";
   for(int i = 0; i < num_processes; ++i) std::cout << '[' << finished[i] << ']';
   std::cout << '\n';

   int safe_count;
   for(int i = 0; i < finished.size(); i++) if(finished[i] == 1) ++safe_count;
   if(safe_count == num_processes) return 1;
   return 0;
}
