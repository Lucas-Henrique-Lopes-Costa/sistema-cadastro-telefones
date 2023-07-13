#include <iostream>
#include <fstream>
#include <cstring>
#include <locale.h>
#include <algorithm>
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
  char nome[30];
  float preco;
  int quantidade;
  char fabricante[10];
  int anoCriacao;
  char descricao[230];
};

void intercala(Celular v[], int p, int q, int r, char tipo)
{
  if (tipo=='1')
  {//Nome
    
  }
  else if (tipo=='2')
  {//Preco
    
  }
  else if (tipo=='3')
  {//Quantidade
    
  }
  else if (tipo=='4')
  {//Ano
    
  }
  else if (tipo=='5')
  {//Fabricante
    
  }
  else if (tipo=='6')
  {
    
  }
  
  
  int i = p, j = q;
  int tamanho = r - p + 1;
  int w[tamanho]; // vetor auxiliar

  int k = 0;

  while ((i < q) && (j <= r))
  {
    if (v[i] <= v[j])
    {
      w[k++] = v[i++]; /* w[k] = v[i]; k++; i++; */
    }
    else
    {
      w[k++] = v[j++]; /* w[k] = v[j]; k++; j++; */
    }
  }

  // terminou um dos vetores, agora copia o outro
  while (i < q)
  {
    w[k++] = v[i++];
  }
  while (j <= r)
  {
    w[k++] = v[j++];
  }

  // agora copiamos do vetor auxiliar aux[] em v[p:r]
  for (int m = 0; m < tamanho; m++)
  {
    v[p + m] = w[m];
  }
}

void mergeiterativo(Celular v[], int tam, char tipo)
{
  int p, r, b = 1;
  while (b < tam)
  {
    p = 0;
    while (p + b < tam)
    {
      r = p + 2 * b - 1;
      if (r >= tam)
        r = tam - 1;
      intercala(v, p, p + b, r, tipo);
      p = p + 2 * b;
    }
    b = 2 * b;
  }
}

void exibirMenuOrdenamento()
{
  system(clearCommand.c_str());

  cout << "===== Ordenacao Celular =====" << endl;
  cout << "1 - Ordenar por Nome" << endl;
  cout << "2 - Ordenar por Preco" << endl;
  cout << "3 - Ordenar por Quantidade" << endl;
  cout << "4 - Ordenar por ano" << endl;
  cout << "5 - Ordenar por Fabricante" << endl;
  cout << "0 - Voltar" << endl;
  cout << "Opcao: ";
}

void exportarParaArquivo(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  char opcao;
  cout << "===== Exportar em arquivos =====" << endl;
  cout << "1 - Salvar em binario (escolha essa opcao se for sair da aplciacao)" << endl;
  cout << "2 - Salvar em .txt" << endl;
  cout << "3 - Salvar em .csv" << endl;
  cout << "4 - Salvar em outro formato" << endl;
  cout << "0 - Voltar para o inicio" << endl;
  cout << "Opcao: ";
  cin >> opcao;

  switch (opcao)
  {
  case '1':
  {
    string nomeArquivo;
    cout << "Digite o nome desejado para o arquivo sem espacos (sem .bin - nome padrao e 'celulares'): ";
    cin >> nomeArquivo;

    ofstream NomeArqvSaida(nomeArquivo + ".bin", ios::binary);

    for (int i = 0; i < estoqueReal; i++)
    {
      // valida os dados
      if (celulares[i].identificador > 0 && celulares[i].preco > 0 && celulares[i].quantidade > 0 && celulares[i].anoCriacao > 0)
      {
        NomeArqvSaida.write((char *)&celulares[i], sizeof(Celular));
      }
    }

    cout << endl
         << "##################################" << endl;
    cout << "Salvo com sucesso!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
    break;
  }
  case '2':
  {
    string nomeArquivo;
    cout << endl
         << "Digite o nome desejado para o arquivo sem espacos (sem .txt): ";
    cin >> nomeArquivo;
    ofstream NomeArqvSaida(nomeArquivo + ".txt");
    NomeArqvSaida << "Indentificador;Nome;Preco;Quantidade;Fabricante;Ano de criacao;Descricao do produto" << endl;
    for (int i = 0; i <= estoqueReal; i++)
    {
      if (celulares[i].identificador > 0)
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
    }

    cout << endl
         << "##################################" << endl;
    cout << "Salvo com sucesso!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
    break;
  }
  case '3':
  {
    string nomeArquivo;
    cout << "Digite o nome desejado para o arquivo sem espacos: ";
    cin >> nomeArquivo;
    ofstream NomeArqvSaida(nomeArquivo + ".csv");
    NomeArqvSaida << "Indentificador;Nome;Preco;Quantidade;Fabricante;Ano de criacao;Descricao do produto" << endl;

    for (int i = 0; i <= estoqueReal; i++)
    {
      if (celulares[i].identificador > 0 && celulares[i].identificador <= estoqueReal)
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
    }

    cout << endl
         << "##################################" << endl;
    cout << "Salvo com sucesso!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar ou Sair: ";
    char voltar;
    cin >> voltar;
    break;
  }
  case '4':
  {
    string nomeArquivo;
    cout << "Digite o nome desejado para o arquivo sem espacos, com o tipo (novosCelulares.xls): ";
    cin >> nomeArquivo;
    ofstream NomeArqvSaida(nomeArquivo);
    NomeArqvSaida << "Indentificador;Nome;Preco;Quantidade;Fabricante;Ano de criacao;Descricao do produto" << endl;
    for (int i = 0; i <= estoqueReal; i++)
    {
      if (celulares[i].identificador > 0)
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
    }
    cout << endl
         << "##################################" << endl;
    cout << "Salvo com sucesso!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
    break;
  }

  default:
    cout << "===== Exportar em arquivos =====" << endl;
    cout << "1 - Salvar em .csv (recomendado)" << endl;
    cout << "2 - Salvar em .txt" << endl;
    cout << "3 - Salvar em outro formato" << endl;
    cout << "0 - Voltar para o inicio" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    break;
  }
}

