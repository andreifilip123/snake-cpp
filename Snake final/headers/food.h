//clasa pentru mancare
class food{
public:
	void generare(){
        int a,b,test,i;
        do{
            test=1;
            a=rand() % (height-2)+1;
            b=rand() % (width-2)+1;
            for(i=1;i<lungime;i++)
                if(a==sarpe[i].x&&b==sarpe[i].y)
                    test=0;
        }while(test==0);
        caseta[a][b]='O';
        caseta[a][b]='O';
		pctX=a;
		pctY=b;
    }
	void stanga(){
        int i;
        for(i=lungime;i>=1;i--)
                    {sarpe[i].x=sarpe[i-1].x;
                     sarpe[i].y=sarpe[i-1].y;
                     sarpe[i].c=sarpe[i-1].c;}
                sarpe[1].c='o';
                sarpe[0].c='<';
                sarpe[0].x=capX;
                sarpe[0].y=capY-1;
                for(i=0;i<lungime;i++)
                    caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
    void dreapta(){
        int i;
        for(i=lungime;i>=1;i--)
            {sarpe[i].x=sarpe[i-1].x;
             sarpe[i].y=sarpe[i-1].y;
             sarpe[i].c=sarpe[i-1].c;}
        sarpe[1].c='o';
        sarpe[0].c='>';
        sarpe[0].x=capX;
        sarpe[0].y=capY+1;
        for(i=0;i<lungime;i++)
            caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
    void sus(){
        int i;
        for(i=lungime;i>=1;i--)
            {sarpe[i].x=sarpe[i-1].x;
             sarpe[i].y=sarpe[i-1].y;
             sarpe[i].c=sarpe[i-1].c;}
        sarpe[1].c='o';
        sarpe[0].c='^';
        sarpe[0].x=capX-1;
        sarpe[0].y=capY;
        for(i=0;i<lungime;i++)
            caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
    void jos(){
        int i;
        for(i=lungime;i>=1;i--)
            {sarpe[i].x=sarpe[i-1].x;
             sarpe[i].y=sarpe[i-1].y;
             sarpe[i].c=sarpe[i-1].c;}
        sarpe[1].c='o';
        sarpe[0].c='v';
        sarpe[0].x=capX+1;
        sarpe[0].y=capY;
        for(i=0;i<lungime;i++)
            caseta[sarpe[i].x][sarpe[i].y]=sarpe[i].c;
    }
	int mancat(){
        if(caseta[pctX][pctY]==' '||caseta[pctX][pctY]=='^'||caseta[pctX][pctY]=='v'||caseta[pctX][pctY]=='<'||caseta[pctX][pctY]=='>'||caseta[pctX][pctY]=='o')
			{lungime++;nr_pct++;return 1;}
		else {return 0;}
    }
}mancare;
