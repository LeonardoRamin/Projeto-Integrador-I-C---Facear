#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void tela(int * menu){
	fflush(stdin);
	system("cls");
	printf("\n\t\t\t *** SISTEMA DE GESTAO DE APP's ***\n \t\t\t\t    EQUIPE - 11\n \t\t\t\tPROJETO INTEGRADOR 1\n \t\t\t   Digite -2 para obter ajuda\n");
	if(*menu== -2){
		*menu= 1;
		ajuda(&menu);
	}
}
void ajuda(int * opcao){
	*opcao=0;
	int menu=0;
	system("cls");
	printf("\n\t\t\t *** SISTEMA DE GESTAO DE APP's ***\n \t\t\t\t    EQUIPE - 11\n \t\t\t\tPROJETO INTEGRADOR 1\n\n");
	do{
		system("cls");
		printf("\n\t\t\t *** SISTEMA DE GESTAO DE APP's ***\n \t\t\t\t    EQUIPE - 11\n \t\t\t\tPROJETO INTEGRADOR 1\n\n");
		printf(" 1-Ajuda sobre cadastros\n 2-Ajuda sobre exclus\706o\n 3-Ajuda ao pesquisar ou avaliar\n 4-Sair do menu ajuda\n");
		scanf("%i",&menu);
		if(menu==1){
			system("cls");
			printf("\n\t\t\t *** SISTEMA DE GESTAO DE APP's ***\n \t\t\t\t    EQUIPE - 11\n \t\t\t\tPROJETO INTEGRADOR 1\n\n");
			printf(" Para cadastrar um aplicativo, teve-se primeiro ter cadastrado no m\641nimo uma\n categoria, um desenvolvedor e um sistema operacional cadastrado.\n Para confirmar o cadastro digite 1 e d\210 enter.");
			getch();
		}
		else if(menu==2){
			system("cls");
			printf("\n\t\t\t *** SISTEMA DE GESTAO DE APP's ***\n \t\t\t\t    EQUIPE - 11\n \t\t\t\tPROJETO INTEGRADOR 1\n\n");
			printf(" Para excluir um app, uma categoria, um desenvolvedor ou um sistema operacional, digite a ID (n\243mero de cadastro) dele(a) no campo de exclus\706o e d\210 enter da\641 \202  s\242 confirmar.");
			getch();
		}
		else if(menu==3){
			system("cls");
			printf("\n\t\t\t *** SISTEMA DE GESTAO DE APP's ***\n \t\t\t\t    EQUIPE - 11\n \t\t\t\tPROJETO INTEGRADOR 1\n\n");
			printf(" Para pesquisar selecione como voc\210 deseja fazer isso (nome, categoria,\n desenvolvedor, SO).\n Por nome: S\242 digitar a ID do app desejado.\n Por categoria ou desenvolvedor ou sistema operacional: Digite a ID da categoria ou desenvolvedor ou sistema operacional cadastrado, assim aparecer\240 os app's\n cadastrados nessa categoria ou desenvolvedor ou sistema operacional e da\641 \202 s\242\n digitar a ID do app desejado.\n\n");
			printf(" Ap\242s selecionar um app, voc\210 pode avali\240-lo. Para isso pode deixar\n um coment\240rio ou dar uma nota que ir\240 somando, atrav\202s da quantidade de\n estrelas (exemplo: uma estrela=um ponto, duas estrelas=dois pontos, assim no\n final resultar\240 em tr\210s pontos de nota para o app).");
			getch();
		}
		else{
			if(menu!=4){
				system("cls");
				printf("\n\t\t\t *** SISTEMA DE GESTAO DE APP's ***\n \t\t\t\t    EQUIPE - 11\n \t\t\t\tPROJETO INTEGRADOR 1\n\n");
				printf(" Op\207\706o inv\240lida.");
				getch();
			}
			system("cls");
			tela(&menu);
			return;
		}
	}while(menu!=4);
}	
int main(int argc, char *argv[]) {
	struct{
		char app_nome[40];
		char app_categoria[40];
		char app_desenvolvedor[10][40];
		char app_os[10][40];
	    char app_descricao[400];
	    char comentario[100][400];
	    int numeros_comentarios, avaliacao;
	}App[10]={{"Sonic the Hedgehog","Jogos",{"SEGA"},{"Windows Phone"},"Jogo do famoso ouri\207o azul, agora lan\207ado tamb\202m para mobiles",{"Jogo muito bem feito"},1,50},
	{"PAC-MAN","Jogos",{"NAMCO"},{"Android"},"Simples jogo ,mas muito divertido.",{"\0"},0,0}};
	int qntde=10;
	int menu=0, vezes=2, i=0, y=0, x=0, z=0, c=0, categoria_c=1, desenvolvedor_c=2, os_c=2, pergunta=0, quantidade=0, quantidade2=0, igual=0;
	int pontos=0, tamanho=0, achou=0, posicao[10][4]; 
	char app[50], cate[50], desen[50], os_aux[50], aux_descricao[500], aux_comentario[500], aux_geral[40]; 
	char os[10][50]={{"Windows Phone"},{"Android"}}, categoria[10][50]={{"Jogos"}}, desenvolvedor[10][50]={{"SEGA"},{"NAMCO"}}, os2[10][50], desenvolvedor2[10][50];
	char login[10], senha[15];
	i=0;
	y=0;
	do{
		tela(&menu);
		printf(" O que voc\210 deseja fazer?\n\n 1-Entrar como usu\240rio normal\n 2-Entrar como administrador\n 3-Ver a quantidade cadastrada\n 0-Sair\n ");
		scanf("%i",&menu);
		if(menu==1){
			do{
				voltar:
				tela(&menu);
				printf("\n 1-Pesquisar app's\n 2-Voltar\n ");
				scanf("%i",&menu);
				tela(&menu);
				y=0;
				if(menu==1){
					if(vezes==0){
						printf(" Nenhum aplicativo cadastrado! ");
						getch();
					}	
					else{
						printf("Pesquisar por: \n 1-Nome \n 2-Categoria \n 3-Desenvolvedor \n 4-Sistema Operacional\n 5-Voltar\n");
						scanf("%i",&menu);
						tela(&y);
						if(menu==1){
							for(z=0;z<qntde;z++){
								if(App[z].app_nome[0]!='\0'){
									printf(" %i-%s",z,App[z].app_nome);
									printf("\n");
								}
							}
						}
						else if(menu==2){
							for(z=0;z<qntde;z++){
								if(categoria[z][0]!='\0'){
									printf(" %i-%s",z,categoria[z]);
									printf("\n");
								}
							}
							printf("Qual categoria?");
							scanf("%i",&y);
							tela(&y);
							for(z=0;z<qntde;z++){
								if(!(strcmp(categoria[y],App[z].app_categoria))){
									printf(" %i-%s",z,App[z].app_nome);
									printf("\n");
								}
							}
						}
						else if(menu==3){
							for(z=0;z<qntde;z++){
								if(desenvolvedor[z][0]!='\0'){
									printf(" %i-%s",z,desenvolvedor[z]);
									printf("\n");
								}
							}
							printf("Qual desenvolvedor?");
							scanf("%i",&y);
							tela(&y);
							for(z=0;z<qntde;z++){
								if(!(strcmp(desenvolvedor[y],App[z].app_desenvolvedor))){
									printf(" %i-%s",z,App[z].app_nome);
									printf("\n");
								}
							}
						}
						else if(menu==4){
							for(z=0;z<qntde;z++){
								if(os[z][0]!='\0'){
									printf(" %i-%s",z,os[z]);
									printf("\n");
								}
							}
							printf("Qual sistema operacional?");
							scanf("%i",&y);
							tela(&y);
							for(z=0;z<qntde;z++){
								if(!(strcmp(os[y],App[z].app_os))){
									printf(" %i-%s",z,App[z].app_nome);
									printf("\n");
								}
							}
						}
						else{
							if(menu!=5&&menu!= -2){
								printf(" Menu inv\240lido!");
								getch();
							}
							goto voltar;
						}
						printf("Qual aplicativo?");
						scanf("%i",&i);
						y=0;
						if(i== -2){
							ajuda(&i);
						}
						if(App[i].app_nome[0]=='\0'){
							tela(&menu);
							printf("Aplicativo n\706o existe.");
							getch();
							goto voltar;
						}
					}
					do{
						aplicativo:
						tela(&menu);
						printf(" Nome: %s",App[i].app_nome);
						printf("\n Categoria: %s",App[i].app_categoria);
						printf("\n Desenvolvedor(es): ");
						for(y=0;y<qntde;y++){
							if(App[i].app_desenvolvedor[y][0]!='\0'){
								printf("%s. ",App[i].app_desenvolvedor[y]);
							}
						}
						printf("\n Sistemas compativeis: ");
						for(y=0;y<qntde;y++){
							if(App[i].app_os[y][0]!='\0'){
								printf("%s. ",App[i].app_os[y]);
							}
						}
						printf("\n Pontua\207\706o: %i\n Descri\207\706o: %s\n\n\n 1-Ver coment\240rios e/ou comentar[%i] 2-Avaliar 3-Editar (Administrador) 4-Voltar\n",App[i].avaliacao,App[i].app_descricao,App[i].numeros_comentarios);
						scanf("%i",&menu);
						tela(&menu);
						if(menu==1){
							do{
								tela(&menu);
								printf(" 1-Ver coment\240rios\n 2-Deixar coment\240rio\n 3-Voltar\n");
								scanf("%i",&menu);
								tela(&menu);
								if(menu==1){
									if(App[i].numeros_comentarios!=0){
										for(z=0;z<qntde;z++){
											if(App[i].comentario[z][0]!='\0'){
												printf("Coment\240rio %i: %s\n",z+1,App[i].comentario[z]);
											}
										}
										getch();
									}
									else{
										printf("N\706o h\240 coment\240rios!\nDigite -1 para comentar.");
										scanf("%i",&menu);
										if(menu== -1){
											goto deixar_comentario;
										}
									}
								}
								else if(menu==2){
									deixar_comentario:
									tela(&menu);
									printf(" Comentar: ");
									gets(aux_comentario);
									printf(" Tem certeza?\n\n1-OK 2-Cancelar\n");
									scanf("%i",&menu);
									if(menu==1){
										if(aux_comentario[0]!='\0'){
											printf(" \nComent\240rio aceito.");
											strcpy(App[i].comentario[App[i].numeros_comentarios],aux_comentario);
											App[i].numeros_comentarios++;
											system("cls");
										}
										else{
											printf(" \nComent\240rio n\706o aceito.");
										}
										system("cls");
									}
									else{
										if(menu!=2&&menu!= -2){
											printf(" Op\207\706o inv\240lida, o coment\240rio n\706o ser\240 salvo");
											getch();
										}
									}
								}
								else{
									if(menu!=3&&menu!= -2){
										tela(&menu);
										printf(" Menu inv\240lido");
										getch();
									}
								}
							}while(menu!=3);
							menu=0;
						}
						else if(menu==2){
							printf(" 0-Nenhuma estrela (cancelar)\n 1-Uma estrela\n 2-Duas estrelas\n 3-Tr\210s estrelas\n 4-Quatro estrelas\n 5-Cinco estrelas\n");
							scanf("%i",&pontos);
							if((pontos>0)&&(pontos<6)){
								App[i].avaliacao=App[i].avaliacao+pontos;
							}
							else{
								printf("Nada foi avaliado!");
								getch();
							}
							system("cls");
						}
						else if(menu==3){
							tela(&menu);
							printf(" Digite o login: ");
							scanf("%s",login);
							printf(" Digite a senha: ");
							scanf("%s",senha);
							if(!(strcmp(login,"E11"))&&!(strcmp(senha,"App"))){
								do{
									x=0;
									y=0;
									z=0;
									pergunta=0;
									aux_geral[0]='\0';
									tela(&menu);
									printf(" Editar:\n 1-Nome\n 2-Categoria\n 3-Desenvolvedor\n 4-Sistema operacional\n 5-Descri\207\706o\n 6-Voltar");
									scanf("%i",&menu);
									tela(&menu);
									if(menu==1){
										printf(" Nome: %s\n",App[i].app_nome);
										printf(" Novo nome: ");
										gets(aux_geral);
										printf("\n\n 1-Alterar 2-Cancelar");
										scanf("%i",&menu);
										if(menu==1){
											if(aux_geral[0]=='\0'){
												printf("\n\nNome inv\240lido!");
												getch();
											}
											else{
												strcpy(App[i].app_nome,aux_geral);
												printf(" Nome Alterado com sucesso.");
												getch();
											}
										}
										else{
											if(menu!=2&&menu!= -2){
												tela(&menu);
												printf(" Op\207\706o in\240lida");
												getch();
											}
										}
									}
									else if(menu==2){
										edit_cate:
										tela(&y);
										printf(" Categoria: %s\n",App[i].app_categoria);
										for(y=0;y<qntde;y++){
											if(categoria[y][0]!='\0'){
												printf("%i-%s\n",y,categoria[y]);
											}
										}
										printf("Nova categoria: (Digite -1 para cadastrar uma nova!) ");
										scanf("%i",&y);
										if(y== -1){
											goto cadastrar_categoria;
										}
										if(categoria[y][0]=='\0'){
											printf("\n\nCategoria inv\240lida!");
											getch();
											goto edit_cate;
										}
										printf("\n\n 1-Alterar 2-Cancelar");
										scanf("%i",&menu);
										if(menu== -2){
											ajuda(&menu);
										}
										if(menu==1){
											if(aux_geral[0]=='\0'){
												printf("\n\nCategoria inv\240lida!");
												getch();
											}
											else{
												strcpy(App[i].app_categoria,categoria[y]);
												printf(" Categoria Alterada com sucesso.");
												getch();
											}
										}
										else{
											if(menu!=2&&menu!= -2){
												printf("\n\n Op\207\706o inv\240lida, a altera\207\706o n\706o ser\240 realizada.");
												getch();
											}
										}
									}
									else if(menu==3){
										tela(&y);
										printf(" Desenvolvedor(es): ");
										for(z=0;z<qntde;z++){
											if(App[i].app_desenvolvedor[z][0]!='\0'){
												printf("%s. ",App[i].app_desenvolvedor[z]);
											}
										}
										getch();
										qntde_desen_edit:
										tela(&quantidade);
										printf("Adicionar quantos desenvolvedores (Digite n\243meros)? ");
										scanf("%i",&quantidade);
										if(quantidade<1){
											printf("\n\nDigito inv\240lido, por favor digite um n\243mero maior que 0.");
											getch();
											goto qntde_desen_edit;
										}		
										edit_desen:
										tela(&y);
										for(z=0;z<qntde;z++){
											if(desenvolvedor[z][0]!='\0'){
												printf("%i-%s\n",z,desenvolvedor[z]);
											}
										}
										for(pergunta;pergunta<quantidade;pergunta++){
											printf("Qual desenvolvedor? (Digite -1 para cadastrar um novo!) ");
											scanf("%i",&y);
											if(y== -1){
												goto cadastrar_desenvolvedor;
											}
											if(desenvolvedor[y][0]=='\0'){
												printf("\n\nDesenvolvedor inv\240lido!");
												getch();
												goto edit_desen;
											}
											else{
												strcpy(desenvolvedor2[x],desenvolvedor[y]);
												x++;
											}
										}
										printf("\n\n 1-Alterar 2-Cancelar");
										scanf("%i",&menu);
										x=0;
										if(menu== -2){
											ajuda(&menu);
										}
										if(menu==1){
											for(z=0;z<quantidade;z++){
												if(desenvolvedor2[z][0]!='\0'){
													strcpy(App[i].app_desenvolvedor[z],desenvolvedor2[z]);
												}
											}
											printf("\n\nDesenvolvedor(es) alterado(s) com sucesso.");
											getch();
										}
										else{
											if(menu!=2&&menu!= -2){
												printf("\n\n Op\207\706o inv\240lida, a altera\207\706o n\706o ser\240 realizada.");
												getch();
											}
										}
									}
									else if(menu==4){
										tela(&y);
										printf(" Sistema(s) Operacional(is): ");
										for(z=0;z<qntde;z++){
											if(App[i].app_os[z][0]!='\0'){
												printf("%s. ",App[i].app_os[z]);
											}
										}
										getch();
										qntde_os_edit:
										tela(&quantidade);
										printf("Adicionar quantos desenvolvedores (Digite n\243meros)? ");
										scanf("%i",&quantidade);
										if(quantidade<1){
											printf("\n\nDigito inv\240lido, por favor digite um n\243mero maior que 0.");
											getch();
											goto qntde_os_edit;
										}		
										edit_os:
										tela(&y);
										for(z=0;z<qntde;z++){
											if(os[z][0]!='\0'){
												printf("%i-%s\n",z,os[z]);
											}
										}
										for(pergunta;pergunta<quantidade;pergunta++){
											printf("Qual Sistema Operacional? (Digite -1 para cadastrar um novo!) ");
											scanf("%i",&y);
											if(y== -1){
												goto cadastrar_os;
											}
											if(os[y][0]=='\0'){
												printf("\n\nDesenvolvedor inv\240lido!");
												getch();
												goto edit_os;
											}
											else{
												strcpy(os2[x],os[y]);
												x++;
											}
										}
										printf("\n\n 1-Alterar 2-Cancelar");
										scanf("%i",&menu);
										x=0;
										if(menu== -2){
											ajuda(&menu);
										}
										if(menu==1){
											for(z=0;z<quantidade;z++){
												if(os2[z][0]!='\0'){
													strcpy(App[i].app_os[z],os2[z]);
												}
											}
											printf("\n\nSistema(s) Operacional(is) alterado(s) com sucesso.");
											getch();
										}
										else{
											if(menu!=2&&menu!= -2){
												printf("\n\n Op\207\706o inv\240lida, a altera\207\706o n\706o ser\240 realizada.");
												getch();
											}
										}
									}
									else if(menu==5){
										printf(" Descri\207\706o: %s\n",App[i].app_descricao);
										getch();
										//tela(&menu);
										printf(" Nova descri\207\706o: ");
										gets(aux_descricao);
										printf("\n\n 1-Alterar 2-Cancelar");
										scanf("%i",&menu);
										if(menu==1){
											if(aux_descricao[0]=='\0'){
												strcpy(App[i].app_descricao,"N\706o h\240 descri\207\706o para este aplicativo.");
											}
											else{
												strcpy(App[i].app_descricao,aux_descricao);
												printf(" Descri\207\706o Alterada com sucesso.");
												getch();
											}
										}
										else{
											if(menu!=2&&menu!= -2){
												tela(&menu);
												printf(" Op\207\706o in\240lida");
												getch();
											}
										}
									}
									else{
										if(menu!=6&&menu!= -2){
											tela(&menu);
											printf(" Menu inv\240lido");
											getch();
										}
									}
								}while(menu!=6);
							}
							else{
								tela(&menu);
								printf(" Login ou senha inv\240lidos.");
								getch();
								goto aplicativo;
							}
						}
						else{
							if(menu!=4&&menu!= -2){
								printf("Menu inv\240lido");
								system("cls");
							}		
						}	
					}while(menu!=4);
				}
				else{
					if(menu!=2){
						printf(" Menu inv\240lido! ");
						getch();
						system("cls");
					}
				}
			}while(menu!=2);
		}//Aqui!
		else if(menu==2){
			tela(&menu);
			printf(" Digite o login: ");
			scanf("%s",login);
			printf(" Digite a senha: ");
			scanf("%s",senha);
			if(!(strcmp(login,"E11"))&&!(strcmp(senha,"App"))){	
				do{
					aux_geral[0]='\0';
					tela(&menu);
					printf(" Seja bem vindo(a)!\n\n 1-Cadastrar app\n 2-Cadastrar categoria\n 3-Cadastrar desenvolvedor\n 4-Cadastrar sistema operacional\n");
					printf(" 5-Excluir app\n 6-Excluir categoria\n 7-Excluir desenvolvedor\n 8-Excluir sistema operacional\n 9-Voltar\n ");
            		scanf("%i",&menu);
            		fflush(stdin);
            		i=0;
            		achou=0;
            		tela(&menu);
            		if(menu==1){
            			cadastrar_nome_app:
            			tela(&menu);
						if((categoria_c!=0)&&(desenvolvedor_c!=0)&&(os_c!=0)){
							printf("Nome do seu app: ");
							gets(app);
							if(app[0]=='\0'){
								printf("\n\nNome inv\240lido!");
								getch();
								goto cadastrar_nome_app;
							}
							select_cate:
							tela(&i);
							for(i=0;i<qntde;i++){
								if(categoria[i][0]!='\0'){
									printf("%i-%s\n",i,categoria[i]);
								}
							}
							printf("Qual categoria? (Digite -1 para cadastrar uma nova!) ");
							scanf("%i",&i);
							x=i;
							if(x== -1){
								goto cadastrar_categoria;
							}
							if(categoria[i][0]=='\0'){
								printf("\n\nCategoria inv\240lida!");
								getch();
								goto select_cate;
							}
							strcpy(cate,categoria[i]);
							qntde_desen:
							tela(&i);
							printf("Quantos desenvolvedores o app ter\240 (digite numeros)? ");
							scanf("%i",&quantidade);
							if(quantidade== -2){
								ajuda(&quantidade);
							}
							if(quantidade<1){
								printf("\n\nDigito inv\240lido, por favor digite um n\243mero maior que 0.");
								getch();
								goto qntde_desen;
							}
							select_desen:
							tela(&i);
							for(i=0;i<qntde;i++){
								if(desenvolvedor[i][0]!='\0'){
									printf("%i-%s\n",i,desenvolvedor[i]);
								}
							}
							for(pergunta;pergunta<quantidade;pergunta++){
								printf("Qual desenvolvedor? (Digite -1 para cadastrar um novo!) ");
								scanf("%i",&i);
								x=i;
								if(x== -1){
									goto cadastrar_desenvolvedor;
								}
								if(desenvolvedor[i][0]=='\0'){
									printf("\n\nDesenvolvedor inv\240lido!");
									getch();
									goto select_desen;
								}
								else{
									strcpy(desenvolvedor2[y],desenvolvedor[i]);
									y++;
								}
							}
							pergunta=0;
							y=0;
							fflush(stdin);
							qntde_os:
							tela(&menu);
							printf("Em quantos sistemas o app vai ser compat\641vel (digite numeros)? ");
							scanf("%i",&quantidade2);
							if(quantidade2== -2){
								ajuda(&quantidade2);
							}
							if(quantidade2<1){
								printf("\n\nDigito inv\240lido, por favor digite um n\243mero maior que 0.");
								getch();
								goto qntde_os;
							}
							select_os:
							tela(&i);
							for(i=0;i<qntde;i++){
								if(os[i][0]!='\0'){
									printf("%i-%s\n",i,os[i]);
								}
							}
							for(pergunta;pergunta<quantidade2;pergunta++){
								printf("Qual sistema? (Digite -1 para cadastrar um novo!) ");
								scanf("%i",&i);
								x=i;
								if(x== -1){
									goto cadastrar_os;
								}
								if(os[i][0]=='\0'){
									printf("\n\nSistema operacional inv\240lido!");
									getch();
									goto select_os;
								}
								else{
									strcpy(os2[y],os[i]);
									y++;
								}
							}
							pergunta=0;
							y=0;
							tela(&menu);
							printf("Coloque uma descri\207\706o: ");
							gets(aux_descricao);
							if(aux_descricao[0]=='\0'){
								strcpy(aux_descricao,"N\706o h\240 descri\207\706o para este aplicativo.");
							}
							printf("Tem certeza?\n\n1-OK 2-Cancelar\n");
							scanf("%i",&menu);
							if(menu==1){
								for(z=0;z<qntde;z++){
									if(App[z].app_nome[0]=='\0'){
										if(aux_descricao[0]!='\0'){
											strcpy(App[z].app_descricao,aux_descricao);
										}
										strcpy(App[z].app_nome, app);
										strcpy(App[z].app_categoria, cate);
										for(i=0;i<quantidade;i++){
											if(desenvolvedor2[i][0]!='\0'){
												strcpy(App[z].app_desenvolvedor[y],desenvolvedor2[i]);
												y++;
											}
										}
										y=0;
										for(i=0;i<quantidade2;i++){
											if(os2[i][0]!='\0'){
												strcpy(App[z].app_os[y],os2[i]);
												y++;
											}
										}	
										y=0;
										for(i=0;i<qntde;i++){
											desenvolvedor2[i][0]='\0';
											os2[i][0]='\0';
										}
										vezes++;
										system("cls");
										break;
									}
								}
							}
							else if(menu==2||menu== -2){
								system("cls");
							}
							else{
								printf("\nOp\207\706o inv\240lida, ser\240 cancelado o cadastro!");
								getch();
								system("cls");
								break;
							}
						}
						else{
							printf(" N\706o existem categoria, desenvolvedor ou sistema operacional cadastrado!");
							getch();
							system("cls");
						}
					}
            		else if(menu==2){
            			cadastrar_categoria:
            			tela(&menu);
						for(c=0;c<qntde;c++){
							if(categoria[c][0]=='\0'){
    							tela(&menu);
        						printf("Nome da categoria:");
        						gets(aux_geral);
        						if(aux_geral[0]=='\0'){
        							printf("\n\nDigite um nome v\240lido!");
        							getch();
        							goto cadastrar_categoria;
        						}
        						printf("\n\n\n1-OK\t2-Cancelar\n");
        						scanf("%i",&menu);
        						if(menu==1){
        							for(z=0;z<qntde;z++){
           								if(!(strcmp(aux_geral,categoria[z]))){
           									igual=1;
           									break;
           								}
           							}	
           							if(igual==0){
           								strcpy(categoria[c],aux_geral);
           								categoria_c++;
           								printf("%i-%s\nCategoria cadastrada!",c,categoria[c]);
           								getch();
           			       				system("cls");
           							}
	           						else if(igual==1){
    		       						igual=0;
           								printf("Categoria j\240 existe.");
           								getch();
           								system("cls");
        		   					}
        		   				}
        						else if(menu==2||menu== -2){
           							system("cls");
           						}
           						else{
           							printf("\nOp\207\706o inv\240lida, ser\240 cancelado o cadastro!");
           							getch();
           							system("cls");
           						}
           						if(x==-1){
									x=0;
									goto select_cate;
								}
								if(y== -1){
									y=0;
									goto edit_cate;
								}
								break;
							}
						}
					}
            		else if(menu==3){
            			cadastrar_desenvolvedor:
            			for(c=0;c<10;c++){
            				tela(&menu);
            				if(desenvolvedor[c][0]=='\0'){
            					printf("Nome do desenvolvedor:");
           						gets(aux_geral);
           						if(aux_geral[0]=='\0'){
        							printf("\n\nDigite um nome v\240lido!");
        							getch();
        							goto cadastrar_desenvolvedor;
        						}
           						printf("\n\n\n1-OK\t2-Cancelar\n");
           						scanf("%i",&menu);
           						if(menu==1){
           							for(z=0;z<qntde;z++){
           								if(!(strcmp(aux_geral,desenvolvedor[z]))){
           									igual=1;
           									break;
           								}
           							}
           							if(igual==0){
           								strcpy(desenvolvedor[c],aux_geral);
           								desenvolvedor_c++;
           								printf("%i-%s\nDesenvolvedor cadastrado!",c,desenvolvedor[c]);
           								getch();
           								system("cls");
           							}
           							else if(igual==1){
           								igual=0;
           								printf("Desenvolvedor j\240 existe.");
           								getch();
           								system("cls");
           							}
           						}
           						else if(menu==2||menu== -2){
           							system("cls");
           						}
           						else{
           							printf("\nOp\207\706o inv\240lida, ser\240 cancelado o cadastro!");
           							getch();
           							system("cls");
           						}
           						if(x==-1){
									x=0;
									goto select_desen;
								}
								if(y== -1){
									y=0;
									goto edit_desen;
								}
								break;
            				}
            			}
            		}
            		else if(menu==4){
            			cadastrar_os:
            			for(c=0;c<10;c++){
            				if(os[c][0]=='\0'){
            					tela(&menu);
            					printf("Nome do sistema operacional:");
           						gets(aux_geral);
           						if(aux_geral[0]=='\0'){
        							printf("\n\nDigite um nome v\240lido!");
        							getch();
        							goto cadastrar_os;
        						}
           						printf("\n\n\n1-OK\t2-Cancelar\n");
           						scanf("%i",&menu);
           						if(menu==1){
           							for(z=0;z<qntde;z++){
           								if(!(strcmp(aux_geral,os[z]))){
           									igual=1;
           									break;
           								}
           							}
           							if(igual==0){
           								strcpy(os[c],aux_geral);
           								os_c++;
           								printf("%i-%s\nSistema operacional cadastrado!",c,os[c]);
           								getch();
           								system("cls");
           							}
           							else if(igual==1){
           								igual=0;
           								printf("Sistema operacional j\240 existe.");
           								getch();
           								system("cls");
           							}
           						}
           						else if(menu==2||menu== -2){
           							system("cls");
           						}
           						else{
           							printf("\nOp\207\706o inv\240lida, ser\240 cancelado o cadastro!");
           							getch();
           							system("cls");
           						}
           						if(x==-1){
									x=0;
									goto select_os;
								}
								if(y== -1){
									y=0;
									goto edit_os;
								}
								break;
            				}
						}
		     		}	
		     		else if(menu==5){
		     			dlt_app:
		     			tela(&menu);
		     			for(z=0;z<qntde;z++){
		     				if(App[z].app_nome[0]!='\0'){
		     					printf("%i-%s/",z,App[z].app_nome);
		     					for(y=0;y<42;y++){
		     						printf("%c",App[z].app_descricao[y]);
		     					}
		     					printf("\n");
		     					achou=1;
		     				}
		     			}
		     			if(achou!=1){
		     				printf("Nenhum app cadastrado");
		     				getch();
		     			}
		     			else{
		     				printf("Qual app voc\210 deseja excluir?");
		     				scanf("%i",&z);
		     				if(App[z].app_nome[0]=='\0'){
		     					printf("\n\nApp n\706o existe.");
		     					getch();
		     					goto dlt_app;
		     				}
		     				else{
		     					tela(&menu);
		     					printf("Tem certeza?\n\n1-OK 2-Cancelar");
		     					scanf("%i",&menu);
		     					if(menu==1){
		     						App[z].app_nome[0]='\0';
		     						App[z].app_categoria[0]='\0';
		     						App[z].app_descricao[0]='\0';
		     						App[z].numeros_comentarios=0;
		     						App[z].avaliacao=0;
		     						for(y=0;y<qntde;y++){
		     							App[z].comentario[y][0]='\0';
		     							App[z].app_os[y][0]='\0';
		     							App[z].app_desenvolvedor[y][0]='\0';
		     						}
		     						y=0;
		     						vezes--;
		     						printf("Exclus\706o foi realizada com \210xito!");
		     						getch();
		     					}
		     					else{
		     						if(menu!=2&&menu!= -2){
		     							printf("Op\207\706o inv\240lida");
		     							getch();
		     						}
		     					}
		     				}
		     			}
		     			system("cls");
		     		}
		     		else if(menu==6){
		     			dlt_cate:
		     				tela(&i);
		     			for(i=0;i<qntde;i++){
		     				if(categoria[i][0]!='\0'){
		     					printf("%i-%s\n",i,categoria[i]);
		     					achou=1;
		     				}
		     			}
		     			if(achou!=1){
		     				printf("Nenhuma categoria cadastrada");
		     				getch();
		     			}
		     			else{
		     				printf("Qual categoria voc\210 deseja excluir?");
		     				scanf("%i",&i);
		     				if(categoria[i][0]=='\0'){
		     					printf("\n\nCategoria n\706o existe.");
		     					getch();
		     					goto dlt_cate;
		     				}
		     				tela(&menu);
		     				printf("Tem certeza?\n\n1-OK 2-Cancelar");
		     				scanf("%i",&menu);
		     				if(menu==1){
		     					categoria[i][0]='\0';
		     					categoria_c--;
		     					printf("Exclus\706o foi realizada com \210xito!");
		     					getch();
		     				}
		     				else{
		     					if(menu!=2&&menu!= -2){
		     						printf("Op\207\706o inv\240lida");
		     						getch();
		     					}
		     				}
		     			}
		     			system("cls");
		     		}
		     		else if(menu==7){
		     			dlt_desen:
		     			tela(&i);
		     			for(i=0;i<qntde;i++){
		     				if(desenvolvedor[i][0]!='\0'){
		     					printf("%i-%s\n",i,desenvolvedor[i]);
		     					achou=1;
		     				}
		     			}
		     			if(achou!=1){
		     				printf("Nenhum desenvolvedor cadastrado");
		     				getch();
		     			}
		     			else{
		     				printf("Qual desenvolvedor voc\210 deseja excluir?");
		     				scanf("%i",&i);
		     				if(desenvolvedor[i][0]=='\0'){
		     					printf("\n\nDesenvolvedor n\706o existe.");
		     					getch();
		     					goto dlt_desen;
		     				}
		     				tela(&menu);
		     				printf("Tem certeza?\n\n1-OK 2-Cancelar");
		     				scanf("%i",&menu);
		     				if(menu==1){
		     					desenvolvedor[i][0]='\0';
		     					desenvolvedor_c--;
		     					printf("Exclus\706o foi realizada com \210xito!");
		     					getch();
		     				}
		     				else{
		     					if(menu!=2&&menu!= -2){
		     						printf("Op\207\706o inv\240lida");
		     						getch();
		     					}
		     				}
		     			}
		     			system("cls");
		     		}
		     		else if(menu==8){
		     			dlt_os:
		     			tela(&i);
		     			for(i=0;i<qntde;i++){
		     				if(os[i][0]!='\0'){
		     					printf("%i-%s\n",i,os[i]);
		     					achou=1;
		     				}
		     			}
		     			if(achou!=1){
		     				printf("Nenhum sistema operacional cadastrado");
		     				getch();
		     			}
		     			else{
		     				printf("Qual sistema operacional voc\210 deseja excluir?");
		     				scanf("%i",&i);
		     				if(os[i][0]=='\0'){
		     					printf("\n\nSistema operacional n\706o existe.");
		     					getch();
		     					goto dlt_os;
		     				}
		     				tela(&menu);
		     				printf("Tem certeza?\n\n1-OK 2-Cancelar");
		     				scanf("%i",&menu);
		     				if(menu==1){
		     					os[i][0]='\0';
		     					os_c--;
		     					printf("Exclus\706o foi realizada com \210xito!");
		     					getch();
		     				}
		     				else{
		     					if(menu!=2&&menu!= -2){
		     						printf("Op\207\706o inv\240lida");
		     						getch();
		     					}
		     				}
		     			}
		     			system("cls");
		     		}
            		else{
            			if(menu!=9&&menu!= -2){
							tela(&menu);
							printf(" Menu inv\240lido!");
							getch();
							system("cls");
						}
            		}
            	}while(menu!=9);
        	}
        	else{
				tela(&menu);
				printf(" Usu\240rio inv\240lido!");
				getch();
				system("cls");     
				
            }
		}                     
		else if(menu==3){
			do{
				tela(&menu);
				printf(" S\706o %i app's cadastado(s), %i categoria(s), %i desenvolvedor(es)\n\t\t e %i sistema(s) operacional(is).",vezes,categoria_c,desenvolvedor_c,os_c);
				printf("\n 1-Ver app's\n 2-Ver categorias\n 3-Ver desenvolvedores\n 4-Ver sistemas operacionais\n 5-Voltar\n");
				scanf("%i",&menu);
				tela(&menu);
				if(menu==1){
					for(z=0;z<qntde;z++){
						if(App[z].app_nome[0]!='\0'){
							printf(" %i-%s",z,App[z].app_nome);
							printf("\n");
						}
					}
				}
				else if(menu==2){
					for(z=0;z<qntde;z++){
						if(categoria[z][0]!='\0'){
							printf(" %i-%s",z,categoria[z]);
							printf("\n");
						}
					}
				}
				else if(menu==3){
					for(z=0;z<qntde;z++){
						if(desenvolvedor[z][0]!='\0'){
							printf(" %i-%s",z,desenvolvedor[z]);
							printf("\n");
						}
					}
				}
				else if(menu==4){
					for(z=0;z<qntde;z++){
						if(os[z][0]!='\0'){
							printf(" %i-%s",z,os[z]);
							printf("\n");
						}
					}
				}
				else{
					if(menu!=5&&menu!= -2){
						printf(" Menu inv\240lido!");
					}
				}
				if(menu!=5&&menu!= -2){
					getch();
				}
			}while(menu!=5);
			
		}
		else{
			if(menu!=0&&menu!= -2){
				tela(&menu);
				printf(" Menu inv\240lido!");
				getch();
				system("cls");
			}
		}
	}while(menu!=0);
	
	return 0;
}              
