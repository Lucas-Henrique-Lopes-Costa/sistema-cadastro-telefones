#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// encontrando o sistema operacional
string getClearCommand()
{
#ifdef _WIN32
  return "cls"; // Comando de limpeza no Windows
#else
  return "clear"; // Comando de limpeza em sistemas Unix
#endif
}
string clearCommand = getClearCommand();

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

void ExportarParaArquivo(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  char opcao;
  cout << "===== Exportar em arquivos =====" << endl;
  cout << "1 - Salvar em .csv (recomendado)" << endl;
  cout << "2 - Salvar em .txt" << endl;
  cout << "3 - Salvar em outro formato" << endl;
  cout << "0 - Voltar para o inicio" << endl;
  cout << "Opcao: ";
  cin >> opcao;

  switch (opcao)
  {
  case '2':
  {
    string nomeArquivo;
    cout << endl
         << "Digite o nome desejado para o arquivo (sem .txt): ";
    cin >> nomeArquivo;
    ofstream NomeArqvSaida(nomeArquivo + ".txt");
    NomeArqvSaida << "Indentificador;Nome;Preco;Quantidade;Fabricante;Ano de criacao;Descricao do produto" << endl;
    for (int i = 0; i < estoqueReal; i++)
    {
      NomeArqvSaida << celulares[i].identificador << ";";
      NomeArqvSaida << celulares[i].nome << ";";
      NomeArqvSaida << celulares[i].preco << ";";
      NomeArqvSaida << celulares[i].quantidade << ";";
      NomeArqvSaida << celulares[i].fabricante << ";";
      NomeArqvSaida << celulares[i].anoCriacao << ";";
      NomeArqvSaida << celulares[i].descricao;
      NomeArqvSaida << endl;
    }
    cout << endl
         << "##################################" << endl;
    cout << "Exportado com sucesso!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
    break;
  }
  case '1':
  {
    string nomeArquivo;
    cout << "Digite o nome desejado para o arquivo (sem .csv): ";
    cin >> nomeArquivo;
    ofstream NomeArqvSaida(nomeArquivo + ".csv");
    NomeArqvSaida << "Indentificador;Nome;Preco;Quantidade;Fabricante;Ano de criacao;Descricao do produto" << endl;
    for (int i = 0; i < estoqueReal; i++)
    {
      NomeArqvSaida << celulares[i].identificador << ";";
      NomeArqvSaida << celulares[i].nome << ";";
      NomeArqvSaida << celulares[i].preco << ";";
      NomeArqvSaida << celulares[i].quantidade << ";";
      NomeArqvSaida << celulares[i].fabricante << ";";
      NomeArqvSaida << celulares[i].anoCriacao << ";";
      NomeArqvSaida << celulares[i].descricao;
      NomeArqvSaida << endl;
    }
    cout << endl
         << "##################################" << endl;
    cout << "Exportado com sucesso!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
    break;
  }
  case '3':
  {
    string nomeArquivo;
    cout << "Digite o nome desejado para o arquivo, com o tipo (novosCelulares.xls): ";
    cin >> nomeArquivo;
    ofstream NomeArqvSaida(nomeArquivo);
    NomeArqvSaida << "Indentificador;Nome;Preco;Quantidade;Fabricante;Ano de criacao;Descricao do produto" << endl;
    for (int i = 0; i < estoqueReal; i++)
    {
      NomeArqvSaida << celulares[i].identificador << ";";
      NomeArqvSaida << celulares[i].nome << ";";
      NomeArqvSaida << celulares[i].preco << ";";
      NomeArqvSaida << celulares[i].quantidade << ";";
      NomeArqvSaida << celulares[i].fabricante << ";";
      NomeArqvSaida << celulares[i].anoCriacao << ";";
      NomeArqvSaida << celulares[i].descricao;
      NomeArqvSaida << endl;
    }
    cout << endl
         << "##################################" << endl;
    cout << "Exportado com sucesso!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
    break;
  }
  default:
    break;
  }
}

