#include "wotan_tools.h"

int main(){

    char *cookie_data = getenv("HTTP_COOKIE");
    if(cookie_data == NULL){
	w_html_prep;
	goto CONTINUE;
    }
    w_strip(cookie_data, '=');
    char session_id[100];
    sscanf(cookie_data, "%*s %s", session_id);
    
    char delete_cookie[500];
    sprintf(delete_cookie, "id=%s; path=/; Expires=Fri, 01 Jan 1970 00:00:00 GMT", session_id);
    w_html_prep_cookie(delete_cookie);

CONTINUE:
    while(1){break;};
    
    char *css_style = w_load_file("../data/style.css");

    printf("<html> <header><style>%s</style></header><img src='/logo.png' alt='logo' class='logo'>", css_style);
    br;br;br;
    printf("<body>");
    div("style='text-align: center;'");
    h3(" ", "Prijava korisnika: ");
    printf("<form action='/cgi-bin/login.cgi' method='post'>");
    w_input("text", "placeholder='Korisnicko Ime' name='username'");
    br;br;
    w_input("password", "placeholder='Lozinka' name='password'");
    br;br;
    w_button("submit", "Prijava");
    br;
    
    cdiv;

    printf("</body> </html>");

    free(css_style);
    return 0;
}
