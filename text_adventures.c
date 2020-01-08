#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define longPosiciones 4 //estas son izquierda, derecha, adelante, atras
#define longHabitaciones 6 //serán 6 puntos de partida en el mapa
#define longLugares 6 //serán 6 lugares

char mapa[longLugares+1][longHabitaciones+1][25];
char posiciones[longPosiciones][10] = {"izquierda", "derecha", "adelante", "atras"};
int habitaciones[longHabitaciones] = {0,1,2,3,4,5};

char lugares[longLugares][25] = {"inicio", "aldea", "casa", "montanas", "castillo", "escaleras"};

void registrarHeroe();
void imprimirGraficos(int grafico);
void generarMapa();
void entrarHabitacion(int lugar, int habitacion);
void batalla(int hp_heroe, int enemigo);
void imprimirMapa();
void moverse(char resultado[25]);
void jugar();

char nombre_heroe[15]="Heroe";
int hp_heroe;
int espada;
int escudo;
int espada_especial;

int hp_dragon = 90;
int hp_criatura = 1;

int habitacion;
int lugar;

int end;

void registrarHeroe(){
	printf("¿Cual es tu nombre, nuevo heroe? :\n");
	scanf("%s",nombre_heroe);
	hp_heroe = 100;
	espada = 0;
	escudo = 0;
	espada_especial = 0;

}

void instrucciones(){
	printf("1. Las instrucciones para avanzar seran: adelante \n atras \n izquierda \n derecha\n");
	printf("2. Los objetos encontrados en los cofres se guardaran en tu inventario\n");
	printf("3. Tendrás solo 100 puntos de HP al iniciar el juego, cuidalos bien!\n");
	printf("4. Las puertas se abren solo escribirndo: adelante\n");
	printf("5. Podrás enfrentarte a los jefes en batallas.\n");
	printf("   Estas batallas seran aleatorias, pero si tienes objetos utiles en tu inventario\n");
	printf("   eso te beneficiara!\n\n\n");
	printf("   ¡Estas listo para iniciar a jugar! \n\n\n");
}