void buscarPorAnoCriacao(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

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
  {
    int anoCriacao;
    cout << "Digite o ano de criacao do celular: ";
    cin >> anoCriacao;

    cout << "=== Celular Encontrado com o ano de criacao: " << anoCriacao << " ===" << endl;

    for (int i = 0; i <= estoqueReal; i++)
    {
      if (celulares[i].anoCriacao == anoCriacao)
      {
        cout << endl
             << "===== Celular Encontrado =====" << endl;

        cout << "Identificador: " << celulares[i].identificador << endl;
        cout << "Nome: " << celulares[i].nome << endl;
        cout << "Preco: " << celulares[i].preco << endl;
        cout << "Quantidade: " << celulares[i].quantidade << endl;
        cout << "Fabricante: " << celulares[i].fabricante << endl;
        cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
        cout << "Descricao: " << celulares[i].descricao << endl;

        encontrado = true;
        cont++;
      }
    }

    if (!encontrado)
    {
      cout << endl
           << "## CELULAR NAO ENCONTRADO! ##" << endl;
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
  case 2:
  {
    int anoCriacaoMin, anoCriacaoMax;
    cout << "Digite o ano de criacao minimo: ";
    cin >> anoCriacaoMin;
    cout << "Digite o ano de criacao maximo: ";
    cin >> anoCriacaoMax;

    cout << "=== Celular Encontrado com o ano de criacao entre: " << anoCriacaoMin << " e " << anoCriacaoMax << " ===" << endl;

    for (int i = 0; i < estoqueReal; i++)
    {
      if (celulares[i].anoCriacao >= anoCriacaoMin && celulares[i].anoCriacao <= anoCriacaoMax)
      {
        cout << endl
             << "===== Celular Encontrado =====" << endl;

        cout << "Identificador: " << celulares[i].identificador << endl;
        cout << "Nome: " << celulares[i].nome << endl;
        cout << "Preco: " << celulares[i].preco << endl;
        cout << "Quantidade: " << celulares[i].quantidade << endl;
        cout << "Fabricante: " << celulares[i].fabricante << endl;
        cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
        cout << "Descricao: " << celulares[i].descricao << endl;

        encontrado = true;
        cont++;
      }
    }

    if (!encontrado)
    {
      cout << endl
           << "## CELULAR NAO ENCONTRADO! ##" << endl;
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
  case 3:
  {
    int anoCriacaoMin;
    cout << "Digite o ano de criacao minimo: ";
    cin >> anoCriacaoMin;

    cout << "=== Celular Encontrado com o ano de criacao minimo de: " << anoCriacaoMin << " ===" << endl;

    for (int i = 0; i < estoqueReal; i++)
    {
      if (celulares[i].anoCriacao >= anoCriacaoMin)
      {
        cout << endl
             << "===== Celular Encontrado =====" << endl;

        cout << "Identificador: " << celulares[i].identificador << endl;
        cout << "Nome: " << celulares[i].nome << endl;
        cout << "Preco: " << celulares[i].preco << endl;
        cout << "Quantidade: " << celulares[i].quantidade << endl;
        cout << "Fabricante: " << celulares[i].fabricante << endl;
        cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
        cout << "Descricao: " << celulares[i].descricao << endl;

        encontrado = true;
        cont++;
      }
    }

    if (!encontrado)
    {
      cout << endl
           << "## CELULAR NAO ENCONTRADO! ##" << endl;
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
  case 4:
  {
    int anoCriacaoMax;
    cout << "Digite o ano de criacao maximo: ";
    cin >> anoCriacaoMax;

    cout << "=== Celular Encontrado com o ano de criacao maximo de: " << anoCriacaoMax << " ===" << endl;

    for (int i = 0; i < estoqueReal; i++)
    {
      if (celulares[i].anoCriacao <= anoCriacaoMax)
      {
        cout << endl
             << "===== Celular Encontrado =====" << endl;

        cout << "Identificador: " << celulares[i].identificador << endl;
        cout << "Nome: " << celulares[i].nome << endl;
        cout << "Preco: " << celulares[i].preco << endl;
        cout << "Quantidade: " << celulares[i].quantidade << endl;
        cout << "Fabricante: " << celulares[i].fabricante << endl;
        cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
        cout << "Descricao: " << celulares[i].descricao << endl;

        encontrado = true;
        cont++;
      }
    }

    if (!encontrado)
    {
      cout << endl
           << "## CELULAR NAO ENCONTRADO! ##" << endl;
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
}

void buscarPorFabricante(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  string fabricante;
  cout << "Digite o fabricante do celular: ";
  cin >> fabricante;

  cout << "=== Celular Encontrado com o Fabricante: " << fabricante << " ===" << endl;

  bool encontrado = false;
  int cont = 0;
  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].fabricante.find(fabricante) != string::npos)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;

      cout << "Identificador: " << celulares[i].identificador << endl;
      cout << "Nome: " << celulares[i].nome << endl;
      cout << "Preco: " << celulares[i].preco << endl;
      cout << "Quantidade: " << celulares[i].quantidade << endl;
      cout << "Fabricante: " << celulares[i].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
      cout << "Descricao: " << celulares[i].descricao << endl;

      encontrado = true;
      cont++;
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
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

void buscarPorQuantidade(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  int quantidade;
  cout << "Digite a quantidade minima: ";
  cin >> quantidade;

  cout << "=== Filtro de: " << quantidade << " unidades ===" << endl;

  bool encontrado = false;
  int cont = 0;
  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].quantidade >= quantidade)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;

      cout << "Identificador: " << celulares[i].identificador << endl;
      cout << "Nome: " << celulares[i].nome << endl;
      cout << "Preco: " << celulares[i].preco << endl;
      cout << "Quantidade: " << celulares[i].quantidade << endl;
      cout << "Fabricante: " << celulares[i].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
      cout << "Descricao: " << celulares[i].descricao << endl;

      encontrado = true;
      cont++;
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
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

void buscarPorFaixaDePreco(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  float precoMin, precoMax;
  cout << "Digite o preco minimo: ";
  cin >> precoMin;
  cout << "Digite o preco maximo: ";
  cin >> precoMax;

  bool encontrado = false;
  int cont = 0;
  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].preco >= precoMin && celulares[i].preco <= precoMax)
    {
      cout << "=== Filtro de : " << precoMin << " até " << precoMax << " dolares ===" << endl;
      cout << endl
           << "===== Celular Encontrado =====" << endl;

      cout << "Identificador: " << celulares[i].identificador << endl;
      cout << "Nome: " << celulares[i].nome << endl;
      cout << "Preco: " << celulares[i].preco << endl;
      cout << "Quantidade: " << celulares[i].quantidade << endl;
      cout << "Fabricante: " << celulares[i].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
      cout << "Descricao: " << celulares[i].descricao << endl;

      encontrado = true;
      cont++;
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
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

void buscarPorNome(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  string nome;
  cout << "Digite o nome do celular: ";
  cin >> nome;

  bool encontrado = false;
  int cont = 0;

  Celular resposta[estoqueReal];
  int j = 0;

  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].nome.find(nome) != string::npos)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;

      cout << "Identificador: " << celulares[i].identificador << endl;
      cout << "Nome: " << celulares[i].nome << endl;
      cout << "Preco: " << celulares[i].preco << endl;
      cout << "Quantidade: " << celulares[i].quantidade << endl;
      cout << "Fabricante: " << celulares[i].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
      cout << "Descricao: " << celulares[i].descricao << endl;

      encontrado = true;

      resposta[j].identificador = celulares[i].identificador;
      resposta[j].nome = celulares[i].nome;
      resposta[j].preco = celulares[i].preco;
      resposta[j].quantidade = celulares[i].quantidade;
      resposta[j].fabricante = celulares[i].fabricante;
      resposta[j].anoCriacao = celulares[i].anoCriacao;
      resposta[j].descricao = celulares[i].descricao;
      j++;

      cont++;
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
  }
  else
  {
    cout << endl
         << "##################################" << endl;
    cout << "Total de celulares encontrados: " << cont;
    cout << endl
         << "##################################" << endl;

    cout << endl << "Deseja exportar essa lista em um arquivo separado?" << endl;
    cout << "1 - sim" << endl
         << "0 - nao" << endl;
    cout << "Opcao: ";
    int respostaExportar;
    cin >> respostaExportar;

    if (respostaExportar == 1)
    {
      ExportarParaArquivo(resposta, cont);
    }
  }
}

void buscarPorIdentificador(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  int identificador;
  cout << "Digite o identificador do celular: ";
  cin >> identificador;

  bool encontrado = false;
  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].identificador == identificador)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;

      cout << "Identificador: " << celulares[i].identificador << endl;
      cout << "Nome: " << celulares[i].nome << endl;
      cout << "Preco: " << celulares[i].preco << endl;
      cout << "Quantidade: " << celulares[i].quantidade << endl;
      cout << "Fabricante: " << celulares[i].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
      cout << "Descricao: " << celulares[i].descricao << endl;

      encontrado = true;
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
  }
}

