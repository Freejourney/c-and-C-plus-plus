// tabtenn1.h -- a table - tennis base class
#ifndef TABTENN1_H_
#define TABTENN1_H_

#include <string>
using std::string;

class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string & fn = "no one", const string & ln = "no one", const bool & ht = false);
	
	void Name() const;
	bool HasTable() const {return hasTable;};//声明的同时定义后大括号外可以加分号 
	void ResetTable(bool v) { hasTable = v;};	
};

class RatedPlayer:public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "no one", const string & ln = "no one", const bool  ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
	
	unsigned int Rating() const {return rating;}
	void ResetRating(unsigned int r) {rating = r;}
};

#endif
