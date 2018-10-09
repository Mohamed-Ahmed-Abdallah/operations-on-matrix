// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <valarray>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  valarray<int> data;       //valarray that will simulate matrix
  int row, col;
};


ostream& operator<< (ostream& out, matrix mat);
// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix& mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)

       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{

  matrix mat1, mat2;
  int x,scalar;

  cout<<"1-for += matrix"<<endl;
  cout<<"2-for -= matrix"<<endl;
  cout<<"3-for matrix++"<<endl;
  cout<<"4-for matrix--"<<endl;
  cout<<"5-for adding scalar to matrix"<<endl;
  cout<<"6-for subtracting scalar from matrix"<<endl;
  cout<<"press any other numbers or letters to exit"<<endl;

  for (int y=0;y<=30;y++){

  cout<<endl;
  cout<<"***************************\n";
  cout<<"\nplease choose a number : ";
  cin>>x;
  cout<<"\n***************************\n";
  cout<<endl;

  if (x==1){
  cout<<"We do += matrix"<<endl<<endl;
  cout<<"enter the first matrix ";
  cin >> mat1 ;
  cout<<endl<<endl<<"enter the second matrix ";
  cin>> mat2 ;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  cout<<"mat2 is "<<endl<<endl;
  cout<<mat2<<endl;
  mat1+=mat2;

  }

  else if (x==2){
  cout<<"We do -= matrix"<<endl<<endl;
  cout<<"enter the first matrix ";
  cin >> mat1 ;
  cout<<endl<<endl<<"enter the second matrix ";
  cin>> mat2 ;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  cout<<"mat2 is "<<endl<<endl;
  cout<<mat2<<endl;
  mat1-=mat2;

  }

  else if (x==3){
  cout<<"We do ++matrix"<<endl<<endl;
  cout<<"enter your matrix ";
  cin >> mat1;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  ++mat1;
  cout<<"mat++ is"<<endl<<endl;
  cout<<mat1;

  }

  else if (x==4){
  cout<<"We do --matrix"<<endl<<endl;
  cout<<"enter your matrix ";
  cin >> mat1;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  --mat1;
  cout<<"mat-- is"<<endl<<endl;
  cout<<mat1;

  }

  else if (x==5){
  cout<<"We add scalar to matrix"<<endl<<endl;
  cout<<"enter your matrix ";
  cin >> mat1;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  cout<<"enter a scalar : ";
  cin>>scalar;
  cout<<endl;
  mat1+=scalar;
  cout<<"mat after adding scalar is"<<endl<<endl;
  cout<<mat1;

  }

  else if (x==6){
  cout<<"We subtract scalar from matrix"<<endl<<endl;
  cout<<"enter your matrix ";
  cin >> mat1;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  cout<<"enter a scalar : ";
  cin>>scalar;
  cout<<endl;
  mat1-=scalar;
  cout<<"mat after subtracting scalar is"<<endl<<endl;
  cout<<mat1;

  }

  else{
  cout<<"Now exit"<<endl;
  break;
  }
 }
}

istream& operator>>(istream& in, matrix& mat){
    cout << "\n\nPlease enter rows and columns : ";
    cin >> mat.row >> mat.col;
    mat.data.resize(mat.row * mat.col);
    for(int i = 0 ; i < mat.row ; i++){
        cout << "\nPlease enter data for row " << i+1 << " : ";
        for(int j = 0 ; j < mat.col ; j++){
            cin >> mat.data[i * mat.col + j];
        }
    }
    cout<<endl;
}

ostream& operator<<(ostream& out,matrix mat)
{
    for(int i=0;i<mat.row;i++)
    {
       for(int j=0;j<mat.col;j++){
            out<<mat.data[i*mat.col+j]<< " ";
     }
     out<<endl;
}
return out;

}

matrix operator-= (matrix& mat1, matrix mat2) {


    if (mat1.row==mat2.row&&mat1.col==mat2.col)
	{
		mat1.data=mat1.data- mat2.data;
        cout<<"mat1-=mat2 is"<<endl<<endl;
        cout<<mat1;
	    return mat1;
	}
    else
        cout<<"Not allowed as row1 must equal row2 && col1 must equal col2"<<endl;
}


matrix operator+= (matrix& mat1, matrix mat2) {


    if (mat1.row==mat2.row&&mat1.col==mat2.col)
	{
		mat1.data=mat1.data+ mat2.data;
	    cout<<"mat1+=mat2 is"<<endl<<endl;
        cout<<mat1;
        return mat1;
    }

    else
        cout<<"Not allowed as row1 must equal row2 && col1 must equal col2"<<endl;

}

matrix operator+= (matrix& mat, int scalar)
{
    mat.data=mat.data+scalar;
    return mat;
}

matrix operator-= (matrix& mat, int scalar)
{
    mat.data=mat.data-scalar;
    return mat;
}

void   operator++ (matrix& mat)
{
    mat.data=mat.data+1;
}

void   operator-- (matrix& mat)
{
    mat.data=mat.data-1;
}