void exibirMenuBuscarCelular()
{
  system(clearCommand.c_str());

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

void alterarTodosDados(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  int identificador;
  cout << "Digite o identificador do celular: ";
  cin >> identificador;
  cin.ignore();

  bool encontrado = false;
  for (int j = 0; j < estoqueReal; j++)
  {
    if (celulares[j].identificador == identificador)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;
      encontrado = true;

      cout << "Identificador: " << celulares[j].identificador << endl;
      cout << "Nome: " << celulares[j].nome << endl;
      cout << "Preco: " << celulares[j].preco << endl;
      cout << "Quantidade: " << celulares[j].quantidade << endl;
      cout << "Fabricante: " << celulares[j].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[j].anoCriacao << endl;
      cout << "Descricao: " << celulares[j].descricao << endl;

      cout << endl
           << "Digite o novo nome: ";
      getline(cin, celulares[j].nome);
      cout << "Digite o novo preco: ";
      cin >> celulares[j].preco;
      cout << "Digite a nova quantidade: ";
      cin >> celulares[j].quantidade;
      cin.ignore();
      cout << "Digite o novo fabricante: ";
      getline(cin, celulares[j].fabricante);
      cout << "Digite o novo ano de criacao: ";
      cin >> celulares[j].anoCriacao;
      cin.ignore();
      cout << "Digite a nova descricao: ";
      getline(cin, celulares[j].descricao);

      system(clearCommand.c_str());

      cout << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << celulares[j].identificador << endl;
      cout << "Nome: " << celulares[j].nome << endl;
      cout << "Preco: " << celulares[j].preco << endl;
      cout << "Quantidade: " << celulares[j].quantidade << endl;
      cout << "Fabricante: " << celulares[j].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[j].anoCriacao << endl;
      cout << "Descricao: " << celulares[j].descricao << endl;

      cout << endl
           << "##################################" << endl;
      cout << "Celular alterado com sucesso!" << endl
           << "##################################" << endl;

      int opcao;
      cout << endl
           << "1 - Voltar para o inicio" << endl;
      cout << "2 - Alterar novamente" << endl;
      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 2)
      {
        alterarTodosDados(celulares, estoqueReal);
      }
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
  }
}

