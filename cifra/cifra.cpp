#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "tries.h"
#include <chrono>
class cifra
{
public:
vector<int> keys;
vector<string> palavras;
cifra(string pathtext,string pathkey)
  {
    ifstream texto(pathtext);
    ifstream chave(pathkey);
    int key;
    while (chave >> key)
    {
      keys.push_back(key);
    }
    string aux;
    string palavra;
    while (texto >> aux)
    {
      aux += ' ';
      for (char c : aux)
      {

        if (c == ' ')
        {
          palavras.push_back(palavra);
          palavra = "";
          continue;
        }
        if (isalpha(c))
          palavra += toupper(c);
      }
    }
    cypher();
    decrypt();
  }

  void decrypt()
  {
    auto start = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    int aux = 1;
    for (unsigned i = 0; i < palavras.size(); i++)
    {
      for (unsigned j = 0; j < palavras[i].length(); j++)
      {

        int key;
        int cont = 65;
        for (unsigned k = 0; k < 26; k++)
        {
          cont = cont + keys[k];
          if (cont > 90)
          {
            int dif = cont - 90;
            cont = 65 + dif - 1;
          }
          if (palavras[i][j] == cont)
          {
            key = keys[k];

            break;
          }
          cont = 65 + aux;
          aux++;
        }
        aux = 1;
        palavras[i][j] -= key;
        if (palavras[i][j] < 65)
        {
          int dif = palavras[i][j] - 65;
          palavras[i][j] = 90 + dif + 1;
          continue;
        }
      }
    }
   // cout << "Sua chave descriptografada: ";
   // for (unsigned i = 0; i < palavras.size(); i++)
   // {
   //   cout << palavras[i] << " ";
   // }
    
    auto end = chrono::high_resolution_clock::now();
    // Calcular a duração da execução
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
  }
  void cypher()
  {
    auto start = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    for (unsigned i = 0; i < palavras.size(); i++)
    {
      for (unsigned j = 0; j < palavras[i].length(); j++)
      {
        int pos = palavras[i][j] - 65;
        palavras[i][j] += keys[pos];
        if (palavras[i][j] > 90)
        {
          int dif = palavras[i][j] - 90;
          palavras[i][j] = 65 + dif - 1;
          continue;
        }
      }
    }
    //cout << "Sua chave criptografada: ";
    //for (unsigned i = 0; i < palavras.size(); i++)
    //{
    //  cout << palavras[i] << " ";
    //}
    
    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    // Calcular a duração da execução
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << duration.count() << " milissegundos" << endl;
  }
};
int main(){
  cifra a("C:/Users/xtron/Desktop/aaaa/cifra/arq.txt","C:/Users/xtron/Desktop/aaaa/cifra/chave.txt");
}
