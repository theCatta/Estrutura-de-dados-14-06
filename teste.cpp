#include <iostream>
using namespace std;

struct No{
	int dado;
	No *prox;
};

struct Fila{
	No *ini;
	No *fim;
};

Fila* init(){
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	
	return f;	
}

int isEmpty(Fila *f){
	return (f->ini == NULL);
}

int count(Fila *f){
	int qtd = 0;
	No* no = f->ini;
	while(no != NULL){
		qtd++;
		no = no->prox;
	}
	
	return qtd;
}

void print(Fila *f){
	cout << "-----------Fila-----------" << endl;
	
	No *no = f->ini;
	while(no != NULL){
		cout << no->dado << endl;
		no = no->prox;
	}
	
	cout << "--------------------------" << endl;
}

void enQueue(Fila *f, int v){
	No *no = new No;
	No->dado = v;
	No->prox = NULL;
	
	if(isEmpty(f)){
		f->ini = no; 
	}else {
		f->fim->prox = no;
	}
	
	f->fim = no;
}

int deQueue(Fila *f){
	int ret;	
	if(isEmpty(f)){
		return 99;
	}
	else{
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if(f->ini == NULL){
			f->fim = NULL;
		}
	}
	
	return ret;
}

void freeFila(Fila *f){
	No *no -> f->ini;
	while(no != NULL){
		No *temp = no->prox;
		//free(no);
		no = temp;
	}
	//free(f);
}

int home(){
	int key;
	
	cout << "0. Sair." << endl; 
	cout << "1. Gerar Senha." << endl;
	cout << "2. Realizar Atendimento." << endl;
	cin >> key;
	
	while(key > 2 || key < 0){
		cout << "Digite uma das opções validas." << endl;
		cin >> key;
	}
	
	return key;
}

int main(int argc, char** argv)
{
	int key;
	
	Fila *senhasGeradas;
	senhasGeradas = init();
	
	key = home();
	
	while(key != 0){
		switch()
		{
		case value:
			break;
		default:
			break;
		}
	}
	
	return 0;
}