void batalla(int hp_heroe, int enemigo){
	//el usuario tiene turno 1 y 0 enemigo
	int turno = 1;

	int rango_ataque_enemigo;
	int rango_ataque_heroe = 3+espada+espada_especial;
	int heroe_ataque = 0;
	int enemigo_ataque = 0;

	//enemigo 0 es criatura y enemigo 1 es dragon
	int hp_enemigo;

	if (enemigo == 0){
		hp_enemigo = hp_criatura;
		rango_ataque_enemigo = 7-escudo;
	}else{
		hp_enemigo = hp_dragon;
		rango_ataque_enemigo = 15-escudo;
	}

	sleep(1);

	printf(" __| |____________________________________________| |__\n");
	printf("(__   ____________________________________________   __)\n");
	printf("   | | TU                                 ENEMIGO | |\n");
	printf("   | | HP: %i                               HP: %i| |\n", hp_heroe, hp_enemigo);
	printf("   | |                                            | |\n");
	printf("   | |                                            | |\n");
	printf("   | |        	  ¡INICIEMOS LA BATALLA!          | |\n");
	printf("   | |                                            | |\n");
	printf("   | |                                            | |\n");
	printf("   | |                                            | |\n");
	printf(" __| |____________________________________________| |__\n");
	printf("(__   ____________________________________________   __)\n");
	printf("   | |                                            | |\n");

	do{
		if (turno==1){
			printf(" __| |____________________________________________| |__\n");
			printf("(__   ____________________________________________   __)\n");
			printf("   | | TU                                 ENEMIGO | |\n");
			printf("   | | HP: %i                             HP: %i  | |\n", hp_heroe, hp_enemigo);
			printf("   | |                                            | |\n");
			printf("   | |                                            | |\n");
			printf("   | |                TU TURNO                    | |\n");
			printf("   | |                                            | |\n");
			printf("   | |                                            | |\n");
			printf("   | |                                            | |\n");
			printf(" __| |____________________________________________| |__\n");
			printf("(__   ____________________________________________   __)\n");
			printf("   | |                                            | |\n");
			sleep(1);
			heroe_ataque = rand() % rango_ataque_heroe;
			hp_enemigo = hp_enemigo-heroe_ataque;
			printf(" __| |____________________________________________| |__\n");
			printf("(__   ____________________________________________   __)\n");
			printf("   | | TU                                 ENEMIGO | |\n");
			printf("   | | HP: %i                             HP: %i  | |\n", hp_heroe, hp_enemigo);
			printf("   | |                                            | |\n");
			printf("   | |                                            | |\n");
			printf("   | |        HAZ CAUSADO %i DE DAÑO!             | |\n", heroe_ataque);
			printf("   | |                                            | |\n");
			printf("   | |                                            | |\n");
			printf("   | |                                            | |\n");
			printf(" __| |____________________________________________| |__\n");
			printf("(__   ____________________________________________   __)\n");
			printf("   | |                                            | |\n");
			turno=0;
			sleep(3);
		}else{
			if (turno==0){
				printf(" __| |____________________________________________| |__\n");
				printf("(__   ____________________________________________   __)\n");
				printf("   | | TU                                 ENEMIGO | |\n");
				printf("   | | HP: %i                               HP: %i| |\n", hp_heroe, hp_enemigo);
				printf("   | |                                            | |\n");
				printf("   | |                                            | |\n");
				printf("   | |        	  TURNO DE TU ENEMIGO             | |\n");
				printf("   | |                                            | |\n");
				printf("   | |                                            | |\n");
				printf("   | |                                            | |\n");
				printf(" __| |____________________________________________| |__\n");
				printf("(__   ____________________________________________   __)\n");
				printf("   | |                                            | |\n");
				sleep(1);
				enemigo_ataque = rand() % rango_ataque_enemigo;
				hp_heroe = hp_heroe-enemigo_ataque;
				printf("Tu enemigo ha causado un ataque de %i!!! \n", enemigo_ataque);
				printf(" __| |____________________________________________| |__\n");
				printf("(__   ____________________________________________   __)\n");
				printf("   | | TU                                 ENEMIGO | |\n");
				printf("   | | HP: %i                               HP: %i| |\n", hp_heroe, hp_enemigo);
				printf("   | |                                            | |\n");
				printf("   | |                                            | |\n");
				printf("   | |         TU ENEMIGO HA CAUSADO %i DAÑO!     | |\n", enemigo_ataque);
				printf("   | |                                            | |\n");
				printf("   | |                                            | |\n");
				printf("   | |                                            | |\n");
				printf(" __| |____________________________________________| |__\n");
				printf("(__   ____________________________________________   __)\n");
				printf("   | |                                            | |\n");
				sleep(3);
				turno = 1;
			}
		}
	}while(hp_heroe>0 && hp_enemigo>0);

	if (hp_heroe <=0){
		printf(" __| |____________________________________________| |__\n");
		printf("(__   ____________________________________________   __)\n");
		printf("   | |                                            | |\n");
		printf("   | |               HAZ MUERTO                   | |\n");
		printf("   | |                                            | |\n");
		printf(" __| |____________________________________________| |__\n");
		printf("(__   ____________________________________________   __)\n");
		printf("   | |                                            | |\n");
		end=1;
	}else{
		if (hp_enemigo <= 0){
			printf(" __| |____________________________________________| |__\n");
			printf("(__   ____________________________________________   __)\n");
			printf("   | |                                            | |\n");
			printf("   | |      ¡¡¡ HAZ GANADO LA BATALLA !!!         | |\n");
			printf("   | |                                            | |\n");
			printf(" __| |____________________________________________| |__\n");
			printf("(__   ____________________________________________   __)\n");
			printf("   | |                                            | |\n");
		}
	}
}

