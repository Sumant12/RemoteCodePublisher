#pragma once
///////////////////////////////////////////////////////////////
// TypeAnalysis.h -              //
// Ver 1.6                                                   //
// Language:     Visual C++ 2015                             //
// Platform:     Mac Machine , Windows 7  Virtual Machine    //
// Application:  for CSE687 - OOD, Pr#2, Spring 2017         //
// Author:      Saisumanth Gopisetty, Syracuse University    //
//              (248) 828-6589, sgopiset@syr.edu             //
///////////////////////////////////////////////////////////////
//*Operations:
//*This packages is used to build the Type table which gives information
//*about the various Interfaces, Structs, Classes and Enums present in the whole package
//*The Type table consists of the type ,name and the file name.
//*Required files
//*ActionsAndRules.h and ActionsAndRules.cpp

#include "../Parser/ActionsAndRules.h"
#include <iostream>
#include <functional>
#include "../Utilities/Utilities.h"
using namespace Utilities;

#pragma warning (disable : 4101)  // disable warning re unused variable x, below

namespace CodeAnalysis
{
	class TypeAnalysis
	{
	public:
		using SPtr = std::shared_ptr<ASTNode*>;
		//----< Performs the Type Analysis >--------------
		TypeAnalysis();
		void doTypeAnalysis();
		//----< Returns the type table which is constructed >--------------
		TypeTable& getTypeTable() { return typeTableInfo; }
		//----< Displays the Typetable >--------------
		void displayTypeTable() { typeTableInfo.displayTypeTable(); }
	private:
		//----< Provides a DFS on the graph, a walk >--------------
		void DepthFirstSearch(ASTNode* pNode);
		AbstrSynTree& ASTref_;
		ScopeStack<ASTNode*> scopeStack_;
		Scanner::Toker& toker_;
		TypeTable &typeTableInfo;
		//TypeTable &Functable;
	};

	
	inline TypeAnalysis::TypeAnalysis() :
		ASTref_(Repository::getInstance()->AST()),
		scopeStack_(Repository::getInstance()->scopeStack()),
		toker_(*(Repository::getInstance()->Toker())),
		typeTableInfo(Repository::getInstance()->typeTable())
	{
		 
		std::function<void()> test = [] { int x; };  

	}


	//----Thsi method displays the Type Table
	inline bool displayTypeTable(ASTNode* pNode)
	{
		static std::string toDisplay[] = {
			"function", "lambda", "class", "struct", "enum", "alias", "typedef"
		};
		for (std::string type : toDisplay)
		{
			if (pNode->type_ == type)
				return true;
		}
		return false;
	}

	//This method performs the DFS on a AST Node
	inline void TypeAnalysis::DepthFirstSearch(ASTNode* pNode)
	{
		static std::string path = "";
		if (pNode->path_ != path)
		{
			path = pNode->path_ + "\\" + pNode->package_;
	
		}
	

		if ((pNode->type_ == "class") || (pNode->type_ == "struct") || (pNode->type_ == "interface") || (pNode->type_ == "enum") /*|| (pNode->type_ == "function")*/ )
		{


			DataStruct s1;
			s1.name = pNode->name_;
			s1.type = pNode->type_;
			s1.filename = pNode->path_;
			typeTableInfo.FeddTypeTable(pNode->name_,s1);
		}
		for (auto pChild : pNode->children_)
			DepthFirstSearch(pChild);
	}

	inline void TypeAnalysis::doTypeAnalysis()
	{
	
		ASTNode* pRoot = ASTref_.root();
		DepthFirstSearch(pRoot);
	}
}