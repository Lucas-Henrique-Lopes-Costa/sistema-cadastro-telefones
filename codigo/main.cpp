/*
  # Projeto: Sistema de cadastro de telefones celulares para venda

  ## Grupo

  Lucas Henrique, Pedro Gonçalves, Gabriel Carvalho

  ## Bases

  Identificador

  Nome

  Quantidade

  Preço

  Fabricante

  Ano de criação

  Descrição do produto

  ## Sobre o Projeto

  ### Introdução

  O objetivo deste projeto é desenvolver um sistema de gerenciamento de vendas de smartphones, que permitirá às empresas monitorar e controlar suas transações de venda de forma eficiente. Com o crescimento do mercado de dispositivos móveis, é essencial que as empresas tenham ferramentas adequadas para acompanhar e analisar suas vendas de smartphones.

  ### Sobre as bases

  Identificador: Cada smartphone vendido receberá um identificador exclusivo, que será utilizado para rastrear e identificar o dispositivo. Tipo de dado: int.

  Nome: O nome do smartphone será registrado, facilitando a identificação do modelo específico. Tipo de dado:  string com espaço

  Preço: Qual é o valor de venda do produto por unidade de cada smartphone. Tipo de dado: float.

  Quantidade: Será registrado o número de unidades em estoque de cada smartphone, permitindo uma logística precisa. Tipo de dado: int.

  Fabricante: O nome do fabricante será armazenado, fornecendo informações sobre a origem do smartphone. Tipo de dado: string.

  Ano de criação: O ano de criação do smartphone será registrado, possibilitando análises históricas e identificação de tendências. Tipo de dado: int

  Descrição do produto: Será incluída uma descrição detalhada do smartphone, fornecendo informações sobre suas características e especificações técnicas. Tipo de dado:  string com espaço.

  ## Funcionalidades

  Cadastro de vendas: O sistema permitirá que as empresas registrem as vendas de smartphones, inserindo as informações relevantes, como identificador, nome, quantidade, fabricante, ano de criação e descrição do produto.

  Controle de estoque: O sistema atualizará automaticamente o estoque de smartphones disponíveis com base nas vendas registradas, evitando vendas duplicadas ou erros de estoque.

  Ordenação por ano, evitando que produtos fiquem parados nos estoques por longos períodos de tempo.

  Importação e exportação em .csv

*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
  // Recebendo dados do arquivo celulares.csv e colocando em um vetor separando cada vetor pela determinada linha
  ifstream arquivoIn("celulares.csv");

  if (!arquivoIn.is_open())
  {
    cout << "Erro ao abrir o arquivo!" << endl;
    return 0;
  }

  // separar cada linha do arquivo em: Indentificador	Nome; Preco	Quantidade; Fabricante; Ano de criacao; Descricao do produto
  string linha;
  getline(arquivoIn, linha);
  
  cout << linha << endl;

  arquivoIn.close();



  return 0;
}