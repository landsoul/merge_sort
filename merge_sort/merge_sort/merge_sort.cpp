// merge_sort.cpp : Defines the entry point for the console application.
//

#include "Sorting.h"
#include<iostream> // cin, cout
#include<fstream> // ofstream, ifstream
#include<string> // string 
#include<vector> // vector
#include<algorithm> // std::sort()

//int main()
//{
//   std::vector<std::string> vStr = { "epple", "axplosive", "cherry", "elephant",
//      "manga", "orangutan", "mouse", "alien", "guitar"};
//   std::vector<int> vInt = { 1, 210, 324, 532, 678, 43, 7765, 3, 4345, 7, 23, 643, 23,
//      4356, 1234, 23, 1, 34, 2, 10, 420, 98, 87, 32, 54, 65, 84, 92, 72, 63, 76, 66 };
//   for (auto strings : vInt)
//      std::cout << strings << std::endl;
//   merge_sort(vInt);
//   std::cout << std::endl;
//   for (auto strings : vInt)
//      std::cout << strings << std::endl;
//   return 0;
//}

int main() {
   std::vector<std::string> strs;
   for (std::string mystrs; getline(std::cin, mystrs);) {
      // std::cout << mystrs << std::endl;
      strs.push_back(mystrs);
   }
   std::cout << std::endl;
   merge_sort(strs);
   for (std::string strings : strs){
      std::cout << strings << std::endl;
   }
   return 0;
}
