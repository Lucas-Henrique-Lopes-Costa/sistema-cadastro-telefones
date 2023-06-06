#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Celular
{
  int identificador;
  string nome;
  float preco;
  int quantidade;
  string fabricante;
  int anoCriacao;
  string descricao;
};

// Função para exibir o menu de opções
void exibirMenu()
{
  cout << "===== Sistema de Cadastro de Celulares =====" << endl;
  cout << "1 - Cadastrar Celular" << endl;
  cout << "2 - Buscar Celular" << endl;
  cout << "3 - Alterar Celular" << endl;
  cout << "4 - Exportar para CSV" << endl;
  cout << "5 - Importar de CSV" << endl;
  cout << "6 - Ordenar por Ano de Criacao" << endl;
  cout << "0 - Sair" << endl;
  cout << "Opcao: ";
}

// Função para cadastrar um celular
void cadastrarCelular(vector<Celular> &celulares)
{
  Celular celular;

  cout << "Identificador: ";
  cin >> celular.identificador;

  cout << "Nome: ";
  cin.ignore();
  getline(cin, celular.nome);

  cout << "Preco: ";
  cin >> celular.preco;

  cout << "Quantidade: ";
  cin >> celular.quantidade;

  cout << "Fabricante: ";
  cin.ignore();
  getline(cin, celular.fabricante);

  cout << "Ano de Criacao: ";
  cin >> celular.anoCriacao;

  cout << "Descricao: ";
  cin.ignore();
  getline(cin, celular.descricao);

  celulares.push_back(celular);
  cout << "Celular cadastrado com sucesso!" << endl;
}

// Função para buscar um celular pelo identificador
void buscarCelular(const vector<Celular> &celulares)
{
  int identificador;
  cout << "Digite o identificador do celular: ";
  cin >> identificador;

  bool encontrado = false;
  for (const Celular &celular : celulares)
  {
    if (celular.identificador == identificador)
    {
      cout << "Celular encontrado:" << endl;
      cout << "Identificador: " << celular.identificador << endl;
      cout << "Nome: " << celular.nome << endl;
      cout << "Preco: " << celular.preco << endl;
      cout << "Quantidade: " << celular.quantidade << endl;
      cout << "Fabricante: " << celular.fabricante << endl;
      cout << "Ano de Criacao: " << celular.anoCriacao << endl;
      cout << "Descricao: " << celular.descricao << endl;
      encontrado = true;
      break;
    }
  }

  if (!encontrado)
  {
    cout << "Celular nao encontrado." << endl;
  }
}

// Função para alterar um celular existente
void alterarCelular(vector<Celular> &celulares)
{
  int identificador;
  cout << "Digite o identificador do celular a ser alterado: ";
  cin >> identificador;

  bool encontrado = false;
  for (Celular &celular : celulares)
  {
    if (celular.identificador == identificador)
    {
      cout << "Digite os novos dados do celular:" << endl;

      cout << "Nome: ";
      cin.ignore();
      getline(cin, celular.nome);

      cout << "Preco: ";
      cin >> celular.preco;

      cout << "Quantidade: ";
      cin >> celular.quantidade;

      cout << "Fabricante: ";
      cin.ignore();
      getline(cin, celular.fabricante);

      cout << "Ano de Criacao: ";
      cin >> celular.anoCriacao;

      cout << "Descricao: ";
      cin.ignore();
      getline(cin, celular.descricao);

      cout << "Celular alterado com sucesso!" << endl;
      encontrado = true;
      break;
    }
  }

  if (!encontrado)
  {
    cout << "Celular nao encontrado." << endl;
  }
}

// Função para exportar os celulares para um arquivo CSV
void exportarCSV(const vector<Celular> &celulares)
{
  ofstream arquivo("celulares.csv");
  if (arquivo.is_open())
  {
    arquivo << "Identificador;Nome;Preco;Quantidade;Fabricante;Ano de Criacao;Descricao do produto" << endl;
    for (const Celular &celular : celulares)
    {
      arquivo << celular.identificador << ";" << celular.nome << ";" << celular.preco << ";" << celular.quantidade << ";" << celular.fabricante << ";" << celular.anoCriacao << ";" << celular.descricao << endl;
    }
    arquivo.close();
    cout << "Dados exportados para celulares.csv" << endl;
  }
  else
  {
    cout << "Erro ao abrir o arquivo." << endl;
  }
}

// Função para importar celulares de um arquivo CSV
void importarCSV(vector<Celular> &celulares)
{
  ifstream arquivo("celulares.csv");
  if (arquivo.is_open())
  {
    celulares.clear();
    string linha;
    getline(arquivo, linha); // Descarta o cabeçalho

    while (getline(arquivo, linha))
    {
      stringstream ss(linha);
      string campo;
      Celular celular;

      getline(ss, campo, ';');
      celular.identificador = stoi(campo);

      getline(ss, celular.nome, ';');

      getline(ss, campo, ';');
      celular.preco = stof(campo);

      getline(ss, campo, ';');
      celular.quantidade = stoi(campo);

      getline(ss, celular.fabricante, ';');

      getline(ss, campo, ';');
      celular.anoCriacao = stoi(campo);

      getline(ss, celular.descricao, ';');

      celulares.push_back(celular);
    }

    arquivo.close();
    cout << "Dados importados do arquivo celulares.csv" << endl;
  }
  else
  {
    cout << "Erro ao abrir o arquivo." << endl;
  }
}

// Função para ordenar os celulares por ano de criação
bool compararAnoCriacao(const Celular &a, const Celular &b)
{
  return a.anoCriacao < b.anoCriacao;
}

void ordenarPorAnoCriacao(vector<Celular> &celulares)
{
  sort(celulares.begin(), celulares.end(), compararAnoCriacao);
  cout << "Celulares ordenados por ano de criacao." << endl;
}

int main()
{
  vector<Celular> celulares;

  int opcao;
  do
  {
    exibirMenu();
    cin >> opcao;

    switch (opcao)
    {
    case 1:
      cadastrarCelular(celulares);
      break;
    case 2:
      buscarCelular(celulares);
      break;
    case 3:
      alterarCelular(celulares);
      break;
    case 4:
      exportarCSV(celulares);
      break;
    case 5:
      importarCSV(celulares);
      break;
    case 6:
      ordenarPorAnoCriacao(celulares);
      break;
    case 0:
      cout << "Saindo..." << endl;
      break;
    default:
      cout << "Opcao invalida." << endl;
      break;
    }

    cout << endl;
  } while (opcao != 0);

  return 0;
}
