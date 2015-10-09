//
// IA.cpp for  in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client/srcs/IA
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Wed Jun 24 11:14:09 2015 Caltraba Mickael
// Last update Sun Jul  5 19:27:36 2015 paul david
//

#include "IA.hpp"

static bool	g_run = true;
IA::IA(const std::string &team) :
  _team(team)
{
  this->_lvl = 1;
  this->_up = 1;
  this->_nb = -1;
  this->_buff = 0;
  this->_food = 5;
  this->_listen = false;
  this->_bro = false;
  this->_inc = false;
  this->_goInc = false;
  this->_block = false;
  this->_pos.first = -1;
  this->_acquired = initLvl(0, 0, 0, 0, 0, 0, 0);
  this->_required[1] = initLvl(1, 1, 0, 0, 0, 0, 0);
  this->_required[2] = initLvl(2, 1, 1, 1, 0, 0, 0);
  this->_required[3] = initLvl(2, 2, 0, 1, 0, 2, 0);
  this->_required[4] = initLvl(4, 1, 1, 2, 0, 1, 0);
  this->_required[5] = initLvl(4, 1, 2, 1, 3, 0, 0);
  this->_required[6] = initLvl(6, 1, 2, 3, 0, 1, 0);
  this->_required[7] = initLvl(6, 2, 2, 2, 2, 2, 1);
}
IA::~IA()
{
}


//____PRINCIPALE_FUNCTION_____

void		IA::send(const std::string &msg)
{
  if (this->_buff < 10)
    {
      this->_select.sendToBuff(msg);
      ++this->_buff;
    }
}

bool		IA::run()
{
  bool		view = true;

  while (g_run)
    {
      this->_select.setFd();
      this->_select.setTime(&this->_select.getTv());
      if (!this->_select.setSelect())
        break;
      if (!this->_select.readIn())
        break;
      std::pair<int, std::string>       buff;

      buff = this->_select.getBuff();
      if (buff.first != -1)
        {
	  std::cout << "Receive : " << buff.second << std::endl;
	  view = setAction(buff.second);
        }
      else if (this->_nb != -1 &&
	       this->_action.empty() && !this->_inc && !this->_goInc
	       && !this->_listen && !this->_bro && 
	       !this->_block && view == true)
	{
	  viewAction();
	  view = false;
	}
      checkLvl();
      if (this->_buff < 10 && this->_action.size() > 0 &&
	  this->_buff < static_cast<int>(this->_action.size()))
	{
	  std::list<std::string>::const_iterator	it;
	  it = this->_action.begin();
	  while (this->_buff < 10 && it != this->_action.end())
	    {
	      send((*it));
	      ++it;
	    }
	}
    }
  std::cout << "*** Exit IA ***" << std::endl;
  close(this->_socket.getFd());
  return (true);
}


//_____ACTION

bool		IA::setAction(std::string &msg)
{
  if (msg == "ok\n" || msg.find("niveau actuel") != msg.npos)
    popAction(msg);
  else if (msg == "ko\n" || msg.find("deplacement") != msg.npos)
    {
      if (this->_action.front() == "incantation")
	{
	  this->_block = false;
	  this->_inc = false;
	  this->_goInc = false;
	  --this->_up;
	  while (!this->_action.empty())
	    this->_action.pop_front();
	  this->_action.push_back("avance");
	  this->_action.push_back("broadcast ---");
	}
      else
	{
	  while (!this->_action.empty())
	    this->_action.pop_front();
	  this->_listen = false;
	  this->_block = false;
	  this->_bro = false;
	  this->_inc = false;
	  this->_goInc = false;
	}
      this->_buff -= 1;
    }
  else if (msg.find("message") != msg.npos)
    parseMessage(msg);
  else if (msg == "BIENVENUE\n")
    {
      send(this->_team);
      this->_buff -= 1;
      return (false);
    }
  else if (isdigit(msg.front()) && this->_nb == -1)
    return (initOption(msg));
  else if (msg.find("{ ") != msg.npos)
    {
      this->_buff -= 1;
      this->_action.pop_front();
      parseAction(msg);
    }
  else if (msg.front() == '{' && this->_action.front() == "inventaire")
    {
      this->_buff -= 1;
      this->_action.pop_front();
      parseInventaire(msg);
    }
  return (true);
}

