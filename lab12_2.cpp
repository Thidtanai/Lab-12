#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[][M]){
  cout << "------------------------------------------------------------------------\n";
  for(int j=0;j<N;j++){
    cout << '|';
    for(int k=0;k<M;k++){
      if(image[j][k])cout << '*';
      else cout << ' ';
    }
    cout << '|' << endl;
  }
  cout << "------------------------------------------------------------------------\n";
  return;
}

void updateImage(bool image[][M],int size,int x,int y){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(size - 1 >= sqrt(pow(i-x,2)+pow(j-y,2)))image[i][j] = 1;
    }
  }
  return;
}
