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
  std::vector<int> array;
  std::ifstream in("../!DaneTestowe/rand_input.txt");
 //std::ifstream in("liczby.txt");

  int liczba;
  srand(time(NULL));
  
  while(!in.eof())
  {
    in >> liczba;
    array.push_back(liczba);
  }
  // std::cout<<"Nieposortowana: \n";
  // //printTab(array);
  // std::cout<<"Posortowana: \n";

  auto start = chrono::high_resolution_clock::now(); //liczymy czas
  ios_base::sync_with_stdio(false);

  QuickSort(array); // sortujemy

  auto end = chrono::high_resolution_clock::now(); //kończymy liczenie
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9; //konwersja ns s →

  //printTab(array);
  
  cout << "Time taken by program is : " << time_taken * 1000 << setprecision(12);
  cout << " ms" << endl;
  return 0;
}

int divide(std::vector<int>& arr, int start, int end)
{
  int i = start - 1;
  int size = end - start;
  int pivotrand = rand() % size + start;
  int pivot_val = arr[pivotrand];
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
