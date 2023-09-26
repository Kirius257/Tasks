#ifndef _LISTGROUP_H
#define _LISTGROUP_H


#include "StudentGroup.h"
#include <fstream>

class ListGroups {
public:
	ListGroups();//default constructor
	ListGroups(const string& path);//read file with list groups
	ListGroups(const ListGroups& obj);//copy groups
	~ListGroups();//delete list groups

	//
	Group** list;//array pointers to groups
	int count_groups;//count groups

	ListGroups& operator=(const ListGroups& obj);
};


#endif
