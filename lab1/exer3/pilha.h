typedef struct _tPilha tPilha;

tPilha *iniciaPilha();
void insereOperando(tPilha *p, double op);
void insereOperador(tPilha *p, char op);
double retiraOperando(tPilha *p);
char retiraOperador(tPilha *p);
void destroiPilha(tPilha *p);