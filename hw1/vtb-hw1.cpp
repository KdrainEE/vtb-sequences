//#include "stdafx.h"
#include <iostream>


using namespace std;

struct sequence
{
	size_t valc;
	double* values;
  double min;
  double max;
  double sum;
  double mean;
};
int main(int argc, char* argv[])
{	
	size_t memLength = 1;
	sequence** memAllocation = new sequence*[memLength];
	size_t sequenceCount = 0;
	
	bool run = true;
  
	  while (run)
		{
		  cout << "Options:" << endl;
		  cout << "\t0: Quit" << endl;
		  cout << "\t1: Add Sequence" << endl;
		  cout << "\t2: List Sequeces" << endl;
		  cout << "\t3: Recall Sequence" << endl;
		  int option;
		  cin >> option;
		  switch(option){
			case 0:
		
			  cout << "Goodbye" << endl;
			  run = false;
			  for (size_t i = 0; i < sequenceCount; i++)
			  {
				  delete[] (*memAllocation[i]).values;

			  }
			  delete[] memAllocation;
			  break;

			case 1:
			{
				//resize container if filled
				if (sequenceCount >= memLength)
				{
					sequence** resized_container = new sequence*[memLength * 2];
					for (size_t i = 0; i < sequenceCount; i++)
					{
						resized_container[i] = memAllocation[i];
					}
					delete[] memAllocation;
					memAllocation = resized_container;
					memLength *= 2;
				}

				memAllocation[sequenceCount] = new sequence;
				sequence& temp = *memAllocation[sequenceCount];
				temp.min = 0;
				temp.min = 0;
				temp.max = 0;
				temp.sum = 0;
				temp.mean = 0;
				cout << "How many values would you like to store?" << endl;
				cin >> temp.valc;
				temp.values = new double[temp.valc];
				for (int i = 0; i < temp.valc; i++)
				{
					cout << "Enter value" << endl;
					double curr;
					cin >> curr;
					temp.values[i] = curr;
					temp.sum += curr;
					if (i == 0)
					{
						temp.min = curr;
						temp.max = curr;
					}
					else if (curr > temp.max)
					{
						temp.max = curr;
					}
					else if (curr < temp.min)
					{
						temp.min = curr;
					}
				}
				temp.mean = temp.sum / temp.valc;
				sequenceCount++;
				break;
			}
			case 2:
			  cout << "Listing all sequences." << endl;
			  for(int i=0; i<sequenceCount; i++)
			  {
				cout << "Sequence " << i << ".  " << (*memAllocation[i]).valc << " elements" << endl;
			  }
			  break;

			case 3:
			  size_t idx;
			  cout << "Enter the index of the sequence to view. Indices start at 0." << endl;
			  cin >> idx;
			  if (idx >= sequenceCount)
			  {
				  cout << "This is not a valid index." << endl;
				  break;
			  }
			  sequence view = *memAllocation[idx];
			  cout << "Sequence " << idx << endl;
			  for(int i=0; i<view.valc; i++)
			  {
				cout << view.values[i] << " ";
			  }
			  cout << endl;
			  cout << "Minimum: " << view.min << " Maximum: " << view.max << " Sum: " << view.sum << " Mean: " << view.mean << endl;
			  break;
		  }
		}
		return 0;
};
