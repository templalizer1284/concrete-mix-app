#include "wotan_tools.h"

int main(void){

    w_html_prep;

    if(check_login() == false){
	printf("Pristup zabranjen! Prijavi se prvo.<br>");
	w_button_url("/cgi-bin/index.cgi", "Na pocetnu");
	goto END;
    }

    MYSQL *sql_connection = mysql_init(NULL);

    if( mysql_real_connect(sql_connection,
			   "localhost",
			   "behaton",
			   "expansion123",
			   "transkop",
			   0,
			   NULL,
			   0) == NULL ){
	fprintf(stderr, "SQL connection error: %s<br>", mysql_error(sql_connection));
	goto END;
    }

    char sql_query_fini[1000] = "SELECT ime FROM recepti_klasik_prana;";

    if( mysql_real_query(sql_connection, sql_query_fini, strlen(sql_query_fini)) != 0 ){
	fprintf(stderr, "SQL connection error: %s<br>", mysql_error(sql_connection));
	goto END;
    }

    char *content_style = w_load_file("../data/style.css");
    if( content_style == NULL ){
	printf("Could not load CSS!<br>\n");
    }

    printf("<html><header>%s</header> <style>%s</style>",
	   "<img src='/logo.png' alt='logo', class='logo'>",
	   content_style);

    free(content_style);

    printf("<h3 style='color: #FF0000'>Unosi kubikazu. (m3)</h3><br>");

    MYSQL_RES *result = NULL;
    result = mysql_store_result(sql_connection);

    if(result == NULL){
	fprintf(stderr, "SQL error: %s<br>", mysql_error(sql_connection));
	goto END;
    }

    int num_fields = mysql_num_fields(result);
    
    MYSQL_ROW row_klasik_prana;

    printf("<body>");
    w_button_url("/cgi-bin/start.cgi", "Nazad");

    printf("<form method='post' action='/cgi-bin/izracunaj.cgi'>");
    printf("<h3>Klasik/Prana</h3><br><br>");

    while((row_klasik_prana = mysql_fetch_row(result))){
	for(int i = 0; i < num_fields; i++){
	    printf("%s <input type='number' step='0.01' placeholder='Kolicina (m3)' name='%s' value='0' required><br>\n",
		   row_klasik_prana[i], row_klasik_prana[i]);
	}
    }
    
    mysql_free_result(result);
    printf("<br>");

    char query_colormix2[1000] = "SELECT ime FROM recepti_colormix2;";

    if( mysql_real_query(sql_connection, query_colormix2, strlen(query_colormix2)) != 0 ){
	sql_err(sql_connection);
    }

    MYSQL_RES *result_colormix2 = mysql_store_result(sql_connection);
    int fields_colormix2 = mysql_num_fields(result_colormix2);

    MYSQL_ROW data_colormix2;

    printf("<h3>Colormix 2</h3><br><br>");
    while( (data_colormix2 = mysql_fetch_row(result_colormix2)) ){
	for(int i = 0; i < fields_colormix2; i++){
	    printf("%s <input type='number' step='0.01' placeholder='Kolicina (m3)' name='%s' value='0' required><br>\n",
		   data_colormix2[i], data_colormix2[i]);
	}
    }
    
    mysql_free_result(result_colormix2);
    printf("<br>");

    printf("<h3>Colormix 3</h3>");

    char query_colormix3[1000] = "SELECT ime FROM recepti_colormix3;";
    if( mysql_real_query(sql_connection, query_colormix3, strlen(query_colormix3)) != 0 ){
	sql_err(sql_connection);
    }

    MYSQL_RES *result_colormix3 = mysql_store_result(sql_connection);
    int fields_colormix3 = mysql_num_fields(result_colormix3);

    MYSQL_ROW data_colormix3;

    while( (data_colormix3 = mysql_fetch_row(result_colormix3)) ){
	for(int i = 0; i < fields_colormix3; i++){
	    printf("%s <input type='number' step='0.01' placeholder='Kolicina (m3)' name='%s' value='0' required><br>\n",
		   data_colormix3[i], data_colormix3[i]);
	}
    }

    mysql_free_result(result_colormix3);
    printf("<br>");
    
    printf("<h3>Grubi Sloj</h3><br>");
    mysql_free_result(result);

    char sql_query_grubi[1000] = "SELECT ime FROM recepti_grubi;";
    
    if( mysql_real_query(sql_connection, sql_query_grubi, strlen(sql_query_grubi)) != 0){
	fprintf(stderr, "SQL error: %s<br>", mysql_error(sql_connection));
    }

    result = mysql_store_result(sql_connection);
    
    MYSQL_ROW row_grubi;

    num_fields = mysql_num_fields(result);
    
    while((row_grubi = mysql_fetch_row(result))){
	for(int i = 0; i < num_fields; i++){	
	    printf("%s <input type='number' step='0.01' placeholder='Kolicina (m3)' name='%s' value='0' required><br>",
		   row_grubi[i], row_grubi[i]);
	}
    }
    printf("<button type='submit'>Izracunaj</button><br>");
    printf("</form><br>");
    printf("</body> </html>");
    mysql_close(sql_connection);
END:
    return 0;
}
