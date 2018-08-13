#include "statement.h"
#include "utils.h"
#include <iostream>
#include <stdlib.h>

namespace skiff
{
	namespace statements
	{
		using ::std::map;
		using ::std::queue;
		using ::std::string;
		using ::std::vector;

		using ::skiff::environment::skiff_object;
		using ::skiff::environment::skiff_class;
		using ::skiff::environment::skiff_function;
		using ::skiff::environment::scope;
        using ::skiff::environment::skiff_value;

        // It might be worth adding a flag for things that can be deallocated immediately

		skiff_object statement::eval(scope * env)
		{
			return skiff_object();
		}

		environment::skiff_object type_statement::eval(environment::scope *env) {
			return skiff_object((void *) env->get_type(this->name), env->get_type("skiff.lang.Class"));
		}

		skiff_object value::eval(scope * env)
		{
            if (!val.empty() && val.find_first_not_of("0123456789") == std::string::npos)
		    {
			    return skiff_object(atoi(val.c_str()), env->get_type("skiff.lang.Int"));
		    }
		    else if (!val.empty() && val.find_first_not_of("0123456789.") == std::string::npos)
		    {
			    return skiff_object(atof(val.c_str()), env->get_type("skiff.lang.Double"));
		    }
		    else if (!val.empty() && val[0] == '"' && val[val.length() - 1] == '"')
            {
                return skiff_object(string(val.substr(1, val.length() - 2)), env->get_type("skiff.lang.String"));
            }
            else if (!val.empty() && val[0] == '\'' && val[val.length() - 1] == '\'')
            {
                return skiff_object(string(val), env->get_type("skiff.lang.Sequence"));
            }
            return skiff_object();
        }

		environment::skiff_object boolean_value::eval(environment::scope *env) {
			return skiff_object(val, env->get_type("skiff.lang.Boolean"));
		}

        skiff_object assignment::eval(environment::scope * env)
        {
            skiff_object obj = name->eval(env);
            skiff_object new_obj = val->eval(env);
            obj.get_value()->set_value(new_obj.get_raw_value());
			obj.get_value()->set_class(new_obj.get_value()->get_class());
            return obj;
        }

        // Math in functions does not parse correctly

//        skiff_object math_statement::eval(scope * env)
//		{
//			queue<char> ops = operators;
//			queue<statement *> stmts = operands;
//			skiff_object collect = stmts.front()->eval(env);
//			stmts.pop();
//			while (!ops.empty())
//			{
//				collect = math_statement::eval_single_op(collect, ops.front(), stmts.front()->eval(env));
//				stmts.pop();
//				ops.pop();
//			}
//			return collect;
//		}
        
		skiff_object math_statement::eval_single_op(skiff_object s1, char op, skiff_object s2)
		{
//			skiff_class * clazz = math_statement::get_dominant_class(s1, s2);
//			if (clazz == nullptr)
//			{
//				clazz = s1.get_class();
//			}
//			vector<skiff_object> p = {
//                s1,
//                s2,
//                skiff_object(new skiff_value((void *) clazz), nullptr)
//            };
//			return clazz->invoke_operator(string(1, op), p);
			return skiff_object();
		}

        skiff_class * math_statement::get_dominant_class(skiff_object s1, skiff_object s2)
        {
//                string type_order[] = {
//					"Double"
//					"Float",
//					"Long",
//					"Int",
//					"Char"
//				};
//				for (string s : type_order)
//				{
//					if (s1.get_class()->get_name() == s)
//					{
//						return s1.get_class();
//					}
//					if (s1.get_class()->get_name() == s)
//					{
//						return s2.get_class();
//					}
//				}
			return nullptr;
        }