void generarMapa(){
	//inicio
	strcpy(mapa[0][0],"gnomo");
	strcpy(mapa[0][1],"paisaje");
	strcpy(mapa[0][2],"aldea");
	strcpy(mapa[0][3],"no");

	//aldea
	strcpy(mapa[1][0],"campesino");
	strcpy(mapa[1][1],"casa");
	strcpy(mapa[1][2],"montanas");
	strcpy(mapa[1][3],"inicio");

	//casa
	strcpy(mapa[2][0],"aldea");
	strcpy(mapa[2][1],"cocina");
	strcpy(mapa[2][2],"recamara");
	strcpy(mapa[2][3],"cofre espada");

	//montañas
	strcpy(mapa[3][0],"criatura");
	strcpy(mapa[3][1],"paisaje");
	strcpy(mapa[3][2],"castillo");
	strcpy(mapa[3][3],"aldea");

	//castillo
	strcpy(mapa[4][0],"cofre escudo");
	strcpy(mapa[4][1],"escaleras");
	strcpy(mapa[4][2],"no");
	strcpy(mapa[4][3],"montanas");

	//escaleras
	strcpy(mapa[5][0],"castillo");
	strcpy(mapa[5][1],"no");
	strcpy(mapa[5][2],"dragon");
	strcpy(mapa[5][3],"no");
}

void entrarHabitacion(int lugar, int habitacion){

	char texto[25];
	char resultado[25];

	printf("Te encuentras en %s \n", lugares[lugar]);
	printf("En que direccion quieres ir? \n");
	scanf("%s", texto);

	if (strcmp(texto, "izquierda") == 0){
		habitacion=0;
	}

	if (strcmp(texto, "derecha") == 0){
		habitacion=1;
	}

	if (strcmp(texto, "adelante") == 0){
		habitacion=2;
	}

	if (strcmp(texto, "atras") == 0){
		habitacion=3;
	}

	strcpy(resultado,mapa[lugar][habitacion]);
	moverse(resultado);
}




