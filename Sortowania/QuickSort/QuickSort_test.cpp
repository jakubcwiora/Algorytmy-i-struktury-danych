#include <bits/stdc++.h>
#include <chrono>
#include <iostream>

int divide(std::vector<int>&, int, int);
void qs(std::vector<int>&, int, int);
void QuickSort(std::vector<int>&);
void printTab(std::vector<int>);

using namespace std;

int main()
{
  srand(time(NULL));
  
  std::vector<int> arr;
  std::ifstream in("../!DaneTestowe/desc_input.txt");
  int number;

  int k = 0;

  while(!in.eof() && k < 50)
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  auto start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  QuickSort(arr);

  auto end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  

  //PrintArray(arr);

  time_taken *= 1e-9;
  
  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  k = 0;
  arr.clear();

  while(!in.eof() && k < 100)
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  QuickSort(arr);

  end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  k = 0;
  arr.clear();

  while(!in.eof() && k < 200)
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  QuickSort(arr);

  end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  k = 0;
  arr.clear();

  while(!in.eof() && k < 500)
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  QuickSort(arr);

  end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  k = 0;
  arr.clear();

  while(!in.eof() && k < 1000)
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  QuickSort(arr);

  end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  k = 0;
  arr.clear();

  while(!in.eof() && k < 2000)
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  QuickSort(arr);

  end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  k = 0;
  arr.clear();

  while(!in.eof())
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  QuickSort(arr);

  end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  k = 0;
  arr.clear();

  return 0;
}

int divide(std::vector<int>& arr, int start, int end)
{
  int i = start - 1;
  int size = end - start;
  int pivotrand = rand() % size + start;
  int pivot_val = arr[end];
  swap(arr[pivotrand], arr[end]);

  for(int j = start; j < end; j++)
  {
    if(arr[j] <= pivot_val)
    {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[end], arr[i+1]);
  return i+1;
}

void qs(std::vector<int>& arr, int start, int end)
{
  if(start < end)
  {
  int pivot = divide(arr, start, end);
  qs(arr, start, pivot - 1);
  qs(arr, pivot + 1, end);
  }
}

void QuickSort(std::vector<int>& arr)
{
  int start = 0;
  int end = arr.size() - 1;
  qs(arr, start, end);
}

void printTab(std::vector<int> arr)
{
  int size = arr.size();
  for(int i = 0; i < size; i++)
  {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<'\n';
}
