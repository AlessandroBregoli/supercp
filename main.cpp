#include <iostream>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
using namespace std;
#include "barra.cpp"
#include "copia.cpp"
int main(int argc, char* argv[]){
	if(argc < 3){
		cerr<<"Sono necessari almeno 2 argomenti"<<endl;
		return 1;
	}
	for(int i = 1; i < argc; i++){
		//cout<<argv[i]<<endl;
	}
	Copia c(argv[1],argv[2]);
	c.superCopia();
	cout << endl;
	return 0;
}
