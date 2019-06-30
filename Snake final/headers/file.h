//clasa pentru fisiere
class file{
	int i;
public:
	void citire_fisier(){
		ifstream f("leaderboard.txt");
		int i=0;
		while(!f.eof())
		{
			f>>s[i].nume;
			f>>s[i].scor;
			i++;
		}
		nr_elem_fisier=i-1;
		f.close();
	}
	void scriere_fisier(){
		ofstream g("leaderboard.txt");
		for(i=0;i<nr_elem_fisier;i++)
			{
				g<<s[i].nume<<endl;
				g<<s[i].scor<<endl;
			}
		g.close();
	}
	void sortare_fisier(char sens[30]){
		if(strcmp(sens,"crescator")==0)
		{
			int test=0;
			do{
				test=0;
				for(i=0;i<nr_elem_fisier;i++)
					if(s[i].scor>s[i+1].scor)
					{
						aux.scor=s[i].scor;
						strcpy(aux.nume,s[i].nume);
						s[i].scor=s[i+1].scor;
						strcpy(s[i].nume,s[i+1].nume);
						s[i+1].scor=aux.scor;
						strcpy(s[i+1].nume,aux.nume);
						test=1;
					}
			}while(test!=0);
		}
		if(strcmp(sens,"descrescator")==0)
		{
			int test=0;
			do{
				test=0;
				for(i=0;i<nr_elem_fisier;i++)
					if(s[i].scor<s[i+1].scor)
					{
						aux.scor=s[i].scor;
						strcpy(aux.nume,s[i].nume);
						s[i].scor=s[i+1].scor;
						strcpy(s[i].nume,s[i+1].nume);
						s[i+1].scor=aux.scor;
						strcpy(s[i+1].nume,aux.nume);
						test=1;
					}
			}while(test!=0);
		}
		scriere_fisier();
	}
	void inserare_in_fisier(elem_leaderboard x){
        nr_elem_fisier++;
		int poz;
		if(nr_elem_fisier<10)
		{
			strcpy(s[nr_elem_fisier-1].nume,x.nume);
			s[nr_elem_fisier-1].scor=x.scor;
			sortare_fisier("descrescator");
		}
		else
		{
			for(i=nr_elem_fisier-1;i>=0;i--)
				if(nr_pct>s[i].scor)
					poz=i;
			for(i=nr_elem_fisier;i>poz;i--)
			{
				strcpy(s[i].nume,s[i-1].nume);
				s[i].scor=s[i-1].scor;
			}
			strcpy(s[poz].nume,x.nume);
			s[poz].scor=x.scor;
		}
		scriere_fisier();
	}
	int verificare_scor(int x){
		citire_fisier();
		sortare_fisier("descrescator");
		for(i=nr_elem_fisier;i>0;i--)
			if(x>s[i].scor)
				return i;
		return -1;
	}
}fisier;
