#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int processamento(int compara,int opcao)
{
	system("cls");//limpa tela
	//Definindo valores
	float masc[]={160,183.5,171.5,
				36,49,42.8,
				133,154.5,143.2,
				29,42,35.5,
				16,20,18.2};
	float fem[]={149,169,158.8,
				34,44,38.9,
				122,139.5,131,
				33,45,39.1,
				15,17.5,16.6};
	//Valores tabelados de médias das medidas masculinas e femininas, segundo estudo realizado no ABC paulista
	//A padronização dos vetores segue o modelo:
	//Menor valor (5%) , Maior valor (95%) , Média
	//Seguindo a ordem: altura, tronco, ombros, quadril, e mãos
	float valor=0.0;
	if(opcao==1)//masc
		switch(compara)
		{
			case 1://Altura
				cout<<"Digite a altura de seu paciente: "<<endl;
				cin>>valor;
				if(valor <= masc[0])cout<<"\nSeu paciente está abaixo da média de altura!";
				else if(valor >= masc[1])cout<<"\nSeu paciente está acima da média de altura!";
				else if(valor > masc[0] && valor < masc[1])cout<<"\nSeu paciente está na média de altura!";
				break;
			case 2://Tronco
				cout<<"Digite o tamanho do tronco de seu paciente"<<endl;
				cin>>valor;
				if(valor <= masc[3])cout<<"\nSeu paciente está abaixo da média de tamanho de tronco!";
				else if(valor >= masc[4])cout<<"\nSeu paciente está acima da média de tamanho de tronco!";
				else if(valor > masc[3] && valor < masc[4])cout<<"\nSeu paciente está na média de altura!";
				break;
			case 3://Ombros
				cout<<"Digite o tamanho dos ombros de seu paciente"<<endl;
				cin>>valor;
				if(valor <= masc[6])cout<<"\nSeu paciente está abaixo da média de tamanho de ombros!";
				else if(valor >= masc[7])cout<<"\nSeu paciente está acima da média de tamanho de ombros!";
				else if(valor > masc[6] && valor < masc[7])cout<<"\nSeu paciente está na média de tamanho de ombros!";
				break;
			case 4://Quadril
				cout<<"Digite o tamanho do quadril de seu paciente"<<endl;
				cin>>valor;
				if(valor <= masc[9])cout<<"\nSeu paciente está abaixo da média de tamanho de quadril!";
				else if(valor >= masc[10])cout<<"\nSeu paciente está acima da média de tamanho de quadril!";
				else if(valor > masc[9] && valor < masc[10])cout<<"\nSeu paciente está na média de tamanho de quadril!";
				break;
			case 5://Mãos
				cout<<"Digite o tamanho das mãos de seu paciente"<<endl;
				cin>>valor;
				if(valor <= masc[12])cout<<"\nSeu paciente está abaixo da média de tamanho das mãos!";
				else if(valor >= masc[13])cout<<"\nSeu paciente está acima da média de tamanho das mãos!";
				else if(valor > masc[12] && valor < masc[13]) cout<<"\nSeu paciente está na média de tamanho das mãos!";
				break;
			default:
				cout<<"Error not found!";
				break;
		}
	else if(opcao==2)//fem
		switch(compara)
		{
			case 1://Altura
				cout<<"Digite a altura de sua paciente: "<<endl;				
				cin>>valor;
				if(valor <= fem[0])cout<<"\nSua paciente está abaixo da média de altura!";
				else if(valor >= fem[1])cout<<"\nSua paciente está acima da média de altura!";
				else if(valor > fem[0] && valor < fem[1]) cout<<"\nSua paciente está na média de altura!";
				break;
			case 2://Tronco
				cout<<"Digite o tamanho do tronco de sua paciente"<<endl;
				cin>>valor;
				if(valor <= fem[3])cout<<"\nSua paciente está abaixo da média de tamanho de tronco!";
				else if(valor >= fem[4])cout<<"\nSua paciente está acima da média de tamanho de tronco!";
				else if(valor > fem[3] && valor < fem[4]) cout<<"\nSua paciente está na média de tamanho de tronco!";
				break;
			case 3://Ombros
				cout<<"Digite o tamanho dos ombros de sua paciente"<<endl;
				cin>>valor;
				if(valor <= fem[6])cout<<"\nSua paciente está abaixo da média de tamanho de ombros!";
				else if(valor >= fem[7])cout<<"\nSua paciente está acima da média de tamanho de ombros!";
				else if(valor > fem[6] && valor < fem[7])cout<<"\nSua paciente está na média de tamanho de ombros!";
				break;
			case 4://Quadril
				cout<<"Digite o tamanho do quadril de sua paciente"<<endl;
				cin>>valor;
				if(valor <= fem[9])cout<<"\nSua paciente está abaixo da média de tamanho de quadril!";
				else if(valor >= fem[10])cout<<"\nSua paciente está acima da média de tamanho de quadril!";
				else if(valor > fem[9] && valor < fem[10]) cout<<"\nSua paciente está na média de tamanho de quadril!";
				break;
			case 5://Mãos
				cout<<"Digite o tamanho das mãos de sua paciente"<<endl;
				cin>>valor;
				if(valor < fem[12])cout<<"\nSua paciente está abaixo da média de tamanho das mãos!";
				else if(valor > fem[13])cout<<"\nSua paciente está acima da média de tamanho das mãos!";
				else if(valor > fem[12] && valor < fem[13]) cout<<"\nSua paciente está na média de tamanho das mãos!";
				break;
			default:
				cout<<"Error not found!";
				break;
		}
}
void menu()
{
	int opcao=0,compara=0, chamada=0;
	cout<<"1- Masculino 2- Feminino\n"<<endl;
	cin>>opcao;
	if(opcao==1){
		cout<<"1-Altura  2-Tronco  3-Ombros  4-Quadril  5-Mãos\nEscolha: ";
		cin>>compara;
		
	}
	else{
		cout<<"1-Altura  2-Tronco  3-Ombros  4-Quadril  5-Mãos\nEscolha: ";
		cin>>compara;
	}
	processamento(compara,opcao);	
	cout<<"\nPressione enter para continuar";
	getche();
	system("cls");
}
main()
{
	setlocale(LC_ALL,"Portuguese");
	system("color 0a");
	int opcao=0;
	cout << "Olá! Bem vindo ao simulador e comparador de tamanhos!"<<endl;
	cout << "Para começarmos nossas atividades, selecione sua opção para comparar, por favor:"<<endl;
	do{
		menu();
		cout<<"Deseja recomparar? 1 para sim, 2 para não: ";
		cin>>opcao;
		system("cls");
	}while(opcao!=2);
	
}