void importarDeArquivo(Celular celulares[], int &estoqueReal, int estoqueMax)
{
  system(clearCommand.c_str());

  cout << "===== Importar de arquivos =====" << endl;
  cout << "Escreva o nome do arquivo (sem .csv) para ser importado. Com no maximo " << estoqueMax - estoqueReal << " cadastros diferentes do atual banco de dados" << endl;
  cout << "Nome do arquivo: ";
  string nomeArquivo;
  cin >> nomeArquivo;

  ifstream NomeArqvEntrada(nomeArquivo + ".csv");
  if (!NomeArqvEntrada.is_open())
  {
    cout << endl
         << "##################################" << endl;
    cout << "Arquivo nao encontrado!" << endl
         << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
  }
  else
  {
    string linha;
    getline(NomeArqvEntrada, linha);

    int contTelefonesAdicionados = 0;

    // armazena os dados do arquivo em celulares, verificando se ele já existe pelo nome, se já existir armazenar em um vetor para ser mostrado depois
    while (getline(NomeArqvEntrada, linha))
    {
      string nome;
      float preco;
      int quantidade;
      string fabricante;
      int anoCriacao;
      string descricao;

      int posicao = 0;
      int posicaoAnterior = 0;
      int cont = 0;
      while (posicao != -1)
      {
        posicao = linha.find(";", posicaoAnterior);                             // procura o ; na string, posicaoAnterior é a posição inicial da busca
        string dado = linha.substr(posicaoAnterior, posicao - posicaoAnterior); // pega o dado entre o ; e o ; seguinte
        switch (cont)
        {
        case 1:
          nome = dado;
          break;
        case 2:
          preco = stof(dado);
          break;
        case 3:
          quantidade = stoi(dado);
          break;
        case 4:
          fabricante = dado;
          break;
        case 5:
          anoCriacao = stoi(dado);
          break;
        case 6:
          descricao = dado;
          break;
        }
        posicaoAnterior = posicao + 1;
        cont++;
      }

      bool existe = false;
      for (int i = 0; i < estoqueReal; i++)
      {
        if (celulares[i].nome == nome)
        {
          existe = true;
          celulares[i].quantidade += quantidade;
        }
      }

      if (!existe)
      {
        celulares[estoqueReal].identificador = estoqueReal + 1;
        for (unsigned int i = 0; i < nome.length(); i++)
        {
          celulares[estoqueReal].nome[i] = nome[i];
        }
        celulares[estoqueReal].preco = preco;
        celulares[estoqueReal].quantidade = quantidade;
        for (unsigned int i = 0; i < fabricante.length(); i++)
        {
          celulares[estoqueReal].fabricante[i] = fabricante[i];
        }
        celulares[estoqueReal].anoCriacao = anoCriacao;
        for (unsigned int i = 0; i < descricao.length(); i++)
        {
          celulares[estoqueReal].descricao[i] = descricao[i];
        }

        estoqueReal++;
        contTelefonesAdicionados++;
      }
    }

    cout << endl
         << "##################################" << endl;
    cout << "Importado com sucesso!" << endl;
    cout << "Total de celulares adicionados: " << contTelefonesAdicionados << endl;
    cout << "##################################" << endl;

    cout << endl
         << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
  }
  NomeArqvEntrada.close();
}

