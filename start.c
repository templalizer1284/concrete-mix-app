#include "wotan_tools.h"

int main(){

    w_html_prep;
    if(check_login() == false){
        
	goto END;
    }

    printf("<body>");
    char *content_style = w_load_file("../data/style.css");
    
    if(content_style == NULL){
	printf("Could not load CSS!<br>\n");
    }
    
    printf("<html><header>%s</header> <style>%s</style>", 
	   "<img src='/logo.png' alt='logo', class='logo'>",
	   content_style);
    free(content_style);

    h3(" ", "Recepti:" );
    check_login();
    w_button_url("/cgi-bin/upisi_recept.cgi", "Upisi");
    w_button_url("/cgi-bin/obrisi_recept.cgi", "Obrisi");
    w_button_url("/cgi-bin/izmeni_recept.cgi", "Izmeni");
    h3(" ", "Izvestaji: ");
    w_button_url("/cgi-bin/napisi_izvestaj.cgi", "Upisi");
    w_button_url("/cgi-bin/pregled_izvestaj.cgi", "Pregled");
    br; br;
    w_button_url("/cgi-bin/odjavi.cgi", "Odjavi se");
    printf("</body> </html>");


END:
    return 0;
}
