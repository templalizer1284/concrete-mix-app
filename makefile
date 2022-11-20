COMPILER = cc
DEBUG = -g -Og -Wall -pedantic -pedantic-errors -std=c2x
RELEASE = -O2 -Wall -pedantic -pedantic-errors -std=c2x
LIBRARIES = -I/usr/local/include -L/usr/local/lib/mysql -lmysqlclient

main:
	$(COMPILER) $(DEBUG) upisi_recept_fini_klasik_prana.c -o upisi_recept_fini_klasik_prana.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) upisi_recept_grubi.c -o upisi_recept_grubi.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) redirect.c -o redirect.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) upisi_recept_fini_colormixdva.c -o upisi_recept_fini_colormixdva.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) upisi_recept_fini_colormixtri.c -o upisi_recept_fini_colormixtri.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) napisi_izvestaj.c -o napisi_izvestaj.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) izracunaj.c -o izracunaj.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) index.c -o index.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) start.c -o start.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) upisi_recept.c -o upisi_recept.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) login.c -o login.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) obrisi_recept.c -o obrisi_recept.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) izmeni_recept.c -o izmeni_recept.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) pregled_izvestaj.c -o pregled_izvestaj.cgi $(LIBRARIES)
	$(COMPILER) $(DEBUG) odjavi.c -o odjavi.cgi $(LIBRARIES)
