#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


void cleanStrings(vector<string> oldVector, int size) {
// Prints elements in both vectors without duplicates


if(size){

  cout << oldVector.at(0) << endl;

  for (int i = 1; i < size; i++) {
    if (oldVector.at(i) != oldVector.at(i-1)) {
      cout << oldVector.at(i) << endl;
      }
    }
  }
}

void stringCompare(vector<string> a, std::vector<string> b, vector<string> &v_intersectionString) {
// Compares both arrays, for same elements, then stores into Dups vector.

set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v_intersectionString));


}


void Merge(string *a, int low, int high, int mid)
//Merge for strings
{

 int i, j, k;
 string temp[high-low+1];
 i = low;
 k = 0;
 j = mid + 1;

 while (i <= mid && j <= high)
 {
   if (a[i] < a[j])
   {
     temp[k] = a[i];
     k++;
     i++;
   }
   else
   {
     temp[k] = a[j];
     k++;
     j++;
   }
 }
 while (i <= mid)
 {
   temp[k] = a[i];
   k++;
   i++;
 }
 while (j <= high)
 {
   temp[k] = a[j];
   k++;
   j++;
 }
 for (i = low; i <= high; i++)
 {
   a[i] = temp[i-low];
 }
}

void MergeSort(string *a, int low, int high)
// MergeSort for strings
{
 int mid;

 if (low < high)
 {
   mid=(low+high)/2;

   MergeSort(a, low, mid);
   MergeSort(a, mid+1, high);
   Merge(a, low, high, mid);
 }
}


//integers
void Mergeints(int *a, int low, int high, int mid)
// Merge for integers
{

	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
  {
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void MergeSortints(int *a, int low, int high)
// Mergesort for integers
{
	int mid;

	if (low < high)
	{
		mid=(low+high)/2;

		MergeSortints(a, low, mid);
		MergeSortints(a, mid+1, high);
		Mergeints(a, low, high, mid);
	}
}

void arrayCompare(vector<int> a, vector<int> b, vector<int> &v_intersection) {
  // Function to compare both arrays and get rid of duplicates

set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v_intersection));

}

void cleanArray(vector<int> oldVector, int size) {
  // Function that prints the sorted list with no duplicates


if(size){


cout << oldVector.at(0) << endl;

for (int i = 1; i < size; i++) {
  if (oldVector.at(i) != oldVector.at(i-1)) {
    cout << oldVector.at(i) << endl;
      }
    }
  }
}

int main(int argc, char const *argv[]) {


string i = "i";
string s = "s";

if (argv[1] == i) {
  std::vector<int> Dups;
  std::vector<int> arr;
  vector<int> v_intersection;

  ifstream File;
  File.open(argv[2]);

  int n;

  while (File >> n) {
    arr.push_back(n);
  }

  int unsortedArray[arr.size()];

  for (int i = 0; i < arr.size(); i++) {
    unsortedArray[i] = arr.at(i);
  }

  std::vector<int> arrr;

  ifstream File2;
  File2.open(argv[3]);


  int m;

  while (File2 >> m) {
    arrr.push_back(m);
  }

  int unsorted[arrr.size()];

  for (int i = 0; i < arrr.size(); i++) {
    unsorted[i] = arrr.at(i);
  }

  MergeSortints(unsortedArray,0,arr.size() - 1);
  MergeSortints(unsorted,0,arrr.size() - 1);


  for (int i = 0; i < arr.size(); i++) {

    arr.at(i) = unsortedArray[i];
  }

  for (int i = 0; i < arrr.size(); i++) {
    arrr.at(i) = unsorted[i];
  }


  arrayCompare(arr, arrr , v_intersection);
  cleanArray(v_intersection, v_intersection.size());

}


if (argv[1] == s) {
  vector<string> array;
  vector<string> Dups;
  vector<string> v_intersectionString;

  ifstream File;
  File.open(argv[2]);

  string n;

  while (File >> n) {
    array.push_back(n);
  }

  string stringArr1[array.size()];

  for (int i = 0; i < array.size(); i++) {
    stringArr1[i] = array.at(i);
  }

  vector<string> array2;

  ifstream File2;
  File2.open(argv[3]);

  string m;

  while (File2 >> m) {
    array2.push_back(m);
  }

  string stringArr2[array2.size()];

  for (int i = 0; i < array2.size(); i++) {
    stringArr2[i] = array2.at(i);
  }

  MergeSort(stringArr1,0,array.size() - 1);
  MergeSort(stringArr2,0,array2.size() - 1);


  for (int i = 0; i < array.size(); i++) {
    array.at(i) = stringArr1[i];
  }


  for (int i = 0; i < array2.size(); i++) {
    array2.at(i) = stringArr2[i];
  }


  stringCompare(array, array2, v_intersectionString);
  cleanStrings(v_intersectionString, v_intersectionString.size());

}

  return 0;
}
