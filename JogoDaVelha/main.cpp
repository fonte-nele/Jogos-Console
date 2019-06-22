#include "jogo_da_velha.h"
#include<cstdlib>

int main()
{
	int i,x,y,jogadas=0;
	string nome1,nome2;
	char jog1,jog2,m[n][n];
	
	criar_matriz(m);
	
	cout<<"Digite o nome do jogador 1:\n"<<endl;
	getline(cin,nome1);
	cout<<"\nJogador "<<maiusculo(nome1)<<", escolha a peca que deseja jogar: X ou O"<<endl<<endl;
	cin>>jog1;
	while(tolower(jog1)!='x' && tolower(jog1)!='o')
	{
		system("cls");
		cout<<"PECA INVALIDA. FAVOR TENTAR NOVAMENTE....."<<endl<<endl;
		cout<<"Jogador "<<maiusculo(nome1)<<", escolha a peca que deseja jogar: X ou O"<<endl<<endl;
		cin>>jog1;
	}
	
	cout<<"\nDigite o nome do jogador 2:\n"<<endl;
	cin.ignore();
	getline(cin,nome2);
	if(tolower(jog1)=='x')
	{
		jog2 = 'O';
	}
	else
	{
		jog2 = 'X';
	}
	system("cls");
	
	imprimir_matriz(m,maiusculo(nome1));
	
	for(i=0;i<9;i++)
	{
		if(i%2==0)
		{
			cout<<"\nJogador "<<maiusculo(nome1)<<",digite as coordenadas(linha,coluna) que deseja colocar sua peca:\n";
			cin>>x>>y;
			while((x<1 || x>3) ||(y<1 ||y>3))
			{
				cout<<"POSICAO DIGITADA INEXISTENTE NO TABULEIRO. FAVOR TENTAR NOVAMENTE...."<<endl<<endl;
				cout<<"\nJogador "<<maiusculo(nome1)<<",digite as coordenadas(linha,coluna) que deseja colocar sua peca:\n";
				cin>>x>>y;
			}
			while(!verificar_matriz(m,x-1,y-1))
			{
				cout<<"\nESTA POSICAO JA ESTA PREENCHIDA NO TABULEIRO. FAVOR TENTAR NOVAMENTE...."<<endl;
				cout<<"\nJogador "<<maiusculo(nome1)<<",digite as coordenadas(linha,coluna) que deseja colocar sua peca:\n";
				cin>>x>>y;
			}
			preencher_matriz(m,nome1,jog1,x-1,y-1);
			
			system("cls");
			imprimir_matriz(m,maiusculo(nome2));
			if(verificar_comb(m,toupper(jog1)))
			{
				system("cls");
				ganhador(maiusculo(nome1),maiusculo(nome2));
				break;
			}
			
		}
		else
		{
			cout<<"\nJogador "<<maiusculo(nome2)<<",digite as coordenadas(linha,coluna) que deseja colocar sua peca:\n";
			cin>>x>>y;
			while((x<1 || x>3) ||(y<1 ||y>3))
			{
				cout<<"POSICAO DIGITADA INEXISTENTE NO TABULEIRO. FAVOR TENTAR NOVAMENTE...."<<endl<<endl;
				cout<<"\nJogador "<<maiusculo(nome2)<<",digite as coordenadas(linha,coluna) que deseja colocar sua peca:\n";
				cin>>x>>y;
			}
			while(!verificar_matriz(m,x-1,y-1))
			{
				cout<<"\nESTA POSICAO JA ESTA PREENCHIDA NO TABULEIRO. FAVOR TENTAR NOVAMENTE...."<<endl;
				cout<<"\nJogador "<<maiusculo(nome2)<<",digite as coordenadas(linha,coluna) que deseja colocar sua peca:\n";
				cin>>x>>y;
			}
			preencher_matriz(m,nome2,jog2,x-1,y-1);
			
			system("cls");
			imprimir_matriz(m,maiusculo(nome1));
			if(verificar_comb(m,toupper(jog2)))
			{
				system("cls");
				ganhador(maiusculo(nome2),maiusculo(nome1));
				break;
			}
		}	
		jogadas++;
	}
	if(jogadas==9)
	{
		system("cls");
		cout<<"ESTE JOGO NAO HOUVE VENCEDOR!!! MAIS SORTE NA PROXIMA...."<<endl<<endl;
		cout<<"JOGO FINALIZADO COM SUCESSO...."<<endl<<endl;
	}
	else
	{
		cout<<"JOGO FINALIZADO COM SUCESSO...."<<endl<<endl;
	}
	return 0;
}