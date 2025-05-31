#include "../waresdes.h"
#include "../i386.h"
#include "../types.h"
#include "../screen.h"
#include "../gui/spscreen.h"
#include "../gui/string.h"

void read_date_time();

#ifndef DATA_H
#define DATA_H

typedef struct {
    char dia;
    char mes;
    short ano;
} date;

typedef struct {
	char hora;
	char menutes;
	char secunds;
} time;


#endif

typedef struct {
	char* names_files[3500];
	char* dirs[3500];
	char* context_files[3500];
	int link_dir_for_files[3500];
	char dia[3500];
	char mes[3500];
	short ano[3500];
	char hora[3500];
	char minuto[3500];
	char segundo[3500];
	char disk_key;
	long number_sereal;
	char* name_prt;
} DiskRamC_t;
DiskRamC_t DISK;

void DrawLogon(int Bar){
	int space = 5;
	int tam_retangolos = 100;
	int alt_logon = 250;
	int XGlobal = (800 / 2) - space - tam_retangolos;
	int YGlobal = (600 / 2) - alt_logon - space;
	int LARTmp = 0;
	int ALTTmp = 0;
	ALTTmp = alt_logon - space;
	LARTmp = tam_retangolos;
	SetReact(XGlobal,YGlobal,LARTmp,ALTTmp,0,0,255);
	ALTTmp = (alt_logon / 4);
	LARTmp = tam_retangolos;
	YGlobal = (600 / 2);
	SetReact(XGlobal,YGlobal,LARTmp,ALTTmp,0,255,0);
	XGlobal = (800 / 2) + space;
	YGlobal = ((600 / 2) - alt_logon) + space + (alt_logon/4);
	ALTTmp = alt_logon - space;
	LARTmp = tam_retangolos;
	SetReact(XGlobal,YGlobal,LARTmp,ALTTmp,0,255,0);
	XGlobal = (800 / 2) + space;
	YGlobal = (600 / 2) - alt_logon - space;
	ALTTmp = (alt_logon / 4);
	LARTmp = tam_retangolos;
	SetReact(XGlobal,YGlobal,LARTmp,ALTTmp,0,0,255);
	
	SetReact((800/2)-200,(600/2)+(alt_logon/4)+19,400,10,  255,255,255);
	SetReact(((800/2)-200)+1,((600/2)+(alt_logon/4)+19)+1,400-2,10-2,  0,0,0);
	if(Bar >= 400-4){
		Bar = 400-4;
	}
	uint16_t Bar2 = Bar;
	if(Bar2 >= 255){
		Bar2 = 255;
	}
	SetReact(((800/2)-200)+2,((600/2)+(alt_logon/4)+19)+2,Bar,10-4,  100,Bar2,0);
	
	
	draw();
}

void DrawScreen(int ScreenNumber){
	if(ScreenNumber == 0){
		DrawLogon(0);
	} else if(ScreenNumber == 1){
		DrawLogon(5);
	} else if(ScreenNumber == 2){
		DrawLogon(100);
	} else if(ScreenNumber == 3){
		DrawLogon(133);
	} else if(ScreenNumber == 4){
		DrawLogon(168);
	} else if(ScreenNumber == 5){
		DrawLogon(199);
	} else if(ScreenNumber == 6){
		DrawLogon(215);
	} else if(ScreenNumber == 7){
		DrawLogon(300);
	} else if(ScreenNumber == 8){
		DrawLogon(400);
	}
}

// Prototipagem, se necessário
int GetNewFileNumber();
int IfExistFile(const char* name, int dir_index);
int GetDirectoryIndex(const char dir);
	/*
	char* names_files[3500];
	char* dirs[3500];
	char* context_files[3500];
	int link_dir_for_files[3500];
	char dia[3500];
	char mes[3500];
	short ano[3500];
	char hora[3500];
	char minuto[3500];
	char segundo[3500];
	char disk_key;
	long number_sereal;
	char* name_prt;*/


void CPrt(char key_prt,long format_sere_number){
	if(DISK.number_sereal != 0){
		if(format_sere_number == DISK.number_sereal){
			for(int i=0;i<3500;i++){
				DISK.link_dir_for_files[i] = 0;
			}
			for(int i=0;i<3500;i++){
				DISK.names_files[i] = "\0";
			}
			for(int i=0;i<3500;i++){
				DISK.dirs[i] = "\0";
			}
			for(int i=0;i<3500;i++){
				DISK.context_files[i] = "\0";
			}
			for(int i=0;i<3500;i++){
				DISK.dia[i] = 0;
				DISK.mes[i] = 0;
				DISK.ano[i] = 0;
				DISK.hora[i] = 0;
				DISK.minuto[i] = 0;
				DISK.segundo[i] = 0;
			}
			
			DISK.name_prt = '\0';
			DISK.number_sereal = 0;
			DISK.disk_key = '\0';
		}
	}
	DISK.disk_key = key_prt;
	DISK.number_sereal = format_sere_number;
}

void InitDisk(){
	DrawScreen(0);
	for(int i=0;i<3500;i++){
		DISK.names_files[i] = "\0";
	}
	DrawScreen(1);
	sleep(100);
	for(int i=0;i<3500;i++){
		DISK.dirs[i] = "\0";
	}
	DrawScreen(2);
	sleep(100);
	for(int i=0;i<3500;i++){
		DISK.context_files[i] = "\0";
	}
	DrawScreen(3);
	sleep(100);
	for(int i=0;i<3500;i++){
		DISK.link_dir_for_files[i] = 0;
	}
	for(int i=0;i<3500;i++){
				DISK.dia[i] = 0;
				DISK.mes[i] = 0;
				DISK.ano[i] = 0;
				DISK.hora[i] = 0;
				DISK.minuto[i] = 0;
				DISK.segundo[i] = 0;
			}
	
	DrawScreen(4);
	sleep(100);
	DrawScreen(5);
	sleep(100);
	DISK.disk_key = '\0';
	
	DrawScreen(6);
	sleep(100);
	DISK.number_sereal = 0;
	DrawScreen(7);
	sleep(100);
	DISK.name_prt = '\0';
	DrawScreen(8);
	sleep(100);
	
}