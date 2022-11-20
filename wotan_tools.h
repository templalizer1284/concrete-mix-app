#ifndef WOTAN_TOOLS_H
#define WOTAN_TOOLS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <mysql/mysql.h>

extern int errno;

#define w_html_prep printf("Content-type: text/html; charset=UTF-8\n\n")
#define w_html_prep_cookie(string) printf("Content-type: text/html; charset=UTF-8\r\nSet-Cookie: %s\r\n\r\n", string)

#define w_next_token(x, y)			\
    token = strtok(NULL, delimiter);		\
    fscanf(token, x, y);

#define w_button_url(url, name)						\
    printf("<form method='get' action='%s'> <button type='submit'>%s</button></form>", \
	   url, name);

#define w_input(type, options)					\
    printf("<input type='%s' %s required>", type, options);

#define w_button(type, name)			\
    printf("<button type='%s' >%s</button>", type, name);

#define sql_err(x) printf("SQL error: %s<br>\n", mysql_error(x));

#define br printf("<br>");

#define div(options)				\
    printf("<div %s>", options);
#define cdiv printf("</div>");

#define h3(options, text)			\
    printf("<h3 %s >%s</h3>", options, text);

typedef struct ReceptKlasik ReceptKlasik;
typedef struct ReceptColormix2 ReceptColormix2;
typedef struct ReceptColormix3 ReceptColormix3;
typedef struct ReceptGrubi ReceptGrubi;
typedef struct Izvestaj Izvestaj;

struct ReceptKlasik {
    char ime[50];
    float pesak;
    float kvarc;
    float bazalt;
    float arandjelovac_beli;
    float arandjelovac_crni;
    float silvergrey;
    float kvarc_krupni;
    float antracit;
    float cement_beli;
    float cement_sivi;
    float rebafob;
    float boja_rumena;
    float boja_crna;
    float boja_bela;
    float boja_braon;
    float boja_crvena;
    float boja_zuta;
    float boja_zelena;
};

struct ReceptColormix2 {
    float pesak;
    float pesak2;
    float kvarc;
    float kvarc2;
    float bazalt;
    float bazalt2;
    float arandjelovac_beli;
    float arandjelovac_beli2;
    float arandjelovac_crni;
    float arandjelovac_crni2;
    float silvergrey;
    float silvergrey2;
    float kvarc_krupni;
    float kvarc_krupni2;
    float antracit;
    float antracit2;
    float cement_beli;
    float cement_beli2;
    float cement_sivi;
    float cement_sivi2;
    float rebafob;
    float rebafob2;
    float boja_rumena;
    float boja_rumena2;
    float boja_crna;
    float boja_crna2;
    float boja_bela;
    float boja_bela2;
    float boja_braon;
    float boja_braon2;
    float boja_crvena;
    float boja_crvena2;
    float boja_zuta;
    float boja_zuta2;
    float boja_zelena;
    float boja_zelena2;
};

struct ReceptColormix3 {
    char ime[100];
    float percentage_first;
    float percentage_second;
    float percentage_third;
    float pesak;
    float pesak2;
    float pesak3;
    float kvarc;
    float kvarc2;
    float kvarc3;
    float bazalt;
    float bazalt2;
    float bazalt3;
    float arandjelovac_beli;
    float arandjelovac_beli2;
    float arandjelovac_beli3;
    float arandjelovac_crni;
    float arandjelovac_crni2;
    float arandjelovac_crni3;
    float silvergrey;
    float silvergrey2;
    float silvergrey3;
    float kvarc_krupni;
    float kvarc_krupni2;
    float kvarc_krupni3;
    float antracit;
    float antracit2;
    float antracit3;
    float cement_beli;
    float cement_beli2;
    float cement_beli3;
    float cement_sivi;
    float cement_sivi2;
    float cement_sivi3;
    float rebafob;
    float rebafob2;
    float rebafob3;
    float boja_rumena;
    float boja_rumena2;
    float boja_rumena3;
    float boja_crna;
    float boja_crna2;
    float boja_crna3;
    float boja_bela;
    float boja_bela2;
    float boja_bela3;
    float boja_braon;
    float boja_braon2;
    float boja_braon3;
    float boja_crvena;
    float boja_crvena2;
    float boja_crvena3;
    float boja_zuta;
    float boja_zuta2;
    float boja_zuta3;
    float boja_zelena;
    float boja_zelena2;
    float boja_zelena3;
};

struct ReceptGrubi {
    char ime[50];
    float cement_sivi;
    float cement_beli;
    float rebament;
    float pesak;
    float dvojka;
    float trojka;
    float eruptivac;
    float boja_rumena;
    float boja_crna;
    float boja_bela;
    float boja_braon;
    float boja_crvena;
    float boja_zuta;
    float boja_zelena;
};

