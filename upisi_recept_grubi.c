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

    ReceptGrubi r;

    char content[1000];
    if(fscanf(stdin, "%s", content) == EOF){
	fprintf(stderr, "%s", "Could not get page content.<br>");
    }

    /* printf("POST: %s<br><br>", content); */

    char *token = NULL;
    char *delimiter = "&";

    token = strtok(content, delimiter);
    sscanf(token, "name=%s", r.ime);
    
    token = strtok(NULL, delimiter);
    sscanf(token, "pesak=%f", &r.pesak);

    token = strtok(NULL, delimiter);
    sscanf(token, "dvojka=%f", &r.dvojka);

    token = strtok(NULL, delimiter);
    sscanf(token, "trojka=%f", &r.trojka);

    token = strtok(NULL, delimiter);
    sscanf(token, "eruptivac=%f", &r.eruptivac);

    token = strtok(NULL, delimiter);
    sscanf(token, "cement_sivi=%f", &r.cement_sivi);

    token = strtok(NULL, delimiter);
    sscanf(token, "cement_beli=%f", &r.cement_beli);
    
    token = strtok(NULL, delimiter);
    sscanf(token, "rebament=%f", &r.rebament);

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
    sprintf(sql_query, "INSERT INTO recepti_grubi ( ime, pesak, dvojka, trojka, eruptivac, cement_sivi, cement_beli, rebament, boja_rumena, boja_crna, boja_bela, boja_braon, boja_crvena, boja_zuta, boja_zelena) VALUES ('%s', %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f ); ",
	    r.ime,

	    r.pesak,
	    r.dvojka,
	    r.trojka,
	    r.eruptivac,
	    r.cement_sivi,
	    r.cement_beli,
	    r.rebament,
	    r.boja_rumena,
	    r.boja_crna,
	    r.boja_bela,
	    r.boja_braon,
	    r.boja_crvena,
	    r.boja_zuta,
	    r.boja_zelena);

    /* printf("Query: %s<br>", sql_query); */
    if( (mysql_real_query(sql_connection, sql_query, strlen(sql_query))) != 0 ){
	fprintf(stderr, "SQL query error. %s", mysql_error(sql_connection));
    }

    printf("Recept je upisan.<br>");
    w_button_url("/upisi_recept.html", "Nazad");

    mysql_close(sql_connection);
END:   
    return 0;
}