void imprimirGraficos (int grafico){
	switch (grafico)
	{
	case 1: //inicio
		printf("        _    .  ,   .           .\n");
		printf("    *  / \\_ *  / \\_         *        *   /\\'__        *\n");
		printf("      /    \\  /    \\,             .    _/  /  \\  *'.\n");
		printf(" .   /\\/\\  /\\/ :' __ \\_             _^/  ^/    `--.\n");
		printf("    /    \\/  \\  _/  \\-'\\      *    /.' ^_   \\_   .'\\  *\n");
		printf("  /\\  .-   `. \\/     \\ /==~=-=~=-=-;.  _/ \\ -. `_/   \\n");
		printf(" /  `-.__ ^   / .-'.--\\ =-=~_=-=~=^/  _ `--./ .-'  `-\n");
		printf("/      `.  / /       `.~-^=-=~=^=.-'      '-._ `._\n");
		break;

	case 2: //aldea
		printf("  ~         ~~          __\n");
		printf("       _T      .,,.    ~--~ ^^\n");
		printf(" ^^   // \\                    ~\n");
		printf("      ][O]    ^^      ,-~ ~\n");
		printf("   /''-I_I         _II____\n");
		printf("__/_  /   \\ ______/ ''   /'\\_\n");
		printf("  | II--'''' \\,--:--..,_/,.-{ },\n");
		printf("; '/__\\,.--';|   |[] .-.| O{ _ }\n");
		printf(":' |  | []  -|   ''--:.;[,.'\\,/\n");
		printf("'  |[]|,.--'' '',   ''-,.    |\n");
		printf("  ..    ..-''    ;       ''. '\n");
		
		break;
	case 3://casa
		printf("      _-'_'-_\n");
		printf("   _-' _____ '-_\n");
		printf("_-' ___________ '-_\n");
		printf(" |___|||||||||___|\n");
		printf(" |___|||||||||___|\n");
		printf(" |___|||||||o|___|\n");
		printf(" |___|||||||||___|\n");
		printf(" |___|||||||||___|\n");
		printf(" |___|||||||||___|\n");
		break;
	case 4://montanas
		printf("                 ___                          (_)\n");
		printf("               _/XXX\\\n");
		printf("_             /XXXXXX\\_                                    __\n");
		printf("X\\__    __   /X XXXX XX\\                          _       /XX\\__      ___\n");
		printf("    \\__/  \\_/__       \\ \\                       _/X\\__   /XX XXX\\____/XXX\\\n");
		printf("  \\  ___   \\/  \\_      \\ \\               __   _/      \\_/  _/  -   __  -  \\__/\n");
		printf(" ___/   \\__/   \\ \\__     \\__           /  \\_//  _ _ \\  \\     __  /  \\____//\n");
		printf("/  __    \\  /     \\ \\_   _//_\\___     _/    //           \\___/  \\/     __/\n");
		printf("__/_______\\________\\__\\_/________\\_ _/_____/_____________/_______\\____/_______\n");
		printf("                                  /|\\\n");
		printf("                                 / | \\\n");
		printf("                                /  |  \\\n");
		printf("                               /   |   \\\n");
		
		break;
	case 5://castillo
		printf("                    |>>>                        |>>>\n");
		printf("                    |                           |\n");
		printf("                _  _|_  _                   _  _|_  _\n");
		printf("               | |_| |_| |                 | |_| |_| |\n");
		printf("               \\  .      /                 \\ .    .  /\n");
		printf("                \\    ,  /                   \\    .  /\n");
		printf("                 | .   |_   _   _   _   _   _| ,   |\n");
		printf("                 |    .| |_| |_| |_| |_| |_| |  .  |\n");
		printf("                 | ,   | .    .     .      . |    .|\n");
		printf("                 |   . |  .     . .   .  ,   |.    |\n");
		printf("     ___----_____| .   |.   ,  _______   .   |   , |---~_____\n");
		printf("_---~            |     |  .   /+++++++\\    . | .   |         ~---_\n");
		printf("                 |.    | .    |+++++++| .    |   . |              ~-_\n");
		printf("              __ |   . |   ,  |+++++++|.  . _|__   |                 ~-_\n");
		printf("     ____--`~    '--~~__ .    |++++ __|----~    ~`---,              ___^~-__\n");
		printf("-~--~                   ~---__|,--~'                  ~~----_____-~'   `~----~\n");
		break;
	case 6: //dragon
		printf("        ,     \\    /      ,        \n");
		printf("       / \\    )\\__/(     / \\       \n");
		printf("      /   \\  (_\\  /_)   /   \\      \n");
		printf(" ____/_____\\__\\@  @/___/_____\\____ \n");
		printf("|             |\\../|              |\n");
		printf("|              \\VV/               |\n");
		printf("|        ----------------         |\n");
		printf("|_________________________________|\n");
		printf(" |    /\\ /      \\       \\ /\\    | \n");
		printf(" |  /   V        ))       V   \\  | \n");
		printf(" |/     `       //        '     \\| \n");
		printf(" `              V                '\n");
		break;
	case 7: //espada especial
		printf("      /| ________________\n");
		printf("O|===|* >________________>\n");
		printf("      \\|\n");
		break;
	default:
		break;
	}
}

