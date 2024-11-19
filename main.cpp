#include <iostream>
#include <cstring>
using namespace std;

class Autobuz{
private:
    static int nrAutobuze;
    const int idAutobuz = 0;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:
    ~Autobuz() {
        delete[] producator;
    };

    Autobuz() : idAutobuz(++nrAutobuze) {
        this->capacitate = 0;
        this->nrPersoaneImbarcate = 0;
        this->producator = nullptr;
    }

    Autobuz(int capacitate, int nrPersoaneImbarcate, char* producator) : idAutobuz(++nrAutobuze) {
        this->capacitate = capacitate;
        if(nrPersoaneImbarcate>capacitate){
            cout<<"Numarul de persoane imbarcate nu poate fi mai mare decat capacitatea autobuzului."<<endl;
            this->nrPersoaneImbarcate=capacitate;
        }
        else this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        if (producator) {
            this->producator = new char[strlen(producator) + 1];
            strcpy(this->producator, producator);
        } else {
            this->producator = nullptr;
        }
    }

    Autobuz(Autobuz& autobuz) : idAutobuz(++nrAutobuze) {
        capacitate = autobuz.capacitate;
        nrPersoaneImbarcate = autobuz.nrPersoaneImbarcate;
        if (autobuz.producator) {
            producator = new char[strlen(autobuz.producator) + 1];
            strcpy(producator, autobuz.producator);
        } else {
            producator = nullptr;
        }
    }

    int getCapacitate(){
        return capacitate;
    }

    int getNrPersoaneImbarcate(){
        return nrPersoaneImbarcate;
    }

    void setCapacitate(int capacitate) {
        this->capacitate=capacitate;
    }

    void setNrPersoaneImbarcate(int nrPersoaneImbarcate) {
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
    }

    Autobuz operator=(Autobuz autobuz) {
        if (this == &autobuz) {
            return *this;
        }

        delete[] producator;

        capacitate = autobuz.capacitate;
        nrPersoaneImbarcate = autobuz.nrPersoaneImbarcate;

        if (autobuz.producator) {
            producator = new char[strlen(autobuz.producator)+1];
            strcpy(producator, autobuz.producator);
        } else {
            producator = nullptr;
        }

        return *this;
    }

    int getNrLocuriLibere(){
        return this->capacitate - this->nrPersoaneImbarcate;
    }


    friend ostream& operator<<(ostream& oStream, Autobuz& autobuz) {
        oStream<<"Autobuz id: "<< autobuz.idAutobuz<<"; firma: "<<autobuz.producator<<"; capacitate: "<<autobuz.capacitate<<"; numar de persoane imbarcate: "<<autobuz.nrPersoaneImbarcate<<endl;
        return oStream;
    }


    operator int(){
        return nrPersoaneImbarcate;
    }


    bool operator>(Autobuz& autobuz){
        return this->capacitate>autobuz.capacitate;
    }



};
int Autobuz::nrAutobuze=0;

int main() {
    Autobuz autobuz1 = Autobuz(32, 35, "Volvo");
    cout<<"Inainte de set: "<<autobuz1.getCapacitate()<<" "<<autobuz1.getNrPersoaneImbarcate()<<"\n";
    autobuz1.setCapacitate(35);
    autobuz1.setNrPersoaneImbarcate(15);
    cout<<"Dupa set: "<<autobuz1.getCapacitate()<<" "<<autobuz1.getNrPersoaneImbarcate();
    cout<<"\n";
    cout<<endl;


    Autobuz autobuz2 = Autobuz(40, 1, "Mercedes");
    cout<<"Inainte de egalare: "<<autobuz2.getCapacitate()<<" "<<autobuz2.getNrPersoaneImbarcate()<<"\n";
    autobuz2 = autobuz1;
    cout<<"Dupa egalare: "<<autobuz2.getCapacitate()<<" "<<autobuz2.getNrPersoaneImbarcate();
    cout<<endl;
    cout<<endl;


    autobuz2 = Autobuz(40, 1, "Mercedes");
    cout<<"Autobuze:\n";
    cout<<autobuz1;
    cout<<autobuz2;
    cout<<endl;


    int nrPersA1 = autobuz1;
    int nrPersA2 = autobuz2;
    cout<<"Persoane Autobuz 1: "<<nrPersA1<<endl;
    cout<<"Persoane Autobuz 2: "<<nrPersA2<<endl;


    if(autobuz1>autobuz2){
        cout<<"Autobuzul 1 are capacitate mai mare decat autobuzul 2. ("<<autobuz1.getCapacitate()<<">"<<autobuz2.getCapacitate()<<")";
    }
    else cout<<"Autobuzul 2 are capacitate mai mare decat autobuzul 1. ("<<autobuz2.getCapacitate()<<">"<<autobuz1.getCapacitate()<<")";
    cout<<endl;
    autobuz1.setCapacitate(30);
    autobuz2.setCapacitate(10);
    if(autobuz1>autobuz2){
        cout<<"Autobuzul 1 are capacitate mai mare decat autobuzul 2. ("<<autobuz1.getCapacitate()<<">"<<autobuz2.getCapacitate()<<")";
    }
    else cout<<"Autobuzul 2 are capacitate mai mare decat autobuzul 1. ("<<autobuz2.getCapacitate()<<">"<<autobuz1.getCapacitate()<<")";



    return 0;

}
