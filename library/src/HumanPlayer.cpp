#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(int idPlayer) : Player(idPlayer) {}

HumanPlayer::~HumanPlayer() {}

void HumanPlayer::move() {
    int X,Y,wybor=0,ruch=0;
    cout<<"Ruch gracza "<<getIdPlayer()<<". Podaj koordynaty pionka ktorym chcesz sie ruszyc."<<endl;
    while(wybor!=1){
        ruch=0;
        cout<<"Podaj koordynate X pionka ktorym chcesz sie ruszyc: ";
        cin>>X;
        cout<<"Podaj koordynate Y pionka ktorym chcesz sie ruszyc: ";
        cin>>Y;
        if(X<=8 && Y<=8){
            int i=0;
            while(i < getBoard()->getWholeBoard().size()){
                if (getBoard()->getWholeBoard()[i].getCoordinatesX() == X && getBoard()->getWholeBoard()[i].getCoordinatesY() == Y){
                    if (getBoard()->getWholeBoard()[i].isPossesed() == 1){
                        if (getBoard()->getWholeBoard()[i].getUnit()->getIdPlayer() == getIdPlayer()){
                            wybor=1;
                            while(ruch!=1){
                                int przesuniecieX;
                                int przesuniecieY;
                                int ponownyWybor;
                                cout<<"Czy chcesz ponownie wybrac pionek ktorym masz zamiar sie ruszyc . Wybierz 1=tak ,2=nie :";
                                cin>>ponownyWybor;
                                if(ponownyWybor==2){
                                    cout<<"Podaj koordynary na ktore chcesz przesunac pionek.\n";
                                    cout<<"Podaj koordynate X na ktora chcesz sie ruszyc: ";
                                    cin>>X;
                                    cout<<"Podaj koordynate Y na ktora chcesz sie ruszyc: ";
                                    cin>>Y;
                                    przesuniecieX=X-getBoard()->getWholeBoard()[i].getCoordinatesX();
                                    przesuniecieY=Y-getBoard()->getWholeBoard()[i].getCoordinatesY();
                                    if(X<=8 && Y<=8){
                                        if(((przesuniecieX + przesuniecieY == 2) || (przesuniecieX + przesuniecieY == 0) || (przesuniecieX + przesuniecieY == -2))){
                                            for(int j = 0; j < getBoard()->getWholeBoard().size(); j++){
                                                if(getBoard()->getWholeBoard()[j].getCoordinatesX() == X && getBoard()->getWholeBoard()[j].getCoordinatesY() == Y){
                                                    if(getBoard()->getWholeBoard()[j].isPossesed() == 0){
                                                        getBoard()->getWholeBoard()[j].setPossesed(1);
                                                        getBoard()->getWholeBoard()[i].setPossesed(0);
                                                        getBoard()->getWholeBoard()[j].setUnit(getBoard()->getWholeBoard()[i].getUnit());
                                                        getBoard()->getWholeBoard()[i].setUnit(nullptr);
                                                        ruch=1;
                                                    }else if(getBoard()->getWholeBoard()[j].isPossesed() == 1){
                                                        if(getBoard()->getWholeBoard()[j].getUnit()->getIdPlayer()!=getIdPlayer()){
                                                            if((X+przesuniecieX)<=8 && (Y+przesuniecieY <=8 )){
                                                                for(int k = 0; k < getBoard()->getWholeBoard().size(); k++){
                                                                    if(getBoard()->getWholeBoard()[k].getCoordinatesX()==(X+przesuniecieX) && getBoard()->getWholeBoard()[k].getCoordinatesY()== (Y+przesuniecieY)){
                                                                        if(getBoard()->getWholeBoard()[k].isPossesed() == 0){
                                                                            getBoard()->getWholeBoard()[k].setPossesed(1);
                                                                            getBoard()->getWholeBoard()[i].setPossesed(0);
                                                                            getBoard()->getWholeBoard()[k].setUnit(getBoard()->getWholeBoard()[i].getUnit());
                                                                            getBoard()->getWholeBoard()[i].setUnit(nullptr);
                                                                            getBoard()->getWholeBoard()[j].setPossesed(false);
                                                                            int flaga1 =0;
                                                                            int p=0;
                                                                            while(flaga1!=1){
                                                                                if(getBoard()->getWholeUnits()[p]->getUnitNr()==getBoard()->getWholeBoard()[j].getUnit()->getUnitNr()){
                                                                                    getBoard()->getWholeUnits().erase(getBoard()->getWholeUnits().begin()+p);
                                                                                    flaga1=1;
                                                                                }
                                                                                p++;
                                                                            }
                                                                            getBoard()->getWholeBoard()[j].setUnit(nullptr);
                                                                            ruch=1;
                                                                        }else{
                                                                            cout<<"XXXXXXPodano nieprawidlowe koorydnaty! Prosze ponownie podac koorydnaty ruchu.\n";
                                                                        }
                                                                    }
                                                                }
                                                            }else{
                                                                cout<<"Podano nieprawidlowe koorydnaty! Prosze ponownie podac koorydnaty ruchu.\n";
                                                            }
                                                        }else{
                                                            cout<<"Podano nieprawidlowe koorydnaty! Prosze ponownie podac koorydnaty ruchu.\n";
                                                        }
                                                    }
                                                }
                                            }
                                        }else{
                                            cout<<"Podano nieprawidlowe koorydnaty! Prosze ponownie podac koorydnaty ruchu.\n";
                                        }
                                    }
                                }else if(ponownyWybor==1){
                                    wybor=0;
                                    ruch=1;
                                }

                            }
                        }else{
                            cout<<"Podano nieprawidlowe koorydnaty! Prosze ponownie podac koorydnaty pionka.\n";
                        }
                    }else{
                        cout<<"Podano nieprawidlowe koorydnaty! Prosze ponownie podac koorydnaty pionka.\n";
                    }
                }
                i++;
            }
        }else{
            cout<<"Podano nieprawidlowe koorydnaty! Prosze ponownie podac koorydnaty pionka.\n";
        }
    }
}