#include <stdio.h>
#include <windows.h>
#include <time.h>

void gotoxy(int , int);
void cuadro(int , int , int , int);
void centrar(char *, int);

int main(){
	system("mode con: cols=170 lines=50");
	system("COLOR 30");
	
    FILE *archivo=NULL;
    archivo=fopen("inventario.txt","r+");
    
    FILE *archivo2=NULL;
    archivo2=fopen("inventario.txt","r+");
    

    char buffer[100];
    char buffer2[100];

    int medicinas[4];
    int c=0;

    if (archivo==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
    
    if (archivo2==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
    
    
	while (!feof(archivo)){
        c++;
        fgets(buffer,100,archivo);
        if(c==3){
        	fscanf(archivo, "%d", medicinas);
		}
		if(c==6){
        	fscanf(archivo, "%d", medicinas+1);
		}
		if(c==9){
        	fscanf(archivo, "%d", medicinas+2);
		}
		if(c==12){
        	fscanf(archivo, "%d", medicinas+3);
		}
    }
	
    char cedula [100];
    char nombre [100];
    char paciente [100];
    char cedulapaciente [100];
    int aux=0;
    int aux1=0;
    int cont=0;
    int cont1=0;
    int paracetamol=0;
    int aspirinas=0;
    int omeprazol=0;
    int simvastatina=0;
    char indicaciones [300];
    int auxparacetamol=0;
    int auxaspirinas=0;
    int auxomeprazol=0;
    int auxsimvastatina=0;
    int med1=0, med2=0, med3=0, med4=0;
    
	int hours, minutes, seconds, day, month, year;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
	day = local->tm_mday;            
    month = local->tm_mon + 1;      
    year = local->tm_year + 1900;
	
	cuadro(2,1,167,5);
	centrar("R E C E T A R I O       M E D I C O",3);
    gotoxy(4,7);printf("=================");
    gotoxy(4,8);printf("INICIO DE SESION");
    gotoxy(4,9);printf("=================");
    printf("\n");
    gotoxy(4,11); printf("Nombre y Apellido"":");
    gotoxy(4,13);
    scanf("%[^\n]",nombre);
    fflush(stdin);
    gotoxy(4,17); printf("Ingrese su cedula:");
    gotoxy(4,19);
    scanf("%s",cedula);
    fflush(stdin);
    centrar("CARGANDO...", 26);
    for(int i=3; i<=167; i++){
    	gotoxy(i,28);printf("%c",177);
	}
	
	for(int i=3; i<=167; i++){
    	gotoxy(i,28);printf("%c",219);
    	Sleep(1);
	}
	system("cls");
	
	cuadro(2,1,167,5);
	centrar("R E C E T A R I O       M E D I C O",3);
    gotoxy(4,7);printf("===========================================");
    gotoxy(10,8);printf("Bienvenido Doctor %s", nombre);
    gotoxy(4,9);printf("===========================================");
    gotoxy(4,13);printf("Ingrese los datos del paciente a recetar:");
    gotoxy(4,14);printf("----------------------------------------");
    gotoxy(4,17);printf("Nombres y Apellidos del paciente:");
    gotoxy(4,19);
    scanf("%[^\n]",paciente);
    fflush(stdin);
	gotoxy(4,22); printf("Numero de cedula del paciente:");
	gotoxy(4,24);
    scanf("%s",cedulapaciente);
    fflush(stdin);
    centrar("CARGANDO INVENTARIO...", 26);
    for(int i=3; i<=167; i++){
    	gotoxy(i,28);printf("%c",177);
	}
	
	for(int i=3; i<=167; i++){
    	gotoxy(i,28);printf("%c",219);
    	Sleep(1);
	}
	system("cls");
	
    
    while (cont<1){
    	cont1=0;
    	system("cls");
    	
    	cuadro(2,1,167,5);
		centrar("R E C E T A R I O       M E D I C O",3);
    	gotoxy(4,7);printf("=================================");
    	gotoxy(10,8);printf("Doctor %s", nombre);
    	gotoxy(4,9);printf("=================================");
    	gotoxy(4,12);printf("Seleccione las medicinas a recetar:");
    	gotoxy(4,13);printf("-----------------------------------");
    	
    	gotoxy(4,16);printf("Ingrese 1 para Paracetamol\n");
    	gotoxy(4,18);printf("Unidades disponibles %d",medicinas[0]);
    	gotoxy(44,16);printf("Ingrese 2 para Aspirinas");
    	gotoxy(44,18);printf("Unidades disponibles %d",medicinas[1]);
    	gotoxy(84,16);printf("Ingrese 3 para Omeprazol");
    	gotoxy(84,18);printf("Unidades disponibles %d",medicinas[2]);
    	gotoxy(124,16);printf("Ingrese 4 para Simvastatina");
    	gotoxy(124,18);printf("Unidades disponibles %d",medicinas[3]);
    	gotoxy(4,20);
		scanf("%d", &aux);
    	
    	switch(aux){
        	case 1:	
        		while(cont1<1){
        			gotoxy(4,23);printf("Ingrese la cantidad de Paracetamol por unidades:");
        			gotoxy(4,24);printf("-------------------------------------------------");
        			gotoxy(4,25);
        			scanf("%d", &paracetamol);
        			auxparacetamol=medicinas[0]-paracetamol;
        			if(auxparacetamol>=0){
        					med1=paracetamol+med1;
            				medicinas[0]=medicinas[0]-paracetamol;
            				cont1=1;
        				}
        			else{
            			gotoxy(4,28);printf("No hay suficientes unidades disponibles para recetar, intente nuevamente");
            			Sleep(2);
            			system("cls");
						cuadro(2,1,167,5);
						centrar("R E C E T A R I O       M E D I C O",3);
    					gotoxy(4,7);printf("=================================");
    					gotoxy(10,8);printf("Doctor %s", nombre);
    					gotoxy(4,9);printf("=================================");
    					gotoxy(4,12);printf("Seleccione las medicinas a recetar:");
    					gotoxy(4,13);printf("-----------------------------------");
    	
    					gotoxy(4,16);printf("Ingrese 1 para Paracetamol\n");
    					gotoxy(4,18);printf("Unidades disponibles %d",medicinas[0]);
    					gotoxy(44,16);printf("Ingrese 2 para Aspirinas");
    					gotoxy(44,18);printf("Unidades disponibles %d",medicinas[1]);
    					gotoxy(84,16);printf("Ingrese 3 para Omeprazol");
    					gotoxy(84,18);printf("Unidades disponibles %d",medicinas[2]);
    					gotoxy(124,16);printf("Ingrese 4 para Simvastatina");
    					gotoxy(124,18);printf("Unidades disponibles %d",medicinas[3]);
    					gotoxy(4,20);
						scanf("%d", &aux);
        				}  
    				}
        		break;
        	case 2:
        		while(cont1<1){
        			gotoxy(4,23);printf("Ingrese la cantidad de Aspirinas por unidades:");
        			gotoxy(4,24);printf("-------------------------------------------------");
        			gotoxy(4,25);
        			scanf("%d", &aspirinas);
        			auxaspirinas=medicinas[1]-aspirinas;
        			if(auxaspirinas>=0){
        					med2=aspirinas+med2;
            				medicinas[1]=medicinas[1]-aspirinas;
            				cont1=1;
        				}
        			else{
            			gotoxy(4,28);printf("No hay suficientes unidades disponibles para recetar, intente nuevamente");
            			Sleep(2);
            			system("cls");
						cuadro(2,1,167,5);
						centrar("R E C E T A R I O       M E D I C O",3);
    					gotoxy(4,7);printf("=================================");
    					gotoxy(10,8);printf("Doctor %s", nombre);
    					gotoxy(4,9);printf("=================================");
    					gotoxy(4,12);printf("Seleccione las medicinas a recetar:");
    					gotoxy(4,13);printf("-----------------------------------");
    	
    					gotoxy(4,16);printf("Ingrese 1 para Paracetamol\n");
    					gotoxy(4,18);printf("Unidades disponibles %d",medicinas[0]);
    					gotoxy(44,16);printf("Ingrese 2 para Aspirinas");
    					gotoxy(44,18);printf("Unidades disponibles %d",medicinas[1]);
    					gotoxy(84,16);printf("Ingrese 3 para Omeprazol");
    					gotoxy(84,18);printf("Unidades disponibles %d",medicinas[2]);
    					gotoxy(124,16);printf("Ingrese 4 para Simvastatina");
    					gotoxy(124,18);printf("Unidades disponibles %d",medicinas[3]);
    					gotoxy(4,20);
						scanf("%d", &aux);
        				}  
    				}
    			break;
    		case 3:
    			while(cont1<1){
        			gotoxy(4,23);printf("Ingrese la cantidad de Omeprazol por unidades:");
        			gotoxy(4,24);printf("-------------------------------------------------");
        			gotoxy(4,25);
        			scanf("%d", &omeprazol);
        			auxomeprazol=medicinas[2]-omeprazol;
        			if(auxomeprazol>=0){
        					med3=omeprazol+med3;
            				medicinas[2]=medicinas[2]-omeprazol;
            				cont1=1;
        				}
        			else{
            			gotoxy(4,28);printf("No hay suficientes unidades disponibles para recetar, intente nuevamente");
            			Sleep(2);
            			system("cls");
						cuadro(2,1,167,5);
						centrar("R E C E T A R I O       M E D I C O",3);
    					gotoxy(4,7);printf("=================================");
    					gotoxy(10,8);printf("Doctor %s", nombre);
    					gotoxy(4,9);printf("=================================");
    					gotoxy(4,12);printf("Seleccione las medicinas a recetar:");
    					gotoxy(4,13);printf("-----------------------------------");
    	
    					gotoxy(4,16);printf("Ingrese 1 para Paracetamol\n");
    					gotoxy(4,18);printf("Unidades disponibles %d",medicinas[0]);
    					gotoxy(44,16);printf("Ingrese 2 para Aspirinas");
    					gotoxy(44,18);printf("Unidades disponibles %d",medicinas[1]);
    					gotoxy(84,16);printf("Ingrese 3 para Omeprazol");
    					gotoxy(84,18);printf("Unidades disponibles %d",medicinas[2]);
    					gotoxy(124,16);printf("Ingrese 4 para Simvastatina");
    					gotoxy(124,18);printf("Unidades disponibles %d",medicinas[3]);
    					gotoxy(4,20);
						scanf("%d", &aux);
        				}  
    				}
    			break;
    		case 4:
    			while(cont1<1){
        			gotoxy(4,23);printf("Ingrese la cantidad de Simvastatina por unidades:");
        			gotoxy(4,24);printf("-------------------------------------------------");
					gotoxy(4,25);        			
        			scanf("%d", &simvastatina);
        			auxsimvastatina=medicinas[3]-simvastatina;
        			if(auxsimvastatina>=0){
        					med4=simvastatina+med4;
            				medicinas[3]=medicinas[3]-simvastatina;
            				cont1=1;
        				}
        			else{
            			gotoxy(4,28);printf("No hay suficientes unidades disponibles para recetar, intente nuevamente");
            			Sleep(2);
            			system("cls");
						cuadro(2,1,167,5);
						centrar("R E C E T A R I O       M E D I C O",3);
    					gotoxy(4,7);printf("=================================");
    					gotoxy(10,8);printf("Doctor %s", nombre);
    					gotoxy(4,9);printf("=================================");
    					gotoxy(4,12);printf("Seleccione las medicinas a recetar:");
    					gotoxy(4,13);printf("-----------------------------------");
    	
    					gotoxy(4,16);printf("Ingrese 1 para Paracetamol\n");
    					gotoxy(4,18);printf("Unidades disponibles %d",medicinas[0]);
    					gotoxy(44,16);printf("Ingrese 2 para Aspirinas");
    					gotoxy(44,18);printf("Unidades disponibles %d",medicinas[1]);
    					gotoxy(84,16);printf("Ingrese 3 para Omeprazol");
    					gotoxy(84,18);printf("Unidades disponibles %d",medicinas[2]);
    					gotoxy(124,16);printf("Ingrese 4 para Simvastatina");
    					gotoxy(124,18);printf("Unidades disponibles %d",medicinas[3]);
    					gotoxy(4,20);
						scanf("%d", &aux);
        				}  
    				}
    			break;
    		default:
    			gotoxy(4,23);printf("Numero incorrecto intente nuevamente\n");
    			gotoxy(4,24);printf("--------------------------------------");
    			break;
    	}
    	gotoxy(4,28);printf("Si desea anadir otros medicamentos ingrese 1, de lo contrario ingrese 2");
    	gotoxy(4,29);printf("------------------------------------------------------------------------");
    	gotoxy(4,31);
    	scanf("%d",&aux1);
    	if(aux1==2){
    	cont=1;
		}
	}
	
	fflush(stdin);
	gotoxy(4,34);printf("Ingrese las indicaciones para el paciente:");
	gotoxy(4,35);printf("-------------------------------------------");
	gotoxy(4,37);
    scanf("%[^\n]",indicaciones);
    fflush(stdin);
    
    centrar("CARGANDO RECETA...", 45);
    for(int i=3; i<=167; i++){
    	gotoxy(i,47);printf("%c",177);
	}
	
	for(int i=3; i<=167; i++){
    	gotoxy(i,47);printf("%c",219);
    	Sleep(1);
	}
	system("cls");
	
	
	cuadro(2,1,167,5);
	centrar("R E C E T A R I O       M E D I C O",3);
	cuadro(10,8,159,12); 
	Sleep(400);
	cuadro(10,8,159,18);
	Sleep(400);
	cuadro(10,8,159,46);
	Sleep(400);
	centrar("F U N D A C I O N   S A L U D   P A R A   T O D O S",10);
	gotoxy(16,14);printf("Doctor %s", nombre);
	Sleep(400);
	gotoxy(16,16);printf("Fecha: %02d/%02d/%d\n", day, month, year);
	Sleep(400);
	gotoxy(120,14);printf("Paciente: %s", paciente);
	Sleep(400);
	gotoxy(120,16);printf("Cedula: %s",cedulapaciente);
	Sleep(400);
	centrar("M e d i c i n a s   R e c e t a d a s:",20);
	Sleep(400);
	gotoxy(16,23);printf("Paracetamol: %d",med1);
	Sleep(400);
	gotoxy(46,23);printf("Aspirinas: %d",med2);
	Sleep(400);
	gotoxy(76,23);printf("Omeprazol: %d",med3);
	Sleep(400);
	gotoxy(106,23);printf("Simvastatina: %d",med4);
	Sleep(400);
	gotoxy(16,27);printf("%s",indicaciones);
	Sleep(400);
	gotoxy(16,43);printf("-------------------------------");
	Sleep(400);
	gotoxy(25,44);printf("FIRMA DOCTOR");
	Sleep(400);
	gotoxy(122,43);printf("-------------------------------");
	Sleep(400);
	gotoxy(131,44);printf("FIRMA PACIENTE");
	Sleep(800);
	
	system("cls");
	
	cuadro(2,1,167,5);
	centrar("R E C E T A R I O       M E D I C O",3);
	centrar("Imprimiendo...", 10);
    for(int i=3; i<=167; i++){
    	gotoxy(i,12);printf("%c",177);
	}
	
	for(int i=3; i<=167; i++){
    	gotoxy(i,12);printf("%c",219);
    	Sleep(1);
	}
	
	centrar("I m p r e s i o n    C o m p l e t a d a!",15);
	centrar("------------------------------------------",16);
	Sleep(700);
	
	FILE *archivo3=NULL;
	archivo3=fopen("auxinventario.txt","w");
	
	if (archivo3==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
	
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fprintf(archivo3,"%d",medicinas[0]);
	fgets(buffer2,100,archivo2);
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fprintf(archivo3,"%\n");
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fprintf(archivo3,"%d",medicinas[1]);
	fgets(buffer2,100,archivo2);
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fprintf(archivo3,"%\n");
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fprintf(archivo3,"%d",medicinas[2]);
	fgets(buffer2,100,archivo2);
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fprintf(archivo3,"%\n");
	fgets(buffer2,100,archivo2);
	fprintf(archivo3,"%s",buffer2);
	fprintf(archivo3,"%d",medicinas[3]);
	
	
	centrar("I n v e n t a r i o    A c t u a l i z a d o!",20);
	centrar("----------------------------------------------",21);
	Sleep(700);
	
	centrar("H a s t a    L u e g o!",25);
	centrar("-----------------------",26);
	Sleep(700);
	
	fclose(archivo);
    fclose(archivo2);
    fclose(archivo3);
	
	remove("inventario.txt");		      		
	rename("auxinventario.txt", "inventario.txt");									
	
    
    return 0;
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void cuadro(int x1, int y1, int x2, int y2){
	for(int i=x1; i<=x2; i++){
		gotoxy(i,y1);printf("%c",196);
		gotoxy(i,y2);printf("%c",196);
	}
	
	for(int i=y1; i<=y2; i++){
		gotoxy(x1,i);printf("%c",179);
		gotoxy(x2,i);printf("%c",179);
	}
	
	gotoxy(x1,y1);printf("%c",218);
	gotoxy(x1,y2);printf("%c",192);
	gotoxy(x2,y1);printf("%c",191);
	gotoxy(x2,y2);printf("%c",217);
}

void centrar(char *texto, int y){
	int longitud = strlen (texto);
	gotoxy(85-(longitud/2),y);printf(texto);
}