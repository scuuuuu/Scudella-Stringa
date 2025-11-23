#include <iostream>
using namespace std;


class Struttura {
protected:
    int dimensione;
public:
    virtual int calcolaDimensione(char* s) = 0;
};

class Stringa : public Struttura {
private:
    char s[50];
public:
    Stringa() {//costruttore di default
        s[0] = '\0';
    }
    Stringa(char* str) {
        int i = 0;
        while (str[i] != '\0' && i < 49) {
            s[i] = str[i];
            i++;
        }
        s[i] = '\0';
    }
    ~Stringa() {}
    void Stampa(char* s) {
        int i = 0;
        while (s[i] != '\0'){
            cout <<s[i];
            i++;
        }
        cout << endl;
    }

    void Reverse(char* s) {
        calcolaDimensione(s);
        int inizio = 0;
        int fine = dimensione - 1;
        while (inizio < fine) {
            char temp = s[inizio];
            s[inizio] = s[fine];
            s[fine] = temp;
            inizio++;
            fine--;
        }
        cout << s << endl;
    }
    void Flip(char* s) {
        int i = 0;
        while (s[i] != '\0') {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32; //maiuscola minuscola
            else if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32; //minuscola maiuscola
            i++;
        }
        cout << s << endl;
    }
    void Palindroma(char* s) {
        calcolaDimensione(s);
        int inizio = 0;
        int fine = dimensione - 1;
        while (inizio < fine) {
            if (s[inizio] == s[fine]) {
                continue;
            }
            else {
                cout<< "La stringa non e' palindroma"<<endl;
                return;
            }
        }
    }
    int calcolaDimensione(char* s) override {
        dimensione=0;
        while (s[dimensione] != '\0') {
            dimensione++;
        }
        return dimensione;
    };
};
int main() {
    char stringa[50];
    cout<< "Primo programma"<<endl;
    cout<< "Inserisci la stringa: ";
    cin.getline(stringa, 50);
    Stringa s(stringa);
    cout <<"Stringa stampata: ";
    s.Stampa(stringa);
    s.Palindroma(stringa);
    cout<<"Stringa al contrario: ";
    s.Reverse(stringa);
    cout<<"Stringa flippata: ";
    s.Flip(stringa);
    return 0;
}