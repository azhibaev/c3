/*
 * File:  parse_c.h
 * Description: C language parser created with grammar from Section A13 of The C programming language, 2nd edition, by Brian W. Kernighan and Dennis M. Ritchie,Prentice Hall, 1988.
 * Author: Askar Azhibaev
 * Date: May 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef PARSE_C_H
#define PARSE_C_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

FUNCTION_INLINE int FUNC(translation_unit)(char_string *s);
FUNCTION_INLINE int FUNC(external_declaration)(char_string *s);
FUNCTION_INLINE int FUNC(function_definition)(char_string *s);
FUNCTION_INLINE int FUNC(declaration)(char_string *s);
FUNCTION_INLINE int FUNC(declaration_list)(char_string *s);
FUNCTION_INLINE int FUNC(declaration_specifiers)(char_string *s);
FUNCTION_INLINE int FUNC(storage_class_specifier)(char_string *s);
FUNCTION_INLINE int FUNC(type_specifier)(char_string *s);
FUNCTION_INLINE int FUNC(type_qualifier)(char_string *s);
FUNCTION_INLINE int FUNC(struct_or_union_specifier)(char_string *s);
FUNCTION_INLINE int FUNC(struct_or_union)(char_string *s);
FUNCTION_INLINE int FUNC(struct_declaration_list)(char_string *s);
FUNCTION_INLINE int FUNC(init_declarator_list)(char_string *s);
FUNCTION_INLINE int FUNC(init_declarator)(char_string *s);
FUNCTION_INLINE int FUNC(struct_declaration)(char_string *s);
FUNCTION_INLINE int FUNC(specifier_qualifier_list)(char_string *s);
FUNCTION_INLINE int FUNC(struct_declarator_list)(char_string *s);
FUNCTION_INLINE int FUNC(struct_declarator)(char_string *s);
FUNCTION_INLINE int FUNC(enum_specifier)(char_string *s);
FUNCTION_INLINE int FUNC(enumerator_list)(char_string *s);
FUNCTION_INLINE int FUNC(enumerator)(char_string *s);
FUNCTION_INLINE int FUNC(declarator)(char_string *s);
FUNCTION_INLINE int FUNC(direct_declarator)(char_string *s);
FUNCTION_INLINE int FUNC(pointer)(char_string *s);
FUNCTION_INLINE int FUNC(type_qualifier_list)(char_string *s);
FUNCTION_INLINE int FUNC(parameter_type_list)(char_string *s);
FUNCTION_INLINE int FUNC(parameter_list)(char_string *s);
FUNCTION_INLINE int FUNC(parameter_declaration)(char_string *s);
FUNCTION_INLINE int FUNC(identifier_list)(char_string *s);
FUNCTION_INLINE int FUNC(initializer)(char_string *s);
FUNCTION_INLINE int FUNC(initializer_list)(char_string *s);
FUNCTION_INLINE int FUNC(type_name)(char_string *s);
FUNCTION_INLINE int FUNC(abstract_declarator)(char_string *s);
FUNCTION_INLINE int FUNC(direct_abstract_declarator)(char_string *s);
FUNCTION_INLINE int FUNC(typedef_name)(char_string *s);
FUNCTION_INLINE int FUNC(statement)(char_string *s);
FUNCTION_INLINE int FUNC(labeled_statement)(char_string *s);
FUNCTION_INLINE int FUNC(expression_statement)(char_string *s);
FUNCTION_INLINE int FUNC(compound_statement)(char_string *s);
FUNCTION_INLINE int FUNC(statement_list)(char_string *s);
FUNCTION_INLINE int FUNC(selection_statement)(char_string *s);
FUNCTION_INLINE int FUNC(iteration_statement)(char_string *s);
FUNCTION_INLINE int FUNC(jump_statement)(char_string *s);
FUNCTION_INLINE int FUNC(expression)(char_string *s);
FUNCTION_INLINE int FUNC(assignment_expression)(char_string *s);
FUNCTION_INLINE int FUNC(assignment_operator)(char_string *s);
FUNCTION_INLINE int FUNC(conditional_expression)(char_string *s);
FUNCTION_INLINE int FUNC(constant_expression)(char_string *s);
FUNCTION_INLINE int FUNC(logical_or_expression)(char_string *s);
FUNCTION_INLINE int FUNC(logical_and_expression)(char_string *s);
FUNCTION_INLINE int FUNC(inclusive_or_expression)(char_string *s);
FUNCTION_INLINE int FUNC(exclusive_or_expression)(char_string *s);
FUNCTION_INLINE int FUNC(and_expression)(char_string *s);
FUNCTION_INLINE int FUNC(equality_expression)(char_string *s);
FUNCTION_INLINE int FUNC(relational_expression)(char_string *s);
FUNCTION_INLINE int FUNC(shift_expression)(char_string *s);
FUNCTION_INLINE int FUNC(additive_expression)(char_string *s);
FUNCTION_INLINE int FUNC(multiplicative_expression)(char_string *s);
FUNCTION_INLINE int FUNC(cast_expression)(char_string *s);
FUNCTION_INLINE int FUNC(unary_expression)(char_string *s);
FUNCTION_INLINE int FUNC(unary_operator)(char_string *s);
FUNCTION_INLINE int FUNC(postfix_expression)(char_string *s);
FUNCTION_INLINE int FUNC(primary_expression)(char_string *s);
FUNCTION_INLINE int FUNC(constant)(char_string *s);
FUNCTION_INLINE int FUNC(assignment_expression_list)(char_string *s);
FUNCTION_INLINE int FUNC(constant)(char_string *s);
FUNCTION_INLINE int FUNC(enumeration_constant)(char_string *s);

FUNCTION_INLINE int FUNC(translation_unit)(char_string *s)
{
	int is_set = 1;

	if (char_string_check(s))
	{
		while (FUNC(external_declaration)(s))
		{
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(external_declaration)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(function_definition)(s))
		{
			is_set = 1;
		}
		else if (FUNC(declaration)(s))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(function_definition)(char_string *s)
{
	int is_set = 0;
	int is_declarator = 0;
	int is_compound_statement = 0;

	if (char_string_check(s))
	{
		if (FUNC(declaration_specifiers))
		{
			is_set++;
		}
		if (FUNC(declarator)(s))
		{
			is_declarator = 1;
		}
		if (FUNC(declaration_list))
		{
			is_set++;
		}
		if (FUNC(compound_statement)(s))
		{
			is_compound_statement = 1;
		}
	}

	if (is_declarator &&
			is_compound_statement)
	{
		is_set++;
	}
	else
	{
		is_set = 0;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(declaration)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(declaration_specifiers)(s))
		{
			is_set++;
			if (FUNC(init_declarator_list)(s))
			{
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(declaration_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		while (FUNC(declaration)(s))
		{
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(declaration_specifiers)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(storage_class_specifier)(s))
		{
			is_set = 1;
			if (FUNC(declaration_specifiers)(s))
			{
			}
		}
		else if (FUNC(type_specifier)(s))
		{
			is_set = 1;
			if (FUNC(declaration_specifiers)(s))
			{
			}
		}
		else if (FUNC(type_qualifier)(s))
		{
			is_set = 1;
			if (FUNC(declaration_specifiers)(s))
			{
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(storage_class_specifier)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "auto"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "register"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "static"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "extern"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "typedef"))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(type_specifier)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "void"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "char"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "short"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "int"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "long"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "float"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "double"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "signed"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "unsigned"))
		{
			is_set = 1;
		}
		else if (FUNC(struct_or_union_specifier)(s))
		{
			is_set = 1;
		}
		else if (FUNC(enum_specifier)(s))
		{
			is_set = 1;
		}
		else if (FUNC(typedef_name)(s))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(type_qualifier)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "const"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "volatile"))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(struct_or_union_specifier)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(struct_or_union)(s))
		{
			if (FUNC(identifier)(s))
			{
			}
			if (FUNC(ch)(s, '{'))
			{
				if (FUNC(struct_declaration_list)(s))
				{
					if (FUNC(ch)(s, '}'))
					{
						is_set = 1;
						return is_set;
					}
				}
			}
		}
		if (FUNC(struct_or_union)(s))
		{
			if (FUNC(identifier)(s))
			{
				is_set = 1;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(struct_or_union)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "struct"))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "union"))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(struct_declaration_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		while (FUNC(struct_declaration)(s))
		{
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(init_declarator_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(init_declarator)(s))
		{
			is_set++;
		}
		else if (FUNC(init_declarator_list)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(init_declarator)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(init_declarator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(declarator)(s))
		{
			is_set++;
			if (FUNC(ch)(s, '='))
			{
				if (FUNC(initializer)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}


FUNCTION_INLINE int FUNC(struct_declaration)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(specifier_qualifier_list)(s))
		{
			if (FUNC(struct_declarator_list)(s))
			{
				if (FUNC(ch)(s, ';'))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(specifier_qualifier_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(type_specifier)(s))
		{
			is_set = 1;
			if (FUNC(specifier_qualifier_list)(s))
			{
			}
		}
		else if (FUNC(type_qualifier)(s))
		{
			is_set = 1;
			if (FUNC(specifier_qualifier_list)(s))
			{
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(struct_declarator_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(struct_declarator)(s))
		{
			is_set = 1;
		}
		else if (FUNC(struct_declarator_list)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(struct_declarator)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(struct_declarator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(declarator)(s))
		{
			is_set++;
		}
		if (FUNC(ch)(s, ':'))
		{
			if (FUNC(constant_expression)(s))
			{
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(enum_specifier)(char_string *s)
{
	int is_set = 0;
	int is_identifier = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "enum"))
		{
			if (FUNC(identifier)(s))
			{
				is_identifier = 1;
			}
			if (FUNC(ch)(s, '{'))
			{
				if (FUNC(enumerator_list)(s))
				{
					if (FUNC(ch)(s, '}'))
					{
						is_set++;
						return is_set;
					}
				}
			}
			if (is_identifier)
			{
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(enumerator_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(enumerator)(s))
		{
			is_set++;
		}
		else if (FUNC(enumerator_list)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(enumerator)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(enumerator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(identifier)(s))
		{
			is_set++;
			if (FUNC(ch)(s, '='))
			{
				if (FUNC(constant_expression)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}


FUNCTION_INLINE int FUNC(declarator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(pointer)(s))
		{
		}
		if (FUNC(direct_declarator)(s))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(direct_declarator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(identifier)(s))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '('))
		{
			if (FUNC(declarator)(s))
			{
				if (FUNC(ch)(s, ')'))
				{
					is_set = 1;
					return is_set;
				}
			}
		}
		if (FUNC(direct_declarator)(s))
		{
			if (FUNC(ch)(s, '['))
			{
				if (FUNC(constant_expression)(s))
				{
				}
				if (FUNC(ch)(s, ']'))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(ch)(s, '('))
			{
				if (FUNC(parameter_type_list)(s))
				{
					if (FUNC(ch)(s, ')'))
					{
						is_set = 1;
						return is_set;
					}
				}
			}
			if (FUNC(ch)(s, '('))
			{
				if (FUNC(identifier_list)(s))
				{
				}
				if (FUNC(ch)(s, ')'))
				{
					is_set = 1;
					return is_set;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(pointer)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(ch)(s, '*'))
		{
			if (FUNC(type_qualifier_list)(s))
			{
				is_set++;
			}
			if (FUNC(pointer)(s))
			{
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(type_qualifier_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		while (FUNC(type_qualifier)(s))
		{
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(parameter_type_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(parameter_list)(s))
		{
			is_set++;
		}
		if (FUNC(ch)(s, ','))
		{
			if (FUNC(char)(s, "..."))
			{
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(parameter_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(parameter_declaration)(s))
		{
			is_set++;
		}
		else if (FUNC(parameter_list)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(parameter_declaration)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(parameter_declaration)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(declaration_specifiers)(s))
		{
			if (FUNC(declaration)(s))
			{
				is_set++;
			}
			else
			{
				if (FUNC(abstract_declarator)(s))
				{
				}
				is_set++;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(identifier_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(identifier)(s))
		{
			is_set++;
		}
		else if (FUNC(identifier_list)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(identifier)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(initializer)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(assignment_expression)(s))
		{
			is_set++;
		}
		else if (FUNC(ch)(s, '{'))
		{
			if (FUNC(initializer_list)(s))
			{
				if (FUNC(ch)(s, ','))
				{
				}
				if (FUNC(ch)(s, '}'))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(initializer_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(initializer)(s))
		{
			is_set++;
		}
		else if (FUNC(initializer_list)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(initializer)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(type_name)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(specifier_qualifier_list)(s))
		{
			is_set++;
			if (FUNC(abstract_declarator)(s))
			{
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(abstract_declarator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(pointer)(s))
		{
			is_set++;
		}
		if (FUNC(direct_abstract_declarator)(s))
		{
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(direct_abstract_declarator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(ch)(s, '('))
		{
			if (FUNC(abstract_declarator)(s))
			{
				if (FUNC(ch)(s, ')'))
				{
					is_set++;
					return is_set;
				}
			}
		}
		if (FUNC(direct_abstract_declarator)(s))
		{
		}
		if (FUNC(ch)(s, '['))
		{
			if (FUNC(constant_expression)(s))
			{
			}
			if (FUNC(ch)(s, ']'))
			{
				is_set++;
				return is_set;
			}
		}
		if (FUNC(ch)(s, '('))
		{
			if (FUNC(parameter_type_list)(s))
			{
			}
			if (FUNC(ch)(s, ')'))
			{
				is_set++;
				return is_set;
			}
		}

	}

	return is_set;
}

FUNCTION_INLINE int FUNC(typedef_name)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(identifier)(s))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(statement)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(labeled_statement)(s))
		{
			is_set++;
		}
		else if (FUNC(expression_statement)(s))
		{
			is_set++;
		}
		else if (FUNC(compound_statement)(s))
		{
			is_set++;
		}
		else if (FUNC(selection_statement)(s))
		{
			is_set++;
		}
		else if (FUNC(iteration_statement)(s))
		{
			is_set++;
		}
		else if (FUNC(jump_statement)(s))
		{
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(labeled_statement)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(identifier)(s))
		{
			if (FUNC(ch)(s, ':'))
			{
				if (FUNC(statement)(s))
				{
					is_set++;
					return is_set;
				}
			}
		}
		if (FUNC(char)(s, "case"))
		{
			if (FUNC(constant_expression)(s))
			{
				if (FUNC(ch)(s, ':'))
				{
					if (FUNC(statement)(s))
					{
						is_set++;
						return is_set;
					}
				}
			}		
		}		
		if (FUNC(char)(s, "default"))
		{
			if (FUNC(ch)(s, ':'))
			{
				if (FUNC(statement)(s))
				{
					is_set++;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(expression_statement)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(expression)(s))
		{
		}
		is_set++;
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(compound_statement)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(ch)(s, '{'))
		{
			if (FUNC(declaration_list)(s))
			{
				is_set++;
			}
			if (FUNC(statement_list)(s))
			{
				is_set++;
			}
			if (FUNC(ch)(s, '}'))
			{
				is_set++;
			}
			else
			{
				is_set = 0;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(statement_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		while (FUNC(statement)(s))
		{
			is_set++;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(selection_statement)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "if"))
		{
			if (FUNC(ch)(s, '('))
			{
				if (FUNC(expression)(s))
				{
					if (FUNC(ch)(s, ')'))
					{
						if (FUNC(statement)(s))
						{
							if (FUNC(char)(s, "else"))
							{
								if (FUNC(statement)(s))
								{
									is_set++;
									return is_set;
								}
							}
							else
							{
								is_set++;
								return is_set;
							}
						}
					}
				}
			}
		}
		if (FUNC(char)(s, "switch"))
		{
			if (FUNC(ch)(s, '('))
			{
				if (FUNC(expression)(s))
				{
					if (FUNC(ch)(s, ')'))
					{
						if (FUNC(statement)(s))
						{
							is_set++;
							return is_set;
						}
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(iteration_statement)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "while"))
		{
			if (FUNC(ch)(s, '('))
			{
				if (FUNC(expression)(s))
				{
					if (FUNC(ch)(s, ')'))
					{
						if (FUNC(statement)(s))
						{
							is_set++;
							return is_set;
						}
					}
				}
			}
		}
		if (FUNC(char)(s, "do"))
		{
			if (FUNC(statement)(s))
			{
				if (FUNC(char)(s, "while"))
				{
					if (FUNC(ch)(s, '('))
					{
						if (FUNC(expression)(s))
						{
							if (FUNC(ch)(s, ')'))
							{
								if (FUNC(ch)(s, ';'))
								{
									is_set++;
									return is_set;
								}
							}
						}
					}
				}
			}
		}
		if (FUNC(char)(s, "for"))
		{
			if (FUNC(ch)(s, '('))
			{
				if (FUNC(expression)(s))
				{
				}
				if (FUNC(ch)(s, ';'))
				{
					if (FUNC(expression)(s))
					{
					}
					if (FUNC(ch)(s, ';'))
					{
						if (FUNC(expression)(s))
						{
						}
						if (FUNC(ch)(s, ')'))
						{
							if (FUNC(statement)(s))
							{
								is_set++;
								return is_set;
							}
						}
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(jump_statement)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(char)(s, "goto"))
		{
			if (FUNC(identifier)(s))
			{
				if (FUNC(ch)(s, ';'))
				{
					is_set++;
					return is_set;
				}
			}
		}
		if (FUNC(char)(s, "continue"))
		{
			if (FUNC(ch)(s, ';'))
			{
				is_set++;
				return is_set;
			}
		}
		if (FUNC(char)(s, "break"))
		{
			if (FUNC(ch)(s, ';'))
			{
				is_set++;
				return is_set;
			}
		}
		if (FUNC(char)(s, "return"))
		{
			if (FUNC(expression)(s))
			{
			}
			is_set++;
			return is_set;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(assignment_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(expression)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(assignment_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(assignment_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(conditional_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(unary_expression)(s))
		{
			if (FUNC(assignment_operator)(s))
			{
				if (FUNC(assignment_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(assignment_operator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(ch)(s, '='))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "*="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "/="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "%="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "+="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "-="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "<<="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, ">>="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "&="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "^="))
		{
			is_set = 1;
		}
		else if (FUNC(char)(s, "|="))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(conditional_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(logical_or_expression)(s))
		{
			is_set++;
		}
		if (FUNC(ch)(s, '?'))
		{
			if (FUNC(expression)(s))
			{
				if (FUNC(ch)(s, ':'))
				{
					if (FUNC(conditional_expression)(s))
					{
						is_set++;
					}
				}
			}
		}
	}

	return is_set;
}


FUNCTION_INLINE int FUNC(constant_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(conditional_expression)(s))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(logical_or_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(logical_and_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(logical_or_expression)(s))
		{
			if (FUNC(char)(s, "||"))
			{
				if (FUNC(logical_and_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(logical_and_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(inclusive_or_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(logical_and_expression)(s))
		{
			if (FUNC(char)(s, "&&"))
			{
				if (FUNC(inclusive_or_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(inclusive_or_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(exclusive_or_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(inclusive_or_expression)(s))
		{
			if (FUNC(ch)(s, '|'))
			{
				if (FUNC(exclusive_or_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(exclusive_or_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(and_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(exclusive_or_expression)(s))
		{
			if (FUNC(ch)(s, '^'))
			{
				if (FUNC(and_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(and_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(equality_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(and_expression)(s))
		{
			if (FUNC(ch)(s, '&'))
			{
				if (FUNC(equality_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(equality_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(relational_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(equality_expression)(s))
		{
			if (FUNC(char)(s, "=="))
			{
				if (FUNC(relational_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(char)(s, "!="))
			{
				if (FUNC(relational_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(relational_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(shift_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(relational_expression)(s))
		{
			if (FUNC(ch)(s, '<'))
			{
				if (FUNC(shift_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(ch)(s, '>'))
			{
				if (FUNC(shift_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(char)(s, "<="))
			{
				if (FUNC(shift_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(char)(s, ">="))
			{
				if (FUNC(shift_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(shift_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(additive_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(shift_expression)(s))
		{
			if (FUNC(char)(s, "<<"))
			{
				if (FUNC(additive_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(char)(s, ">>"))
			{
				if (FUNC(additive_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(additive_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(multiplicative_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(additive_expression)(s))
		{
			if (FUNC(ch)(s, '+'))
			{
				if (FUNC(multiplicative_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(ch)(s, '-'))
			{
				if (FUNC(multiplicative_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(multiplicative_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(cast_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(multiplicative_expression)(s))
		{
			if (FUNC(ch)(s, '*'))
			{
				if (FUNC(cast_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(ch)(s, '/'))
			{
				if (FUNC(cast_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(ch)(s, '%'))
			{
				if (FUNC(cast_expression)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
		}

	}

	return is_set;
}

FUNCTION_INLINE int FUNC(cast_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(unary_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '('))
		{
			if (FUNC(type_name)(s))
			{
				if (FUNC(ch)(s, ')'))
				{
					if (FUNC(cast_expression)(s))
					{
						is_set = 1;
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(unary_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(postfix_expression)(s))
		{
			is_set = 1;
			return is_set;
		}
		if (FUNC(char)(s, "++"))
		{
			if (FUNC(unary_expression)(s))
			{
				is_set = 1;
				return is_set;
			}
		}
		if (FUNC(char)(s, "--"))
		{
			if (FUNC(unary_expression)(s))
			{
				is_set = 1;
				return is_set;
			}
		}
		if (FUNC(unary_operator)(s))
		{
			if (FUNC(cast_expression)(s))
			{
				is_set = 1;
				return is_set;
			}
		}
		if (FUNC(char)(s, "sizeof"))
		{
			if (FUNC(unary_expression)(s))
			{
				is_set = 1;
				return is_set;
			}
			else if (FUNC(ch)(s, '('))
			{
				if (FUNC(type_name)(s))
				{
					if (FUNC(ch)(s, ')'))
					{
						is_set = 1;
						return is_set;
					}
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(unary_operator)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(ch)(s, '&'))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '*'))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '+'))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '-'))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '~'))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '!'))
		{
			is_set = 1;
		}
	}

	return is_set;
}


FUNCTION_INLINE int FUNC(postfix_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(primary_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(postfix_expression)(s))
		{
			if (FUNC(ch)(s, '['))
			{
				if (FUNC(expression)(s))
				{
					if (FUNC(ch)(s, ']'))
					{
						is_set = 1;
						return is_set;
					}
				}
			}
			if (FUNC(ch)(s, '('))
			{
				if (FUNC(assignment_expression_list)(s))
				{
				}
				if (FUNC(ch)(s, ')'))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(ch)(s, '.'))
			{
				if (FUNC(identifier)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(char)(s, "->"))
			{
				if (FUNC(identifier)(s))
				{
					is_set = 1;
					return is_set;
				}
			}
			if (FUNC(char)(s, "++"))
			{
				is_set = 1;
				return is_set;
			}
			if (FUNC(char)(s, "--"))
			{
				is_set = 1;
				return is_set;
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(primary_expression)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(identifier)(s))
		{
			is_set = 1;
		}
		else if (FUNC(constant)(s))
		{
			is_set = 1;
		}
		else if (FUNC(string)(s))
		{
			is_set = 1;
		}
		else if (FUNC(ch)(s, '('))
		{
			if (FUNC(expression)(s))
			{
				if (FUNC(ch)(s, ')'))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(assignment_expression_list)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(assignment_expression)(s))
		{
			is_set = 1;
		}
		else if (FUNC(assignment_expression_list)(s))
		{
			if (FUNC(ch)(s, ','))
			{
				if (FUNC(assignment_expression)(s))
				{
					is_set = 1;
				}
			}
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(constant)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(integer_constant)(s))
		{
			is_set = 1;
		}
		else if (FUNC(character_constant)(s))
		{
			is_set = 1;
		}
		else if (FUNC(floating_constant)(s))
		{
			is_set = 1;
		}
		else if (FUNC(enumeration_constant)(s))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(enumeration_constant)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (FUNC(identifier)(s))
		{
			is_set = 1;
		}
	}

	return is_set;
}

FUNCTION_INLINE int FUNC(keyword)(char_string *s)
{
	int is_set = 0;

	if (char_string_check(s))
	{
		if (0)
		{
		}
#define ITEM(s_i) \
		else if (FUNC(char)(s, s_i)) \
		{ \
			is_set = 1; \
		}
#include "parse_c_keyword.h"
#undef ITEM
	}

	return is_set;
}

#endif	/* PARSE_C_H */

