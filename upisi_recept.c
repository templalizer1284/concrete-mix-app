#include "wotan_tools.h"

/* NEEDS COMPLETE REWORK IN C */

int main(void){
    w_html_prep;

    if(check_login() == false){
	printf("Pristup zabranjen! Prijavi se prvo.<br>");
	w_button_url("/cgi-bin/index.cgi", "Na pocetnu");
	goto END;
    }
    
    /* char *content_style = w_load_file("../data/style.css"); */
    /* if(content_style == NULL){ */
    /* 	printf("Could not load CSS!<br>\n"); */
    /* } */
    
    /* printf("<html><header>%s</header> <style>%s</style>", */
    /* 	   "<img src='/logo.png' alt='logo', class='logo'>", */
    /* 	   content_style); */

    char *page = w_load_file("../data/upisi_recept.html");
    if(page == NULL){
	printf("Could not load page!<br>\n");
    }
    
    printf("%s", page);

END:
    return 0;
}