struct Izvestaj {
    float kubikaza_fini;
    float kubikaza_grubi;
    float pesak;
    float pesak_grubi;
    float kvarc;
    float dvojka;
    float trojka;
    float eruptivac;
    float bazalt;
    float arandjelovac_beli;
    float arandjelovac_crni;
    float silvergrey;
    float kvarc_krupni;
    float antracit;
    float cement_beli;
    float cement_sivi;
    float cement_sivi_grubi;
    float rebafob;
    float rebament;
    float boja_rumena;
    float boja_crna;
    float boja_bela;
    float boja_braon;
    float boja_crvena;
    float boja_zuta;
    float boja_zelena;
};

enum KlasikElements {
    klasik_pranaPESAK = 3,
    klasik_pranaKVARC,
    klasik_pranaBAZALT,
    klasik_pranaARANDJELOVAC_BELI,
    klasik_pranaARANDJELOVAC_CRNI,
    klasik_pranaSILVERGREY,
    klasik_pranaKVARC_KRUPNI,
    klasik_pranaANTRACIT,
    klasik_pranaCEMENT_BELI,
    klasik_pranaCEMENT_SIVI,
    klasik_pranaREBAFOB,
    klasik_pranaBOJA_RUMENA,
    klasik_pranaBOJA_CRNA,
    klasik_pranaBOJA_BELA,
    klasik_pranaBOJA_BRAON,
    klasik_pranaBOJA_CRVENA,
    klasik_pranaBOJA_ZUTA,
    klasik_pranaBOJA_ZELENA,
};


enum Colormix2Elements {
    colormix2PESAK = 5,
    colormix2PESAK2,
    colormix2KVARC,
    colormix2KVARC2,
    colormix2BAZALT,
    colormix2BAZALT2,
    colormix2ARANDJELOVAC_BELI,
    colormix2ARANDJELOVAC_BELI2,
    colormix2ARANDJELOVAC_CRNI,
    colormix2ARANDJELOVAC_CRNI2,
    colormix2SILVERGREY,
    colormix2SILVERGREY2,
    colormix2KVARC_KRUPNI,
    colormix2KVARC_KRUPNI2,
    colormix2ANTRACIT,
    colormix2ANTRACIT2,
    colormix2CEMENT_BELI,
    colormix2CEMENT_BELI2,
    colormix2CEMENT_SIVI,
    colormix2CEMENT_SIVI2,
    colormix2REBAFOB,
    colormix2REBAFOB2,
    colormix2BOJA_RUMENA,
    colormix2BOJA_RUMENA2,
    colormix2BOJA_CRNA,
    colormix2BOJA_CRNA2,
    colormix2BOJA_BELA,
    colormix2BOJA_BELA2,
    colormix2BOJA_BRAON,
    colormix2BOJA_BRAON2,
    colormix2BOJA_CRVENA,
    colormix2BOJA_CRVENA2,
    colormix2BOJA_ZUTA,
    colormix2BOJA_ZUTA2,
    colormix2BOJA_ZELENA,
    colormix2BOJA_ZELENA2
};

enum Colormix3Elements {
    colormix3PESAK = 6,
    colormix3PESAK2,
    colormix3PESAK3,
    colormix3KVARC,
    colormix3KVARC2,
    colormix3KVARC3,
    colormix3BAZALT,
    colormix3BAZALT2,
    colormix3BAZALT3,
    colormix3ARANDJELOVAC_BELI,
    colormix3ARANDJELOVAC_BELI2,
    colormix3ARANDJELOVAC_BELI3,
    colormix3ARANDJELOVAC_CRNI,
    colormix3ARANDJELOVAC_CRNI2,
    colormix3ARANDJELOVAC_CRNI3,
    colormix3SILVERGREY,
    colormix3SILVERGREY2,
    colormix3SILVERGREY3,
    colormix3KVARC_KRUPNI,
    colormix3KVARC_KRUPNI2,
    colormix3KVARC_KRUPNI3,
    colormix3ANTRACIT,
    colormix3ANTRACIT2,
    colormix3ANTRACIT3,
    colormix3CEMENT_BELI,
    colormix3CEMENT_BELI2,
    colormix3CEMENT_BELI3,
    colormix3CEMENT_SIVI,
    colormix3CEMENT_SIVI2,
    colormix3CEMENT_SIVI3,
    colormix3REBAFOB,
    colormix3REBAFOB2,
    colormix3REBAFOB3,
    colormix3BOJA_RUMENA,
    colormix3BOJA_RUMENA2,
    colormix3BOJA_RUMENA3,
    colormix3BOJA_CRNA,
    colormix3BOJA_CRNA2,
    colormix3BOJA_CRNA3,
    colormix3BOJA_BELA,
    colormix3BOJA_BELA2,
    colormix3BOJA_BELA3,
    colormix3BOJA_BRAON,
    colormix3BOJA_BRAON2,
    colormix3BOJA_BRAON3,
    colormix3BOJA_CRVENA,
    colormix3BOJA_CRVENA2,
    colormix3BOJA_CRVENA3,
    colormix3BOJA_ZUTA,
    colormix3BOJA_ZUTA2,
    colormix3BOJA_ZUTA3,
    colormix3BOJA_ZELENA,
    colormix3BOJA_ZELENA2,
    colormix3BOJA_ZELENA3
};