void alterarQuantidade(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  int identificador;
  cout << "Digite o identificador do celular: ";
  cin >> identificador;
  cin.ignore();

  bool encontrado = false;
  for (int j = 0; j < estoqueReal; j++)
  {
    if (celulares[j].identificador == identificador)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;
      encontrado = true;

      cout << "Identificador: " << celulares[j].identificador << endl;
      cout << "Nome: " << celulares[j].nome << endl;
      cout << "Preco: " << celulares[j].preco << endl;
      cout << "Quantidade: " << celulares[j].quantidade << endl;
      cout << "Fabricante: " << celulares[j].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[j].anoCriacao << endl;
      cout << "Descricao: " << celulares[j].descricao << endl;

      cout << endl
           << "Digite a nova quantidade: ";
      int resposta;
      cin >> resposta;

      system(clearCommand.c_str());

      cout << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << celulares[j].identificador << endl;
      cout << "Nome: " << celulares[j].nome << endl;
      cout << "Preco: " << celulares[j].preco << endl;
      cout << "Quantidade: " << resposta << endl;
      cout << "Fabricante: " << celulares[j].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[j].anoCriacao << endl;
      cout << "Descricao: " << celulares[j].descricao << endl;

      string cancelar;
      cout << endl
           << "Deseja salvar? (sim / nao): ";
      cin >> cancelar;
      if (cancelar == "nao")
      {
        cout << endl
             << "##################################" << endl;
        cout << "Alteracao cancelada!" << endl
             << "##################################" << endl;
      }
      else
      {
        celulares[j].quantidade = resposta;
        cout << endl
             << "##################################" << endl;
        cout << "Celular alterado com sucesso!" << endl
             << "##################################" << endl;
      }

      int opcao;
      cout << endl
           << "1 - Voltar para o inicio" << endl;
      cout << "2 - Alterar novamente" << endl;

      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 2)
      {
        alterarQuantidade(celulares, estoqueReal);
      }
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
  }
}

