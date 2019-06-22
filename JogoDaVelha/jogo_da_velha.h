#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H
#define n 4
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void criar_matriz(char[n][n]);
string maiusculo(string);
void imprimir_matriz(char[n][n],string);
bool verificar_matriz(char[n][n],int,int);
void preencher_matriz(char[n][n],string,char,int,int);
bool verificar_comb(char[n][n],char);
void ganhador(string,string);



#endif