void cadastrarCelular(Celular celulares[], int &estoqueReal)
{
  system(clearCommand.c_str());

  cout << "===== Cadastro de um novo SmartPhone =====" << endl;
  cout << "Para cadastrar um novo celular, serao necessarios:" << endl
       << "Nome" << endl
       << "Preco" << endl
       << "Quatidade em estoque" << endl
       << "Nome do fabricante" << endl
       << "Ano de criacao" << endl
       << "Descricao" << endl
       << endl
       << "Deseja continuar?" << endl;

  char opcao;
  cout << "1 - Sim" << endl;
  cout << "0 - Voltar para o Inicio" << endl;
  cout << "Opcao: ";
  cin >> opcao;
  cin.ignore();
  if (opcao == '1')
  {
    system(clearCommand.c_str());

    estoqueReal++;

    celulares[estoqueReal - 1].identificador = estoqueReal;
    cout << endl
         << "Digite o nome do produto: ";
    cin.getline(celulares[estoqueReal - 1].nome, 30);
    cout
        << "Digite o preco do produto: ";
    cin >> celulares[estoqueReal - 1].preco;
    cout
        << "Digite a quantidade em estoque: ";
    cin >> celulares[estoqueReal - 1].quantidade;
    cin.ignore();
    cout
        << "Digite o nome do fabricante: ";
    cin.getline(celulares[estoqueReal - 1].fabricante, 10);
    cout
        << "Digite o ano de criacao do aparelho: ";
    cin >> celulares[estoqueReal - 1].anoCriacao;
    cin.ignore();
    cout
        << "Digite a descricao do produto: ";
    cin.getline(celulares[estoqueReal - 1].descricao, 230);

    system(clearCommand.c_str());

    cout << "### Celular cadastrado com sucesso ###" << endl;
    cout << "Identificacao: " << celulares[estoqueReal - 1].identificador << endl;
    cout << "Nome: " << celulares[estoqueReal - 1].nome << endl;
    cout << "Preco: " << celulares[estoqueReal - 1].preco << endl;
    cout << "Quantidade em estoque: " << celulares[estoqueReal - 1].quantidade << endl;
    cout << "Fabricante do Aparelho: " << celulares[estoqueReal - 1].fabricante << endl;
    cout << "Ano de Criacao: " << celulares[estoqueReal - 1].anoCriacao << endl;
    cout << "Descricao do produto: " << celulares[estoqueReal - 1].descricao << endl;

    cout << endl
         << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
  }
}

bool contemPalavra(string nomeReferencia, string nome)
{
  unsigned int cont = 0;
  for (unsigned int i = 0; i < nomeReferencia.length(); i++)
  {
    if (nomeReferencia[i] == nome[i])
    {
      cont++;
    }
  }

  if (cont == nome.length())
  {
    return true;
  }
  else
  {
    return false;
  }
}