void moverse(char resultado[25]){

	if (strcmp(resultado, "no") == 0){
		if (lugar == 0){
			printf(" ¡¡¡¡¡ ESPADA ESPECIAL !!!!\n\n");
			printf("Te has encontrado un cofre especial! Y tiene una espada instantanea\n\n");
			printf("Ha sido agregada a tu inventario");
			espada_especial = 20;
			printf("\n\n");
			imprimirGraficos(7);
			printf("\n\n");
		}else{
			printf("Aqui no hay nada...\n\n");
		}
	}else{
		if (strcmp(resultado, "paisaje") == 0){
			printf("¡Que paisaje tan bonito!\n\n\n");
			imprimirGraficos(1);
			printf("\n\n\n");
		}else{
			if (strcmp(resultado, "gnomo") == 0){
				printf("Hola! Soy un gnomo, creo que por aqui he visto un moustro, ten cuidado\n\n");
			}else{
				if (strcmp(resultado, "campesino") == 0){
					printf("Hola! Soy un campesino, que tenga un buen dia\n\n");
				}else{
					if (strcmp(resultado, "recamara") == 0){
						printf("Aqui hay una bonita recamara.\n\n");
					}else{
						if (strcmp(resultado, "cocina") == 0){
							printf("Has llegado a la cocina y huele a hotcakes!\n\n");
						}else{
							if (strcmp(resultado, "cofre escudo") == 0){
								printf("Te has encontrado un cofre! Y tiene un escudo\n\n");
								printf("Ha sido agregado a tu inventario");
								escudo = 1;
								}else{
									if (strcmp(resultado, "cofre espada") == 0){
										printf("Te has encontrado un cofre! Y tiene una espada\n\n");
										printf("Ha sido agregada a tu inventario");
										espada = 5;
									}else{
										if (strcmp(resultado, "criatura") == 0){
											printf("Aqui hay una criatura extraña\n\n");
											char decision[2];
											printf("Deseas enfrentarlo? (Si/No)\n");
											scanf("%s", decision);
											if (strcmp(decision, "Si") == 0){
												batalla(hp_heroe, 0);
											}else{
												printf("Haz huido\n\n\n");
											}
										}else{
											if (strcmp(resultado, "inicio") == 0){
												printf("Has vuelto al inicio del juego\n\n");
												printf("\n\n\n");
												lugar = 0;
											}else{
												if (strcmp(resultado, "aldea") == 0){
													printf("Te encuentras en la aldea\n\n");
													imprimirGraficos(2);
													printf("\n\n\n");
													lugar = 1;
												}else{
													if (strcmp(resultado, "casa") == 0){
													printf("Te encuentras en la casa\n\n");
													imprimirGraficos(3);
													printf("\n\n\n");
													lugar = 2;
													}else{
														if (strcmp(resultado, "montanas") == 0){
														printf("Te encuentras en las montanas\n\n");
														imprimirGraficos(4);
														printf("\n\n\n");
														lugar = 3;
													}else{
														if (strcmp(resultado, "castillo") == 0){
															printf("Te encuentras en el castillo\n\n");
															imprimirGraficos(5);
															printf("\n\n\n");
															lugar =4;
														}else{	
															if (strcmp(resultado, "escaleras") == 0){
																printf("Te encuentras en las escaleras del castillo\n\n");
																lugar = 5;
															}else{
																if (strcmp(resultado, "dragon") == 0){
																	char decision[2];
																	printf("oh no! un dragon!!!\n\n\n");
																	imprimirGraficos(6);
																	printf("\n\n\n");
																	printf("Deseas enfrentarlo? (Si/No)\n");
																	scanf("%s", decision);
																	if (strcmp(decision, "Si") == 0){
																		batalla(hp_heroe, 1);
																	}else{
																		printf("El juego ha acabado");
																		end = 1;
																	}
																}
															}

														}

													}

												}
													
											}

										}

									}

								}
							}

						}
					}

				}

			}
		}
	}
}

void imprimirMapa(){
	//header
	printf("\t");
	int i, j;
	for(i=0; i<longLugares; i++){
		printf("%s\t",lugares[i]);
	}
	printf("\n");
	//body
	for(i=0; i<(longHabitaciones+1); i++){
		printf("%d\t",habitaciones[i]);
		for(j=0; j<(longLugares+1); j++){
			printf("%s\t",mapa[i][j]);
		}
		printf("\n");
	}
}

int main(){
	printf("   ______________________________\n");
	printf(" / \\                             \\.\n");
	printf("|   |                            |.\n");
	printf(" \\_ |                            |.\n");
	printf("    |                            |.\n");
	printf("    |                            |.\n");
	printf("    |     BIENVENIDO A           |.\n");
	printf("    |                            |.\n");
	printf("    |            TEXT            |.\n");
	printf("    |                            |.\n");
	printf("    |              ADVENTURES!   |.\n");
	printf("    |                            |.\n");
	printf("    |                            |.\n");
	printf("    |   _________________________|___\n");
	printf("    |  /                            /.\n");
	printf("    \\_/____________________________/.\n");

	generarMapa();

	registrarHeroe();

	printf("Bienvenid@ al juego %s !!! \n\n\n", nombre_heroe);

	char desicion[2];

	printf("Deseas saber las instrucciones? (Si/No)\n");
	scanf("%s", desicion);
	if (strcmp(desicion, "Si") == 0){
		instrucciones();
		}
	
	printf("Comenzemos!!! \n\n\n");

	lugar = 0;
	habitacion = 0;

	do{
		entrarHabitacion(lugar, habitacion);
	}while (end==0);

	printf("GAME OVER");
}