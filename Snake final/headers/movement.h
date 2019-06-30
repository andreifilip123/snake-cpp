//clasa pentru miscare
class movement{
public:
	void stanga(){
        int i,a,b;
        a=sarpe[lungime-1].x;
        b=sarpe[lungime-1].y;
        sarpe[0].y--;
        sarpe[0].c='<';
        capX=sarpe[0].x;
        capY=sarpe[0].y;
        for(i=lungime-1;i>=2;i--)
            {sarpe[i].x=sarpe[i-1].x;
            sarpe[i].y=sarpe[i-1].y;
            }
        sarpe[1].x=sarpe[0].x;
        sarpe[1].y=sarpe[0].y+1;
        sarpe[1].c='o';
        caseta[a][b]=' ';
        for(i=0;i<lungime;i++)
            caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
	void dreapta(){
        int i,a,b;
        a=sarpe[lungime-1].x;
        b=sarpe[lungime-1].y;
        sarpe[0].y++;
        sarpe[0].c='>';
        capX=sarpe[0].x;
        capY=sarpe[0].y;
        for(i=lungime-1;i>=2;i--)
            {sarpe[i].x=sarpe[i-1].x;
            sarpe[i].y=sarpe[i-1].y;
            }
        sarpe[1].x=sarpe[0].x;
        sarpe[1].y=sarpe[0].y-1;
        sarpe[1].c='o';
        caseta[a][b]=' ';
        for(i=0;i<lungime;i++)
            caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
	void sus(){
        int i,a,b;
        sarpe[0].x--;
        sarpe[0].c='^';
        a=sarpe[lungime-1].x;
        b=sarpe[lungime-1].y;
        capX=sarpe[0].x;
        capY=sarpe[0].y;
        for(i=lungime-1;i>=2;i--)
            {sarpe[i].x=sarpe[i-1].x;
            sarpe[i].y=sarpe[i-1].y;
            }
        sarpe[1].x=sarpe[0].x+1;
        sarpe[1].y=sarpe[0].y;
        sarpe[1].c='o';
        caseta[a][b]=' ';
        for(i=0;i<lungime;i++)
            caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
	void jos(){
        int i,a,b;
        a=sarpe[lungime-1].x;
        b=sarpe[lungime-1].y;
        sarpe[0].x++;
        sarpe[0].c='v';
        capX=sarpe[0].x;
        capY=sarpe[0].y;
        for(i=lungime-1;i>=2;i--)
            {sarpe[i].x=sarpe[i-1].x;
            sarpe[i].y=sarpe[i-1].y;
            }
        sarpe[1].x=sarpe[0].x-1;
        sarpe[1].y=sarpe[0].y;
        sarpe[1].c='o';
        caseta[a][b]=' ';
        for(i=0;i<lungime;i++)
            caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
}miscare;