void buscarPorAnoCriacao(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  char opcao;
  cout << "===== Buscar por Ano de Criacao =====" << endl;
  cout << "1 - Por Ano de Criacao" << endl;
  cout << "2 - Por Faixa de Ano de Criacao" << endl;
  cout << "3 - Por Ano de Criacao Minimo" << endl;
  cout << "4 - Por Ano de Criacao Maximo" << endl;
  cout << "Opcao: ";
  cin >> opcao;

  bool encontrado = false;
  int cont = 0;

  Celular resposta[estoqueReal];
  int j = 0;

  switch (opcao)
  {
  case '1':
  {
    int anoCriacao;
    cout << "Digite o ano de criacao do celular: ";
    cin >> anoCriacao;

    cout << "=== Celular Encontrado com o ano de criacao: " << anoCriacao << " ===" << endl;

    for (int i = 0; i <= estoqueReal; i++)
    {
      if (celulares[i].anoCriacao == anoCriacao && celulares[i].identificador > 0)
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
        for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
        {
          resposta[j].nome[c] = celulares[i].nome[c];
        }
        resposta[j].preco = celulares[i].preco;
        resposta[j].quantidade = celulares[i].quantidade;
        for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
        {
          resposta[j].fabricante[c] = celulares[i].fabricante[c];
        }
        resposta[j].anoCriacao = celulares[i].anoCriacao;
        for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
        {
          resposta[j].descricao[c] = celulares[i].descricao[c];
        }

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

      cout << endl
           << "Deseja exportar essa lista em um arquivo separado?" << endl;
      cout << "1 - sim" << endl
           << "0 - nao" << endl;
      cout << "Opcao: ";
      int respostaExportar;
      cin >> respostaExportar;

      if (respostaExportar == 1)
      {
        exportarParaArquivo(resposta, cont);
      }
    }
    break;
  }
  case '2':
  {
    int anoCriacaoMin, anoCriacaoMax;
    cout << "Digite o ano de criacao minimo: ";
    cin >> anoCriacaoMin;
    cout << "Digite o ano de criacao maximo: ";
    cin >> anoCriacaoMax;

    cout << "=== Celular Encontrado com o ano de criacao entre: " << anoCriacaoMin << " e " << anoCriacaoMax << " ===" << endl;

    for (int i = 0; i <= estoqueReal; i++)
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

        resposta[j].identificador = celulares[i].identificador;
        for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
        {
          resposta[j].nome[c] = celulares[i].nome[c];
        }
        resposta[j].preco = celulares[i].preco;
        resposta[j].quantidade = celulares[i].quantidade;
        for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
        {
          resposta[j].fabricante[c] = celulares[i].fabricante[c];
        }
        resposta[j].anoCriacao = celulares[i].anoCriacao;
        for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
        {
          resposta[j].descricao[c] = celulares[i].descricao[c];
        }

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

      cout << endl
           << "Deseja exportar essa lista em um arquivo separado?" << endl;
      cout << "1 - sim" << endl
           << "0 - nao" << endl;
      cout << "Opcao: ";
      int respostaExportar;
      cin >> respostaExportar;

      if (respostaExportar == 1)
      {
        exportarParaArquivo(resposta, cont);
      }
    }
    break;
  }
  case '3':
  {
    int anoCriacaoMin;
    cout << "Digite o ano de criacao minimo: ";
    cin >> anoCriacaoMin;

    cout << "=== Celular Encontrado com o ano de criacao minimo de: " << anoCriacaoMin << " ===" << endl;

    for (int i = 0; i <= estoqueReal; i++)
    {
      if (celulares[i].anoCriacao >= anoCriacaoMin && celulares[i].identificador > 0)
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
        for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
        {
          resposta[j].nome[c] = celulares[i].nome[c];
        }
        resposta[j].preco = celulares[i].preco;
        resposta[j].quantidade = celulares[i].quantidade;
        for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
        {
          resposta[j].fabricante[c] = celulares[i].fabricante[c];
        }
        resposta[j].anoCriacao = celulares[i].anoCriacao;
        for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
        {
          resposta[j].descricao[c] = celulares[i].descricao[c];
        }

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

      cout << endl
           << "Deseja exportar essa lista em um arquivo separado?" << endl;
      cout << "1 - sim" << endl
           << "0 - nao" << endl;
      cout << "Opcao: ";
      int respostaExportar;
      cin >> respostaExportar;

      if (respostaExportar == 1)
      {
        exportarParaArquivo(resposta, cont);
      }
    }
    break;
  }
  case '4':
  {
    int anoCriacaoMax;
    cout << "Digite o ano de criacao maximo: ";
    cin >> anoCriacaoMax;

    cout << "=== Celular Encontrado com o ano de criacao maximo de: " << anoCriacaoMax << " ===" << endl;

    for (int i = 0; i <= estoqueReal; i++)
    {
      if (celulares[i].anoCriacao <= anoCriacaoMax && celulares[i].identificador > 0)
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
        for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
        {
          resposta[j].nome[c] = celulares[i].nome[c];
        }
        resposta[j].preco = celulares[i].preco;
        resposta[j].quantidade = celulares[i].quantidade;
        for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
        {
          resposta[j].fabricante[c] = celulares[i].fabricante[c];
        }
        resposta[j].anoCriacao = celulares[i].anoCriacao;
        for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
        {
          resposta[j].descricao[c] = celulares[i].descricao[c];
        }

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

      cout << endl
           << "Deseja exportar essa lista em um arquivo separado?" << endl;
      cout << "1 - sim" << endl
           << "0 - nao" << endl;
      cout << "Opcao: ";
      int respostaExportar;
      cin >> respostaExportar;

      if (respostaExportar == 1)
      {
        exportarParaArquivo(resposta, cont);
      }
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

  Celular resposta[estoqueReal];
  int j = 0;

  for (int i = 0; i <= estoqueReal; i++)
  {
    if (contemPalavra(celulares[i].fabricante, fabricante) && celulares[i].identificador > 0)
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
      for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
      {
        resposta[j].nome[c] = celulares[i].nome[c];
      }
      resposta[j].preco = celulares[i].preco;
      resposta[j].quantidade = celulares[i].quantidade;
      for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
      {
        resposta[j].fabricante[c] = celulares[i].fabricante[c];
      }
      resposta[j].anoCriacao = celulares[i].anoCriacao;
      for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
      {
        resposta[j].descricao[c] = celulares[i].descricao[c];
      }

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

    cout << endl
         << "Deseja exportar essa lista em um arquivo separado?" << endl;
    cout << "1 - sim" << endl
         << "0 - nao" << endl;
    cout << "Opcao: ";
    int respostaExportar;
    cin >> respostaExportar;

    if (respostaExportar == 1)
    {
      exportarParaArquivo(resposta, cont);
    }
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

  Celular resposta[estoqueReal];
  int j = 0;

  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].quantidade >= quantidade && celulares[i].identificador > 0)
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
      for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
      {
        resposta[j].nome[c] = celulares[i].nome[c];
      }
      resposta[j].preco = celulares[i].preco;
      resposta[j].quantidade = celulares[i].quantidade;
      for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
      {
        resposta[j].fabricante[c] = celulares[i].fabricante[c];
      }
      resposta[j].anoCriacao = celulares[i].anoCriacao;
      for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
      {
        resposta[j].descricao[c] = celulares[i].descricao[c];
      }

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

    cout << endl
         << "Deseja exportar essa lista em um arquivo separado?" << endl;
    cout << "1 - sim" << endl
         << "0 - nao" << endl;
    cout << "Opcao: ";
    int respostaExportar;
    cin >> respostaExportar;

    if (respostaExportar == 1)
    {
      exportarParaArquivo(resposta, cont);
    }
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

  Celular resposta[estoqueReal];
  int j = 0;

  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].preco >= precoMin && celulares[i].preco <= precoMax && celulares[i].identificador > 0)
    {
      cout << "=== Filtro de : " << precoMin << " ate " << precoMax << " dolares ===" << endl;
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
      for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
      {
        resposta[j].nome[c] = celulares[i].nome[c];
      }
      resposta[j].preco = celulares[i].preco;
      resposta[j].quantidade = celulares[i].quantidade;
      for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
      {
        resposta[j].fabricante[c] = celulares[i].fabricante[c];
      }
      resposta[j].anoCriacao = celulares[i].anoCriacao;
      for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
      {
        resposta[j].descricao[c] = celulares[i].descricao[c];
      }

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

    cout << endl
         << "Deseja exportar essa lista em um arquivo separado?" << endl;
    cout << "1 - sim" << endl
         << "0 - nao" << endl;
    cout << "Opcao: ";
    int respostaExportar;
    cin >> respostaExportar;

    if (respostaExportar == 1)
    {
      exportarParaArquivo(resposta, cont);
    }
  }
}

