#include "copia.h"
void Copia::ciao(){
	cout<<"ciao"<<endl;
}

Copia::Copia(char in[], char out[]){
	this->in = in;
	this->out = out;
	this->DIMBUFFER = 4096;
}
bool Copia::superCopia(){
	if(!this->valida()){
		return false;
	}
	//proviamo ad aprire.
	FILE* input = fopen(this->in, "r");
	if (input == NULL){
		cerr << "Errore" << endl;
		return false;
	}
	if(this->outIsCartella){	
		//TODO estrapolare il nome dell'input e aggiungerlo all'output
	}
	FILE* output = fopen(this->out, "a");
	this->offsetFile = 1;
	this->bufferone = (char*) malloc(sizeof(char)*this->DIMBUFFER);
	while((this->dimFile -this->offsetFile) > 0){
		if((this->dimFile - this->offsetFile- this->DIMBUFFER)>0){
			this->offsetFile += this->DIMBUFFER;
			this->dimBufferone = this->DIMBUFFER;
		}
		else{
			this->dimBufferone = (this->dimFile - this->offsetFile);
			this->offsetFile = this->dimFile;
		}
		fread(this->bufferone, (this->offsetFile - this->dimBufferone), this->offsetFile, input);
		fwrite(this->bufferone, sizeof(char), this->dimBufferone, output);		
	}
	free(this->bufferone);
	fclose(input);
	fclose(output);
	return true;
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
	this->outIsCartella = false;
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
