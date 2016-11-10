#include <stdio.h>
#include <stdlib.h>

int i;
int pes[200];
int ncontas;

union pessoa{
    int cpf;
    int cnpj;
};

struct cadastro
{
    int conta;
    float saldo;
    int nagencia;
    char nomecliente[20];
    union pessoa p;
    int tipocliente;
};

int main()
{
    printf("Usuario, quantas contas deseja cadastrar?\n");
    scanf("%d", &ncontas);
    do
    {
        if(ncontas < 0)
        {
            printf("Numero Invalido, por favor, digite um numero maior do que 0\n");
            printf("Usuario, quantas contas deseja cadastrar?\n");
            scanf("%d", &ncontas);
        }
    }while(ncontas < 0);
    int recebercontas(struct cadastro lista[]);
    int printcontas(struct cadastro lista[]);
    int buscacliente(struct cadastro lista[]);
    int buscaagencia(struct cadastro lista[]);
    int deposito(struct cadastro lista[]);
    int saque(struct cadastro lista[]);
    struct cadastro listacontas[200];
    recebercontas(listacontas);
    int recebercontas(struct cadastro lista[]);
    int printcontas(struct cadastro lista[]);
    int opcao;
    for(i=0;i!=8;)
    {
    system("pause");
    system("cls");

    printf("\t============BANCO IFSP============\n");
    printf("Bem vindo ao Menu! Escolha uma das opcoes abaixo:\n");
    printf("1- Insercao\n");
    printf("2- Impressao\n");
    printf("3- Busca Cliente\n");
    printf("4- Busca Agencia\n");
    printf("5- Deposito\n");
    printf("6- Saque\n");
    printf("7- Sair\n");
    opcao = getch();
    switch(opcao)
    {
    case '1':
        system("cls");
        printf("Nao ha mais espacos para contas serem cadastradas, desculpe! :(\n");
        system("pause");
        system("cls");
        break;
    case '2':
        system("cls");
    printcontas(listacontas);
        break;
    case '3':
    buscacliente(listacontas);
        break;

    case '4':
        buscaagencia(listacontas);
        break;
    case '5':
        deposito(listacontas);
        break;
    case '6':
        saque(listacontas);
        break;
    case'7':
        system("cls");
        printf("\nO sistema sera finalizado!");
        exit (0);
        break;
    }
    }
}

int recebercontas(struct cadastro lista[])
{
    int opcao;
    int i=0;
    for(i=0;i<ncontas;i++)
    {
        system("cls");
        printf("\t====Cadastro de Contas====\n");
        printf("Codigo da Conta: %d\n", lista[i].conta = i+1001);
        printf("Usuario, digite o nome do usuario da Conta %d: ", i+1);
        fflush(stdin);
        gets(lista[i].nomecliente);
        printf("Usuario, escolha uma das agencias para cadastro da Conta:\n");
        printf("1- Agencia 2882\n");
        printf("2- Agencia 2883\n");
        printf("3- Agencia 2884\n");
        printf("4- Agencia 2885\n");
        printf("5- Agencia 2886\n");
        lista[i].nagencia = getch();
        switch(lista[i].nagencia)
        {
        case '1':
            lista[i].nagencia = 2882;
            break;
        case '2':
            system("cls");
            lista[i].nagencia = 2883;
            break;
        case '3':
            lista[i].nagencia = 2884;
            break;
        case '4':
            lista[i].nagencia = 2885;
            break;
        case '5':
            lista[i].nagencia = 2886;
            break;
                    }

        system("cls");
        printf("Codigo da Conta: %d\n", lista[i].conta = i+1001);
        printf("Nome do Cliente: ");
        puts(lista[i].nomecliente);
        printf("Agencia: %d\n", lista[i].nagencia);
        printf("Usuario, escolha o tipo de Cliente a ser cadastrado: \n");
        printf("1- Pessoa Fisica\n");
        printf("2- Pessoa Juridica\n");
        pes [i]= getch();
        switch(pes[i])
        {
        case '1':
            pes[i] = 1;
            break;
        case '2':
            pes[i]= 2;
            break;
        }
            if(pes[i]==1)
            {
                printf("CPF: ");
                scanf("%d", &lista[i].p.cpf);
                lista[i].tipocliente=1;
            }
            else if(pes[i]==2)
            {
                printf("CNPJ: ");
                scanf("%d", &lista[i].p.cnpj);
                lista[i].tipocliente=2;
            }
        system("cls");
        printf("Codigo da Conta: %d\n", lista[i].conta = i+1001);
        printf("Nome do Cliente: ");
        puts(lista[i].nomecliente);
        printf("Agencia: %d\n", lista[i].nagencia);
            if(lista[i].tipocliente == 1)
            {
                printf("Tipo de Cliente: Pessoa Fisica\n");
                printf("CPF: %d\n", lista[i].p.cpf);
            }
            else if(lista[i].tipocliente == 2)
            {
                fflush(stdin);
                printf("Tipo de Cliente: Pessoa Juridica\n");
                printf("CNPJ: %d\n", lista[i].p.cnpj);
            }
        printf("Usuario, insira o saldo da Conta do Cliente: ");
        scanf("%f", &lista[i].saldo);
    }
    system("cls");
    printf("Todas as contas foram cadastradas com sucesso!\n");
}