void buscarPorNome(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  char nome[30];
  cout << "Digite o nome do celular: ";
  cin.getline(nome, 30);

  bool encontrado = false;
  int cont = 0;

  Celular resposta[estoqueReal];
  int j = 0;

  for (int i = 0; i <= estoqueReal; i++)
  {
    if (contemPalavra(celulares[i].nome, nome) && celulares[i].identificador > 0)
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
      for (unsigned int c = 0; c < strlen(celulares[i].nome); c++)
      {
        resposta[j].nome[c] = celulares[i].nome[c];
      }
      resposta[j].preco = celulares[i].preco;
      resposta[j].quantidade = celulares[i].quantidade;
      for (unsigned int c = 0; c < strlen(celulares[i].fabricante); c++)
      {
        resposta[j].fabricante[c] = celulares[i].fabricante[c];
      }
      resposta[j].anoCriacao = celulares[i].anoCriacao;
      for (unsigned int c = 0; c < strlen(celulares[i].descricao); c++)
      {
        resposta[j].descricao[c] = celulares[i].descricao[c];
      }

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

    cout << endl
         << "Deseja exportar essa lista em um arquivo separado?" << endl;
    cout << "1 - sim" << endl
         << "0 - nao" << endl;
    cout << "Opcao: ";
    int respostaExportar;
    cin >> respostaExportar;

    if (respostaExportar == 1)
    {
      exportarParaArquivo(resposta, cont);
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
  for (int j = 0; j <= estoqueReal; j++)
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
           << "Digite o novo nome (maximo 30 caracteres): ";
      cin.getline(celulares[j].nome, 30);
      cout << "Digite o novo preco: ";
      cin >> celulares[j].preco;
      cout << "Digite a nova quantidade: ";
      cin >> celulares[j].quantidade;
      cin.ignore();
      cout << "Digite o novo fabricante (maximo 10 caracteres): ";
      cin.getline(celulares[j].fabricante, 10);
      cout << "Digite o novo ano de criacao: ";
      cin >> celulares[j].anoCriacao;
      cin.ignore();
      cout << "Digite a nova descricao (maximo 230 caracteres): ";
      cin.getline(celulares[j].descricao, 230);

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
           << "1 - Alterar novamente" << endl;
      cout << "0 - Voltar para o inicio" << endl;
      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 1)
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
  for (int j = 0; j <= estoqueReal; j++)
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
           << "1 - Alterar novamente" << endl;
      cout << "0 - Voltar para o inicio" << endl;

      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 1)
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
  for (int j = 0; j <= estoqueReal; j++)
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
           << "1 - Alterar novamente" << endl;
      cout << "0 - Voltar para o inicio" << endl;

      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 1)
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
  for (int i = 0; i <= estoqueReal; i++)
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
      char resposta[30];
      cin.getline(resposta, 30);

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
        for (unsigned j = 0; j < strlen(celulares[i].nome); j++)
        {
          celulares[i].nome[j] = ' ';
        }

        for (unsigned j = 0; j < strlen(resposta); j++)
        {
          celulares[i].nome[j] = resposta[j];
        }

        cout << endl
             << "##################################" << endl;
        cout << "Celular alterado com sucesso!" << endl
             << "##################################" << endl;
      }

      int opcao;
      cout << endl
           << "1 - Alterar novamente" << endl;
      cout << "0 - Voltar para o inicio" << endl;

      cout << "Opcao: ";
      cin >> opcao;

      if (opcao == 1)
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

