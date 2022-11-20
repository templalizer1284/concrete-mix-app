#include "wotan_tools.h"

int main(void){

    w_html_prep;

    if(check_login() == false){
	printf("Pristup zabranjen! Prijavi se prvo.<br>");
	w_button_url("/cgi-bin/index.cgi", "Na pocetnu");
	goto END;
    }

    MYSQL *sql_connection = mysql_init(NULL);

    if( mysql_real_connect( sql_connection,
			    "localhost",
			    "behaton",
			    "expansion123",
			    "transkop",
			    0,
			    NULL,
			    0) == NULL ){
	fprintf(stderr, "SQL Connection error: %s<br>", mysql_error(sql_connection));
	goto END;
    }

    ReceptKlasik r;
    char content[1000];
    
    fscanf(stdin, "%s", content);
    /* printf("%s", content); */

    char *token = NULL;
    char *delimiter = "&";

    token = strtok(content, delimiter);
    sscanf(token, "name=%s", r.ime);

    token = strtok(NULL, delimiter);
    sscanf(token, "pesak=%f", &r.pesak);

    token = strtok(NULL, delimiter);
    sscanf(token, "kvarc=%f", &r.kvarc);

    token = strtok(NULL, delimiter);
    sscanf(token, "bazalt=%f", &r.bazalt);

    token = strtok(NULL, delimiter);
    sscanf(token, "arandjelovac_beli=%f", &r.arandjelovac_beli);

    token = strtok(NULL, delimiter);
    sscanf(token, "arandjelovac_crni=%f", &r.arandjelovac_crni);

    token = strtok(NULL, delimiter);
    sscanf(token, "silvergrey=%f", &r.silvergrey);

    token = strtok(NULL, delimiter);
    sscanf(token, "kvarc_krupni=%f", &r.kvarc_krupni);

    token = strtok(NULL, delimiter);
    sscanf(token, "antracit=%f", &r.antracit);

    token = strtok(NULL, delimiter);
    sscanf(token, "cement_beli=%f", &r.cement_beli);

    token = strtok(NULL, delimiter);
    sscanf(token, "cement_sivi=%f", &r.cement_sivi);

    token = strtok(NULL, delimiter);
    sscanf(token, "rebafob=%f", &r.rebafob);

    token = strtok(NULL, delimiter);
    sscanf(token, "boja_rumena=%f", &r.boja_rumena);

    token = strtok(NULL, delimiter);
    sscanf(token, "boja_crna=%f", &r.boja_crna);

    token = strtok(NULL, delimiter);
    sscanf(token, "boja_bela=%f", &r.boja_bela);

    token = strtok(NULL, delimiter);
    sscanf(token, "boja_braon=%f", &r.boja_braon);

    token = strtok(NULL, delimiter);
    sscanf(token, "boja_crvena=%f", &r.boja_crvena);

    token = strtok(NULL, delimiter);
    sscanf(token, "boja_zuta=%f", &r.boja_zuta);

    token = strtok(NULL, delimiter);
    sscanf(token, "boja_zelena=%f", &r.boja_zelena);

    char sql_query[1000];
    sprintf(sql_query, "INSERT INTO recepti_klasik_prana (ime, pesak, kvarc, bazalt, arandjelovac_beli, arandjelovac_crni, silvergrey, kvarc_krupni, antracit, cement_beli, cement_sivi, rebafob, boja_rumena, boja_crna, boja_bela, boja_braon, boja_crvena, boja_zuta, boja_zelena) VALUES ('%s', %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f )",
	    r.ime,
	    r.pesak,
	    r.kvarc,
	    r.bazalt,
	    r.arandjelovac_beli,
	    r.arandjelovac_crni,
	    r.silvergrey,
	    r.kvarc_krupni,
	    r.antracit,
	    r.cement_beli,
	    r.cement_sivi,
	    r.rebafob,
	    r.boja_rumena,
	    r.boja_crna,
	    r.boja_bela,
	    r.boja_braon,
	    r.boja_crvena,
	    r.boja_zuta,
	    r.boja_zelena);

    if( mysql_real_query(sql_connection, sql_query, strlen(sql_query)) != 0){
	fprintf(stderr, "SQL Query error: %s<br>", mysql_error(sql_connection));
	goto END;
    }

    printf("Recept je upisan.<br>");
    w_button_url("/upisi_recept.html", "Nazad");

    mysql_close(sql_connection);
END:
    return 0;
}
