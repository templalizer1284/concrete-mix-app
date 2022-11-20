#include "wotan_tools.h"

int main(void){
    w_html_prep;
    char *content_style = w_load_file("../data/style.css");
    if(content_style == NULL){
	printf("Could not load CSS!<br>\n");
    }
    
    printf("<html><header>%s</header> <style>%s</style>",
	   "<img src='/logo.png' alt='logo', class='logo'>",
	   content_style);
    free(content_style);

    return 0;
}