void removerCelular(Celular celulares[], int estoqueReal)
{
  system(clearCommand.c_str());

  cout << "===== Remocao de SmartPhone =====" << endl;
  cout << "Digite o identificador do SmartPhone que deseja remover: ";

  int identificador;
  cin >> identificador;

  int posicao;
  int contPosicao = 0;
  for (int i = 0; i <= estoqueReal; i++)
  {
    if (celulares[i].identificador == identificador)
    {
      posicao = i;
      contPosicao++;
    }
  }

  if (contPosicao == 1)
  {
    cout << "O celular que sera removido e: " << endl;
    cout << "Identificacao: " << celulares[posicao].identificador << endl;
    cout << "Nome: " << celulares[posicao].nome << endl;
    cout << "Preco: " << celulares[posicao].preco << endl;
    cout << "Quantidade em estoque: " << celulares[posicao].quantidade << endl;
    cout << "Fabricante do Aparelho: " << celulares[posicao].fabricante << endl;
    cout << "Ano de Criacao: " << celulares[posicao].anoCriacao << endl;
    cout << "Descricao do produto:  " << celulares[posicao].descricao << endl;

    cout << endl
         << "Deseja realmente remover esse celular?" << endl;
    char opcao;
    cout << "1 - Sim" << endl;
    cout << "0 - Voltar para o Inicio" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    cin.ignore();

    if (opcao == '1')
    {
      system(clearCommand.c_str());

      // invalidando os campus
      celulares[posicao].identificador = -1;
      for (unsigned int i = 0; i < strlen(celulares[posicao].nome); i++)
      {
        celulares[posicao].nome[i] = ' ';
      }
      celulares[posicao].preco = -1;
      celulares[posicao].quantidade = -1;
      for (unsigned int i = 0; i < strlen(celulares[posicao].fabricante); i++)
      {
        celulares[posicao].fabricante[i] = ' ';
      }
      celulares[posicao].anoCriacao = -1;
      for (unsigned int i = 0; i < strlen(celulares[posicao].descricao); i++)
      {
        celulares[posicao].descricao[i] = ' ';
      }

      cout << "##################################" << endl;
      cout << "Removido com sucesso!" << endl;
      cout << "##################################" << endl;
      cout << "Digite '0' Para Voltar: ";
      int voltar;
      cin >> voltar;
    }
    system(clearCommand.c_str());
  }
  else
  {
    system(clearCommand.c_str());

    cout << "##################################" << endl;
    cout << "IDENTIFICADOR NAO ENCONTRADO!" << endl;
    cout << "##################################" << endl;
    cout << "Digite '0' Para Voltar: ";
    char voltar;
    cin >> voltar;
  }
}

