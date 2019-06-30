
//meniu
class menu{
    int i,j,n;
    bool merge_meniul;
public:
    void start(){
        system("cls");
        clear();
        snake s;
        mancare.generare();
        do{
            s.afisare();
            s.citire();
            s.misc();
            if(mancare.mancat()==1)
                mancare.generare();
            if(dir==LEFT||dir==RIGHT)
                Sleep(100);
            else
                Sleep(150);
        }while(gameover!=true);
    }
    void clear(){
        int i,j;
        for(i=0;i<height;i++)
            {for(j=0;j<width;j++)
                {meniu[i][j]=' ';
                 if(i==0||i==height-1)
                    meniu[i][j]=205;
                 if(j==0||j==width-1)
                    meniu[i][j]=186;
                }
            }
        meniu[0][0]=201;
        meniu[height-1][0]=200;
        meniu[0][width-1]=187;
        meniu[height-1][width-1]=188;
    }
    void afisare(){
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
                cout<<meniu[i][j];
            cout<<endl;
        }
    }
    void afisare_meniu(){
        clear();
		afisare_text("Snake",1,14);
		afisare_text("1.Start",3,1);
		afisare_text("2.Highscores",4,1);
		afisare_text("3.Instructiuni",5,1);
		afisare_text("4.Exit",6,1);
		afisare_text("by Filip",8,8);
        afisare();
    }
    void exit(){
        clear();
		afisare_text("La revedere",7,9);
		afisare();
        merge_meniul=false;
    }
    menu(){
        char optiune;
        clear();
        merge_meniul=true;
        while(merge_meniul==true)
        {
            afisare_meniu();
            cout<<"Introdu optiunea dorita:";
            cin>>optiune;
            system("cls");
            switch(optiune){
            case '1':
                start();
                break;
            case '2':
                scor_record();
                break;
            case '3':
                instructiuni();
                break;
            case '4':
                exit();
                break;
            }
        }
    }
	void scor_record(){
        clear();
        char* highscore_text="Leaderboard: ";
        afisare_text(highscore_text,2,8);
		fisier.citire_fisier();
		fisier.sortare_fisier("descrescator");
        int i=1;
		int linie=4;
		int pozitie=0;
        for(i=0;i<nr_elem_fisier;i++)
        {
            int j;
			char poz[10];
			pozitie++;
			itoa(pozitie,poz,10);
			char linia_i[40];
			strcpy(linia_i,poz);
			strcat(linia_i,")");
            strcat(linia_i,s[i].nume);
            if(pozitie>9)
			{if(nr_cifre(s[i].scor)==3)
                for(j=1;j<=width-strlen(s[i].nume)-3-2-2-1;j++)
                    strcat(linia_i,".");
            else
                {if(nr_cifre(s[i].scor)==2)
                    for(j=1;j<=width-strlen(s[i].nume)-1-nr_cifre(s[i].scor)-2-2;j++)
                        strcat(linia_i,".");
                else
					for(j=1;j<=width-strlen(s[i].nume)-1-1-nr_cifre(s[i].scor)-1-2;j++)
                        strcat(linia_i,".");
				}
			}
			else
			{if(nr_cifre(s[i].scor)==3)
                for(j=1;j<=width-strlen(s[i].nume)-3-2-2;j++)
                    strcat(linia_i,".");
            else
                {if(nr_cifre(s[i].scor)==2)
                    for(j=1;j<=width-strlen(s[i].nume)-nr_cifre(s[i].scor)-2-2;j++)
                        strcat(linia_i,".");
                else
					for(j=1;j<=width-strlen(s[i].nume)-1-nr_cifre(s[i].scor)-1-2;j++)
                        strcat(linia_i,".");
				}
			}
            char scor_char[10];
            itoa(s[i].scor,scor_char,10);
            strcat(linia_i,scor_char);
            afisare_text(linia_i,linie,1);
            linie++;

        }
		afisare();
        getch();
        system("cls");
	}
	void instructiuni(){
        clear();
        afisare_text("Instructiuni",1,9);
        afisare_text("Misiunea ta este sa mananci",4,1);
        afisare_text("toate punctele generate ",5,3);
        afisare_text("random pe ecran.",6,5);
        afisare_text("Controale:",8,9);
        afisare_text("W-sus",10,4);
        afisare_text("A-stanga",10,17);
        afisare_text("S-jos",11,4);
        afisare_text("D-dreapta",11,17);
        afisare();
        getch();
        system("cls");
    }
	void afisare_text(char s[100],int linie,int coloana){
		int i;
		for(i=coloana;i<strlen(s)+coloana;i++)
			meniu[linie][i]=s[i-coloana];
	}
}m;