enum GrubiElements {
    grubiPESAK = 3,
    grubiDVOJKA,
    grubiTROJKA,
    grubiERUPTIVAC,
    grubiCEMENT_SIVI,
    grubiCEMENT_BELI,
    grubiREBAMENT,
    grubiBOJA_RUMENA,
    grubiBOJA_CRNA,
    grubiBOJA_BELA,
    grubiBOJA_BRAON,
    grubiBOJA_CRVENA,
    grubiBOJA_ZUTA,
    grubiBOJA_ZELENA
};

enum RECIPE_FLAGS{
    KLASIK_PRANA,
    COLORMIX2,
    COLORMIX3,
    GRUBI
};

enum BOJE{
    RUMENA,
    RUMENA2,
    RUMENA3,
    CRNA,
    CRNA2,
    CRNA3,
    BELA,
    BELA2,
    BELA3,
    BRAON,
    BRAON2,
    BRAON3,
    CRVENA,
    CRVENA2,
    CRVENA3,
    ZUTA,
    ZUTA2,
    ZUTA3,
    ZELENA,
    ZELENA2,
    ZELENA3
};

bool w_if_exist(MYSQL* connection, char table_name[], char string[]);
void w_strip(char *string, char delimiter);
char *w_load_file(char file_path[]);
bool check_login(void);
char *w_generate_id(void);

bool w_if_exist(MYSQL *sql_connection, char table_name[100], char string[1000]){
    char *query = malloc(sizeof(char) * 100);
    sprintf(query, "SELECT ime FROM %s;", table_name);

    if( mysql_real_query(sql_connection, query, strlen(query)) != 0 ){
	fprintf(stderr, "SQL error: %s<br>", mysql_error(sql_connection));
	free(query);
	return false;
    }

    MYSQL_RES *result = mysql_store_result(sql_connection);

    int num_fields = mysql_num_fields(result);
    if(num_fields == 0){
	mysql_free_result(result);
	free(query);
	return false;
    }

    MYSQL_ROW data;

    while((data = mysql_fetch_row(result))){
	for(int i = 0; i < num_fields; i++){
	    if(strcmp(string, data[i]) == 0){
		mysql_free_result(result);
		free(query);
		return true;
	    }
	}
    }

    free(query);
    mysql_free_result(result);
    return false;
}

/* Replaces 'del' in string with whitespace. */
/* This is nice preparation for sscanf ;) */
void w_strip(char *string, char del){
    char c1,c2;
    c2 = del;

    int i = 0;

WHILE:
    c1 = string[i];
    if(c1 == c2){
	string[i] = 0x20;
    }

    if(c1 == EOF){
	goto END;
    }

    i++;

    goto WHILE;

END:
    while(1){break;}; /* This nonsense is here because compiler doesn't like void funcs with LABELS at the end. */
    /* Also i don't need anything to return so.... Here is your statement! you f*ck! */
}

char *w_load_file(char filename[1000]){
    FILE *stream_style = NULL;
    stream_style = fopen(filename, "r");

    if(stream_style == NULL){
	return NULL;
    }

    char *content_style = NULL;
    long len = 0;

    fseek(stream_style, len, SEEK_END);
    len = ftell(stream_style);
    rewind(stream_style);

    content_style = malloc(sizeof(char) * len + 1);
    fread(content_style, 1, len, stream_style);

    fclose(stream_style);
    
    return content_style;
}

bool check_login(){
    char *cookie_data = getenv("HTTP_COOKIE");
    if(cookie_data != NULL){
	MYSQL *sql_connection = mysql_init(NULL);

	if( (mysql_real_connect(sql_connection,
				"localhost",
				"behaton",
				"expansion123",
				"transkop",
				0,
				NULL,
				0)) == NULL ){
	    sql_err(sql_connection);
	}
	
	w_strip(cookie_data, '=');
	char session_id[100];
	sscanf(cookie_data, "%*s %s", session_id);

	char query[200] = "SELECT session_id FROM cookies;";

	if( (mysql_real_query(sql_connection, query, strlen(query))) != 0){
	    sql_err(sql_connection);
	}

	MYSQL_RES *result = mysql_store_result(sql_connection);
	int fields = mysql_num_fields(result);

	MYSQL_ROW data;

	while( (data = mysql_fetch_row(result)) ){
	    for(int i = 0; i < fields; i++){
		if(strcmp(session_id, data[i]) == 0){
		    mysql_free_result(result);
		    mysql_close(sql_connection);
		    return true;
		}
	    }
	}

	mysql_free_result(result);
	mysql_close(sql_connection);
    }

    return false;
}

char *w_generate_id(){
    char *id = malloc(sizeof(char) * 50);
    char random_char;
    time_t t = time(NULL);

    srand((unsigned) t);

    for(int i = 0; i < 45; i++){
    AGAIN:
	random_char = rand() % 122;
	if(random_char < 97){
	    goto AGAIN;
	}

	id[i] = random_char;
    }

    return id;
}

#endif
