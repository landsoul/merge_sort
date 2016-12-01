#pragma once
#include<vector>

template<typename T>
T& quick_sort(T& myArray) {
   if (myArray != NULL)
      quick_sort(myArray, 0, (sizeof(myArray) / sizeof(myArray[0])) - 1);
}

template<typename T>
T& quick_sort(T& myArray, int low, int high) {
   // pick a pivot randomly
   // grab everything greater than the pivot and put it to the right of it
   // grab everything less than the pivot and put it to the left of it
   // when done, recurse left
   // when done, recurse right
}

template<typename T>
void merge_sort(std::vector<T>& myArray) {
   std::vector<T> extra;
   extra.reserve(myArray.size());
   return merge_sort(myArray, extra, 0, myArray.size() - 1);
}

template<typename T>
void merge_sort(std::vector<T>& myArray, std::vector<T>& extra, int low, int high) {
   if (!is_sorted(myArray, low, high)) {
      auto mid = ((high - low) / 2) + low;
      merge_sort(myArray, extra, low, mid);
      merge_sort(myArray, extra, mid + 1, high);
      merge(myArray, extra, low, mid, high);
   }
}

template<typename T>
void merge(std::vector<T>& myArray, std::vector<T>& extra, int low, int mid, int high) {
   if (low < high) {
      auto i = low;
      auto j = mid + 1; 
      const auto NUM_THINGS = myArray.size();

      // check each place in myArray, store it in order in extra to be copied back over later.
      while (i <= mid && j <= high) {
         if ((myArray[i] < myArray[j])) {
            extra.push_back(myArray[i]);
            ++i;
         }
         else { // just a safety check to ensure it will not check outside of the boundry.
            extra.push_back(myArray[j]);
            ++j;
         }
      }
      // if there is anything else to add to extra in left half
      while (i <= mid && j > high) {
         extra.push_back(myArray[i]);
         ++i;
      }
      // if there is anything else to add in right half
      while (j <= high && i > mid) {
         extra.push_back(myArray[j]);
         ++j;
      }
      // for everything in extra, change myArray's n elements to extra's n elements, from low to high.
      for (int i = 0, j = low; i < extra.size() && j <= high; ++i, ++j) {
         myArray[j] = extra[i];
      }
      extra.clear();
   }
}

template<typename T>
bool is_sorted(std::vector<T>& myArray, int low, int high) {
   if (low < high) {
      for (int i = low; i < high; ++i) {
         if (myArray[i] > myArray[i + 1]) {
            return false;
         }
      }
   }
   return true;
}

