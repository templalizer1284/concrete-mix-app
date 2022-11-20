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

    ReceptColormix3 r;

    char content[5000];
    if(fscanf(stdin, "%s", content) == EOF){
	fprintf(stderr, "%s", "Could not get page content.<br>");
    }

    /* printf("POST: %s<br><br>", content); */

    char *token = NULL;
    char *separator = "&";

    token = strtok(content, separator);
    sscanf(token, "name=%s", r.ime);

    token = strtok(NULL, separator);
    sscanf(token, "percentage_first=%f", &r.percentage_first);

    token = strtok(NULL, separator);
    sscanf(token, "percentage_second=%f", &r.percentage_second);

    token = strtok(NULL, separator);
    sscanf(token, "percentage_third=%f", &r.percentage_third);
    
    token = strtok(NULL, separator);
    sscanf(token, "pesak=%f", &r.pesak);

    token = strtok(NULL, separator);
    sscanf(token, "pesak2=%f", &r.pesak2);

    token = strtok(NULL, separator);
    sscanf(token, "pesak3=%f", &r.pesak3);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc=%f", &r.kvarc);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc2=%f", &r.kvarc2);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc3=%f", &r.kvarc3);

    token = strtok(NULL, separator);
    sscanf(token, "bazalt=%f", &r.bazalt);
    
    token = strtok(NULL, separator);
    sscanf(token, "bazalt2=%f", &r.bazalt2);

    token = strtok(NULL, separator);
    sscanf(token, "bazalt3=%f", &r.bazalt3);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_beli=%f", &r.arandjelovac_beli);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_beli2=%f", &r.arandjelovac_beli2);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_beli3=%f", &r.arandjelovac_beli3);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_crni=%f", &r.arandjelovac_crni);
    
    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_crni2=%f", &r.arandjelovac_crni2);

    token = strtok(NULL, separator);
    sscanf(token, "arandjelovac_crni3=%f", &r.arandjelovac_crni3);

    token = strtok(NULL, separator);
    sscanf(token, "silvergrey=%f", &r.silvergrey);

    token = strtok(NULL, separator);
    sscanf(token, "silvergrey2=%f", &r.silvergrey2);
    
    token = strtok(NULL, separator);
    sscanf(token, "silvergrey3=%f", &r.silvergrey3);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc_krupni=%f", &r.kvarc_krupni);
   
    token = strtok(NULL, separator);
    sscanf(token, "kvarc_krupni2=%f", &r.kvarc_krupni2);

    token = strtok(NULL, separator);
    sscanf(token, "kvarc_krupni3=%f", &r.kvarc_krupni3);

    token = strtok(NULL, separator);
    sscanf(token, "antracit=%f", &r.antracit);

    token = strtok(NULL, separator);
    sscanf(token, "antracit2=%f", &r.antracit2);

    token = strtok(NULL, separator);
    sscanf(token, "antracit3=%f", &r.antracit3);

    token = strtok(NULL, separator);
    sscanf(token, "cement_beli=%f", &r.cement_beli);

    token = strtok(NULL, separator);
    sscanf(token, "cement_beli2=%f", &r.cement_beli2);

    token = strtok(NULL, separator);
    sscanf(token, "cement_beli3=%f", &r.cement_beli3);

    token = strtok(NULL, separator);
    sscanf(token, "cement_sivi=%f", &r.cement_sivi);

    token = strtok(NULL, separator);
    sscanf(token, "cement_sivi2=%f", &r.cement_sivi2);

    token = strtok(NULL, separator);
    sscanf(token, "cement_sivi3=%f", &r.cement_sivi3);
    
    token = strtok(NULL, separator);
    sscanf(token, "rebafob=%f", &r.rebafob);

    token = strtok(NULL, separator);
    sscanf(token, "rebafob2=%f", &r.rebafob2);

    token = strtok(NULL, separator);
    sscanf(token, "rebafob3=%f", &r.rebafob3);

    token = strtok(NULL, separator);
    sscanf(token, "boja_rumena=%f", &r.boja_rumena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_rumena2=%f", &r.boja_rumena2);

    token = strtok(NULL, separator);
    sscanf(token, "boja_rumena3=%f", &r.boja_rumena3);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crna=%f", &r.boja_crna);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crna2=%f", &r.boja_crna2);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crna3=%f", &r.boja_crna3);

    token = strtok(NULL, separator);
    sscanf(token, "boja_bela=%f", &r.boja_bela);

    token = strtok(NULL, separator);
    sscanf(token, "boja_bela2=%f", &r.boja_bela2);

    token = strtok(NULL, separator);
    sscanf(token, "boja_bela3=%f", &r.boja_bela3);

    token = strtok(NULL, separator);
    sscanf(token, "boja_braon=%f", &r.boja_braon);

    token = strtok(NULL, separator);
    sscanf(token, "boja_braon2=%f", &r.boja_braon2);

    token = strtok(NULL, separator);
    sscanf(token, "boja_braon3=%f", &r.boja_braon3);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crvena=%f", &r.boja_crvena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crvena2=%f", &r.boja_crvena2);

    token = strtok(NULL, separator);
    sscanf(token, "boja_crvena3=%f", &r.boja_crvena3);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zuta=%f", &r.boja_zuta);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zuta2=%f", &r.boja_zuta2);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zuta3=%f", &r.boja_zuta3);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zelena=%f", &r.boja_zelena);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zelena2=%f", &r.boja_zelena2);

    token = strtok(NULL, separator);
    sscanf(token, "boja_zelena3=%f", &r.boja_zelena3);
    
    char sql_query[5000];

    sprintf(sql_query, "INSERT INTO recepti_colormix3 (ime, percentage_first, percentage_second, percentage_third, pesak, pesak2, pesak3, kvarc, kvarc2, kvarc3, bazalt, bazalt2, bazalt3, arandjelovac_beli, arandjelovac_beli2, arandjelovac_beli3, arandjelovac_crni, arandjelovac_crni2, arandjelovac_crni3, silvergrey, silvergrey2, silvergrey3, kvarc_krupni, kvarc_krupni2, kvarc_krupni3, antracit, antracit2, antracit3, cement_beli, cement_beli2, cement_beli3, cement_sivi, cement_sivi2, cement_sivi3, rebafob, rebafob2, rebafob3, boja_rumena, boja_rumena2, boja_rumena3, boja_crna, boja_crna2, boja_crna3, boja_bela, boja_bela2, boja_bela3, boja_braon, boja_braon2, boja_braon3, boja_crvena, boja_crvena2, boja_crvena3, boja_zuta, boja_zuta2, boja_zuta3, boja_zelena, boja_zelena2, boja_zelena3) VALUES ('%s', %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f);",
	    r.ime,
	    r.percentage_first,
	    r.percentage_second,
	    r.percentage_third,
	    r.pesak,
	    r.pesak2,
	    r.pesak3,
	    r.kvarc,
	    r.kvarc2,
	    r.kvarc3,
	    r.bazalt,
	    r.bazalt2,
	    r.bazalt3,
	    r.arandjelovac_beli,
	    r.arandjelovac_beli2,
	    r.arandjelovac_beli3,
	    r.arandjelovac_crni,
	    r.arandjelovac_crni2,
	    r.arandjelovac_crni3,
	    r.silvergrey,
	    r.silvergrey2,
	    r.silvergrey3,
	    r.kvarc_krupni,
	    r.kvarc_krupni2,
	    r.kvarc_krupni3,
	    r.antracit,
	    r.antracit2,
	    r.antracit3,
	    r.cement_beli,
	    r.cement_beli2,
	    r.cement_beli3,
	    r.cement_sivi,
	    r.cement_sivi2,
	    r.cement_sivi3,
	    r.rebafob,
	    r.rebafob2,
	    r.rebafob3,
	    r.boja_rumena,
	    r.boja_rumena2,
	    r.boja_rumena3,
	    r.boja_crna,
	    r.boja_crna2,
	    r.boja_crna3,
	    r.boja_bela,
	    r.boja_bela2,
	    r.boja_bela3,
	    r.boja_braon,
	    r.boja_braon2,
	    r.boja_braon3,
	    r.boja_crvena,
	    r.boja_crvena2,
	    r.boja_crvena3,
	    r.boja_zuta,
	    r.boja_zuta2,
	    r.boja_zuta3,
	    r.boja_zelena,
	    r.boja_zelena2,
	    r.boja_zelena3);

    /* printf("QUERY: %s", sql_query); */
    if( (mysql_real_query(sql_connection, sql_query, strlen(sql_query))) != 0 ){
	fprintf(stderr, "SQL query error. %s", mysql_error(sql_connection));
    }

    printf("Recept je upisan.<br>");
    w_button_url("/upisi_recept.html", "Nazad");

    mysql_close(sql_connection);
END:
    return 0;
}
