#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void buscarPorAnoCriacao(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("cls");

  // perguntar se o usuário que buscar por ano de criação ou por faixa de ano de criação ou por ano de criação minimo ou por ano de criação maximo
  int opcao;

  cout << "===== Buscar por Ano de Criacao =====" << endl;
  cout << "1 - Por Ano de Criacao" << endl;
  cout << "2 - Por Faixa de Ano de Criacao" << endl;
  cout << "3 - Por Ano de Criacao Minimo" << endl;
  cout << "4 - Por Ano de Criacao Maximo" << endl;
  cout << "Opcao: ";

  cin >> opcao;

  bool encontrado = false;
  int cont = 0;

  switch (opcao)
  {
  case 1:
    int anoCriacaoCelular;
    cout << "Digite o ano de criacao do celular: ";
    cin >> anoCriacaoCelular;

    for (int j = 0; j < i; j++)
    {
      if (anoCriacao[j] == anoCriacaoCelular)
      {
        cout << endl
             << "===== Celular Encontrado =====" << endl;
        encontrado = true;

        cout << "Identificador: " << identificador[j] << endl;
        cout << "Nome: " << nome[j] << endl;
        cout << "Preco: " << preco[j] << endl;
        cout << "Quantidade: " << quantidade[j] << endl;
        cout << "Fabricante: " << fabricante[j] << endl;
        cout << "Ano de Criacao: " << anoCriacao[j] << endl;
        cout << "Descricao: " << descricao[j] << endl;

        cont++;
      }
    }

    if (!encontrado)
    {
      cout << "CELULAR NAO ENCONTRADO!" << endl;
    }
    else
    {
      cout << endl
           << "##################################" << endl;
      cout << "Total de celulares encontrados: " << cont;
      cout << endl
           << "##################################" << endl;
    }

    break;
  case 2:
    int anoCriacaoMin, anoCriacaoMax;
    cout << "Digite o ano de criacao minimo: ";
    cin >> anoCriacaoMin;
    cout << "Digite o ano de criacao maximo: ";
    cin >> anoCriacaoMax;

    cout << "=== Celular Encontrado na entre: " << anoCriacaoMin << " e " << anoCriacaoMax << " ===" << endl;

    for (int j = 0; j < i; j++)
    {
      if (anoCriacao[j] >= anoCriacaoMin && anoCriacao[j] <= anoCriacaoMax)
      {
        cout << endl;
        encontrado = true;

        cout << "Identificador: " << identificador[j] << endl;
        cout << "Nome: " << nome[j] << endl;
        cout << "Preco: " << preco[j] << endl;
        cout << "Quantidade: " << quantidade[j] << endl;
        cout << "Fabricante: " << fabricante[j] << endl;
        cout << "Ano de Criacao: " << anoCriacao[j] << endl;
        cout << "Descricao: " << descricao[j] << endl;

        cont++;
      }
    }

    if (!encontrado)
    {
      cout << "CELULAR NAO ENCONTRADO!" << endl;
    }
    else
    {
      cout << endl
           << "##################################" << endl;
      cout << "Total de celulares encontrados: " << cont;
      cout << endl
           << "##################################" << endl;
    }

    break;
  case 3:
    int anoCriacaoMinimo;
    cout << "Digite o ano de criacao minimo: ";
    cin >> anoCriacaoMinimo;

    cout << "=== Celular Encontrado com no mínimo: " << anoCriacaoMinimo << " ===" << endl;

    for (int j = 0; j < i; j++)
    {
      if (anoCriacao[j] >= anoCriacaoMinimo)
      {
        cout << endl;
        encontrado = true;

        cout << "Identificador: " << identificador[j] << endl;
        cout << "Nome: " << nome[j] << endl;
        cout << "Preco: " << preco[j] << endl;
        cout << "Quantidade: " << quantidade[j] << endl;
        cout << "Fabricante: " << fabricante[j] << endl;
        cout << "Ano de Criacao: " << anoCriacao[j] << endl;
        cout << "Descricao: " << descricao[j] << endl;

        cont++;
      }
    }

    if (!encontrado)
    {
      cout << "CELULAR NAO ENCONTRADO!" << endl;
    }
    else
    {
      cout << endl
           << "##################################" << endl;
      cout << "Total de celulares encontrados: " << cont;
      cout << endl
           << "##################################" << endl;
    }

    break;
  case 4:
    int anoCriacaoMaximo;
    cout << "Digite o ano de criacao maximo: ";
    cin >> anoCriacaoMaximo;

    cout << "=== Celular Encontrado com no máximo: " << anoCriacaoMaximo << " ===" << endl;

    for (int j = 0; j < i; j++)
    {
      if (anoCriacao[j] <= anoCriacaoMaximo)
      {
        cout << endl;
        encontrado = true;

        cout << "Identificador: " << identificador[j] << endl;
        cout << "Nome: " << nome[j] << endl;
        cout << "Preco: " << preco[j] << endl;
        cout << "Quantidade: " << quantidade[j] << endl;
        cout << "Fabricante: " << fabricante[j] << endl;
        cout << "Ano de Criacao: " << anoCriacao[j] << endl;
        cout << "Descricao: " << descricao[j] << endl;

        cont++;
      }
    }

    if (!encontrado)
    {
      cout << "CELULAR NAO ENCONTRADO!" << endl;
    }
    else
    {
      cout << endl
           << "##################################" << endl;
      cout << "Total de celulares encontrados: " << cont;
      cout << endl
           << "##################################" << endl;
    }

    break;
  }
}