printcontas(struct cadastro lista[])
{
    printf("\t====Contas Cadastradas====\n");
    for(i=0;i<ncontas;i++)
    {
    printf("Numero da Conta: %d\n", lista[i].conta);
    printf("Numero da Agencia: %d\n", lista[i].nagencia);
    printf("Nome do Cliente: ");
    puts(lista[i].nomecliente);
     if(pes[i]==1)
            {
                printf("Tipo de Pessoa: Fisica\n");
                printf("CPF: %d\n", lista[i].p.cpf);
            }
            else if(pes[i]==2)
                {
                    printf("Tipo de Pessoa: Juridica\n");
                    printf("CPF: %d\n", lista[i].p.cnpj);
                }
    printf("Saldo Bancario: %.2f\n\n", lista[i].saldo);
    }
}

int buscacliente(struct cadastro lista[])
{
    int i;
    int numconta;
    system("cls");
    printf("Usuario, digite o Numero da Conta: ");
    scanf("%d", &numconta);

    for(i=0;i<ncontas;i++)
    {
       if(numconta == lista[i].conta)
       {
            fflush(stdin);
            printf("Contra encontrada!\nDados:\n");
            printf("Numero da Conta: %d\n", lista[i].conta);
            printf("Numero da Agencia: %d\n", lista[i].nagencia);
            printf("Nome do Cliente: ");
            puts(lista[i].nomecliente);

            if(pes[i]==1)
            {
                printf("Tipo de Pessoa: Fisica\n");
                printf("CPF: %d\n", lista[i].p.cpf);
            }
            else if(pes[i]==2)
                {
                    printf("Tipo de Pessoa: Juridica\n");
                    printf("CPF: %d\n", lista[i].p.cnpj);
                }
            printf("Saldo Bancario: %.2f\n\n", lista[i].saldo);
            return 0;
       }
    }
}

int buscaagencia(struct cadastro lista[])
{
    int i;
    int numagencia;
    system("cls");
    printf("Usuario, digite o Numero da Agencia: ");
    scanf("%d", &numagencia);

    for(i=0;i<ncontas;i++)
    {
       if(numagencia == lista[i].nagencia)
       {
            for(i=0;i<ncontas;i++)
            {
            if(lista[i].nomecliente[0] == 'A' || lista[i].nomecliente[0] == 'B' || lista[i].nomecliente[0] == 'C')
            {
            printf("Agencia encontrada!\n");
            printf("Numero da Agencia: %d\n", lista[i].nagencia);
            printf("Numero da Conta: %d\n", lista[i].conta);
            printf("Nome do Cliente: ");
            puts(lista[i].nomecliente);

            if(pes[i]==1)
            {
                printf("Tipo de Pessoa: Fisica\n");
                printf("CPF: %d\n", lista[i].p.cpf);
            }
            else if(pes[i]==2)
                {
                    printf("Tipo de Pessoa: Juridica\n");
                    printf("CPF: %d\n", lista[i].p.cnpj);
                }
            printf("Saldo Bancario: %.2f\n\n", lista[i].saldo);
            }
            }
        }
    }
}

int deposito(struct cadastro lista[])
{
    int i, cc;
    float valor;
    system("cls");
    printf("====Deposito em Conta Corrente====\n");
    printf("Usuario, digite a Conta Corrente: ");
    scanf("%d", &cc);

    for(i=0;i<ncontas;i++)
    {
        if(cc == lista[i].conta)
        {
            printf("Usuario, digite o valor que deseja depositar: ");
            scanf("%f", &valor);
            system("cls");
            printf("Numero da Conta: %d", lista[i].conta);
            printf("\nNome do Cliente: %s",lista[i].nomecliente);
            printf("\nAntigo Saldo: %.2f",lista[i].saldo);
            printf("\nValor do Deposito: %.2f", valor);
            printf("\nSaldo Atual: %.2f\n", lista[i].saldo + valor);
        }
    }
}

int saque(struct cadastro lista[])
{
    int i, cc;
    float valor;
    system("cls");
    printf("====Saque em Conta Corrente====\n");
    printf("Usuario, digite a Conta Corrente: ");
    scanf("%d", &cc);

    for(i=0;i<ncontas;i++)
    {
        if(cc == lista[i].conta)
        {
            printf("Usuario, digite o valor que deseja sacar: ");
            scanf("%f", &valor);
            system("cls");
            printf("Numero da Conta: %d", lista[i].conta);
            printf("\nNome do Cliente: %s",lista[i].nomecliente);
            printf("\nAntigo Saldo: %.2f",lista[i].saldo);
            printf("\nValor do Deposito: %.2f", valor);
            if(valor > lista[i].saldo)
            {
                printf("\nVoce nao tem tudo isso!");
            }
            else
            {
            printf("\nSaldo Atual: %.2f\n", lista[i].saldo - valor);
            }
        }
    }
}

