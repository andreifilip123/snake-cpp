//variabile globale
struct coord{
        char c;
        int x,y;
    };
struct elem_leaderboard{
	char nume[30];
	int scor;
}s[30],aux;
int width=30,height=15;
char caseta[15][30];
int capX,capY,pctX,pctY;
int lungime;
int nr_pct;
int nr_elem_fisier;
coord sarpe[200];
enum directii { STOP=0,UP,DOWN,LEFT,RIGHT};
directii dir;
bool gameover;
char meniu[15][30];