void consultarEspacoEmEstoque(int estoqueReal, int estoqueMax)
{
  system(clearCommand.c_str());

  // perguntar se ele quer o espaço utilziado ou o espaço que ainda está disponivel
  int opcao;
  cout << "Deseja consultar:" << endl;
  cout << "1 - Espaco utilizado" << endl;
  cout << "2 - Espaco disponivel" << endl;
  cout << "0 - Voltar" << endl;
  cout << "Opcao: ";
  cin >> opcao;

  if (opcao == 1)
  {
    cout << endl
         << "##################################" << endl;
    cout << "Espaco utilizado: " << estoqueReal << endl;
    cout << "##################################" << endl;

    int opcao;
    cout << endl
         << "Digite '0' para voltar: " << endl;
    cout << "Opcao: ";
    cin >> opcao;
  }
  else if (opcao == 2)
  {
    cout << endl
         << "##################################" << endl;
    cout << "Espaco disponivel: " << estoqueMax - estoqueReal << endl;
    cout << "##################################" << endl;

    int opcao;
    cout << endl
         << "Digite '0' para voltar: " << endl;
    cout << "Opcao: ";
    cin >> opcao;
  }
  else
  {
    cout << endl
         << "##################################" << endl;
    cout << "Opcao invalida!" << endl;
    cout << "##################################" << endl;
  }
}

void confirmarSaida(Celular celulares[], int &estoqueReal)
{
  system(clearCommand.c_str());

  int opcao;
  cout << "Deseja salvar o arquivo?" << endl;
  cout << "1 - Sim" << endl;
  cout << "0 - Nao" << endl;
  cout << "Opcao: ";
  cin >> opcao;

  if (opcao == 1)
  {
    exportarParaArquivo(celulares, estoqueReal);
    // finaliza programa
    cout << endl
         << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << endl;
    cout << "Obrigado por utilizar o sistema!" << endl
         << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << endl;
    exit(0);
  }
  else
  {
    // finaliza programa
    cout << endl
         << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << endl;
    cout << "Obrigado por utilizar o sistema!" << endl
         << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << endl;
    exit(0);
  }
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
  cout << "7 - Consultar espaco em estoque" << endl;
  cout << "0 - Sair" << endl;
  cout << "Opcao: ";
}

