#include <bits/stdc++.h>
#include <chrono>

void MergeSort (std::vector<int>& );
void MergS(int, int);
void Merge(int, int, int);
void PrintArray(std::vector<int>&);

std::vector<int> g_array;

int main()
{
  std::vector<int> arr;
  std::ifstream in("../!DaneTestowe/rand_input.txt");
  int number;

  int k = 0;

  while(!in.eof() && k < 2000)
  {
    in >> number;
    arr.push_back(number);
    k++;
  }

  //PrintArray(arr);

  auto start = std::chrono::high_resolution_clock::now(); //liczymy czas

  std::ios_base::sync_with_stdio(false);

  MergeSort(arr);

  auto end = std::chrono::high_resolution_clock::now(); //kończymy liczenie
  double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  //PrintArray(arr);

  time_taken *= 1e-9;
  
  std::cout << k <<" Time taken by program is : " << time_taken * 1000 << std::setprecision(12);
  std::cout << " ms\n";

  return 0;
}

void Merge(int low, int high, int middle)
{
  int i1= low;
  int i2 = middle + 1;
  int size = high - low + 1;

  int *tmp = new int[size];
  int j = 0;
  
  while(i1 <= middle && i2 <= high)
  {
    if(g_array[i1] < g_array[i2])
    {
      tmp[j] = g_array[i1];
      i1++;
    }
    else
    {
      tmp[j] = g_array[i2];
      i2++;
    }
    j++;
  }
  if(i1 > middle)
  {
    while(i2 <= high)
    {
      tmp[j] = g_array[i2];
      i2++;
      j++;
    }
  }
  else 
  {
    while(i1 <= middle)
    {
      tmp[j] = g_array[i1];
      i1++;
      j++;
    }  
  }

  for(j = 0; j < size; j++)
  {
    g_array[low + j] = tmp[j];
  }
  
  delete[] tmp;
}

void MergS(int low, int high)
{
  int middle = (low + high)/2;
  if(low < high)
  {
    MergS(low, middle);
    MergS(middle+1, high);
    Merge(low, high, middle);
  }
}

void MergeSort(std::vector<int> &arr)
{
  int low = 0;
  int high = arr.size() - 1;
  g_array = arr;
  MergS(low, high);
  arr = g_array;
  g_array.clear();
}

void PrintArray(std::vector<int>& arr)
{
  for(int i = 0 ; i < arr.size(); i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
}