void		IA::popAction(std::string &msg)
{
  if (this->_action.front() == "incantation"
      || msg.find("niveau actuel") != msg.npos)
    {
      ++this->_lvl;
      this->_inc = false;
      this->_block = false;
      this->_listen = false;
      this->_bro = false;
      this->_acquired = initLvl(0, 0, 0, 0, 0, 0, 0);
      if (this->_action.front() == "incantation"
	  && msg.find("niveau actuel") != msg.npos)
	{
	  this->_buff -= 1;
	  this->_action.pop_front();
	}
      this->_action.push_back("broadcast ---");
    }
  else if (this->_action.front().find("prend") != this->_action.front().npos)
    {
      msg = this->_action.front().substr(this->_action.front().find(" ") + 1);
      if (this->_acquired.find(msg) != this->_acquired.end())
	++this->_acquired[msg];
      else if (msg == "nourriture")
	this->_action.push_back("inventaire");
    }
  else if (this->_action.front().find("pose") != this->_action.front().npos)
    {
      msg = this->_action.front().substr(this->_action.front().find(" ") + 1);
      if (this->_acquired.find(msg) != this->_acquired.end())
	--this->_acquired[msg];      
    }
  if (msg.find("niveau actuel") == msg.npos)
    {
      this->_buff -= 1;
      this->_action.pop_front();
    }
}

void		IA::checkLvl()
{
  if (this->_required[this->_lvl]["linemate"] <= this->_acquired["linemate"]
      && this->_required[this->_lvl]["deraumere"]<=this->_acquired["deraumere"]
      && this->_required[this->_lvl]["sibur"] <= this->_acquired["sibur"]
      && this->_required[this->_lvl]["mendie"] <= this->_acquired["mendie"]
      && this->_required[this->_lvl]["phiras"] <= this->_acquired["phiras"]
      && this->_required[this->_lvl]["thystame"]<= this->_acquired["thystame"]
      && this->_up == this->_lvl && this->_goInc == false)
    {
      if (this->_required[this->_lvl]["joueur"] <= this->_acquired["joueur"] &&
	  this->_food > 35)
	{
	  poseInvent();
	  this->_block = true;
	  this->_goInc = true;
	}
      else if (this->_food > 35 && !this->_listen)
      	{
      	  this->_bro = true;
      	  this->_block = true;
      	  if (this->_action.empty())
      	    broadcast();
      	}
            else
      	{
      	  this->_block = false;
      	  //	  this->_listen = false;
      	  this->_bro = false;
      	}
    }
  if (this->_goInc == true && this->_action.size() == 0)
   {
     this->_block = true;
     this->_inc = true;
     this->_goInc = false;
     this->_bro = false;
     this->_action.push_back("incantation");
     ++this->_up;
    }
}

void			IA::broadcast()
{
  std::stringstream	ss;
  std::string		lvl;
  
  ss << this->_lvl;
  ss >> lvl;
  
  std::string		msg = "broadcast " + this->_team + " " + lvl;
  
  this->_action.push_back(msg);
  this->_action.push_back("inventaire");
  this->_action.push_back("voir");
}

void		IA::poseInvent()
{
  std::string			action;
  std::vector<std::string>	base;
  std::size_t			i;
  int				pose;
  std::string		        msg = "broadcast " + this->_team + " -1";

  base.push_back("linemate");
  base.push_back("deraumere");
  base.push_back("sibur");
  base.push_back("mendie");
  base.push_back("phiras");
  base.push_back("thystame");
  pose = 0;
  i = 0;
  while (i != base.size())
    {
      pose = this->_acquired[base[i]];
      while (pose > 0)
	{
	  action = "pose " + base[i];
	  this->_action.push_back(action);
	  pose -= 1;
	}
      ++i;
    }
  this->_action.push_back(msg);
}

bool		IA::viewAction()
{
  if (this->_action.empty())
    {
      this->_action.push_back("voir");
      return (true);
    }
  return (false);
}


//_____PARSE_FUNCTION________________

void			IA::parseAction(std::string &msg)
{
  std::size_t		pos;
  std::string		line;
  bool			action = true;
  int			i = 0;
  int			j = 0;

  this->_acquired["joueur"] = 0;
  if (msg.find("{") == msg.npos)
    return ;
  msg.erase(msg.find("{"), 1);
  msg.erase(msg.find("}"), 1);
  do
    {
      pos = msg.find_first_of(",");
      if (pos != msg.npos)
	{
	  line = msg.substr(0, pos);
	  msg.erase(0, ++pos);
	}
      else
	line = msg.substr(0, pos);
      action = parseLine(line, i, j);
      if (j == i)
	{
	  ++j;
	  i = -j;
	}
      else
	++i;
    } while(pos != msg.npos && action && !this->_bro && !this->_inc);
  if (this->_action.empty() && !this->_bro && !this->_listen && !this->_block)
    this->_action.push_back("avance");
}