int main()
{
  system("color 0E");              // cor da tela = preta, fonte = amarela
  setlocale(LC_ALL, "Portuguese"); // Leitura do idioma

  // Recebendo dados do arquivo celulares.csv e colocando em um vetor registro
  ifstream arquivoIn("celulares.bin", ios::binary);

  if (!arquivoIn.is_open())
  {
    cout << "Erro ao abrir o arquivo 'celulares.bin'!" << endl;
    return 0;
  }

  // utilizando struct com ponteiro para armazenar os dados do arquivo

  arquivoIn.seekg(0, ios::end);
  int tamanhoArquivo = arquivoIn.tellg();

  arquivoIn.seekg(0, ios::beg);

  int estoqueMax = tamanhoArquivo / sizeof(Celular);
  Celular *celulares;
  celulares = new Celular[estoqueMax];

  int estoqueReal = 0;
  string linha;

  while (estoqueReal < estoqueMax && arquivoIn.read((char *)&celulares[estoqueReal], sizeof(Celular)))
  {
    estoqueReal++;
  }

  // Funções:
  exibirMenu();
  char opcao;
  do
  {
    cin >> opcao;
    int opcaoConsultaNovamente;
    char opcaoBuscarCelular;

    switch (opcao)
    {
    case '1':
    { // Cadastrar Celular
      do
      {
        if (estoqueMax - estoqueReal <= 50)
        {
          Celular *aux;
          aux = new Celular[estoqueReal + 100];
          copy(celulares, celulares + estoqueReal, aux);
          delete[] celulares;
          celulares = aux;

          estoqueMax += 100;
        }

        cadastrarCelular(celulares, estoqueReal);
      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);

      break;
    }
    case '2':
    { // Remover Celular
      do
      {
        removerCelular(celulares, estoqueReal);
      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);

      break;
    }
    case '3':
    { // Busca Celular
      do
      {
        exibirMenuBuscarCelular();
        cin >> opcaoBuscarCelular;
        cin.ignore();

        switch (opcaoBuscarCelular)
        {

        case '1':
          buscarPorIdentificador(celulares, estoqueReal);
          break;
        case '2':
          buscarPorNome(celulares, estoqueReal);
          break;
        case '3':
          buscarPorFaixaDePreco(celulares, estoqueReal);
          break;
        case '4':
          buscarPorQuantidade(celulares, estoqueReal);
          break;
        case '5':
          buscarPorFabricante(celulares, estoqueReal);
          break;
        case '6':
          buscarPorAnoCriacao(celulares, estoqueReal);
          break;

        default:
          cout << "Opcao invalida!" << endl;
          exibirMenuBuscarCelular();
          cin >> opcaoBuscarCelular;
          cin.ignore();
          break;
        }

        if (opcaoBuscarCelular != 0)
        {
          cout << endl
               << "Gostaria de buscar novamente?" << endl;
          cout << "1 - Sim" << endl;
          cout << "0 - Nao" << endl;
          cout << "Opcao: ";
          cin >> opcaoConsultaNovamente;
        }
      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);
      break;
    }
    case '4':
    { // Alterar Celular
      do
      {
        exibirMenuAlterarCelular();
        char opcaoAlterarCelular;
        cin >> opcaoAlterarCelular;

        switch (opcaoAlterarCelular)
        {
        case '1':
          alterarNome(celulares, estoqueReal);
          break;
        case '2':
          alterarPreco(celulares, estoqueReal);
          break;
        case '3':
          alterarQuantidade(celulares, estoqueReal);
          break;
        case '4':
          alterarTodosDados(celulares, estoqueReal);
          break;
        case '5':
        {
          do
          {
            exibirMenuBuscarCelular();
            cin >> opcaoBuscarCelular;
            cin.ignore();

            switch (opcaoBuscarCelular)
            {

            case '1':
              buscarPorIdentificador(celulares, estoqueReal);
              break;
            case '2':
              buscarPorNome(celulares, estoqueReal);
              break;
            case '3':
              buscarPorFaixaDePreco(celulares, estoqueReal);
              break;
            case '4':
              buscarPorQuantidade(celulares, estoqueReal);
              break;
            case '5':
              buscarPorFabricante(celulares, estoqueReal);
              break;
            case '6':
              buscarPorAnoCriacao(celulares, estoqueReal);
              break;

            default:
              cout << "Opcao invalida!" << endl;
              exibirMenuBuscarCelular();
              cin >> opcaoBuscarCelular;
              cin.ignore();
              break;
            }

            if (opcaoBuscarCelular != 0)
            {
              cout << endl
                   << "Gostaria de buscar novamente?" << endl;
              cout << "1 - Sim" << endl;
              cout << "0 - Nao" << endl;
              cout << "Opcao: ";
              cin >> opcaoConsultaNovamente;
            }
          } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);
          break;
        }

        default:
          cout << "Opcao invalida!" << endl;
          exibirMenuBuscarCelular();
          cin >> opcaoBuscarCelular;
          break;
        }
      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);
      break;
    }
    case '5':
    { // Exportar para CSV
      do
      {
        exportarParaArquivo(celulares, estoqueReal);

      } while (opcaoBuscarCelular != 0 && opcaoConsultaNovamente == 1);

      break;
    }
    case '6':
    { // Importar de CSV
      if (estoqueMax - estoqueReal <= 50)
      {
        Celular *aux;
        aux = new Celular[estoqueReal * 2];
        copy(celulares, celulares + estoqueReal, aux);
        delete[] celulares;
        celulares = aux;

        estoqueMax *= 2;
      }
      importarDeArquivo(celulares, estoqueReal, estoqueMax);
      break;
    }
    case '7':
    { // Consultar espaco em estoque
      consultarEspacoEmEstoque(estoqueReal, estoqueMax);
      break;
    }
    case '8':
    { // Ordenar
      exibirMenuOrdenamento();
      char opcaoOrdenamento;

      cin >> opcaoOrdenamento;

      switch (opcaoOrdenamento)
      {
      case '1':
        char tipo = '1';
        mergeiterativo(celulares, estoqueReal, tipo);
        break;
      case '2':
        char tipo = '2';
        mergeiterativo(celulares, estoqueReal, tipo);
        break;
      case '3':
        char tipo = '3';
        mergeiterativo(celulares, estoqueReal, tipo);
        break;
      case '4':
        char tipo = '4';
        mergeiterativo(celulares, estoqueReal, tipo);
        break;
      case '5':
        char tipo = '5';
        mergeiterativo(celulares, estoqueReal, tipo);
        break;
      case '0':
        break;

      default:
        cout << "Opcao invalida!" << endl;
        exibirMenuOrdenamento();
        cin >> opcaoOrdenamento;
        break;
      }
    }
    case '0':
    { // Sair
      confirmarSaida(celulares, estoqueReal);
      break;
    }

    default:
      exibirMenu();
      cin >> opcao;
      break;
    }
    cout << endl;
    exibirMenu();
  } while (opcao != 0);

  arquivoIn.close();

  return 0;
}
