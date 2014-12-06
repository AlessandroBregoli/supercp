#include "barra.h"

const int Barra::STANDARD_CARACHTERS;

Barra::Barra(int max){
	if(max > 0){
		this->max = max;
	}
	else{
		this->max = max * (-1);
	}
	this->num_states_bar = 74;
	this->state_bar = 0;
}

bool Barra::change_state(int val){
	int tmp = (val * this->num_states_bar)/this->max;	
	if(tmp > this->max){
		return false;
	}
	if(tmp < 0){
		return false;
	}
	if(tmp < this->state_bar || (val*100/this->max) < (this->val*100/this->max)){
		this->state_bar = tmp;
		this->val = val;
		this->clear_bar();
		this->print_bar();
	}
	else if(tmp > this->state_bar || (val*100/this->max) < (this->val*100/this->max)){
		this->state_bar = tmp;
		this->val = val;
		this->print_bar();
	}
	return true;
}

void Barra::clear_bar(){
	cout << "\r";
	for(int i = 0; i < (this->num_states_bar + Barra::STANDARD_CARACHTERS); i++){
		cout << " ";
	}
}

void Barra::print_bar(){
	cout << "\r";
	cout << "[";
	for(int i = 0; i < (this->state_bar - 1); i++){
		cout << "=";
	}
	if(this->state_bar > 0){
		cout << ">";
	}
	for(int i = 0; i < (this->num_states_bar - this->state_bar); i++){
		cout << " ";
	}
	int percentuale = this->val*100/this->max;
	cout << "]"<< percentuale << "%";
}
