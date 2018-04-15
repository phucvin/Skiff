#pragma once
#include <string>
#include <stack>
#include <vector>
#include "statement.h"
#include "types.h"

using std::stack;
using std::vector;
using std::string;

statement * parse_statement(string stmt);

bool handle_line(string input, char c, queue<statement *> * stmts);
