#include"delserver.h"
#include<stdio.h>
int main(int argc,char *argv[])
{
  if(argc==2) //condition to ensure that user enteres only the username wihtout additonal parameters
  deluser(argv[1]);
  else
  printf("INVALID INPUT");
  return 0;
}