void alterarPreco(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  int identificador;
  cout << "Digite o identificador do celular: ";
  cin >> identificador;
  cin.ignore();

  bool encontrado = false;
  for (int j = 0; j < estoqueReal; j++)
  {
    if (celulares[j].identificador == identificador)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;
      encontrado = true;

      cout << "Identificador: " << celulares[j].identificador << endl;
      cout << "Nome: " << celulares[j].nome << endl;
      cout << "Preco: " << celulares[j].preco << endl;
      cout << "Quantidade: " << celulares[j].quantidade << endl;
      cout << "Fabricante: " << celulares[j].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[j].anoCriacao << endl;
      cout << "Descricao: " << celulares[j].descricao << endl;

      cout << endl
           << "Digite o novo preco: ";
      float resposta;
      cin >> resposta;

      system(clearCommand.c_str());

      cout << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << celulares[j].identificador << endl;
      cout << "Nome: " << celulares[j].nome << endl;
      cout << "Preco: " << resposta << endl;
      cout << "Quantidade: " << celulares[j].quantidade << endl;
      cout << "Fabricante: " << celulares[j].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[j].anoCriacao << endl;
      cout << "Descricao: " << celulares[j].descricao << endl;

      string cancelar;
      cout << endl
           << "Deseja salvar? (sim / nao): ";
      cin >> cancelar;
      if (cancelar == "nao")
      {
        cout << endl
             << "##################################" << endl;
        cout << "Alteracao cancelada!" << endl
             << "##################################" << endl;
      }
      else
      {
        celulares[j].preco = resposta;
        cout << endl
             << "##################################" << endl;
        cout << "Celular alterado com sucesso!" << endl
             << "##################################" << endl;
      }

      int opcao;
      cout << endl
           << "1 - Voltar para o inicio" << endl;
      cout << "2 - Alterar novamente" << endl;

      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 2)
      {
        alterarPreco(celulares, estoqueReal);
      }
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
  }
}

void alterarNome(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  int identificador;
  cout << "Digite o identificador do celular: ";
  cin >> identificador;
  cin.ignore();

  bool encontrado = false;
  for (int i = 0; i < estoqueReal; i++)
  {
    if (celulares[i].identificador == identificador)
    {
      cout << endl
           << "===== Celular Encontrado =====" << endl;
      encontrado = true;

      cout << "Identificador: " << celulares[i].identificador << endl;
      cout << "Nome: " << celulares[i].nome << endl;
      cout << "Preco: " << celulares[i].preco << endl;
      cout << "Quantidade: " << celulares[i].quantidade << endl;
      cout << "Fabricante: " << celulares[i].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
      cout << "Descricao: " << celulares[i].descricao << endl;

      cout << endl
           << "Digite o novo nome: ";
      string resposta;
      getline(cin, resposta);

      system(clearCommand.c_str());

      cout << "===== Celular Alterado =====" << endl;
      cout << "Identificador: " << celulares[i].identificador << endl;
      cout << "Nome: " << resposta << endl;
      cout << "Preco: " << celulares[i].preco << endl;
      cout << "Quantidade: " << celulares[i].quantidade << endl;
      cout << "Fabricante: " << celulares[i].fabricante << endl;
      cout << "Ano de Criacao: " << celulares[i].anoCriacao << endl;
      cout << "Descricao: " << celulares[i].descricao << endl;

      // opção de cancelar
      string cancelar;
      cout << endl
           << "Deseja salvar? (sim / nao): ";
      cin >> cancelar;
      if (cancelar == "nao")
      {
        cout << endl
             << "##################################" << endl;
        cout << "Alteracao cancelada!" << endl
             << "##################################" << endl;
      }
      else
      {
        celulares[i].nome = resposta;
        cout << endl
             << "##################################" << endl;
        cout << "Celular alterado com sucesso!" << endl
             << "##################################" << endl;
      }

      int opcao;
      cout << endl
           << "1 - Voltar para o inicio" << endl;
      cout << "2 - Alterar novamente" << endl;

      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 2)
      {
        alterarNome(celulares, estoqueReal);
      }
    }
  }

  if (!encontrado)
  {
    cout << endl
         << "## CELULAR NAO ENCONTRADO! ##" << endl;
  }
}

