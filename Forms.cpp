#include <iostream>
#include <string>
#include "StackT.h"
#include "Forms.h"

double postfix(std::string& sir)
{
	StackT<double> s;
	double t1, t2;

	double rez = 0;
	int i = 0;

	while (sir[i] != '\0')
	{
		if (sir[i] <= 57 && sir[i] >= 48)
		{
			s.push(sir[i] - '0');
		}
		else
		{
			if (sir[i] >= 42 && sir[i] <= 47)
			{
				t1 = s.top();
				s.pop();
				t2 = s.top();
				s.pop();
				rez = operatia(t1, t2, sir[i]);
				s.push(rez);
			}
			else
			{
				std::cout << "\n!!! Eroare !!!\nIn sir apare element ce nu e nici operand,nici operator\n";
			}
		}
		i++;
	}

	return s.top();
}

double operatia(double t1, double t2, char op)
{
	double rez;

	switch (op)
	{
	case 42:
		rez = t2 * t1;
		break;
	case 43:
		rez = t2 + t1;
		break;
	case 45:
		rez = t2 - t1;
		break;
	case '/':
		rez = t2 / t1;
		break;
	default:
		std::cout << "Nu e un operator\n";
		rez = 0;
	}

	return rez;
}


void Inf2Post(std::string sir, std::string& rez)   //  Transforma forma infixata (memorata in sir) in forma postfixata (memorata in rez)
{
	StackT<char> s;
	int i = 0;

	while (sir[i] != '\0')               // Analizam sirul sir caracter cu caracter
	{
		if (sir[i] <= 57 && sir[i] >= 48)     // Verificam daca caracterul analizat (din string-ul sir) este un numar (0-9
		{
			rez.push_back(sir[i]);           // Adaugam caracterul in sirul rez(forma postfixata)
		}
		else
		{
			if (sir[i] >= 40 && sir[i] <= 47)  // Verificam daca caracterul analizat este un operator sau paranteza rotunda(  +, -, ), (, *, /   )
			{
				pushOp(s,rez, sir[i]);             //  In functie de prioritatea operatorului trebuie fie de adaugar caracterul analizat in stack,fie de scos anumiti operatori din stack
			}
			else
			{
				std::cout << "\n!!! Eroare !!!\nIn sir apare element ce nu e nici operant,nici operator\n";
			}
		}

		i++;
	}
	while (!s.isEmpty())   // Golim stack-ul
	{
		rez.push_back(s.top());
		s.pop();
	}
}

void pushOp(StackT<char>& s, std::string& rez, char c)  
{
	if (c != 40 && c != 41)    // Verificam daca caracterul analizat e un operator(nu e paranteza)
	{
		if (!s.isEmpty())
		{
			if (prioritate(c, s.top()))    // Daca c are prioritate mai mare,acesta se pune pe stack
			{
				s.push(c);
			}
			else
			{
				while (!s.isEmpty() && !prioritate(c, s.top()))  // Daca c nu are prioritate mai mare,scoatem 
				{												//din stack operatorii pana gasim un operator cu prioritate mai mica
					rez.push_back(s.top());
					s.pop();
				}
				s.push(c);
			}
		}
		else
		{
			s.push(c);
		}
	}
	else
	{
		if (c == 40)  // Daca gasim un caracter paranteza deschisa,simplu il adaugam in stack
		{
			s.push(c);
		}
		else
		{
			while (s.top() != 40)   //Daca gasim un caracter paranteza inchisa,scoatem toti
			{						// operatorii pana gasim o paranteza deschisa
				if (!s.isEmpty())
				{
					rez.push_back(s.top());
					s.pop();
				}
				else
				{
					std::cout << "Eroare : incercam sa adaugam ) in lista vida\n";
				}
			}
			s.pop();   // Scoatem paranteza deschisa
		}
	}
}

bool prioritate(char c1, char c2)  // c1 - operator nou    c2 - op din vs
{
	int p1, p2;
	
	switch (c1)
	{
	case 42:
	case 47:
		p1 = 2;      // * si / au prioritate maxima (2)
		break;
	case 43:
	case 45:
		p1 = 1;   // + si - au prioritate 1
		break;
	case 40:
		p1 = 0;   // paranteza deschisa(/) are orioritatea cea mai mica
		break;
	default :
		std::cout << "Nu e operator\n";
		p1 = -1;
		break;
	}

	switch (c2)
	{
	case 42:
	case 47:
		p2 = 2;
		break;
	case 43:
	case 45:
		p2 = 1;
		break;
	case 40:
		p2 = 0;
		break;
	default:
		std::cout << "Nu e operator\n";
		p2 = -1;
		break;
	}

	if (p1 > p2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Post2Pre(std::string s_postfix, std::string& s_prefix)
{ 
	StackT<std::string> s;  
	std::string aux1 = "";
	std::string aux2 = "";
	int i = 0;

	while (s_postfix[i] != '\0')
	{
		if (s_postfix[i] <= '9' && s_postfix[i] >= 48)
		{
			aux1.push_back(s_postfix[i]);  // aux1 = "2"
			s.push(aux1);
			aux1 = "";
		}
		else
		{
			if (s_postfix[i] >= 42 && s_postfix[i] <= 47)
			{
				aux1.push_back(s_postfix[i]);  // aux1 = "+"
				aux2 = s.top();   // aux2 = "2"
				s.pop();
				aux1.append(s.top()); //aux1 = "+1"
				s.pop();
				aux1.append(aux2);  // aux1 = "+12"
				s.push(aux1);
				aux1 = "";
				aux2 = "";
			}
			else
			{
				std::cout << "\n!!! Eroare !!!\nIn sir apare element ce nu e nici operant,nici operator\n";
			}
		}

		i++;
	}
	
	s_prefix = s.top();

}

double prefix(std::string str)
{
	StackT<double> s;
	int i = str.length() - 1;
	double rez = 0;
	double t1, t2;

	while (i >= 0)
	{
		if (str[i] <= 57 && str[i] >= 48)
		{
			s.push(str[i] - '0');
		}
		else
		{
			if (str[i] >= 42 && str[i] <= 47)
			{
				t1 = s.top();
				s.pop();
				t2 = s.top();
				s.pop();
				rez = operatia(t2, t1, str[i]);
				s.push(rez);
			}
			else
			{
				std::cout << "\n!!! Eroare !!!\nIn sir apare element ce nu e nici operand,nici operator\n";
			}
		}
		i--;
	}

	return rez;
}