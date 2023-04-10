#pragma once
#include <string>

double postfix(std::string& sir);
double operatia(double t1, double t2, char op);
void Inf2Post(std::string sir, std::string& rez);
void pushOp(StackT<char>& s, std::string& rez, char c);
bool prioritate(char c1, char c2);
void Post2Pre(std::string s_postfix, std::string& s_prefix);
double prefix(std::string s);