void CadastrarCelular(Celular celulares[], int &estoqueReal)
{
  system(clearCommand.c_str());

  cout << "===== Cadastro de um novo SmartPhone =====" << endl;
  cout << "Para cadastrar um novo celular, serao necessarios:" << endl
       << "·Nome," << endl
       << "·Preco," << endl
       << "·Quatidade em estoque," << endl
       << "·Nome do fabricante," << endl
       << "·Ano de criacao," << endl
       << "·Descricao" << endl
       << endl
       << "Deseja continuar?" << endl;

  int opcao;
  cout << "1 - Sim" << endl;
  cout << "0 - Voltar para o Inicio" << endl;
  cout << "Opcao: ";
  cin >> opcao;
  cin.ignore();
  if (opcao == 1)
  {
    estoqueReal += 1;
    celulares[estoqueReal].identificador = estoqueReal;
    cout << endl
         << "Digite o nome do produto: ";
    getline(cin, celulares[estoqueReal].nome);
    cout
        << "Digite o preco do produto: ";
    cin >> celulares[estoqueReal].preco;
    cout
        << "Digite a quantidade em estoque: ";
    cin >> celulares[estoqueReal].quantidade;
    cout
        << "Digite o nome do fabricante: ";
    cin >> celulares[estoqueReal].fabricante;
    cout
        << "Digite o ano de criacao do aparelho: ";
    cin >> celulares[estoqueReal].anoCriacao;
    cin.ignore();
    cout
        << "Digite a descricao do produto: ";
    getline(cin, celulares[estoqueReal].descricao);

    system(clearCommand.c_str());

    cout << "### Celular cadastrado com sucesso ###" << endl;
    cout << "Identificacao: " << celulares[estoqueReal].identificador << endl;
    cout << "Nome: " << celulares[estoqueReal].nome << endl;
    cout << "Preco: " << celulares[estoqueReal].preco << endl;
    cout << "Quantidade em estoque: " << celulares[estoqueReal].quantidade << endl;
    cout << "Fabricante do Aparelho: " << celulares[estoqueReal].fabricante << endl;
    cout << "Ano de Criacao: " << celulares[estoqueReal].anoCriacao << endl;
    cout << "Descricao do produto:  " << celulares[estoqueReal].descricao << endl;

    cout << endl
         << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
  }
}

void exibirMenuAlterarCelular()
{
  system(clearCommand.c_str());

  cout << "===== Alterar Celular =====" << endl;
  cout << "1 - Alterar Nome" << endl;
  cout << "2 - Alterar Preco" << endl;
  cout << "3 - Alterar Quantidade" << endl;
  cout << "4 - Alterar Todos os Dados" << endl;
  cout << "5 - Deseja buscar primeiro? (voce vai precisar do identificador)" << endl;
  cout << "0 - Voltar" << endl;
  cout << "Opcao: ";
}

void exibirMenu()
{
  system(clearCommand.c_str());

  cout << "===== Sistema de Cadastro de Celulares =====" << endl;
  cout << "1 - Cadastrar Celular" << endl;
  cout << "2 - Remover Celular" << endl;
  cout << "3 - Buscar Celular" << endl;
  cout << "4 - Alterar Celular" << endl;
  cout << "5 - Exportar Arquivo" << endl;
  cout << "6 - Importar de CSV" << endl;
  cout << "0 - Sair" << endl;
  cout << "Opcao: ";
}

