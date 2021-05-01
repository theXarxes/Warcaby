
#include <humanGame.h>
#include <nonHumanGame.h>
#include "Game.h"
using namespace  std;


Game::~Game() {}

void Game::setBoard(Board *board) {
    Game::board = board;
}
Game::Game(Board *board) : board(board) {}

void Game::Gra() {
    cout<<endl<<"Witaj w Grze Warcaby"<<endl<<endl;
    cout<<endl<<"Chcesz zacząć grę od nowa czy wczytać poprzednią grę ?"<<endl;
    cout<<"Nowa gra 1: , Poprzednia gra 2 :"<<endl;
    int  wybor1;
    cin>>wybor1;
    while(wybor1!=1&&wybor1!=2){
        cout<<"podano złą liczbę"<<endl;
        cout<<"Nowa gra 1: , Poprzednia gra 2 :"<<endl;
        cin>>wybor1;
    }
    if(wybor1==1) {
        cout << "Wybierz Opcję Gry :" << endl;
        cout << "1: Gracz vs Gracz" << endl;
        cout << "2: Gracz vs Komputer" << endl;
        int wybor;
        cin >> wybor;
        while(wybor!=1&&wybor!=2){
            cout<<"podano złą liczbę"<<endl;
            cout << "1: Gracz vs Gracz" << endl;
            cout << "2: Gracz vs Komputer" << endl;
            cin>>wybor;
        }

        if (wybor == 1) {
            humanGame Y(board);
            Y.currentBoard();
            while(Y.currentGame()){
                Y.getGracze()[0]->move();
                system("CLS");
                Y.currentBoard();
                Y.getGracze()[1]->move();
                system("CLS");
                Y.currentBoard();
                int zapis;
                do {
                    cout << "Chcesz zapisać stan gry i zakończyć? " << endl;
                    cout << "Tak :1 Nie :2 ";
                    cin >> zapis;
                }
                while(zapis!=1 && zapis!=2);
                if(zapis==1){
                    Y.save();
                    break;
                }
            }
        }
        else{
            nonHumanGame X(board);
            X.currentBoard();
            while(X.currentGame()==true){
                X.getGracze()[0]->move();
                system("CLS");
                X.currentBoard();
                X.getGracze()[1]->move();
                system("CLS");
                X.currentBoard();
                int zapis;
                do {
                    cout << "Chcesz zapisać stan gry i zakończyć? " << endl;
                    cout << "Tak :1 Nie :2 ";
                    cin >> zapis;
                }
                while(zapis!=1 && zapis!=2);
                if(zapis==1){
                    X.save();
                    break;
                }
            }
        }
    }
    else{
        cout << "Wybierz Opcję Gry :" << endl;
        cout << "1: Gracz vs Gracz" << endl;
        cout << "2: Gracz vs Komputer" << endl;
        int wybor;
        cin >> wybor;
        while(wybor!=1&&wybor!=2){
            cout<<"podano złą liczbę"<<endl;
            cout << "1: Gracz vs Gracz" << endl;
            cout << "2: Gracz vs Komputer" << endl;
            cin>>wybor;
        }
        if (wybor == 1) {
            humanGame X(board);
            X.load();
            X.currentBoard();
            while(X.currentGame()==true){
                X.getGracze()[0]->move();
                system("CLS");
                X.currentBoard();
                X.getGracze()[1]->move();
                system("CLS");
                X.currentBoard();
                int zapis;
                do {
                    cout << "Chcesz zapisać stan gry i zakończyć? " << endl;
                    cout << "Tak :1 Nie :2 ";
                    cin >> zapis;
                }
                while(zapis!=1 && zapis!=2);
                if(zapis==1){
                    X.save();
                    break;
                }
            }
        }
        else{
            nonHumanGame X(board);
            X.setBoard(board);
            X.load();
            X.currentBoard();
            while(X.currentGame()==true){
                X.getGracze()[0]->move();
                system("CLS");
                X.currentBoard();
                X.getGracze()[1]->move();
                system("CLS");
                X.currentBoard();
                int zapis;
                do {
                    cout << "Chcesz zapisać stan gry i zakończyć? " << endl;
                    cout << "Tak :1 Nie :2 ";
                    cin >> zapis;
                }
                while(zapis!=1 && zapis!=2);
                if(zapis==1){
                    X.save();
                    break;
                }
            }
        }

    }

}

void Game::save() try{
    std::ofstream zapis("zapis.txt");
    for(int i=0;i<64;i++)
    {
        int x=0;
        if(board->getWholeBoard()[i].isPossesed()==false){
            x++;
            if(x==64){
                throw -1;
            }
        }
        zapis<<board->getWholeBoard()[i].isPossesed();
        zapis<<std::endl;
        if(board->getWholeBoard()[i].isPossesed()==true)
        {
            zapis<<board->getWholeBoard()[i].getUnit()->getLook();
            zapis<<std::endl;
            zapis<<board->getWholeBoard()[i].getUnit()->getIdPlayer();
            zapis<<std::endl;
        }

    }
    zapis.close();
}catch(int) {
    std::cout << std::endl << "Złapano wyjątek" << std::endl;
    throw OptionsException("Nie ma czego zapisać ");
}
void Game::load() try{
    int c=0;
    int Id=0;
    bool P=1;
    std::string look;
    std::ifstream otworz("zapis.txt");
    if (! otworz) {
        throw -1;
    }
    for(int i=0;i<64;i++) {
        otworz >> P;
        board->getWholeBoard()[i].setPossesed(P);
        if (P == 1) {
            otworz >> look;
            otworz >> Id;
            board->getWholeBoard()[i].setUnit(board->getWholeUnits()[c]);
            board->getWholeUnits()[c]->setLook(look);
            board->getWholeUnits()[c]->setIdPlayer(Id);
            c++;
        }
    }
    otworz.close();
}catch(int){
    std::cout<<std::endl<<"Złapano wyjątek"<<std::endl;
    throw OptionsException("Nie ma takiego pliku");
}
void Game::currentBoard() try{
    std::cout<<"  -------- ";
    if(currentGame()==false){
        throw -1;
    }
    int k=0;
    for(int i=0;i<8;i++)
    {
        std::cout<<std::endl;
        std::cout<<8-i;
        std::cout<<"|";
        for(int j=1;j<9;j++)
        {

            if(board->getWholeBoard()[k].isPossesed()==true)
            {

                std::cout<<board->getWholeBoard()[k].getUnit()->getLook();

            }
            else
            {
                std::cout<<" ";
            }
            k++;
        }
        std::cout<<"|";
    }


    std::cout<<std::endl<<"  -------- ";
    std::cout<<std::endl<<"  12345678"<<std::endl;

}catch (int){
    std::cout << std::endl << "Złapano wyjątek" << std::endl;
    throw OptionsException("Gra się skończyła");
}
bool Game::currentGame() try{
    int a=0;
    int b=0;
    if(a!=0||b!=0||board->getWholeBoard().size()==0){
        throw -1;
    }
    for(int i=0;i<64;i++)
    {
        if(board->getWholeBoard()[i].isPossesed()==true){
            if(board->getWholeBoard()[i].getUnit()->getIdPlayer()==1){
                a++;
            }
            if(board->getWholeBoard()[i].getUnit()->getIdPlayer()==2){
                b++;
            }
        }
    }
    if(a==0||b==0){
        return false;
    }

    return true;
}catch(int){
    std::cout << std::endl << "Złapano wyjątek" << std::endl;
    throw OptionsException("Gra nie istnieje");
}

const std::vector<PlayerPtr> &Game::getGracze() const {
    return gracze;
}









