// an program to know the execution time
// by caskmy
#include<stdio.h>
#include<process.h>
#include<time.h>
#include<errno.h>
int main(int argc,const char **argv){
  if(argc<2){
    fprintf(stderr,"etime: noting to run\n");
    return 1;
  }
  argv++;
  clock_t t0=clock();
  int r=_spawnvp(_P_WAIT,argv[0],argv);
  clock_t t1=clock();
  if(r!=0){
    if(errno==0)
      fprintf(stderr,"%s: (an error)\n",argv[0]);
    else
      perror(argv[0]);
    return r;
  }
  fprintf(stderr,"execution time: %.3fs\n",(double)(t1-t0)/CLOCKS_PER_SEC);
  return 0;
}