void			IA::parseInventaire(std::string &msg)
{
  std::stringstream	ss;
  std::string		tmp;

  ss << msg.substr(12, msg.find(","));
  ss >> this->_food;
}

void			IA::parseMessage(std::string &msg)
{
  std::stringstream	ss;
  std::string		line;
  int			dir;
  int			lvl;

  ss << msg.substr(8, 1);
  ss >> dir;
  ss.clear();
  ss << msg.substr(10, msg.find(" "));
  ss >> line;
  ss.clear();
  ss << msg.substr(10, (msg.size() - 1));
  ss >> lvl;
  if (line == this->_team && (this->_lvl == lvl || lvl == -1 )
      && this->_food > 35)
    {
      this->_listen = true;
      // if (this->_bro)
      // 	{
      this->_bro = false;
      while (!this->_action.empty())
	this->_action.pop_front();
      // }
      if (this->_action.empty())
	goToIA(dir);
      else if (line == "---" || this->_lvl != lvl || this->_food < 35)
	{
	  this->_block = false;
	  this->_listen = false;
	}
    }
}

bool			IA::parseLine(std::string &line, int i, int j)
{
  std::size_t		pos;
  std::string		action;

  do
    {
      pos = line.find_first_of(" ");
      if (pos != line.npos)
	{
	  action = line.substr(0, pos);
	  line.erase(0, ++pos);
	}
      else
	action = line.substr(0, pos);
      if (action == "joueur")
	this->_acquired[action] += 1;
      else if (this->_required[this->_lvl][action] != 0
	       && this->_acquired[action] <
	       this->_required[this->_lvl][action])
	return (goToCase(action, i, j));
      else if (action == "nourriture" && !this->_bro)
	return (goToCase(action, i, j));
    } while (pos != line.npos);
  return (true);
}

void			IA::goToIA(int i)
{
  this->_action.push_back("inventaire");
  if (i == 0)
    this->_block = true;
  else
    {
      if (i >= 3 && i <= 5)
	this->_action.push_back("gauche");
      else if (i == 1 || i == 2 || i == 8)
	this->_action.push_back("avance");
      else
	this->_action.push_back("droite");
    }
  // else if (this->_action.empty())
  //   {
  //     if (i >= 3 && i <= 5)
  // 	{
  // 	  this->_action.push_back("gauche");
  // 	  if (i == 5)
  // 	    this->_action.push_back("gauche");
  // 	}
  //     else if (i == 7 || i == 6)
  // 	this->_action.push_back("droite");
  //     this->_action.push_back("avance");
  //     if (i == 2 || i == 4)
  // 	this->_action.push_back("gauche");
  //     else if (i == 6 || i == 8)
  // 	this->_action.push_back("droite");
  //     this->_action.push_back("avance");
  //   }
}

bool			IA::goToCase(const std::string &cases, int i, int j)
{
  std::string				action = "prend " + cases;
  std::list<std::string>::iterator	it;

  if (i < 0)
    {
      this->_action.push_back("gauche");
      while (i++ < 0)
	this->_action.push_back("avance");
      this->_action.push_back("droite");
    }
  else if (i > 0)
    {
      this->_action.push_back("droite");
      while (i-- > 0)
	this->_action.push_back("avance");
      this->_action.push_back("gauche");
    }
  while (j-- > 0)
    this->_action.push_back("avance");
  this->_action.push_back(action);
  return (false);
}


//____INITIALIZE_FUNCTION_____

bool				IA::initialize(const std::string &add,
					       int port)
{
  if (!this->_socket.initialize(port, add))
    return (false);
  if (!this->_socket.clientConnect())
    return (false);
  this->_select.initialize(this->_socket.getFd(), 0, 10000);
  return (true);
}

std::map<const std::string, int>	IA::initLvl(int lvl, int linemate,
						    int derau, int sibur,
						    int mendiane, int phiras,
						    int thyst) const
{
  std::map<const std::string, int>		required;

  required["joueur"] = lvl;
  required["linemate"] = linemate;
  required["deraumere"] = derau;
  required["sibur"] = sibur;
  required["mendie"] = mendiane;
  required["phiras"] = phiras;
  required["thystame"] = thyst;
  return (required);
}

bool		IA::initOption(std::string &msg)
{
  std::stringstream	ss;

  ss << msg;
  if (this->_nb == -1)
    {
      msg.clear();
      ss >> this->_nb;
    }
  if (msg.size() > 1)
    {
      ss >> this->_pos.first;
      ss >> this->_pos.second;
    }
  else
    return (false);
  return (true);
}

//____UTILS_______________

void            my_handler(int s)
{
  std::cout << "\r***Exit : Caught signal [" << s << "].\n" << std::endl;
  g_run = false;
}
