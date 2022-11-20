#include "wotan_tools.h"

int main(void){

    sleep(5); /* stupid bruteforce protection x) */
    
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

    char content[1000];
    fscanf(stdin, "%s", content);

    char *token = NULL;
    char *del = "&";

    char username[50];
    char password[50];

    token = strtok(content, del);
    sscanf(token, "username=%s", username);

    token = strtok(NULL, del);
    sscanf(token, "password=%s", password);

    char check_query[1000];
    sprintf(check_query, "SELECT username,password FROM users WHERE username=\"%s\";", username);

    if( (mysql_real_query(sql_connection,
			  check_query,
			  strlen(check_query))) != 0)  {
	sql_err(sql_connection);
	goto END;
    }

    MYSQL_RES *result = mysql_store_result(sql_connection);
    if(result == NULL){
	sql_err(sql_connection);
	goto END;
    }

    int fields = mysql_num_fields(result);

    MYSQL_ROW data;

    char username_check[50];
    char password_check[50];

    char *style = w_load_file("../data/style.css");
    
    while( (data = mysql_fetch_row(result)) ){
	for(int i = 0; i < fields; i++){
	    sprintf(username_check, "%s", data[i]);
	    i++;
	    sprintf(password_check, "%s", data[i]);
	}
    }
    
    if( (strcmp(username, username_check)) != 0 ){
	w_html_prep;
	printf("Pogresni podaci.<br>");
	w_button_url("/cgi-bin/index.cgi", "Nazad");
	goto END;
    }

    if( (strcmp(password, password_check)) != 0 ){
	w_html_prep;
	printf("Pogresni podaci.<br>");
	w_button_url("/cgi-bin/index.cgi", "Nazad");
	goto END;
    } else{
	mysql_free_result(result);
       
	char register_session[100];
	char *session_id = w_generate_id();
	sprintf(register_session, "INSERT INTO cookies (session_id,username) VALUES (\"%s\", \"%s\");", session_id, username);

	if( mysql_real_query(sql_connection, register_session, strlen(register_session)) != 0){
	    sql_err(sql_connection);
	    mysql_free_result(result);
	    mysql_close(sql_connection);
	    goto END;
	}

	/* set expire for 30 mins */
	/* time_t now = time(NULL); */
	/* struct tm *tm_struct = localtime(&now); */

	/* int hour = tm_struct->tm_hour; */
	/* int min = tm_struct->tm_min; */

	/* if( (tm_min + 30) > 59 ){ */
	/*     tm_hour += 1; */
	/*     tm_min = (t_min + 30) - 60; */
	/* } */
	
	char cookie_data[100];
	sprintf(cookie_data, "id=%s; path=/; Max-Age=1800", session_id );
	free(session_id);

	w_html_prep_cookie(cookie_data);
    }

    mysql_free_result(result);

    printf("<html> <header><style>%s</style></header><img src='/logo.png' class='logo' alt='logo'> <body>", style);

    printf("Uspesna prijava!");
    w_button_url("/cgi-bin/start.cgi", "Potvrdi");

    printf("</body></html>");
    mysql_close(sql_connection);
END:
    return 0;
}
