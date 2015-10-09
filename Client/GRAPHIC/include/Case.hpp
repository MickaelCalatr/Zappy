//
// Case.hpp for zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/GRAPHIC/include
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Tue Jun 30 15:29:46 2015 Alexandre Tanyeres
// Last update Sun Jul  5 05:10:17 2015 Alexandre Tanyeres
//

#include <iostream>

class Case
{
public:
  Case();
  ~Case();
  void			doBct(int, int, int, int, int, int, int);
  int			getNourriture() const {return (this->_nourriture);}
  int			getLinemate() const {return (this->_linemate);}
  int			getDeraumere() const {return (this->_deraumere);}
  int			getSibur() const {return (this->_sibur);}
  int			getMendiane() const {return (this->_mendiane);}
  int			getPhiras() const {return (this->_phiras);}
  int			getThystame() const {return (this->_thystame);}
  bool			getInc() const {return (this->_inc);}

  void                  setNourriture(int nou) {this->_nourriture = nou;}
  void                  setLinemate(int lin) {this->_linemate = lin;}
  void                  setDeraumere(int der) {this->_deraumere = der;}
  void                  setSibur(int sib) {this->_sibur = sib;}
  void                  setMendiane(int men) {this->_mendiane = men;}
  void                  setPhiras(int phi) {this->_phiras = phi;}
  void                  setThystame(int thy) {this->_thystame = thy;}
  void                  setInc(bool in) {this->_inc = in;}
private:
  int			_nourriture;
  int			_linemate;
  int			_deraumere;
  int			_sibur;
  int			_mendiane;
  int			_phiras;
  int			_thystame;
  bool			_inc;
};
