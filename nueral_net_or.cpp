//implementation of nueral net or function with the help of perceptrin learning algorithm
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void read_data ();
//function to read the data from a text file

void write_data ();
//function to print the data obtained from the text file

void perceptron ( float bias, int count );
//function to implement perceptron algorithm which changes the associated weight as per the need

bool prediction_error ( float y_c, float ans );
//function to check whether the calculated outcome is same as that of the outcome present in the text file

void predict ( int x_1,int x_2 );
//function to predict the outcome when two inputs are given with the help of the weights calculated

vector < bool > x1;
//vector to store the first input

vector < bool > x2;
//vector to store the second input

vector < bool > y;
//vector to store the outcome

float w1, w2, y_c;
//variables to store the weights and current outcome

void read_data ()
//function to read the data from a text file
{
  for( int i = 0; i < 4; i++)
  {
      int x;
      cin>>x;
      x1.push_back(x);
      cin>>x;
      x2.push_back(x);
      cin>>x;
      y.push_back(x);
  }
}

void write_data ()
//function to print the data obtained from the text file
{
  for( int i = 0; i < 4; i++)
  {
      cout<<x1[i]<<" "<<x2[i]<<" "<<y[i]<<"\n";
  }
}

void perceptron ( float bias, int count )
//function to implement perceptron algorithm which changes the associated weight as per the need
{
  bool condition_met = true;
  float learning_rate = 0.6, val = 0;
  //learning rate initially we keep it as 0.6 and we gradually decrease its value by 0.05 after the iteration
  while( condition_met )
  {
    w1 = 1;
    w2 = 1;
    //initially we assign the weights as 1

    for(int i = 0; i < x1.size(); i++)
    {
      y_c =( ( w1 * x1[i] ) + (w2 * x2[i] ) + bias );
      //outcome is calculated with the help of the weights
      // cout<<prediction_error(y_c, y[i]);
      if( prediction_error(y_c, y[i]) )
      //if the calculated outcome and the actual outcome are different then the weights are updated it may be incremented or decremented based on the requirement
      {
          w1 = w1 + learning_rate * ( (y[i] - y_c) * x1[i] );
          w2 = w2 + learning_rate * ( (y[i] - y_c) * x2[i] );    
          //new weights are calculated  
      }
    }
    cout<< "w1 = "<<w1<<" "<<"w2 = "<<w2<< " "<<"after "<<val<<"th iteration"<<"\n";
    val++;
    val == count ? condition_met = false : condition_met = true;
    //to check if the condition is met

    learning_rate -= 0.05;
    //learning rate is decremented
  }  

}
bool prediction_error ( float y_c, float ans )
//function to check whether the calculated outcome is same as that of the outcome present in the text file
{
  int result;
  y_c >= 0 ? result = 1 : result = 0;
  //if calculated value is greater than 0 result is 1 or else it is 1
  if(result == ans)
  {
      return true;
  }
  return false;
  //if there is prediction error return true else return false
}

void predict ( int x_1, int x_2 )
//function to predict the outcome when two inputs are given with the help of the weights calculated
{
    float res;
    res = (w1 * x_1) + (w2 * x_2);
    //outcome is calculated when the inputs are given
    res > 0 ? res = 1 : res = 0;

    cout<<x_1<<"  "<<x_2<<" answer is "<<res<<"\n";
    //answer is printed on the screen
}
int main()
{
    float t = 0;
    //we are assuming the bias to be 0;

    read_data();
    //function call to read the data from a text file

    //write_data();
    //function call to print the data obtained from the text file

    perceptron( t, 10 );
    //function call to implement perceptron algorithm which changes the associated weight as per the need

    bool x_1, x_2;
   //cout<<"Enter the value of x1 and x2:\n";
    cin>>x_1>>x_2;
    predict ( x_1, x_2 );
    //function call to predict the outcome when two inputs are given with the help of the weights calculated

    predict ( 0, 1 );
    predict ( 1, 0 );
    predict ( 0, 0 );
    
    return 0;
}
