#ifndef INTRODUCTIONPROJECT_UNIT_H
#define INTRODUCTIONPROJECT_UNIT_H
#include <memory>
#include <string>

class Unit {
private:
    int idPlayer;
    std::string Look;
    int unitNr;
public:
    Unit(int idPlayer, const std::string &look, int unitNr);
    ~Unit();
    int getIdPlayer() const;
    const std::string &getLook() const;
    int getUnitNr() const;
    void setIdPlayer(int idPlayer);
    void setLook(const std::string &look);
};


#endif //INTRODUCTIONPROJECT_UNIT_H
