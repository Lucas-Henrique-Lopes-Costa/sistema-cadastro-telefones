#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void alterarTodosOsDados(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("clear");

  int id;
  cout << "Digite o identificador do celular: ";
  cin >> id;
  cin.ignore();

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

      cout << endl
           << "Digite o novo nome: ";
      cin >> nome[j];
      cout << endl
           << "Digite o novo preco: ";
      cin >> preco[j];
      cout << endl
           << "Digite a nova quantidade: ";
      cin >> quantidade[j];
      cout << endl
           << "Digite o novo fabricante: ";
      cin >> fabricante[j];
      cout << endl
           << "Digite o novo ano de criacao: ";
      cin >> anoCriacao[j];
      cout << endl
           << "Digite a nova descricao: ";
      cin >> descricao[j];

      cout << endl
           << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cout << endl
           << "##################################" << endl;
      cout << "Celular alterado com sucesso!" << endl;
      cout << "0 - Voltar para Inicio" << endl;
      cout << "Opcao: ";
      int opcao;
      cin >> opcao;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
}

void alterarQuantidade(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("clear");

  int id;
  cout << "Digite o identificador do celular: ";
  cin >> id;
  cin.ignore();

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

      cout << endl
           << "Digite a nova quantidade: ";
      cin >> quantidade[j];

      cout << endl
           << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cout << endl
           << "##################################" << endl;
      cout << "Celular alterado com sucesso!" << endl;
      cout << "0 - Voltar para Inicio" << endl;
      cout << "Opcao: ";
      int opcao;
      cin >> opcao;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
}

void alterarPreco(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("clear");

  int id;
  cout << "Digite o identificador do celular: ";
  cin >> id;
  cin.ignore();

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

      cout << endl
           << "Digite o novo preco: ";
      cin >> preco[j];

      cout << endl
           << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cout << endl
           << "##################################" << endl;
      cout << "Celular alterado com sucesso!" << endl;
      cout << "0 - Voltar para Inicio" << endl;
      cout << "Opcao: ";
      int opcao;
      cin >> opcao;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
}

void alterarNome(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("clear");

  int id;
  cout << "Digite o identificador do celular: ";
  cin >> id;
  cin.ignore();

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

      cout << endl
           << "Digite o novo nome: ";
      getline(cin, nome[j]);

      cout << endl
           << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << identificador[j] << endl;
      cout << "Nome: " << nome[j] << endl;
      cout << "Preco: " << preco[j] << endl;
      cout << "Quantidade: " << quantidade[j] << endl;
      cout << "Fabricante: " << fabricante[j] << endl;
      cout << "Ano de Criacao: " << anoCriacao[j] << endl;
      cout << "Descricao: " << descricao[j] << endl;

      cout << endl
           << "##################################" << endl;
      cout << "Celular alterado com sucesso!" << endl;
      cout << "0 - Voltar para Inicio" << endl;
      cout << "Opcao: ";
      int opcao;
      cin >> opcao;
    }
  }

  if (!encontrado)
  {
    cout << "CELULAR NAO ENCONTRADO!" << endl;
  }
}

void exibirMenuAlterarCelular()
{
  system("clear");

  cout << "===== Alterar Celular =====" << endl;
  cout << "1 - Alterar Nome" << endl;
  cout << "2 - Alterar Preco" << endl;
  cout << "3 - Alterar Quantidade" << endl;
  cout << "4 - Alterar Todos os Dados" << endl;
  cout << "0 - Voltar" << endl;
  cout << "Opcao: ";
}

void buscarPorAnoCriacao(int identificador[], string nome[], float preco[], int quantidade[], string fabricante[], int anoCriacao[], string descricao[], int i)
{
  system("clear");

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
  system("clear");

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
  system("clear");

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
  system("clear");

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
  system("clear");

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
  system("clear");

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
  system("clear");

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
  system("clear");

  cout << "===== Sistema de Cadastro de Celulares =====" << endl;
  cout << "1 - Cadastrar Celular" << endl;
  cout << "2 - Remover Celular" << endl;
  cout << "3 - Buscar Celular" << endl;
  cout << "4 - Alterar Celular" << endl;
  cout << "5 - Exportar para CSV" << endl;
  cout << "6 - Importar de CSV" << endl;
  cout << "7 - Ordenacoes" << endl;
  cout << "0 - Sair" << endl;
  cout << "Opcao: ";
}

int main()
{
  // Recebendo dados do arquivo celulares.csv e colocando em um vetor separando cada vetor pela determinada linha
  ifstream arquivoIn("celulares.csv");

  if (!arquivoIn.is_open())
  {
    cout << "Erro ao abrir o arquivo 'celulares.csv'!" << endl;
    return 0;
  }

  string linha;
  getline(arquivoIn, linha); // dicartando a primeira linha do arquivo

  // separar cada linha do arquivo
  int identificador[100];
  string nome[100];
  float preco[100];
  int quantidade[100];
  string fabricante[100];
  int anoCriacao[100];
  string descricao[100];

  int i = 0; // contador de celulares real
  while (!arquivoIn.eof())
  {
    getline(arquivoIn, linha);

    if (linha == "")
    {
      continue;
    }

    // identificador
    int pos = linha.find(";");
    identificador[i] = stoi(linha.substr(0, pos)); // stoi converte string para int

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
    int opcaoConsultaNovamente;
    int opcaoBuscarCelular;

    switch (opcao)
    {
    case 1:
    { // Cadastrar Celular
      break;
    }
    case 2:
    { // Remover Celular
      break;
    }
    case 3:
    { // Busca Celular
      do
      {
        exibirMenuBuscarCelular();
        cin >> opcaoBuscarCelular;

        switch (opcaoBuscarCelular)
        {
        case 1:
          buscarPorIdentificador(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 2:
          buscarPorNome(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 3:
          buscarPorFaixaDePreco(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 4:
          buscarPorQuantidade(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 5:
          buscarPorFabricante(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 6:
          buscarPorAnoCriacao(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
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
    }
    case 4:
    { // Alterar Celular
      do
      {
        exibirMenuAlterarCelular();
        int opcaoAlterarCelular;
        cin >> opcaoAlterarCelular;

        switch (opcaoAlterarCelular)
        {
        case 1:
          alterarNome(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 2:
          alterarPreco(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        case 3:
          alterarQuantidade(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
        case 4:
          alterarTodosOsDados(identificador, nome, preco, quantidade, fabricante, anoCriacao, descricao, i);
          break;
        default:
          cout << "Opcao invalida!" << endl;
          break;
        }

      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);
      break;
    }
    case 5:
    { // Exportar para CSV
      break;
    }
    case 6:
    { // Importar de CSV
      break;
    }
    case 7:
    { // Ordenar
      break;
    }

    default:
      break;
    }
    cout << endl;
    exibirMenu();

  } while (opcao != 0);

  return 0;
}
