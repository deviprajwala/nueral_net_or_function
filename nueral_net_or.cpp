//implementation of nueral net or function with the help of perceptrin learning algorithm
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool prediction_error(float y_c, float ans);

vector < bool > x1;
vector < bool > x2;
vector < bool > y;

float w1, w2, y_c;

void read_data ()
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
{
  for( int i = 0; i < 4; i++)
  {
      cout<<x1[i]<<" "<<x2[i]<<" "<<y[i]<<"\n";
  }
}

void perceptron (float bias, int count)
{
  bool condition_met = true;
  float learning_rate = 0.6, val = 0;
  while(condition_met)
  {
    w1 = 1;
    w2 = 1;
    for(int i = 0; i < x1.size(); i++)
    {
      y_c =( ( w1 * x1[i] ) + (w2 * x2[i] ) + bias );
      
     // cout<<prediction_error(y_c, y[i]);
      if( !prediction_error(y_c, y[i]) )
      {
          w1 = w1 + learning_rate * ( (y[i] - y_c) * x1[i] );
          w2 = w2 + learning_rate * ( (y[i] - y_c) * x2[i] );
         
      }
    }
    cout<< "w1 = "<<w1<<" "<<"w2 = "<<w2<< " "<<"after "<<val<<"th iteration"<<"\n";
    val++;
    val == count ? condition_met = false : condition_met = true;
    learning_rate -= 0.05;
  }  

}
bool prediction_error(float y_c, float ans)
{
  int result;
  y_c >= 0 ? result = 1 : result = 0;

  if(result == ans)
  {
      return false;
  }
  return true;
}
void predict (int x_1,int x_2)
{
    float res;
    res = (w1 * x_1) + (w2 * x_2);
    res > 0 ? res = 1 : res = 0;

    cout<<x_1<<"  "<<x_2<<" answer is "<<res<<"\n";
}
int main()
{
    float t = 0;
    read_data();
   // write_data();
    perceptron(t, 10);
    bool x_1, x_2;
   // cout<<"Enter the value of x1 and x2:\n";
    cin>>x_1>>x_2;
    predict (x_1, x_2);
    predict (0, 1);
    predict (1, 0);
    predict (0, 0);
    
    return 0;
}