int main()
{
  // Recebendo dados do arquivo celulares.csv e colocando em um vetor registro
  ifstream arquivoIn("celulares.csv");

  if (!arquivoIn.is_open())
  {
    cout << "Erro ao abrir o arquivo 'celulares.csv'!" << endl;
    return 0;
  }

  string linha;
  getline(arquivoIn, linha); // dicartando a primeira linha do arquivo

  // utilizando struct para armazenar os dados do arquivo
  const int estoqueMax = 100;
  Celular celulares[estoqueMax];
  int estoqueReal = 0;

  bool continuar = true;
  while (continuar)
  {
    getline(arquivoIn, linha);
    if (linha == "")
    {
      continuar = false;
    }
    else
    {
      // separando os dados da linha
      int pos = linha.find(";");
      celulares[estoqueReal].identificador = stoi(linha.substr(0, pos));
      linha = linha.substr(pos + 1);

      pos = linha.find(";");
      celulares[estoqueReal].nome = linha.substr(0, pos);
      linha = linha.substr(pos + 1);

      pos = linha.find(";");
      celulares[estoqueReal].preco = stof(linha.substr(0, pos));
      linha = linha.substr(pos + 1);

      pos = linha.find(";");
      celulares[estoqueReal].quantidade = stoi(linha.substr(0, pos));
      linha = linha.substr(pos + 1);

      pos = linha.find(";");
      celulares[estoqueReal].fabricante = linha.substr(0, pos);
      linha = linha.substr(pos + 1);

      pos = linha.find(";");
      celulares[estoqueReal].anoCriacao = stoi(linha.substr(0, pos));
      linha = linha.substr(pos + 1);

      celulares[estoqueReal].descricao = linha;

      estoqueReal++;
    }
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
      do
      {
        CadastrarCelular(celulares, estoqueReal);
      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);

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
          buscarPorIdentificador(celulares, estoqueReal);
          break;
        case 2:
          buscarPorNome(celulares, estoqueReal);
          break;
        case 3:
          buscarPorFaixaDePreco(celulares, estoqueReal);
          break;
        case 4:
          buscarPorQuantidade(celulares, estoqueReal);
          break;
        case 5:
          buscarPorFabricante(celulares, estoqueReal);
          break;
        case 6:
          buscarPorAnoCriacao(celulares, estoqueReal);
          break;

        default:
          cout << "Opcao invalida!" << endl;
          break;
        }

        if (opcaoBuscarCelular != 0)
        {
          cout << endl
               << "Gostaria de consultar novamente?" << endl;
          cout << "1 - Sim" << endl;
          cout << "0 - Nao" << endl;
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
          alterarNome(celulares, estoqueReal);
          break;
        case 2:
          alterarPreco(celulares, estoqueReal);
          break;
        case 3:
          alterarQuantidade(celulares, estoqueReal);
          break;
        case 4:
          alterarTodosDados(celulares, estoqueReal);
          break;
        case 5:
          do
          {
            exibirMenuBuscarCelular();
            cin >> opcaoBuscarCelular;

            switch (opcaoBuscarCelular)
            {

            case 1:
              buscarPorIdentificador(celulares, estoqueReal);
              break;
            case 2:
              buscarPorNome(celulares, estoqueReal);
              break;
            case 3:
              buscarPorFaixaDePreco(celulares, estoqueReal);
              break;
            case 4:
              buscarPorQuantidade(celulares, estoqueReal);
              break;
            case 5:
              buscarPorFabricante(celulares, estoqueReal);
              break;
            case 6:
              buscarPorAnoCriacao(celulares, estoqueReal);
              break;

            default:
              cout << "Opcao invalida!" << endl;
              break;
            }

            if (opcaoBuscarCelular != 0)
            {
              cout << endl
                   << "Gostaria de consultar novamente?" << endl;
              cout << "1 - Sim" << endl;
              cout << "0 - Nao" << endl;
              cout << "Opcao: ";
              cin >> opcaoConsultaNovamente;
            }
          } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);
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
      do
      {
        ExportarParaArquivo(celulares, estoqueReal);

      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);

      break;
    }
    case 6:
    { // Importar de CSV
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
