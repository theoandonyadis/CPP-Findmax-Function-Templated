//Theo Andonyadis
//ECE 2620 Section 001
//Lab 4 Extra Credit
#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>
using namespace std;
template<typename T>
T findmax(T arr[])		//templated findmax function returns maximum value of a 5 member array of any type
{
	T max=arr[0];
	for(int i=1;i<5;i++)
		if(arr[i]>max)
		max=arr[i];
	return max;	
}
template<typename T>
void maincopy()		//templated maincopy function allows values of any type from input file
{
	T x1, x2, x3, x4, x5;	//declares the values of the lines as templated
	ifstream infile;		//creates infile and outfile objects for reading/writing
	ofstream outfile;
	infile.open("lab4_input.txt");		//uses ifstream member function open to open the input text file for reading
	outfile.open("lab4_output.txt");
	if (infile.is_open())		//if condition checks to ensure the infile is really open
	{
		int i=0;
		while(infile >> x1 >> x2 >> x3 >> x4 >> x5)		//while loop condition runs through however many lines in the input text file have 5 values
		{		
			T arr[5]={x1,x2,x3,x4,x5};		//templated array is filled with 5 members from the lines
			i++;							//keeps count of number of lines
			outfile << findmax(arr) << endl;		//calls findmax function for each array of 5 members and writes to the output text file
			cout << i << endl;		//prints number of lines gone through for each iteration
		}
	}
	else
	{
		cout<<"Error";		//outputs error if the text file is not open for reading
	}
	outfile.close();		//close outfile and infile
	infile.close();
	return;
}
	
int main()
{
	maincopy<int>();
			
	return 0;
}