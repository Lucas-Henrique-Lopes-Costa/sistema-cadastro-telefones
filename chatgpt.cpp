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
  int quantidade;
  float preco;
  string fabricante;
  int anoCriacao;
  string descricao;
};

vector<Celular> celulares;

void cadastrarCelular()
{
  Celular celular;
  cout << "Identificador: ";
  cin >> celular.identificador;
  cin.ignore();
  cout << "Nome: ";
  getline(cin, celular.nome);
  cout << "Quantidade: ";
  cin >> celular.quantidade;
  cout << "Preco: ";
  cin >> celular.preco;
  cin.ignore();
  cout << "Fabricante: ";
  getline(cin, celular.fabricante);
  cout << "Ano de Criacao: ";
  cin >> celular.anoCriacao;
  cin.ignore();
  cout << "Descricao: ";
  getline(cin, celular.descricao);

  celulares.push_back(celular);
  cout << "Celular cadastrado com sucesso!" << endl;
}

void buscarCelular()
{
  int identificador;
  cout << "Digite o identificador do celular: ";
  cin >> identificador;

  auto it = find_if(celulares.begin(), celulares.end(), [identificador](const Celular &celular)
                    { return celular.identificador == identificador; });

  if (it != celulares.end())
  {
    cout << "Celular encontrado:" << endl;
    cout << "Identificador: " << it->identificador << endl;
    cout << "Nome: " << it->nome << endl;
    cout << "Quantidade: " << it->quantidade << endl;
    cout << "Preco: " << it->preco << endl;
    cout << "Fabricante: " << it->fabricante << endl;
    cout << "Ano de Criacao: " << it->anoCriacao << endl;
    cout << "Descricao: " << it->descricao << endl;
  }
  else
  {
    cout << "Celular nao encontrado." << endl;
  }
}

void alterarCelular()
{
  int identificador;
  cout << "Digite o identificador do celular que deseja alterar: ";
  cin >> identificador;

  auto it = find_if(celulares.begin(), celulares.end(), [identificador](const Celular &celular)
                    { return celular.identificador == identificador; });

  if (it != celulares.end())
  {
    cout << "Digite os novos dados do celular:" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, it->nome);
    cout << "Quantidade: ";
    cin >> it->quantidade;
    cout << "Preco: ";
    cin >> it->preco;
    cin.ignore();
    cout << "Fabricante: ";
    getline(cin, it->fabricante);
    cout << "Ano de Criacao: ";
    cin >> it->anoCriacao;
    cin.ignore();
    cout << "Descricao: ";
    getline(cin, it->descricao);

    cout << "Celular alterado com sucesso!" << endl;
  }
  else
  {
    cout << "Celular nao encontrado." << endl;
  }
}

void exportarCSV()
{
  ofstream file("celulares.csv");
  if (file.is_open())
  {
    file << "Identificador,Nome,Quantidade,Preco,Fabricante,Ano de Criacao,Descricao\n";
    for (const auto &celular : celulares)
    {
      file << celular.identificador << ","
           << celular.nome << ","
           << celular.quantidade << ","
           << celular.preco << ","
           << celular.fabricante << ","
           << celular.anoCriacao << ","
           << celular.descricao << "\n";
    }
    file.close();
    cout << "Dados exportados para celulares.csv" << endl;
  }
  else
  {
    cout << "Erro ao abrir o arquivo." << endl;
  }
}

void importarCSV()
{
  celulares.clear();

  ifstream file("celulares.csv");
  if (file.is_open())
  {
    string line;
    getline(file, line); // Ignorar a linha de cabeçalho
    while (getline(file, line))
    {
      stringstream ss(line);
      string field;
      vector<string> fields;

      while (getline(ss, field, ','))
      {
        fields.push_back(field);
      }

      Celular celular;
      celular.identificador = stoi(fields[0]);
      celular.nome = fields[1];
      celular.quantidade = stoi(fields[2]);
      celular.preco = stof(fields[3]);
      celular.fabricante = fields[4];
      celular.anoCriacao = stoi(fields[5]);
      celular.descricao = fields[6];

      celulares.push_back(celular);
    }
    file.close();
    cout << "Dados importados de celulares.csv" << endl;
  }
  else
  {
    cout << "Erro ao abrir o arquivo." << endl;
  }
}

void ordenarPorAno()
{
  sort(celulares.begin(), celulares.end(), [](const Celular &c1, const Celular &c2)
       { return c1.anoCriacao < c2.anoCriacao; });
  cout << "Celulares ordenados por ano de criacao." << endl;
}

int main()
{
  int opcao;

  do
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
    cin >> opcao;

    switch (opcao)
    {
    case 1:
      cadastrarCelular();
      break;
    case 2:
      buscarCelular();
      break;
    case 3:
      alterarCelular();
      break;
    case 4:
      exportarCSV();
      break;
    case 5:
      importarCSV();
      break;
    case 6:
      ordenarPorAno();
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
