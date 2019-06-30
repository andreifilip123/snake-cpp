//clasa principala
class snake{
public:
    snake(){
        dir= STOP;
		nr_pct=0;
		lungime=3;
        gameover=false;
        int i,j;
        for(i=0;i<height;i++)
            {for(j=0;j<width;j++)
                {caseta[i][j]=' ';
                 if(i==0||i==height-1)
                    caseta[i][j]=205;
                 if(j==0||j==width-1)
                    caseta[i][j]=186;
                }
            }
        caseta[0][0]=201;
        caseta[height-1][0]=200;
        caseta[0][width-1]=187;
        caseta[height-1][width-1]=188;
        srand(time(NULL));
        capX=rand() % (height-1)+1;
        capY=rand() % (width-1)+1;
        caseta[capX][capY]='+';
        sarpe[0].c='+';
        sarpe[0].x=capX;
        sarpe[0].y=capY;
        int r=rand() % 2;
        if(r==1)
            gen_snake_orizontala();
        else
            gen_snake_verticala();
    }
    void gen_snake_verticala(){
        int test=0,i;//cap in sus
        if(capX<height-5&&capX+2<=height-3)
             {
                 for(i=1;i<lungime;i++)
                    {caseta[capX+i][capY]='o';
                    sarpe[i].c=caseta[capX+i][capY];
                    sarpe[i].x=capX+i;
                    sarpe[i].y=capY;
                    }
                 test=1;
                 caseta[capX][capY]='^';
             }
        else
            if(test==0)//cap in jos
                if(capX>=height-4&&capX-2>1)
                    {
                        for(i=1;i<lungime;i++)
                            {caseta[capX-i][capY]='o';
                            sarpe[i].c=caseta[capX-i][capY];
                            sarpe[i].x=capX-i;
                            sarpe[i].y=capY;
                            }
                        test=1;
                        caseta[capX][capY]='v';
                    }
    }
    void gen_snake_orizontala(){
        int test=0,i;//cap in stanga
         if(capY<width-4&&capY+2<=width-2)
            {
                for(i=1;i<lungime;i++)
                    {caseta[capX][capY+i]='o';
                    sarpe[i].c=caseta[capX][capY+i];
                    sarpe[i].x=capX;
                    sarpe[i].y=capY+i;
                    }
                test=1;
                caseta[capX][capY]='<';
             }
        else
            if(test==0)//cap in dreapta
                if(capY>=width-4&&capY-2>1)
                    {
                        for(i=1;i<lungime;i++)
                            {caseta[capX][capY-i]='o';
                            sarpe[i].c=caseta[capX][capY-1];
                            sarpe[i].x=capX;
                            sarpe[i].y=capY-i;}
                        test=1;
                        caseta[capX][capY]='>';
                    }
    }
    void afisare(){
        int i,j;
        system("cls");
        for(i=0;i<height;i++)
            {for(j=0;j<width;j++)
                cout<<caseta[i][j];
            cout<<endl;
            }
		cout<<endl;
		cout<<"\tScor:"<<nr_pct;
    }
    void citire(){
        if(_kbhit())
            switch(_getch())
            {
            case 'w':
                {dir=UP;sarpe[0].c='^';break;}
            case 's':
                {dir=DOWN;sarpe[0].c='v';break;}
            case 'a':
                {dir=LEFT;sarpe[0].c='<';break;}
            case 'd':
                {dir=RIGHT;sarpe[0].c='>';break;}
            case 'x':
                {cout<<endl<<"Ai apasat x asa ca jocul se va inchide"<<endl;getch();system("cls");gameover=true;break;}
            }
    }
	void misc(){
        perete();
		switch(dir){
        case UP:{
                coord next_element=next(dir);
                if(cap.jos()!=true)
                {
                    if(coada(next_element)==true)
                    {
                        cout<<endl<<endl<<"Te-ai lovit de coada ! Ai murit !"<<endl;
						if(fisier.verificare_scor(nr_pct)!=-1)
						{
							elem_leaderboard scor_nou;
							cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
							cout<<"Introdu-ti numele :";
							cin>>scor_nou.nume;
							scor_nou.scor=nr_pct;
							fisier.inserare_in_fisier(scor_nou);
						}
                        getch();
                        system("cls");
                        gameover=true;
                        break;
                    }
                    else
                    {
                        if(caseta[capX-1][capY]=='O')
                        {
                            mancare.sus();
                            break;
                        }
                        else
                        {
                            miscare.sus();
                            break;
                        }
                    }
                }
            }
        case DOWN:{
			    coord next_element=next(dir);
                if(cap.sus()!=true)
                {
                    if(coada(next_element)==true)
                    {
                        cout<<endl<<endl<<"Te-ai lovit de coada ! Ai murit !"<<endl;
						if(fisier.verificare_scor(nr_pct)!=-1)
						{
							elem_leaderboard scor_nou;
							cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
							cout<<"Introdu-ti numele :";
							cin>>scor_nou.nume;
							scor_nou.scor=nr_pct;
							fisier.inserare_in_fisier(scor_nou);
						}
                        getch();
                        system("cls");
                        gameover=true;
                        break;
                    }
                    else
                    {
                        if(caseta[capX+1][capY]=='O')
                        {
                            mancare.jos();
                            break;
                        }
                        else
                        {
                            miscare.jos();
                            break;
                        }
                    }
                }
			}
        case LEFT:{
                coord next_element=next(dir);
                if(cap.dreapta()!=true)
                {
                    if(coada(next_element)==true)
                    {
                        cout<<endl<<endl<<"Te-ai lovit de coada ! Ai murit !"<<endl;
                        if(fisier.verificare_scor(nr_pct)!=-1)
						{
							elem_leaderboard scor_nou;
							cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
							cout<<"Introdu-ti numele :";
							cin>>scor_nou.nume;
							scor_nou.scor=nr_pct;
							fisier.inserare_in_fisier(scor_nou);
						}
						getch();
                        system("cls");
                        gameover=true;
                        break;
                    }
                    else
                    {
                        if(caseta[capX][capY-1]=='O')
                        {
                            mancare.stanga();
                            break;
                        }
                        else
                        {
                            miscare.stanga();
                            break;
                        }
                    }
                }
            }
        case RIGHT:{
                coord next_element=next(dir);
                if(cap.stanga()!=true)
                {
                    if(coada(next_element)==true)
                    {
                        cout<<endl<<endl<<"Te-ai lovit de coada ! Ai murit !"<<endl;
                        if(fisier.verificare_scor(nr_pct)!=-1)
						{
							elem_leaderboard scor_nou;
							cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
							cout<<"Introdu-ti numele :";
							cin>>scor_nou.nume;
							scor_nou.scor=nr_pct;
							fisier.inserare_in_fisier(scor_nou);
						}
						getch();
                        system("cls");
                        gameover=true;
                        break;
                    }
                    else
                    {
                        if(caseta[capX][capY+1]=='O')
                        {
                            mancare.dreapta();
                            break;
                        }
                        else
                        {
                            miscare.dreapta();
                            break;
                        }
                    }
                }
            }
        }
	}
	void perete(){
		if(capX==1&&dir==UP)
			{cout<<endl<<endl<<"Ai pierdut !"<<endl<<endl;
			if(fisier.verificare_scor(nr_pct)!=-1)
            {
                elem_leaderboard scor_nou;
                cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
                cout<<"Introdu-ti numele :";
                cin>>scor_nou.nume;
                scor_nou.scor=nr_pct;
                fisier.inserare_in_fisier(scor_nou);
            }
			cout<<"Apasa orice tasta pentru a reveni la meniul anterior";
			getch();
			clear();
			system("cls");
			gameover=true;}
		if(capX==height-2&&dir==DOWN)
			{cout<<endl<<endl<<"Ai pierdut !"<<endl<<endl;
			if(fisier.verificare_scor(nr_pct)!=-1)
            {
                elem_leaderboard scor_nou;
                cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
                cout<<"Introdu-ti numele :";
                cin>>scor_nou.nume;
                scor_nou.scor=nr_pct;
                fisier.inserare_in_fisier(scor_nou);
            }
			cout<<"Apasa orice tasta pentru a reveni la meniul anterior";
			getch();
			clear();
			system("cls");
			gameover=true;}
		if(capY==1&&dir==LEFT)
			{cout<<endl<<endl<<"Ai pierdut !"<<endl<<endl;
			if(fisier.verificare_scor(nr_pct)!=-1)
            {
                elem_leaderboard scor_nou;
                cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
                cout<<"Introdu-ti numele :";
                cin>>scor_nou.nume;
                scor_nou.scor=nr_pct;
                fisier.inserare_in_fisier(scor_nou);
            }
			cout<<"Apasa orice tasta pentru a reveni la meniul anterior";
			getch();
			clear();
			system("cls");
			gameover=true;}
		if(capY==width-2&&dir==RIGHT)
			{cout<<endl<<endl<<"Ai pierdut !"<<endl<<endl;
			if(fisier.verificare_scor(nr_pct)!=-1)
            {
                elem_leaderboard scor_nou;
                cout<<"Felicitari ! Ai obtinut un scor record !!"<<endl;
                cout<<"Introdu-ti numele :";
                cin>>scor_nou.nume;
                scor_nou.scor=nr_pct;
                fisier.inserare_in_fisier(scor_nou);
            }
            cout<<"Apasa orice tasta pentru a reveni la meniul anterior";
			getch();
			clear();
			system("cls");
			gameover=true;}
	}
	coord next(directii x){
		coord next_element;
		switch(x){
			case UP:{
                next_element.x=capX-2;
                next_element.y=capY;
				break;
				}
			case DOWN:{
			    next_element.x=capX+2;
                next_element.y=capY;
				break;
				}
			case LEFT:{
			    next_element.x=capX;
                next_element.y=capY-2;
				break;
				}
			case RIGHT:{
                next_element.x=capX;
                next_element.y=capY+2;
				break;
				}
		}
		return next_element;
	}
    bool coada(coord punct){
        int i;
        for(i=0;i<lungime;i++)
            if(sarpe[i].x==punct.x&&sarpe[i].y==punct.y)
                return true;
        return false;
    }
    void clear(){
        int i,j;
        for(i=0;i<height;i++)
            {for(j=0;j<width;j++)
                {caseta[i][j]=' ';
                 if(i==0||i==height)
                    caseta[i][j]=205;
                 if(j==0||j==width)
                    caseta[i][j]=186;
                }
            }
        caseta[0][0]=201;
        caseta[height][0]=200;
        caseta[0][width]=187;
        caseta[height][width]=188;
    }
};
