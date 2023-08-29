#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX_FILA 5

using namespace std;

struct DADOS_ALUNO {
	
	int CodAluno;
	char Nome[100];
	int Turma;
	
};

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila);
bool ExibirPrimeiro(DADOS_ALUNO[], int IniFila, int FimFila);
bool Desenfileirar(DADOS_ALUNO Fila[], int&PosicaoFim);

main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	struct DADOS_ALUNO FilaAlunos[MAX_FILA];
	int IniFila = 0;
	int FimFila = 0;
	bool Ret; int CodAluno, Turma;
	char Nome[100];
	 int opcao;

    do {
    	
        cout << "\nDigite a opção:\n\n";
        cout << "1 - Exibir\n";
        cout << "2 - Enfileirar\n";
        cout << "3 - Desenfileirar\n";
        cout << "4 - Sair\n\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
        	
            case 1: Ret = ExibirPrimeiro(FilaAlunos, IniFila, FimFila);
                	if (!Ret) {
                	
                    	cout << "Não foi possível exibir a fila" << endl;
                    
                	} break;
                	
            case 2: cout << "\nDigite o código do aluno: ";
                	cin >> CodAluno;

                	cout << "Digite o nome do aluno: ";
                	cin.ignore();
                	cin.getline(Nome, sizeof(Nome));

                	cout << "Digite a turma: ";
                	cin >> Turma;

                	Ret = Enfileirar(FilaAlunos, CodAluno, Nome, Turma, FimFila);

                	if (Ret) {
                		
                    	cout << "Inserção efetuada com sucesso!" << endl;
                    	
                	} 
                	
					else {
						
                    	cout << "Não foi possível enfileirar o aluno." << endl;
                    	
                	} break;
            
            case 3: Ret = Desenfileirar(FilaAlunos, FimFila);
                	if (Ret) {
                		
                    	cout << "Primeiro da fila desenfileirado com sucesso." << endl;
                    	
                	}
					 
					else {
						
                    	cout << "Não foi possível desenfileirar a fila." << endl;
                    	
                	} break;

            case 4: cout << "Encerrando o programa." << endl;
                	break;

            default: cout << "Opção inválida. Digite uma opção válida." << endl;
                	break;
                	
        }
    } while (opcao != 4);

    return 0;
	
}

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila) {
	
	if (FimFila == MAX_FILA) {
		
		cout << "ERRO: Fila cheia.";
		return false;
		
	}
	
	else {
		
		Fila[FimFila].CodAluno = CodAluno;
		strcpy(Fila[FimFila].Nome, Nome);
		Fila[FimFila].Turma = Turma;
		FimFila++;
		
	}
	
	return true;

}

bool ExibirPrimeiro(DADOS_ALUNO Fila[], int IniFila, int FimFila) {
	
	if (FimFila == 0) {
		
		cout << "ERRO: Fila vazia.";
		return false;
		
	}
	
	cout << "\nCódigo do Aluno: " << Fila[IniFila].CodAluno << endl;
	cout << "Nome: " << Fila[IniFila].Nome << endl;
	cout << "Turma: " << Fila[IniFila].Turma << endl;
	
	return true;
	
}

bool Desenfileirar(DADOS_ALUNO Fila[], int&PosicaoFim){
	
	int ind;
	int PosRem;
	
	if (PosicaoFim == 0) {
		
		cout << "ERRO: Lista vazia.";
		return false;
		
	}
	
	for (ind=0; ind<PosicaoFim; ind++) {
		
		Fila[ind] = Fila[ind+1];
		
	}
	
	PosicaoFim--;
	
	return true;
	
}
