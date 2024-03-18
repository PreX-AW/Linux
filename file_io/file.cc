#include<iostream>
#include<cstdio>
#include<unistd.h>
using namespace std;
int main()
{
  //c
  
  close(2);

  printf("wizard-->stdout\n");
  fprintf(stdout,"wizard-->stdout\n");
  fprintf(stderr,"wizard-->stderr\n");



  //c++
  cout<<"wizard-->cout"<<endl;
  cerr<<"wizard-->cerr"<<endl;


  return 0;
}
