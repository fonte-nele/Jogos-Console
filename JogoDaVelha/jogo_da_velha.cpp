#include "jogo_da_velha.h"

int cont=1,rest=9;
void criar_matriz(char m[n][n])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			m[i][j] = '0';
		}
	}
}

string maiusculo(string nome)
{
	char ch;
	int tam = nome.size();
	for(int i=0;i<tam;i++)
	{
		ch = nome[i];
		ch = toupper(ch);
		nome[i] = ch;
	}
	return nome;
}

void imprimir_matriz(char m[n][n], string nome)
{
	cout<<"\n\nVez do(a) jogador(a) "<<nome<<endl;
	cout<<"\n\nTabuleiro do jogo no momento "<<cont<<":\n"<<endl;
	
	int i,j;
	for(i=0;i<3;i++)
	{
		
		for(j=0;j<3;j++)
		{
			if(m[i][j]=='0')
			{
				if(j==2)
				{
					cout<<"   ";
				}
				else
				{
					cout<<"   "<<"//";
				}
			}
			else
			{
				if(j==2)
				{
					cout<<" "<<m[i][j];
				}
				else
				{
					cout<<" "<<m[i][j]<<" "<<"//";
				}
			}
		}
		if(i==2)
		{
			cout<<endl<<endl;
		}
		else
		{
			cout<<endl<<"=============="<<endl;
		}
	}
	cout<<"RESTAM APENAS "<<rest<<" JOGADAS... PENSE BEM...."<<endl;
	cont++;
	rest--;
}

void preencher_matriz(char m[n][n],string nome,char peca,int lin,int col)
{
	m[lin][col] = toupper(peca);
}

bool verificar_matriz(char m[n][n],int lin,int col)
{
	if(m[lin][col]=='0')
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool verificar_comb(char m[n][n],char peca)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(m[i][j]==peca)
			{
				if(m[i][j+1]==peca)
				{
					if(m[i][j+2]==peca)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					if(m[i+1][j]==peca)
					{
						if(m[i+2][j]==peca)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						if(m[i+1][j+1]==peca)
						{
							if(m[i+2][j+2]==peca)
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}
				}
			}
			else
			{
				if(m[i][j+1]==peca)
				{
					if(m[i+1][j+1]==peca)
					{
						if(m[i+2][j+1]==peca)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					if(m[i][j+2]==peca)
					{
						if(m[i+1][j+2]==peca)
						{
							if(m[i+2][j+2]==peca)
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						{
							if(m[i+1][j+1]==peca)
							{
								if(m[i+2][j]==peca)
								{
									return true;
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}	
						}
					}
					else
					{
						if(m[i+1][j]==peca)
						{
							if(m[i+1][j+1]==peca)
							{
								if(m[i+1][j+2]==peca)
								{
									return true;
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						else
						{
							if(m[i+2][j]==peca)
							{
								if(m[i+2][j+1]==peca)
								{
									if(m[i+2][j+2]==peca)
									{
										return true;
									}
									else
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
							return false;
						}
						return false;
					}
					return false;
				}
				return false;
			}
		}
	}
	return false;
}

void ganhador(string nome,string perdedor)
{
	cout<<"  ||||||||||||||          |||            ||||||||||||||            |||            ||||||||||      ||||||||||||||  ||||        ||     |||||||||"<<endl;
	cout<<"  ||          ||        ||| |||          ||          ||          ||| |||          ||        |||   ||              || ||       ||    ||        "<<endl;
	cout<<"  ||          ||       |||   |||         ||          ||         |||   |||         ||          ||  ||              ||  ||      ||    ||        "<<endl;
	cout<<"  ||          ||      |||     |||        ||          ||        |||     |||        ||          ||  ||              ||   ||     ||      ||      "<<endl;
	cout<<"  ||          ||     |||       |||       ||          ||       |||       |||       ||         ||   ||              ||    ||    ||        ||    "<<endl;
	cout<<"  ||||||||||||||    |||||||||||||||      ||||||||||||||      |||||||||||||||      |||||||||||||   ||||||||||||||  ||     ||   ||         ||   "<<endl;
	cout<<"  ||               |||           |||     ||  |||            |||           |||     ||         ||   ||              ||      ||  ||          ||  "<<endl;
	cout<<"  ||              |||             |||    ||    |||         |||             |||    ||          ||  ||              ||       || ||           || "<<endl;
	cout<<"  ||             |||               |||   ||      |||      |||               |||   ||        |||   ||              ||        ||||          ||  "<<endl;
	cout<<"  ||            |||                 |||  ||        |||   |||                 |||  ||||||||||      ||||||||||||||  ||         |||    |||||||   "<<endl;
	cout<<"\n\n\n\nO JOGADOR "<<nome<<" GANHOU A PARTIDA!!!!"<<endl<<endl<<endl;
	cout<<"\n\nCHUPA "<<perdedor<<" PODE CHORAR!!!"<<endl<<endl<<endl;
	
}