#include "wotan_tools.h"

int main(){
    
    w_html_prep;
    
    if(check_login() == false){
	printf("Pristup zabranjen! Prijavi se prvo.<br>");
	w_button_url("/cgi-bin/index.cgi", "Na pocetnu");
	goto END;
    }
	
    MYSQL *sql_connection = mysql_init(NULL);

    if( (mysql_real_connect(sql_connection,
			    "localhost",
			    "behaton",
			    "expansion123",
			    "transkop",
			    0,
			    NULL,
			    0)) == NULL){
	sql_err(sql_connection);
    }

    char *cookie_data = getenv("HTTP_COOKIE");

    w_strip(cookie_data, '=');

    char session_id[100];
    sscanf(cookie_data, "%*s %s", session_id);
    
    char query[100];
    sprintf(query, "DELETE FROM cookies WHERE session_id='%s';", session_id);
    

    if( (mysql_real_query(sql_connection, query, strlen(query))) != 0){
	sql_err(sql_connection);
    }

    mysql_close(sql_connection);

    char *css_style = w_load_file("../data/style.css");

    printf("<html> <header><style>%s</style></header><img src='/logo.png' alt='logo' class='logo'>", css_style);
    br;br;br;
    printf("<body>");
    printf("VAL: %s<br>", session_id);
    printf("Odjava je uspesna.<br>");
    w_button_url("/cgi-bin/index.cgi", "Potvrdi");
    printf("</body></html>");

END:
    return 0;
}