void buscarPorFabricante(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("cls");

  string fabricanteCelular;
  cout << "Digite o fabricante do celular: ";
  cin >> fabricanteCelular;

  bool encontrado = false;
  int cont = 0;
  for (int j = 0; j < i; j++)
  {
    // Se tiver alguma parte do nome do celular que o usuario digitou no nome do celular do vetor
    if (fabricante[j].find(fabricanteCelular) != string::npos) // string::npos = -1
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;
      encontrado = true;

      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cont++;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
  else
  {
    cout << endl
         << "##################################" << endl;
    cout << "Total de celulares encontrados: " << cont;
    cout << endl
         << "##################################" << endl;
  }
}

void buscarPorQuantidade(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("cls");

  int quantidadeMin;
  cout << "Digite a quantidade minima: ";
  cin >> quantidadeMin;

  bool encontrado = false;
  int cont = 0;

  cout << "=== Celular Encontrado com no mínimo: " << quantidadeMin << " unidades" << endl;

  for (int j = 0; j < i; j++)
  {
    if (quantidade[j] >= quantidadeMin)
    {
      cout << endl;
      encontrado = true;

      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cont++;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
  else
  {
    cout << endl
         << "##################################" << endl;
    cout << "Total de celulares encontrados: " << cont;
    cout << endl
         << "##################################" << endl;
  }
}

void buscarPorFaixaDePreco(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("cls");

  float precoMin, precoMax;
  cout << "Digite o preco minimo: ";
  cin >> precoMin;
  cout << "Digite o preco maximo: ";
  cin >> precoMax;

  bool encontrado = false;
  int cont = 0;

  cout << "=== Celular Encontrado na entre: " << precoMin << " e " << precoMax << " ===" << endl;

  for (int j = 0; j < i; j++)
  {
    if (preco[j] >= precoMin && preco[j] <= precoMax)
    {
      cout << endl;
      encontrado = true;

      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cont++;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
  else
  {
    cout << endl
         << "##################################" << endl;
    cout << "Total de celulares encontrados: " << cont;
    cout << endl
         << "##################################" << endl;
  }
}

void buscarPorNome(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("cls");

  string nomeCelular;
  cout << "Digite o nome do celular: ";
  cin >> nomeCelular;

  bool encontrado = false;
  int cont = 0;
  for (int j = 0; j < i; j++)
  {
    // Se tiver alguma parte do nome do celular que o usuario digitou no nome do celular do vetor
    if (nome[j].find(nomeCelular) != string::npos) // string::npos = -1
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;
      encontrado = true;

      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cont++;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
  else
  {
    cout << endl
         << "##################################" << endl;
    cout << "Total de celulares encontrados: " << cont;
    cout << endl
         << "##################################" << endl;
  }
}

void buscarPorIdentificador(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("cls");

  int id;
  cout << "Digite o identificador do celular: ";
  cin >> id;

  bool encontrado = false;
  for (int j = 0; j < i; j++)
  {
    if (id == identificador[j])
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;
      encontrado = true;

      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
}

void exibirMenuBuscarCelular()
{
  system("cls");

  cout << "===== Buscar Celular =====" << endl;
  cout << "1 - Por Identificador" << endl;
  cout << "2 - Por Nome" << endl;
  cout << "3 - Por Preco" << endl;
  cout << "4 - Por Quantidade" << endl;
  cout << "5 - Por Fabricante" << endl;
  cout << "6 - Por Ano de Criacao" << endl;
  cout << "0 - Voltar" << endl;
  cout << "Opcao: ";
}

void exibirMenu()
{
  system("cls");

  cout << "===== Sistema de Cadastro de Celulares =====" << endl;
  cout << "1 - Cadastrar Celular" << endl;
  cout << "2 - Buscar Celular" << endl;
  cout << "3 - Alterar Celular" << endl;
  cout << "4 - Exportar para CSV" << endl;
  cout << "5 - Importar de CSV" << endl;
  cout << "6 - Ordenações" << endl;
  cout << "0 - Sair" << endl;
  cout << "Opcao: ";
}

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

  // Funções:
  exibirMenu();

  int opcao;
  do
  {
    cin >> opcao;

    switch (opcao)
    {
    case 1:
      // Cadastrar Celular
      break;
    case 2:
      // Busca Celular
      int opcaoConsultaNovamente;
      int opcaoBuscarCelular;

      do
      {
        exibirMenuBuscarCelular();
        cin >> opcaoBuscarCelular;

        switch (opcaoBuscarCelular)
        {
        case 1:
          buscarPorIdentificador(indentificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 2:
          buscarPorNome(indentificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 3:
          buscarPorFaixaDePreco(indentificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 4:
          buscarPorQuantidade(indentificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 5:
          buscarPorFabricante(indentificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 6:
          buscarPorAnoCriacao(indentificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
        default:
          cout << "Opcao invalida!" << endl;
          break;
        }

        if (opcaoBuscarCelular != 0)
        {
          cout << endl
               << "Gostaria de consultar novamente?" << endl;
          cout << "1 - Sim" << endl;
          cout << "2 - Nao" << endl;
          cout << "Opcao: ";
          cin >> opcaoConsultaNovamente;
        }
      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);

      break;
    case 3:
      // Alterar Celular
      break;
    case 4:
      // Exportar para CSV
      break;
    case 5:
      // Importar de CSV
      break;
    case 6:
      // Ordenar
      break;

    default:
      break;
    }

    cout << endl;
    exibirMenu();

  } while (opcao != 0);

  return 0;
}
