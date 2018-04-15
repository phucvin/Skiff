#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <fstream>
#include "../Core/types.h"
#include "../Core/statement.h"
#include "../Core/parsers.h"
#include "../Core/utils.h"
#include "../Core/builtin.h"
#include "../Core/modes.h"

using std::string;
using std::map;
using std::stack;
using std::vector;

scope env;

int main()
{
	builtin_load::load_standards(&env);
	//interactive_mode();
	queue<statement *> test_statements = parse_file("test.su");
	print_parse(test_statements);
	//evaluate(test_statements);
	//system("pause");
	//queue<statement *> trans_statements = parse_file("pos_c.su");
	//print_parse(trans_statements);
	//translate_c(trans_statements);
	system("pause");
}

