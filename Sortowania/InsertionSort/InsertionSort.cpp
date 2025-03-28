#include <chrono>
#include<bits/stdc++.h>



void PrintArray(std::vector<int>& arr);

std::vector<int> arr;

int main()
{
  int num, tmp, k = 0, sizeOfarr = arr.size(), x;
  bool flag;

  std::ifstream in("../!DaneTestowe/dbg100.txt");
  int number;

  while(!in.eof())
  {
    in >> number;
    arr.push_back(number);
  }

  int j;
  auto start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

   for (int i = 1; i < arr.size(); ++i) 
   {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) 
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
    }
    
  auto end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  //PrintArray(arr);

  time_taken *= 1e-9;
  PrintArray(arr);
  std::cout << "Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

    return 0;
}

void PrintArray(std::vector<int>& arr)
{
  for(int i = 0 ; i < arr.size(); i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
}