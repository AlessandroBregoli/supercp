#include "copia.h"
void Copia::ciao(){
	cout<<"ciao"<<endl;
}

Copia::Copia(char in[], char out[]){
	this->in = in;
	this->out = out;
}
bool Copia::superCopia(){
	if(!this->valida()){
		return false;
	}
	//proviamo ad aprire.
	FILE* f = fopen(this->in, "r");
	if (f == NULL){
		cerr << "Errore numero " << ERRNO << endl;
		return false;
	}
	fclose(f);
}

bool Copia::valida(){
	struct stat fIn;
	int rets = stat(this->in, &fIn);
	if(rets != 0){
		cerr<< "File di input non valido"<<endl;
		return false;
	}
	if(!S_ISREG(fIn.st_mode)){
		cerr<<"Non posso copiare robe strane"<<endl;
		return false;
	}
	this->dimFile = fIn.st_size;
	
	rets = stat(this->out, &fIn);
	if(rets == 0){
		if(S_ISDIR(fIn.st_mode))
			this->outIsCartella = true;
		else{ 
			cerr<<"Il file esiste già e noi non vogliamo supportare la sovrascrittura"<<endl;
			return false;
		}
	}
	return true;
}
