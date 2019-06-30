//clasa pentru aflarea directiei capului
class head{
public:
	bool stanga(){
        if(caseta[capX][capY]=='<')
            return true;
        else
            return false;
    }
    bool dreapta(){
        if(caseta[capX][capY]=='>')
            return true;
        else
            return false;
    }
    bool sus(){
        if(caseta[capX][capY]=='^')
            return true;
        else
            return false;
    }
    bool jos(){
        if(caseta[capX][capY]=='v')
            return true;
        else
            return false;
    }
}cap;
