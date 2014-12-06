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
	Barra b(100);
	//proviamo ad aprire.
	FILE* input = fopen(this->in, "r");
	if (input == NULL){
		cerr << "Errore nella lettura di " << this->in << endl;
		return false;
	}
	if(this->outIsCartella){	
		//TODO estrapolare il nome dell'input e aggiungerlo all'output
	}
	FILE* output = fopen(this->out, "a");
	
	bool ritorno = true;
	
	this->bufferone = (char*) malloc(sizeof(char)*this->DIMBUFFER);
	if(this->bufferone == NULL){
		cerr << "Errore nell'allocare la memoria per il buffer." << endl;
		return false;
	}
	this->dimBufferone = this->DIMBUFFER;
	size_t tmp = 0;
	while(this->dimBufferone > 0){		
		this->dimBufferone = fread(this->bufferone, sizeof(char), this->dimBufferone, input);
		if(this->dimBufferone == 0 && !feof(input)){
			ritorno = false;
			cerr << "File di input inaccessibile " << endl;
			break;
		}
		if(fwrite(this->bufferone, sizeof(char), this->dimBufferone, output) != this->dimBufferone){
			ritorno = false;
			cerr << "File di destinazione inaccessibile." << endl;
			break;
		}
		tmp++;
		b.change_state((int) (tmp*(100)*this->DIMBUFFER/this->dimFile));
	}
	free(this->bufferone);
	fclose(input);
	fclose(output);
	return ritorno;
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
