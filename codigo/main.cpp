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

  string linha;
  getline(arquivoIn, linha); // dicartando a primeira linha do arquivo

  // separar cada linha do arquivo
  int indentificador[100] = {-1};
  string nome[100] = {""};
  float preco[100] = {-1};
  int quantidade[100] = {-1};
  string fabricante[100] = {""};
  int anoCriacao[100] = {-1};
  string descricao[100] = {""};

  int i = 0;

  while (!arquivoIn.eof())
  {
    getline(arquivoIn, linha);

    if (linha == "")
    {
      continue;
    }

    // indentificador
    int pos = linha.find(";");
    indentificador[i] = stoi(linha.substr(0, pos)); // stoi converte string para int

    // nome
    int pos2 = linha.find(";", pos + 1);
    nome[i] = linha.substr(pos + 1, pos2 - pos - 1);

    // preco
    pos = linha.find(";", pos2 + 1);
    preco[i] = stof(linha.substr(pos2 + 1, pos - pos2 - 1)); // stof converte string para float

    // quantidade
    pos2 = linha.find(";", pos + 1);
    quantidade[i] = stoi(linha.substr(pos + 1, pos2 - pos - 1));

    // fabricante
    pos = linha.find(";", pos2 + 1);
    fabricante[i] = linha.substr(pos2 + 1, pos - pos2 - 1);

    // anoCriacao
    pos2 = linha.find(";", pos + 1);
    anoCriacao[i] = stoi(linha.substr(pos + 1, pos2 - pos - 1));

    // descricao
    pos = linha.find(";", pos2 + 1);
    descricao[i] = linha.substr(pos2 + 1, pos - pos2 - 1);

    i++;
  }

  arquivoIn.close();

  // Exibir o ano do primeiro celular cadastrado
  cout << "Utlimo celular cadastrado: " << endl;
  cout << "Identificador: " << indentificador[i - 1] << endl;
  cout << "Nome: " << nome[i - 1] << endl;
  cout << "Preco: " << preco[i - 1] << endl;
  cout << "Quantidade: " << quantidade[i - 1] << endl;
  cout << "Fabricante: " << fabricante[i - 1] << endl;
  cout << "Ano de Criacao: " << anoCriacao[i - 1] << endl;
  cout << "Descricao: " << descricao[i - 1] << endl;

  return 0;
}