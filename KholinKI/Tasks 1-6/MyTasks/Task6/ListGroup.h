#ifndef _LISTGROUP_H
#define _LISTGROUP_H

#include "framework.h"
#include "StudentGroup.h"
#include <fstream>

class ListGroups {
private:
	Group** list;
	int count_groups;
	/*void realloc();*/
public:
	ListGroups();
	ListGroups(const string& path);
	ListGroups(const ListGroups& obj);
	~ListGroups();

	//
	//void add_entry(const Student& person);
	//void delete_entry(int index);

	//ListGroups& operator=(const ListGroups& obj);
};


#endif
