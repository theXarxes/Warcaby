
#include "nonHumanPlayer.h"
using namespace std;
boost::random::mt19937 gen;
boost::random::uniform_int_distribution<> ruch(0, 3);
boost::random::uniform_int_distribution<> pionek(12, 23);

nonHumanPlayer::nonHumanPlayer(int idPlayer) : Player(idPlayer) {}
nonHumanPlayer::~nonHumanPlayer() {}
void nonHumanPlayer::move() {
    int flaga=0;
    int iloscUnit=0;
    for(int i=0;i<getBoard()->getWholeUnits().size();i++){
        if(getBoard()->getWholeUnits()[i]->getIdPlayer()==getIdPlayer()){
            iloscUnit++;
        }
    }
    while(flaga!=1){
        int losUnit=rand()%iloscUnit+1;
        int skip=0;
        int unitWybor=pionek(gen);
        for(int i=0;i<getBoard()->getWholeBoard().size();i++){
                    if(getBoard()->getWholeBoard()[i].isPossesed()==true){
                        if(getBoard()->getWholeBoard()[i].getUnit()->getIdPlayer()==getIdPlayer()){
                            skip++;
                            if(skip==losUnit){
                                int randRuch=ruch(gen);
                                int ruchX,ruchY;
                                switch(randRuch){
                                    case 0:
                                        ruchX=1;
                                        ruchY=1;
                                        break;
                                    case 1:
                                        ruchX=1;
                                        ruchY=-1;
                                        break;
                                    case 2:
                                        ruchX=-1;
                                        ruchY=1;
                                        break;
                                    case 3:
                                        ruchX=-1;
                                        ruchY=-1;
                                        break;
                                }
                                if((getBoard()->getWholeBoard()[i].getCoordinatesX()+ruchX>=1 && getBoard()->getWholeBoard()[i].getCoordinatesX()+ruchX<=8) && (getBoard()->getWholeBoard()[i].getCoordinatesY()+ruchY>=1 && getBoard()->getWholeBoard()[i].getCoordinatesY()<=8)){
                                    for(int j=0;j<getBoard()->getWholeBoard().size();j++){
                                        if(getBoard()->getWholeBoard()[j].getCoordinatesX()==getBoard()->getWholeBoard()[i].getCoordinatesX()+ruchX && getBoard()->getWholeBoard()[j].getCoordinatesY()==getBoard()->getWholeBoard()[i].getCoordinatesY()+ruchY){
                                            if(getBoard()->getWholeBoard()[j].isPossesed()==0){
                                                getBoard()->getWholeBoard()[j].setPossesed(1);
                                                getBoard()->getWholeBoard()[i].setPossesed(0);
                                                getBoard()->getWholeBoard()[j].setUnit(getBoard()->getWholeBoard()[i].getUnit());
                                                getBoard()->getWholeBoard()[i].setUnit(nullptr);
                                                flaga=1;
                                            }else{
                                                if(getBoard()->getWholeBoard()[j].getUnit()->getIdPlayer()!=getIdPlayer()){
                                                    if((getBoard()->getWholeBoard()[j].getCoordinatesX()+ruchX>=1 && getBoard()->getWholeBoard()[j].getCoordinatesX()+ruchX<=8) && (getBoard()->getWholeBoard()[j].getCoordinatesY()+ruchY>=1 && getBoard()->getWholeBoard()[j].getCoordinatesY()+ruchY<=8)){
                                                        for(int k=0;k<getBoard()->getWholeBoard().size();k++){
                                                            if(getBoard()->getWholeBoard()[k].getCoordinatesX()==getBoard()->getWholeBoard()[j].getCoordinatesX()+ruchX && getBoard()->getWholeBoard()[k].getCoordinatesY()==getBoard()->getWholeBoard()[j].getCoordinatesY()+ruchY){
                                                                if(getBoard()->getWholeBoard()[k].isPossesed()==0){
                                                                    getBoard()->getWholeBoard()[k].setPossesed(1);
                                                                    getBoard()->getWholeBoard()[i].setPossesed(0);
                                                                    getBoard()->getWholeBoard()[k].setUnit(getBoard()->getWholeBoard()[i].getUnit());
                                                                    getBoard()->getWholeBoard()[i].setUnit(nullptr);
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
                                                                    getBoard()->getWholeBoard()[j].setPossesed(0);

                                                                    flaga=1;
                                                                }
                                                            }

                                                        }
                                                    }
                                                }
                                            }
                                        }


                                    }
                                }
                            }

                        }

                    }
        }
    }
}