#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){

    system("CLS");

}

string retornaPalavraAleatoria(){

    string palavras[3] = {"carro", "violao", "jogar"};

    //Opera��o para gerar um indice aleatorio  (1, 2, 3)
    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){

    int cont = 0;
    string palavraComMascara;

    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;

}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes){

    cout << "Palavra:" << palavraComMascara << "(Tamanho: " << tamanhoDaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;


}

void jogaSozinho(){

    string palavra = retornaPalavraAleatoria();

    int cont;
    int tamanhoDaPalavra = palavra.size();

    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tentativas = 0, maximoDeTentativas = 5;

    char letra;

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0 ){

    limpaTela();

    exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas);

    cout << "\nDigite uma letra:";
    cin >> letra;

    for(cont = 0; cont < tamanhoDaPalavra; cont++){
        if(palavra[cont] == letra){

            palavraComMascara[cont] = palavra[cont];


        }

    }

    tentativas++;

    }

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "n\n\n\nParabens voce venceu!n\n\n\n";

    }else{

        limpaTela();
        cout << "\n\n\n\nVoce perdeu :(\n\n\n\n";


    }
}



void menuInicial(){

    //fun��o escolhida pelo usuario
    int opcao = 0;
    limpaTela();
    while(opcao < 1 || opcao>3){
    limpaTela();
    cout << "Bem-vindo ao jogo\n\n";
    cout << "1 - Jogar\n";
    cout << "2 - Sobre\n";
    cout << "3 - Sair\n\n";
    cout << "Digite um dos numeros acima e aperte ENTER:\n";

    cin >> opcao;

    switch(opcao){

    case 1:
        //inicia o jogo

        cout << "Jogo Iniciado";
        jogaSozinho();
        break;


    case 2:

        cout << "Informacoes do jogo";

        break;


    case 3:

        cout << "Ate mais grande amigo(a)";

        break;

    }

    }

}

int main(){
    menuInicial();

    srand( (unsigned) time(NULL));

    return 0;

}