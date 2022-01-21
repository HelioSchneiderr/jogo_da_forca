#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
#include <stdbool.h>

using namespace std;

void limpaTela(){

    system("CLS");

}

string retornaPalavraAleatoria(){

    string palavras[5] = {"carro", "violao", "jogar", "dinheiro", "festa"};

    //Opera��o para gerar um indice aleatorio  (1, 2, 3)
    int indiceAleatorio = rand() % 5;

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

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

    cout << mensagem << "\n";
    cout << "Palavra:" << palavraComMascara << "(Tamanho: " << tamanhoDaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;


    int cont;
    cout << "\n Letras arriscadas:";
    for(cont = 0; cont < letrasJaArriscadas.size();cont++){

        cout << letrasJaArriscadas[cont]<< ", ";

    }

}

int jogar(int numeroDeJogadores){

    //palavra a ser adivinhada
    string palavra;


    //confere o numero de jogadores

    if(numeroDeJogadores == 1){

        palavra = retornaPalavraAleatoria();


    }else{

        cout << "\n Digite uma Palavra:";
        cin >> palavra;

    }


    int cont;
    int tamanhoDaPalavra = palavra.size();

    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);


    ///Variáveis Gerais

    int opcao;
    int tentativas = 0, maximoDeTentativas = 10; //número de tentativas e erros
    cont = 0;                                   //auxiliar para laços de repetições
    char letra;                                 //letra arriscada pelo usuarioa
    string letrasJaArriscadas;                  // acumula as tentativas do jogador
    string mensagem = "Bem Vindo(a) ao jogo:";
    bool jaDigitouLetra, acertouLetra;                        // pra ver se ja digitou a letra ou não




    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0 ){

        limpaTela();

    exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);

    cout << "\nDigite uma letra:";
    cin >> letra;

    //percorre as letras ja arriscada
    for(cont = 0; cont < tentativas; cont++){

        if(letrasJaArriscadas[cont] == letra){

            mensagem = "Essa letra ja foi digitada!";

            jaDigitouLetra = true;

        }

    }


    if(jaDigitouLetra == false){

        //incrementa as letras ja arriscadas
         letrasJaArriscadas += tolower(letra);

         for(cont = 0; cont < tamanhoDaPalavra; cont++){

         if(palavra[cont] == tolower(letra)){

            palavraComMascara[cont] = palavra[cont];



            acertouLetra = true;
        }

       }

        if(acertouLetra==false){
            mensagem = "Voce acertou uma letra";
        }else{

            mensagem = "Voce acertou uma letra";
            acertouLetra = true;

        }
        tentativas++;


    }

    //reinicia as variaveis auxiliares
    jaDigitouLetra = false;
    acertouLetra = false;



    }

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "\n\n\nParabens voce venceu!\n\n\n";
        cout << "\nDeseja Reiniciar?\n\n";
        cout << "1 - sim";
        cout << "\n\n2 - nao";
        cin >> opcao;
        return opcao;

        }else{

        limpaTela();
        cout << "\n\n\nParabens voce venceu!\n\n\n";
        cout << "\nDeseja Reiniciar?\n\n";
        cout << "1 - sim";
        cout << "\n\n2 - nao";
        cin >> opcao;
        return opcao;



    }
}



void menuInicial(){

    //fun��o escolhida pelo usuario
    int opcao = 0;
    limpaTela();
    while(opcao < 1 || opcao>3){
    limpaTela();
    cout << "Bem-vindo ao jogo\n\n";
    cout << "1 - Jogar Sozinho\n";
    cout << "2 - Jogar em Dupla\n";
    cout << "3 - Sobre\n";
    cout << "4 - Sair\n\n";
    cout << "Digite um dos numeros acima e aperte ENTER:\n";

    cin >> opcao;

    switch(opcao){

    case 1:
        //inicia o jogo

        cout << "Jogo Iniciado";
        if(jogar(1) == 1){

            menuInicial();
        }
        break;

    case 2:
        //inicia o jogo

        cout << "Jogo Iniciado";
        if(jogar(2) == 1){

            menuInicial();
        }
        break;


    case 3:

        cout << "Informacoes do jogo";
        limpaTela();
        cout << "Jogo criado por Helio Leandro, junto ao professor João em um curso de C# e C++";
        cout << "\n1 - Voltar";
        cout << "\n2 - Sair";
        cin >> opcao;
        if(opcao == 1){

            menuInicial();
        }


        break;


    case 4:

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
