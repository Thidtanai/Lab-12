#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double inputArray[],int Number,double ans[]){
    double AriMean, SD =0, GeoMean = 1;
    double HarMean, Max , Min = inputArray[0];

    for(int i = 0;i < Number;i++){
      AriMean += inputArray[i];
      GeoMean *= inputArray[i]; 
      HarMean += 1/inputArray[i];
      if(inputArray[i] > Max)Max = inputArray[i];
      if(inputArray[i] < Min)Min = inputArray[i];
    }
    ans[0] = AriMean / Number;
    for(int j=0;j<Number;j++){
        SD += pow(inputArray[j]-ans[0],2);
    }
    ans[1] = pow((SD/Number),0.5);
    ans[2] = pow(GeoMean,1/(double)Number);
    ans[3] = Number/HarMean;
    ans[4] = Max;
    ans[5] = Min;
    return;
}