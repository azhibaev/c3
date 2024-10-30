/*
 * File:  parse_c3_define_compare.h
 * Description: C3 extension parser for C programming language
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#define PARSE_C3_OCTET (c >= 0 && c <= 255)
#define PARSE_C3_CHAR (c >= 0 && c <= 127)
#define PARSE_C3_UPALPHA (c >= 'A' && c <= 'Z')
#define PARSE_C3_LOALPHA (c >= 'a' && c <= 'z')
#define PARSE_C3_ALPHA (PARSE_C3_UPALPHA || PARSE_C3_LOALPHA)
#define PARSE_C3_DIGIT (c >= '0' && c <= '9')
#define PARSE_C3_CTL ((c >= 0 && c <= 31) || c == 127)
#define PARSE_C3_CR (c == '\r')
#define PARSE_C3_LF (c == '\n')
#define PARSE_C3_SP (c == ' ')
#define PARSE_C3_HT (c == '\t')
#define PARSE_C3_DQ_MARK (c == '"')
#define PARSE_C3_HEX (c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f' || PARSE_C3_DIGIT)
#define PARSE_C3_SEPARATORS (c == '(' || c == ')' || c == '<' || c == '>' \
		|| c == ',' || c == ';' || c == ':' || c == '\\' \
		|| c == '"' || c == '/' || c == '[' || c == ']' \
		|| c == '?' || c == '=' || c == '{' || c == '}' \
		|| PARSE_C3_SP || PARSE_C3_HT)
#define PARSE_C3_UNDERLINE (c == '_')
#define PARSE_C3_OPERATOR (c == '!' || c == '\"' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '*' || c == '+' || c == '-' || c == '/' || c == '<' || c == '=' || c == '>' || c == '@' || c == '\\' || c == '^' || c == '_' || c == '`' || c == '|' || c == '~')
#define PARSE_C3_DIGIT_0 (c == '0')
#define PARSE_C3_DIGIT_OCTAL (c >= '0' && c <= '7')
#define PARSE_C3_ALPHA_E (c == 'E' || c == 'e')
#define PARSE_C3_ALPHA_F (c == 'F' || c == 'f')
#define PARSE_C3_ALPHA_L (c == 'L' || c == 'l')
#define PARSE_C3_ALPHA_U (c == 'U' || c == 'u')
#define PARSE_C3_ALPHA_X (c == 'X' || c == 'x')
#define PARSE_C3_ALPHA_HEX ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
#define PARSE_C3_ALPHA_NL (c == 'n')
#define PARSE_C3_ALPHA_LF (c == 'n')
#define PARSE_C3_ALPHA_HT (c == 't')
#define PARSE_C3_ALPHA_VT (c == 'v')
#define PARSE_C3_ALPHA_BS (c == 'b')
#define PARSE_C3_ALPHA_CR (c == 'r')
#define PARSE_C3_ALPHA_FF (c == 'f')
#define PARSE_C3_ALPHA_BEL (c == 'a')
#define PARSE_C3_ALPHA_BACKSLASH (c == '\\')
#define PARSE_C3_ALPHA_QUESTION_MARK (c == '?')
#define PARSE_C3_ALPHA_SINGLE_QUOTE (c == '\'')
#define PARSE_C3_ALPHA_DOUBLE_QUOTE (c == '\"')
#define PARSE_C3_ESCAPE_NL (c == '\n')
#define PARSE_C3_ESCAPE_LF (c == '\n')
#define PARSE_C3_ESCAPE_HT (c == '\t')
#define PARSE_C3_ESCAPE_VT (c == '\v')
#define PARSE_C3_ESCAPE_BS (c == '\b')
#define PARSE_C3_ESCAPE_CR (c == '\r')
#define PARSE_C3_ESCAPE_FF (c == '\f')
#define PARSE_C3_ESCAPE_BEL (c == '\a')

#define PARSE_C3_ESCAPE_BACKSLASH (c == '\\')
#define PARSE_C3_ESCAPE_QUESTION_MARK (c == '\?')
#define PARSE_C3_ESCAPE_SINGLE_QUOTE (c == '\'')
#define PARSE_C3_ESCAPE_DOUBLE_QUOTE (c == '\"')
#define PARSE_C3_ALPHA_ESCAPE (PARSE_C3_ALPHA_NL || PARSE_C3_ALPHA_LF || PARSE_C3_ALPHA_HT || PARSE_C3_ALPHA_VT || PARSE_C3_ALPHA_BS || PARSE_C3_ALPHA_CR || PARSE_C3_ALPHA_FF || PARSE_C3_ALPHA_BEL || PARSE_C3_ALPHA_BACKSLASH || PARSE_C3_ALPHA_QUESTION_MARK || PARSE_C3_ALPHA_SINGLE_QUOTE || PARSE_C3_ALPHA_DOUBLE_QUOTE)