		skiff_object function_call::eval(scope * env)
		{
//			if (name == "print")
//			{
//				string tp;
//				for (statement * stmt : params)
//				{
//					skiff_object res = stmt->eval(env);
//					res = res.get_class()->get_scope()->get_function("to_string").eval(res);
//					tp += *((string *) res.get_value()->get_value());
//					tp += " ";
//				}
//				tp.erase(tp.length() - 1);
//				std::cout << tp << std::endl;
//			}
			return skiff_object();
		}

		skiff_object variable::eval(environment::scope * env)
		{
			return env->get_variable(name);
		}

		skiff_object self_modifier::eval(environment::scope * env)
		{
//			skiff_object obj = on->eval(env);
//			vector<skiff_object> params = {
//				obj,
//				skiff_object(new skiff_value(::skiff::utils::allocate(1)), env->get_type("Int")),
//                skiff_object(new skiff_value(obj.get_class()), nullptr)
//			};
//
//			// this was not the intent for this function, it should be fixed to match the design doc
//			if(type == PLUS)
//			{
//				obj.get_class()->invoke_operator(std::string(1, '+'), params);
//			}
//			else
//			{
//				obj.get_class()->invoke_operator(std::string(1, '-'), params);
//			}
//
//			return obj;
		}

		environment::skiff_object declaration_with_assignment::eval(environment::scope * env)
		{
			skiff_object obj = type.eval(env);
			skiff_class * clazz = (skiff_class *) type.eval(env).get_raw_value();
			env->set_variable(name, value->eval(env));
			return environment::skiff_object();
		}

//        skiff_object if_heading::eval(environment::scope * env)
//        {
//			skiff_object obj = condition->eval(env);
//            bool passed = *((bool *) obj.get_value()->get_value());
//			if(passed)
//			{
//				body->eval(env);
//			}
//			else
//			{
//				if(else_block != nullptr)
//				{
//					else_block->eval(env);
//				}
//			}
//            return skiff_object();
//        }

//		skiff_object else_heading::eval(environment::scope * env)
//		{
//			if(wrapping == nullptr)
//			{
//				body->eval(env);
//			}
//			else
//			{
//				wrapping->eval(env);
//			}
//			return skiff_object();
//		}

		skiff_object comparison::eval(environment::scope * env)
		{
//			skiff_object o1 = s1->eval(env);
//			skiff_object o2 = s2->eval(env);
//			vector<skiff_object> p = {
//				o1, o2
//			};
//			switch (typ)
//			{
//			case EQUAL:
//				return o1.get_class()->invoke_operator("==", p);
//			case NOT_EQUAL:
//			{
//				skiff_object res = o1.get_class()->invoke_operator("==", p);
//				bool * b = (bool *) res.get_value()->get_value();
//				*b = !(*b);
//				return res;
//			}
//			case LESS_THAN:
//				return o1.get_class()->invoke_operator("<", p);;
//			case LESS_THAN_EQUAL_TO:
//			{
//				skiff_object lt = o1.get_class()->invoke_operator("<", p);
//				skiff_object et = o1.get_class()->invoke_operator("==", p);
//				bool * lt_b = (bool *) lt.get_value()->get_value();
//				bool * et_b = (bool *) et.get_value()->get_value();
//
//				*lt_b = (*lt_b) || (*et_b);
//
//				return lt;
//			}
//			case GREATER_THAN:
//				return o1.get_class()->invoke_operator(">", p);
//			case GREATER_THAN_EQUAL_TO:
//			{
//				skiff_object gt = o1.get_class()->invoke_operator(">", p);
//				skiff_object et = o1.get_class()->invoke_operator("==", p);
//				bool * gt_b = (bool *) gt.get_value()->get_value();
//				bool * et_b = (bool *) et.get_value()->get_value();
//
//				*gt_b = (*gt_b) || (*et_b);
//
//				return gt;
//			}
//			}
			return skiff_object();
		}

//		skiff_object braced_block::eval(scope * env)
//		{
//			while(!this->stmts.empty())
//			{
//				stmts.front()->eval(env);
//				stmts.pop();
//			}
//			return skiff_object();
//		}

    }

}