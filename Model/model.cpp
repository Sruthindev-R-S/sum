#include<iostream>
#include<cmath>
#include <vector>
#include<random>
int main()
{
    double input[70][3];
    double output[70],sequences[10][10];
    std::mt19937 d(10);
    std::uniform_int_distribution<int> first(-100,100);
    std::uniform_int_distribution<int> common(-100,100);
    double k,b;
    int counter=0;
    
    for(int j=0;j<10;j++)
    {
    k=first(d);
    b=common(d);
    if(b==0)
    {
        j--;
        continue;
    }
    for(int i=0;i<10;i++)
    {
        sequences[j][i]=k+b*i;      
    }
    
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<7;j++)
        {
            input[counter][0]=sequences[i][j];
            input[counter][1]=sequences[i][j+1];
            input[counter][2]=sequences[i][j+2];
            output[counter]=sequences[i][j+3];
            counter++;
            
        }
    }
    std::cout<<counter;
    return 0;
    double 

}