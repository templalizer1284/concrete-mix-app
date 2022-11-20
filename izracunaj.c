#include "wotan_tools.h"

typedef struct Mesung Mesung;

struct Mesung {
    char ime[100];
    float kubikaza;
};

int main(void){

    w_html_prep;

    if(check_login() == false){
	printf("Pristup zabranjen! Prijavi se prvo.<br>");
	w_button_url("/cgi-bin/index.cgi", "Na pocetnu");
	goto END2;
    }

    MYSQL *sql_connection = mysql_init(NULL);

    if( mysql_real_connect (sql_connection,
			    "localhost",
			    "behaton",
			    "expansion123",
			    "transkop",
			    0,
			    NULL,
			    0) == NULL){
	fprintf(stderr, "SQL error: %s<br>", mysql_error(sql_connection));
    }
    
    char post[1000];
    fscanf(stdin, "%s", post);
    char query_report[1000];

    float percentage_first_colormix2;
    float percentage_second_colormix2;
    float percentage_first_colormix3;
    float percentage_second_colormix3;
    float percentage_third_colormix3;

    Mesung m[500]; int mi = -1;

    char *token = NULL;
    char *del = "&";
    char tmpc[100];
    float tmpf;

    static Izvestaj izvestaj;

    token = strtok(post, del);
    w_strip(token, '=');
    sscanf(token, "%s %f", tmpc, &tmpf);
	
    if(tmpf == 0){
	goto NEXT_TOKEN;
    }

    goto CHECK_KLASIK;

NEXT_TOKEN:
    
    token = strtok(NULL, del);
    
    if(token == NULL){
	if(mi > 0){
	    goto WRITE_REPORT;
	}
	goto END;
    }
    
    sscanf(token, "%s %f", tmpc, &tmpf);
    
    if(tmpf == 0){
	goto NEXT_TOKEN;
    } else{
	mi++;
	strcpy(m[mi].ime, tmpc);
	m[mi].kubikaza = tmpf;
	goto CHECK_KLASIK;	
    }

CHECK_KLASIK:    
    if( w_if_exist(sql_connection, "recepti_klasik_prana", tmpc) == true){
	char query_klasik_prana[1000];
	sprintf(query_klasik_prana, "SELECT * FROM recepti_klasik_prana WHERE ime='%s';", tmpc);
	if( mysql_real_query(sql_connection, query_klasik_prana, strlen(query_klasik_prana)) != 0 ){
	    sql_err(sql_connection);
	}
    
	MYSQL_RES *result_klasik_prana = mysql_store_result(sql_connection);
	if(result_klasik_prana == NULL){
	    sql_err(sql_connection);
	}
	MYSQL_ROW data;
	int fields_klasik_prana = mysql_num_fields(result_klasik_prana);
	float fdata[fields_klasik_prana];

	bool skip = true;
	while( (data = mysql_fetch_row(result_klasik_prana)) ){
	    for(int i = 0; i < fields_klasik_prana; i++){
		if(skip == true){
		    skip = false;
		    i++; i++; i++;
		}
	        fdata[i] = atof(data[i]);
	    }
	}
	izvestaj.pesak += fdata[klasik_pranaPESAK] * tmpf;
	izvestaj.kvarc += fdata[klasik_pranaKVARC] * tmpf;
	izvestaj.bazalt += fdata[klasik_pranaBAZALT] * tmpf;
	izvestaj.arandjelovac_beli += fdata[klasik_pranaARANDJELOVAC_BELI] * tmpf;
	izvestaj.arandjelovac_crni += fdata[klasik_pranaARANDJELOVAC_CRNI] * tmpf;
	izvestaj.silvergrey += fdata[klasik_pranaSILVERGREY] * tmpf;
	izvestaj.kvarc_krupni += fdata[klasik_pranaKVARC_KRUPNI] * tmpf;
	izvestaj.antracit += fdata[klasik_pranaANTRACIT] * tmpf;
	izvestaj.cement_beli += fdata[klasik_pranaCEMENT_BELI] * tmpf;
	izvestaj.cement_sivi += fdata[klasik_pranaCEMENT_SIVI] * tmpf;
	izvestaj.rebafob += fdata[klasik_pranaREBAFOB] * tmpf;
	izvestaj.boja_rumena += fdata[klasik_pranaBOJA_RUMENA] * tmpf;
	izvestaj.boja_crna += fdata[klasik_pranaBOJA_CRNA] * tmpf;
	izvestaj.boja_bela += fdata[klasik_pranaBOJA_BELA] * tmpf;
	izvestaj.boja_braon += fdata[klasik_pranaBOJA_BRAON] * tmpf;
	izvestaj.boja_crvena += fdata[klasik_pranaBOJA_CRVENA] * tmpf;
	izvestaj.boja_zuta += fdata[klasik_pranaBOJA_ZUTA] * tmpf;
	izvestaj.boja_zelena += fdata[klasik_pranaBOJA_ZELENA] * tmpf;
	izvestaj.kubikaza_fini += tmpf;
	
	mysql_free_result(result_klasik_prana);
	goto NEXT_TOKEN;
    } else{
	goto CHECK_COLORMIX2;
    }

CHECK_COLORMIX2:
    if( w_if_exist(sql_connection, "recepti_colormix2", tmpc) == true){
	char query_colormix2[1000];
	sprintf(query_colormix2, "SELECT * FROM recepti_colormix2 WHERE ime='%s';", tmpc);
	if( mysql_real_query(sql_connection, query_colormix2, strlen(query_colormix2)) != 0 ){
	    sql_err(sql_connection);
	}
    
	MYSQL_RES *result_colormix2 = mysql_store_result(sql_connection);
	if(result_colormix2 == NULL){
	    sql_err(sql_connection);
	}
	MYSQL_ROW data;
	int fields_colormix2 = mysql_num_fields(result_colormix2);
	float fdata[fields_colormix2];

	bool skip = true;
	while( (data = mysql_fetch_row(result_colormix2)) ){
	    for(int i = 0; i < fields_colormix2; i++){
		if(skip == true){
		    skip = false;
		    i++; i++; i++;
		    percentage_first_colormix2 = atof(data[i]); i++;
		    percentage_second_colormix2 = atof(data[i]); i++;
		}
	        fdata[i] = atof(data[i]);
	    }
	}
	izvestaj.pesak += (fdata[colormix2PESAK] * tmpf) * percentage_first_colormix2;
	izvestaj.pesak += (fdata[colormix2PESAK2] * tmpf) * percentage_second_colormix2;
	izvestaj.kvarc += (fdata[colormix2KVARC] * tmpf) * percentage_first_colormix2;
	izvestaj.kvarc += (fdata[colormix2KVARC2] * tmpf) * percentage_second_colormix2;
	izvestaj.bazalt += (fdata[colormix2BAZALT] * tmpf) * percentage_first_colormix2;
	izvestaj.bazalt += (fdata[colormix2BAZALT] * tmpf) * percentage_second_colormix2;
	izvestaj.arandjelovac_beli += (fdata[colormix2ARANDJELOVAC_BELI] * tmpf) * percentage_first_colormix2;
	izvestaj.arandjelovac_beli += (fdata[colormix2ARANDJELOVAC_BELI2] * tmpf) * percentage_second_colormix2;
	izvestaj.arandjelovac_crni += (fdata[colormix2ARANDJELOVAC_CRNI] * tmpf) * percentage_first_colormix2;
	izvestaj.arandjelovac_crni += (fdata[colormix2ARANDJELOVAC_CRNI2] * tmpf) * percentage_second_colormix2;
	izvestaj.silvergrey += (fdata[colormix2SILVERGREY] * tmpf) * percentage_first_colormix2;
	izvestaj.silvergrey += (fdata[colormix2SILVERGREY2] * tmpf) * percentage_second_colormix2;
	izvestaj.kvarc_krupni += (fdata[colormix2KVARC_KRUPNI] * tmpf) * percentage_first_colormix2;
	izvestaj.kvarc_krupni += (fdata[colormix2KVARC_KRUPNI2] * tmpf) * percentage_second_colormix2;
	izvestaj.antracit += (fdata[colormix2ANTRACIT] * tmpf) * percentage_first_colormix2;
	izvestaj.antracit += (fdata[colormix2ANTRACIT2] * tmpf) * percentage_second_colormix2;
	izvestaj.cement_beli += (fdata[colormix2CEMENT_BELI] * tmpf) * percentage_first_colormix2;
	izvestaj.cement_beli += (fdata[colormix2CEMENT_BELI2] * tmpf) * percentage_second_colormix2;
	izvestaj.cement_sivi += (fdata[colormix2CEMENT_SIVI] * tmpf) * percentage_first_colormix2;
	izvestaj.cement_sivi += (fdata[colormix2CEMENT_SIVI2] * tmpf) * percentage_second_colormix2;
	izvestaj.rebafob += (fdata[colormix2REBAFOB] * tmpf) * percentage_first_colormix2;
	izvestaj.rebafob += (fdata[colormix2REBAFOB2] * tmpf) * percentage_second_colormix2;
	izvestaj.boja_rumena += (fdata[colormix2BOJA_RUMENA] * tmpf) * percentage_first_colormix2;
	izvestaj.boja_rumena += (fdata[colormix2BOJA_RUMENA2] * tmpf) * percentage_second_colormix2;
	izvestaj.boja_crna += (fdata[colormix2BOJA_CRNA] * tmpf) * percentage_first_colormix2;
	izvestaj.boja_crna += (fdata[colormix2BOJA_CRNA2] * tmpf) * percentage_second_colormix2;
	izvestaj.boja_bela += (fdata[colormix2BOJA_BELA] * tmpf) * percentage_first_colormix2;
	izvestaj.boja_bela += (fdata[colormix2BOJA_BELA2] * tmpf) * percentage_second_colormix2;
	izvestaj.boja_braon += (fdata[colormix2BOJA_BRAON] * tmpf) * percentage_first_colormix2;
	izvestaj.boja_braon += (fdata[colormix2BOJA_BRAON2] * tmpf) * percentage_second_colormix2;
	izvestaj.boja_crvena += (fdata[colormix2BOJA_CRVENA] * tmpf) * percentage_first_colormix2;
	izvestaj.boja_crvena += (fdata[colormix2BOJA_CRVENA2] * tmpf) * percentage_second_colormix2;
	izvestaj.boja_zuta += (fdata[colormix2BOJA_ZUTA] * tmpf) * percentage_first_colormix2;
	izvestaj.boja_zuta += (fdata[colormix2BOJA_ZUTA2] * tmpf) * percentage_second_colormix2;
	izvestaj.boja_zelena += (fdata[colormix2BOJA_ZELENA] * tmpf) * percentage_first_colormix2;
	izvestaj.boja_zelena += (fdata[colormix2BOJA_ZELENA2] * tmpf) * percentage_second_colormix2;
	izvestaj.kubikaza_fini += tmpf;

	mysql_free_result(result_colormix2);
	goto NEXT_TOKEN;
    } else{
	goto CHECK_COLORMIX3;
    }

CHECK_COLORMIX3:
    if( w_if_exist(sql_connection, "recepti_colormix3", tmpc) == true ){
	char query_colormix3[1000];
	sprintf(query_colormix3, "SELECT * FROM recepti_colormix3 WHERE ime='%s';", tmpc);
	if( mysql_real_query(sql_connection, query_colormix3, strlen(query_colormix3)) != 0 ){
	    sql_err(sql_connection);
	}
    
	MYSQL_RES *result_colormix3 = mysql_store_result(sql_connection);
	if(result_colormix3 == NULL){
	    sql_err(sql_connection);
	}
	MYSQL_ROW data;
	int fields_colormix3 = mysql_num_fields(result_colormix3);
	float fdata_colormix3[fields_colormix3];

	bool skip = true;
	while( (data = mysql_fetch_row(result_colormix3)) ){
	    for(int i = 0; i < fields_colormix3; i++){
		if(skip == true){
		    skip = false;
		    i++; i++; i++;
		    percentage_first_colormix3 = atof(data[i]); i++;
		    percentage_second_colormix3 = atof(data[i]); i++;
		    percentage_third_colormix3 = atof(data[i]); i++;
		}
	        fdata_colormix3[i] = atof(data[i]);
	    }
	}

	printf("VAL %f %f %f<br>", percentage_first_colormix3, percentage_second_colormix3, percentage_third_colormix3);
	izvestaj.pesak += (fdata_colormix3[colormix3PESAK] * tmpf) * percentage_first_colormix3;
	izvestaj.pesak += (fdata_colormix3[colormix3PESAK2] * tmpf) * percentage_second_colormix3;
	izvestaj.pesak += (fdata_colormix3[colormix3PESAK3] * tmpf) * percentage_third_colormix3;
	izvestaj.kvarc += (fdata_colormix3[colormix3KVARC] * tmpf) * percentage_first_colormix3;
	izvestaj.kvarc += (fdata_colormix3[colormix3KVARC2] * tmpf) * percentage_second_colormix3;
	izvestaj.kvarc += (fdata_colormix3[colormix3KVARC3] * tmpf) * percentage_third_colormix3;
	izvestaj.bazalt += (fdata_colormix3[colormix3BAZALT] * tmpf) * percentage_first_colormix3;
	izvestaj.bazalt += (fdata_colormix3[colormix3BAZALT2] * tmpf) * percentage_second_colormix3;
	izvestaj.bazalt += (fdata_colormix3[colormix3BAZALT3] * tmpf) * percentage_third_colormix3;
	izvestaj.arandjelovac_beli += (fdata_colormix3[colormix3ARANDJELOVAC_BELI] * tmpf) * percentage_first_colormix3;
	izvestaj.arandjelovac_beli += (fdata_colormix3[colormix3ARANDJELOVAC_BELI2] * tmpf) * percentage_second_colormix3;
	izvestaj.arandjelovac_beli += (fdata_colormix3[colormix3ARANDJELOVAC_BELI3] * tmpf) * percentage_third_colormix3;
	izvestaj.arandjelovac_crni += (fdata_colormix3[colormix3ARANDJELOVAC_CRNI] * tmpf) * percentage_first_colormix3;
	izvestaj.arandjelovac_crni += (fdata_colormix3[colormix3ARANDJELOVAC_CRNI2] * tmpf) * percentage_second_colormix3;
	izvestaj.arandjelovac_crni += (fdata_colormix3[colormix3ARANDJELOVAC_CRNI3] * tmpf) * percentage_third_colormix3;
	izvestaj.silvergrey += (fdata_colormix3[colormix3SILVERGREY] * tmpf) * percentage_first_colormix3;
	izvestaj.silvergrey += (fdata_colormix3[colormix3SILVERGREY2] * tmpf) * percentage_second_colormix3;
	izvestaj.silvergrey += (fdata_colormix3[colormix3SILVERGREY3] * tmpf) * percentage_third_colormix3;
	izvestaj.kvarc_krupni += (fdata_colormix3[colormix3KVARC_KRUPNI] * tmpf) * percentage_first_colormix3;
	izvestaj.kvarc_krupni += (fdata_colormix3[colormix3KVARC_KRUPNI2] * tmpf) * percentage_second_colormix3;
	izvestaj.kvarc_krupni += (fdata_colormix3[colormix3KVARC_KRUPNI3] * tmpf) * percentage_third_colormix3;
	izvestaj.antracit += (fdata_colormix3[colormix3ANTRACIT] * tmpf) * percentage_first_colormix3;
	izvestaj.antracit += (fdata_colormix3[colormix3ANTRACIT2] * tmpf) * percentage_second_colormix3;
	izvestaj.antracit += (fdata_colormix3[colormix3ANTRACIT2] * tmpf) * percentage_third_colormix3;
	izvestaj.cement_beli += (fdata_colormix3[colormix3CEMENT_BELI] * tmpf) * percentage_first_colormix3;
	izvestaj.cement_beli += (fdata_colormix3[colormix3CEMENT_BELI2] * tmpf) * percentage_second_colormix3;
	izvestaj.cement_beli += (fdata_colormix3[colormix3CEMENT_BELI3] * tmpf) * percentage_third_colormix3;
	izvestaj.cement_sivi += (fdata_colormix3[colormix3CEMENT_SIVI] * tmpf) * percentage_first_colormix3;
	izvestaj.cement_sivi += (fdata_colormix3[colormix3CEMENT_SIVI2] * tmpf) * percentage_second_colormix3;
	izvestaj.cement_sivi += (fdata_colormix3[colormix3CEMENT_SIVI3] * tmpf) * percentage_third_colormix3;
	izvestaj.rebafob += (fdata_colormix3[colormix3REBAFOB] * tmpf) * percentage_first_colormix3;
	izvestaj.rebafob += (fdata_colormix3[colormix3REBAFOB2] * tmpf) * percentage_second_colormix3;
	izvestaj.rebafob += (fdata_colormix3[colormix3REBAFOB3] * tmpf) * percentage_third_colormix3;
	izvestaj.boja_rumena += (fdata_colormix3[colormix3BOJA_RUMENA] * tmpf) * percentage_first_colormix3;
	izvestaj.boja_rumena += (fdata_colormix3[colormix3BOJA_RUMENA2] * tmpf) * percentage_second_colormix3;
	izvestaj.boja_rumena += (fdata_colormix3[colormix3BOJA_RUMENA3] * tmpf) * percentage_third_colormix3;
	izvestaj.boja_crna += (fdata_colormix3[colormix3BOJA_CRNA] * tmpf) * percentage_first_colormix3;
	izvestaj.boja_crna += (fdata_colormix3[colormix3BOJA_CRNA2] * tmpf) * percentage_second_colormix3;
	izvestaj.boja_crna += (fdata_colormix3[colormix3BOJA_CRNA3] * tmpf) * percentage_third_colormix3;
	izvestaj.boja_bela += (fdata_colormix3[colormix3BOJA_BELA] * tmpf) * percentage_first_colormix3;
	izvestaj.boja_bela += (fdata_colormix3[colormix3BOJA_BELA2] * tmpf) * percentage_second_colormix3;
	izvestaj.boja_bela += (fdata_colormix3[colormix3BOJA_BELA3] * tmpf) * percentage_third_colormix3;
	izvestaj.boja_braon += (fdata_colormix3[colormix3BOJA_BRAON] * tmpf) * percentage_first_colormix3;
	izvestaj.boja_braon += (fdata_colormix3[colormix3BOJA_BRAON2] * tmpf) * percentage_second_colormix3;
	izvestaj.boja_braon += (fdata_colormix3[colormix3BOJA_BRAON3] * tmpf) * percentage_third_colormix3;
	izvestaj.boja_crvena += (fdata_colormix3[colormix3BOJA_CRVENA] * tmpf) * percentage_first_colormix3;
	izvestaj.boja_crvena += (fdata_colormix3[colormix3BOJA_CRVENA2] * tmpf) * percentage_second_colormix3;
	izvestaj.boja_crvena += (fdata_colormix3[colormix3BOJA_CRVENA3] * tmpf) * percentage_third_colormix3;
	izvestaj.boja_zuta += (fdata_colormix3[colormix3BOJA_ZUTA] * tmpf) * percentage_first_colormix3;
	izvestaj.boja_zuta += (fdata_colormix3[colormix3BOJA_ZUTA2] * tmpf) * percentage_second_colormix3;
	izvestaj.boja_zuta += (fdata_colormix3[colormix3BOJA_ZUTA3] * tmpf) * percentage_third_colormix3;
	izvestaj.boja_zelena += (fdata_colormix3[colormix3BOJA_ZELENA] * tmpf) * percentage_first_colormix3;
	izvestaj.boja_zelena += (fdata_colormix3[colormix3BOJA_ZELENA2] * tmpf) * percentage_second_colormix3;
	izvestaj.boja_zelena += (fdata_colormix3[colormix3BOJA_ZELENA3] * tmpf) * percentage_third_colormix3;
	izvestaj.kubikaza_fini += tmpf;
	
	mysql_free_result(result_colormix3);
	goto NEXT_TOKEN;
    } else{
	goto CHECK_GRUBI;
    }

CHECK_GRUBI:
    if( w_if_exist(sql_connection, "recepti_grubi", tmpc) == true ){
	char query_grubi[1000];
	sprintf(query_grubi, "SELECT * FROM recepti_grubi WHERE ime='%s';", tmpc);
	if( mysql_real_query(sql_connection, query_grubi, strlen(query_grubi)) != 0 ){
	    sql_err(sql_connection);
	}
    
	MYSQL_RES *result_grubi = mysql_store_result(sql_connection);
	if(result_grubi == NULL){
	    sql_err(sql_connection);
	}
	MYSQL_ROW data;
	int fields_grubi = mysql_num_fields(result_grubi);
	float fdata_grubi[fields_grubi];

	bool skip = true;
	while( (data = mysql_fetch_row(result_grubi)) ){
	    for(int i = 0; i < fields_grubi; i++){
		if(skip == true){
		    skip = false;
		    i++; i++; i++;
		}
		fdata_grubi[i] = atof(data[i]);
	    }
	}
	printf("<br>");

	izvestaj.pesak_grubi += (fdata_grubi[grubiPESAK] * tmpf);
	izvestaj.dvojka += (fdata_grubi[grubiDVOJKA] * tmpf);
	izvestaj.trojka += (fdata_grubi[grubiTROJKA] * tmpf);
	izvestaj.cement_beli += fdata_grubi[grubiCEMENT_BELI] * tmpf;
	izvestaj.cement_sivi_grubi += fdata_grubi[grubiCEMENT_SIVI] * tmpf;
	izvestaj.rebament += fdata_grubi[grubiREBAMENT] * tmpf;
	izvestaj.boja_rumena += fdata_grubi[grubiBOJA_RUMENA] * tmpf;
	izvestaj.boja_crna += fdata_grubi[grubiBOJA_CRNA] * tmpf;
	izvestaj.boja_bela += fdata_grubi[grubiBOJA_BELA] * tmpf;
	izvestaj.boja_braon += fdata_grubi[grubiBOJA_BRAON] * tmpf;
	izvestaj.boja_crvena += fdata_grubi[grubiBOJA_CRVENA] * tmpf;
	izvestaj.boja_zuta += fdata_grubi[grubiBOJA_ZUTA] * tmpf;
	izvestaj.boja_zelena += fdata_grubi[grubiBOJA_ZELENA] * tmpf;
	izvestaj.kubikaza_grubi += tmpf;

	mysql_free_result(result_grubi);
	goto NEXT_TOKEN;
    } else{
	printf("Fatal error, could not find recipe among tables. Aborting.<br>\n");
	goto END;
    }

WRITE_REPORT:
    
    sprintf(query_report, "INSERT INTO izvestaji (kubikaza_fini, kubikaza_grubi,pesak,kvarc,dvojka,trojka,eruptivac,bazalt,arandjelovac_beli,arandjelovac_crni,silvergrey,kvarc_krupni,antracit,cement_beli,cement_sivi,rebafob,rebament,boja_rumena,boja_crna,boja_bela,boja_braon,boja_crvena,boja_zuta, boja_zelena) VALUES (%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f)",
	    izvestaj.kubikaza_fini,
	    izvestaj.kubikaza_grubi,
	    izvestaj.pesak,
	    izvestaj.kvarc,
	    izvestaj.dvojka,
	    izvestaj.trojka,
	    izvestaj.eruptivac,
	    izvestaj.bazalt,
	    izvestaj.arandjelovac_beli,
	    izvestaj.arandjelovac_crni,
	    izvestaj.silvergrey,
	    izvestaj.kvarc_krupni,
	    izvestaj.antracit,
	    izvestaj.cement_beli,
	    izvestaj.cement_sivi,
	    izvestaj.rebafob,
	    izvestaj.rebament,
	    izvestaj.boja_rumena,
	    izvestaj.boja_crna,
	    izvestaj.boja_bela,
	    izvestaj.boja_braon,
	    izvestaj.boja_crvena,
	    izvestaj.boja_zuta,
	    izvestaj.boja_zelena
	);

    if( mysql_real_query(sql_connection, query_report, strlen(query_report)) != 0 ){
	sql_err(sql_connection);
    }
    
END:
    mysql_close(sql_connection);

    char *content_style = w_load_file("../data/style.css");
    if(content_style == NULL){
	printf("Could not load CSS!<br>\n");
    }
    
    printf("<html><header>%s</header> <style>%s</style>",
	   "<img src='/logo.png' alt='logo', class='logo'>",
	   content_style);

    free(content_style);

    printf("<body>");
    printf("<p>Sadrzaj izvestaja:</p>");
    w_button_url("/cgi-bin/napisi_izvestaj.cgi", "Nazad");

    printf("<table class='center_table'>\n");
    printf("<tr>\n <th><b>Utroseno Finog Sloja (m3)</b></th>\n <td>%1.2f m3</td> </tr>\n", izvestaj.kubikaza_fini);
    printf("<tr>\n <th><b>Utroseno Grubog Sloja (m3)</b></th>\n <td>%1.2f m3</td> </tr>\n", izvestaj.kubikaza_grubi);
    printf("<tr>\n <th><b>Pesak</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.pesak);
    printf("<tr>\n <th><b>Kvarc</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.kvarc);
    printf("<tr>\n <th><b>Pesak Grubi</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.pesak_grubi);
    printf("<tr>\n <th><b>Dvojka</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.dvojka);
    printf("<tr>\n <th><b>Trojka</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.trojka);
    printf("<tr>\n <th><b>Eruptivac</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.eruptivac);
    printf("<tr>\n <th><b>Bazalt</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.bazalt);
    printf("<tr>\n <th><b>Arandjelovac Beli</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.arandjelovac_beli);
    printf("<tr>\n <th><b>Arandjelovac Crni</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.arandjelovac_crni);
    printf("<tr>\n <th><b>Silvergrey</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.silvergrey);
    printf("<tr>\n <th><b>Kvarc Krupni</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.kvarc_krupni);
    printf("<tr>\n <th><b>Antracit</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.antracit);
    printf("<tr id='BELA'>\n <th><b>Cement Beli</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.cement_beli);
    printf("<tr id='CEMENT_SIVI'>\n <th><b>Cement Sivi</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.cement_sivi);
    printf("<tr id='CEMENT_SIVI'>\n <th><b>Cement Sivi Grubi</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.cement_sivi_grubi);
    printf("<tr>\n <th><b>Rebafob</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.rebafob);
    printf("<tr>\n <th><b>Rebament</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.rebament);
    printf("<tr id='RUMENA'>\n <th><b>Boja Rumena</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.boja_rumena);
    printf("<tr id='CRNA'>\n <th><b>Boja Crna</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.boja_crna);
    printf("<tr id='BELA'>\n <th><b>Boja Bela</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.boja_bela);
    printf("<tr id='BRAON'>\n <th><b>Boja Braon</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.boja_braon);
    printf("<tr id='CRVENA'>\n <th><b>Boja Crvena</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.boja_crvena);
    printf("<tr id='ZUTA'>\n <th><b>Boja Zuta</b></th>\n <td>%1.2f kg</td> </tr>\n", izvestaj.boja_zuta);
    printf("<tr id='ZELENA'>\n <th><b>Boja Zelena</b></th>\n <td>%1.2f kg</td> </tr>\n<br><br>", izvestaj.boja_zelena);
    printf("</table><br><br>");
    
    printf("<center><b>Mesunzi</b>:</center>");
    printf("<table class='center_table'>\n");
    int ii = -1;
    
    while(true){
	ii++;
	printf("<tr>\n <th><b>%s</b></th>\n <td>%1.2f m3</td> </tr>\n", m[ii].ime, m[ii].kubikaza);
	if(ii == mi){
	    break;
	}
    }
    
    printf("</table>");
    printf("</body>");

END2:
    return 0;
}
