#include <iostream>
#include <locale.h>
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
	no->dado = v;
	no->prox = NULL;
	
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
	
	cout << "Senha " << ret << " foi atendida." << endl << endl;
	
	return ret;
}

void freeFila(Fila *f){
	No *no = f->ini;
	while(no != NULL){
		No *temp = no->prox;
		//free(no);
		no = temp;
	}
	//free(f);
}

int home(Fila *n){
	int key;
	
	cout << "--------------Pendentes-------------" << endl;
	cout << "Quantidade de senhas pendentes: " << count(n)  << endl; 
	cout << "------------------------------------" << endl;
	
	cout << "----------------Menu----------------" << endl;
	cout << "0. Finalizar Atendimentos." << endl; 
	cout << "1. Gerar Senha." << endl;
	cout << "2. Realizar Atendimento." << endl << endl;
	
	cout << "Escolha uma opção: ";
	cin >> key;
	cout << "------------------------------------" << endl;
	
	while(key > 2 || key < 0){
		cout << "Digite uma das opções validas." << endl;
		cin >> key;
	}
	
	return key;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
    int soma = 0;
    int senha;
	int key;
	int n;
	
	Fila *senhasGeradas;
	senhasGeradas = init();
	Fila *senhasAtendidas;
	senhasAtendidas = init();
	
	key = home(senhasGeradas);
	
	while(!isEmpty(senhasGeradas) || key!=0){
		switch(key)
		{
		case 0:
			if(!isEmpty(senhasGeradas)){
				cout << "Termine de atendender todas as senhas pendentes!!!" << endl << endl;
			}
			key = home(senhasGeradas);
			break;	
		case 1:
		    enQueue(senhasGeradas, (++soma));
		    cout << "Senha gerada: " <<  soma << endl << endl;
		    key = home(senhasGeradas);
			break;
		case 2:
			if(isEmpty(senhasGeradas)){
				cout << "Todas as senhas geradas foram atendidas." << endl << endl;
			}
		    senha = deQueue(senhasGeradas);
		    enQueue(senhasAtendidas, senha);
		    
		    key = home(senhasGeradas);
			break;
		}
	}
	n = count(senhasAtendidas);
	cout << "Programa finalizado. Quantidade de senhas atendidas: " << n << endl << endl;
	
	return 0;
}