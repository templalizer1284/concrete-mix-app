#include "wotan_tools.h"

int main(void){

    w_html_prep;

    if(check_login() == false){
	printf("Pristup zabranjen! Prijavi se prvo.<br>");
	w_button_url("/cgi-bin/index.cgi", "Na pocetnu");
	goto END;
    }

    MYSQL *sql_connection = mysql_init(NULL);
    if(mysql_real_connect(sql_connection,
			  "localhost",
			  "behaton",
			  "expansion123",
			  "transkop",
			  0,
			  NULL,
			  0) == NULL){
	fprintf(stderr, "Error occured. Could not connect to SQL database.<br> %s<br>", mysql_error(sql_connection));
	goto END;
    }

    ReceptKlasik r,r2;
    float percentage_first, percentage_second;

    char content[5000];
    if(fscanf(stdin, "%s", content) == EOF){
	fprintf(stderr, "%s", "Could not get page content.<br>");
    }

    printf("POST: %s<br><br>", content);

    char *token = NULL;
    char *separator = "&";

    token = strtok(content, separator);
    sscanf(token, "name=%s", r.ime);

    token = strtok(NULL, separator);
    sscanf(token, "percentage_first=%f", &percentage_first);

    token = strtok(NULL, separator);
    sscanf(token, "percentage_second=%f", &percentage_second);

    token = strtok(NULL, separator);
    sscanf(token, "pesak=%f", &r.pesak);

    token = strtok(NULL, separator);
    sscanf(token, "pesak2=%f", &r2.pesak);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc=%f", &r.kvarc);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc2=%f", &r2.kvarc);

    token = strtok(NULL, separator);
    sscanf(token, "bazalt=%f", &r.bazalt);
    
    token = strtok(NULL, separator);
    sscanf(token, "bazalt2=%f", &r2.bazalt);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_beli=%f", &r.arandjelovac_beli);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_beli2=%f", &r2.arandjelovac_beli);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_crni=%f", &r.arandjelovac_crni);
    
    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_crni2=%f", &r2.arandjelovac_crni);

    token = strtok(NULL, separator);
    sscanf(token, "silvergrey=%f", &r.silvergrey);

    token = strtok(NULL, separator);
    sscanf(token, "silvergrey2=%f", &r2.silvergrey);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc_krupni=%f", &r.kvarc_krupni);
   
    token = strtok(NULL, separator);
    sscanf(token, "kvarc_krupni2=%f", &r2.kvarc_krupni);

    token = strtok(NULL, separator);
    sscanf(token, "antracit=%f", &r.antracit);

    token = strtok(NULL, separator);
    sscanf(token, "antracit2=%f", &r2.antracit);

    token = strtok(NULL, separator);
    sscanf(token, "cement_beli=%f", &r.cement_beli);

    token = strtok(NULL, separator);
    sscanf(token, "cement_beli2=%f", &r2.cement_beli);

    token = strtok(NULL, separator);
    sscanf(token, "cement_sivi=%f", &r.cement_sivi);

    token = strtok(NULL, separator);
    sscanf(token, "cement_sivi2=%f", &r2.cement_sivi);

    
    token = strtok(NULL, separator);
    sscanf(token, "rebafob=%f", &r.rebafob);

    token = strtok(NULL, separator);
    sscanf(token, "rebafob2=%f", &r2.rebafob);

    token = strtok(NULL, separator);
    sscanf(token, "boja_rumena=%f", &r.boja_rumena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_rumena2=%f", &r2.boja_rumena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crna=%f", &r.boja_crna);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crna2=%f", &r2.boja_crna);

    token = strtok(NULL, separator);
    sscanf(token, "boja_bela=%f", &r.boja_bela);

    token = strtok(NULL, separator);
    sscanf(token, "boja_bela2=%f", &r2.boja_bela);

    token = strtok(NULL, separator);
    sscanf(token, "boja_braon=%f", &r.boja_braon);

    token = strtok(NULL, separator);
    sscanf(token, "boja_braon2=%f", &r2.boja_braon);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crvena=%f", &r.boja_crvena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crvena2=%f", &r2.boja_crvena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zuta=%f", &r.boja_zuta);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zuta2=%f", &r2.boja_zuta);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zelena=%f", &r.boja_zelena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zelena2=%f", &r2.boja_zelena);
    
    char sql_query[5000];

    sprintf(sql_query, "INSERT INTO recepti_colormix2 (ime, percentage_first, percentage_second, pesak, pesak2, kvarc, kvarc2, bazalt, bazalt2, arandjelovac_beli, arandjelovac_beli2, arandjelovac_crni, arandjelovac_crni2, silvergrey, silvergrey2, kvarc_krupni, kvarc_krupni2, antracit, antracit2, cement_beli, cement_beli2, cement_sivi, cement_sivi2, rebafob, rebafob2, boja_rumena, boja_rumena2, boja_crna, boja_crna2, boja_bela, boja_bela2, boja_braon, boja_braon2, boja_crvena, boja_crvena2, boja_zuta, boja_zuta2, boja_zelena, boja_zelena2) VALUES ('%s', %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f );",
	    r.ime,
	    percentage_first,
	    percentage_second,
	    r.pesak,
	    r2.pesak,
	    r.kvarc,
	    r2.kvarc,
	    r.bazalt,
	    r2.bazalt,
	    r.arandjelovac_beli,
	    r2.arandjelovac_beli,
	    r.arandjelovac_crni,
	    r2.arandjelovac_crni,
	    r.silvergrey,
	    r2.silvergrey,
	    r.kvarc_krupni,
	    r2.kvarc_krupni,
	    r.antracit,
	    r2.antracit,
	    r.cement_beli,
	    r2.cement_beli,
	    r.cement_sivi,
	    r2.cement_sivi,
	    r.rebafob,
	    r2.rebafob,
	    r.boja_rumena,
	    r2.boja_rumena,
	    r.boja_crna,
	    r2.boja_crna,
	    r.boja_bela,
	    r2.boja_bela,
	    r.boja_braon,
	    r2.boja_braon,
	    r.boja_crvena,
	    r2.boja_crvena,
	    r.boja_zuta,
	    r2.boja_zuta,
	    r.boja_zelena,
	    r2.boja_zelena);
    	
    if( (mysql_real_query(sql_connection, sql_query, strlen(sql_query))) != 0 ){
	fprintf(stderr, "SQL query error. %s", mysql_error(sql_connection));
    }

    printf("Recept je upisan.<br>");
    w_button_url("/upisi_recept.html", "Nazad");

    mysql_close(sql_connection);
END:
    return 0;
}
