int nr_cifre(int x){
    int nr=0;
    while(x!=0)
    {
        nr++;
        x=x/10;
    }
    return nr;
}
void afisare_text(char s[100],int linie,int coloana){
    int i;
    for(i=coloana;i<strlen(s)+coloana;i++)
        meniu[linie][i]=s[i-coloana];
}
