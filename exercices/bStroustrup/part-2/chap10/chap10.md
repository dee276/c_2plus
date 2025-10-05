### Expression

#### 10.1 Introduction
This chapter discusses expressions in some detail. In C++, an assignment is an expression, a function call is an expression, the construction of an object is an expression, and so are many other
operations that go beyond conventional arithmetic expression evaluation.

#### 10.2.4 Error Handling
It is always important to detect and report errors. However, for this program, a simple error handling strategy suffices. The error() function simply counts the errors, writes out an error message,
and returns:
int no_of_errors;
double error(const string& s)
{
no_of_errors++;
cerr << "error: " << s << '\n';
return 1;
}
The stream cerr is an unbuffered output stream usually used to report errors (§38.1).
The reason for returning a value is that errors typically occur in the middle of the evaluation of
an expression, so we should either abort that evaluation entirely or return a value that is unlikely to
cause subsequent errors. The latter is adequate for this simple calculator. Had Token_stream::g et()

#### 10.2.7 Command-Line Arguments
After the program was written and tested, I found it a bother to first start the program, then type the
expressions, and finally quit. My most common use was to evaluate a single expression. If that
expression could be presented as a command-line argument, a few keystrokes could be avoided.
A program starts by calling main() (§2.2.1, §15.4). When this is done, main() is given two arguments specifying the number of arguments, conventionally called argc, and an array of arguments,
conventionally called argv. The arguments are C-style character strings (§2.2.5, §7.3), so the type
of argv is char∗[argc+1]. The name of the program (as it occurs on the command line) is passed as
argv[0], so argc is always at least 1. The list of arguments is zero-terminated; that is, argv[argc]==0.

example : 

int main(int argc, char∗ argv[])
{
switch (argc) {
case 1: // read from standard input
break;
case 2: // read from argument string
ts.set_input(new istringstream{argv[1]});
break;
default:
error("too many arguments");
return 1;
}
table["pi"] = 3.1415926535897932385; // inser t predefined names
table["e"] = 2.7182818284590452354;
calculate();
return no_of_errors;
}

| Opérateur / Syntaxe                        | Nom / Description                        | Exemple d'utilisation                | Référence |
|--------------------------------------------|------------------------------------------|--------------------------------------|-----------|
| ( expr )                                  | Parenthèse (expression)                  | (a + b)                              | §iso.5.1  |
| [capture-list] lambda-decl. { stmts }      | Lambda                                   | [x]{ return x+1; }                   | §11.4     |
| class::member, ns::member, ::name          | Résolution de portée                     | std::vector<int>::iterator           | §16.2.3   |
| obj.member                                | Sélection membre                         | s.size()                             | §16.2.3   |
| ptr->member                               | Sélection membre via pointeur            | p->size()                            | §16.2.3   |
| ptr[expr]                                 | Indexation (subscripting)                | arr[2]                               | §7.3      |
| expr(expr-list)                           | Appel de fonction                        | f(x, y)                              | §12.2     |
| type{expr-list}                           | Construction de valeur                   | vector<int>{1,2,3}                   | §11.3.2   |
| type(expr-list)                           | Conversion style-fonction                | int(3.14)                            | §11.5.4   |
| lvalue++                                  | Post-incrément                           | i++                                  | §11.1.4   |
| lvalue--                                  | Post-décrément                           | i--                                  | §11.1.4   |
| typeid(type), typeid(expr)                 | Identification de type                   | typeid(x)                            | §22.5     |
| dynamic_cast<type>(expr)                   | Conversion dynamique                     | dynamic_cast<Base*>(p)               | §22.2.1   |
| static_cast<type>(expr)                    | Conversion statique                      | static_cast<int>(d)                  | §11.5.2   |
| reinterpret_cast<type>(expr)               | Conversion non sécurisée                 | reinterpret_cast<char*>(&i)           | §11.5.2   |
| const_cast<type>(expr)                     | Conversion const                         | const_cast<char*>(str)               | §11.5.2   |
| sizeof expr, sizeof(type)                  | Taille                                   | sizeof(int)                          | §6.2.8    |
| sizeof... name                            | Taille d'un pack                         | sizeof...(args)                      | §28.6.2   |
| alignof(type)                             | Alignement                               | alignof(double)                      | §6.2.9    |
| ++lvalue                                  | Pré-incrément                            | ++i                                  | §11.1.4   |
| --lvalue                                  | Pré-décrément                            | --i                                  | §11.1.4   |
| ~expr                                     | Complément bit à bit                     | ~x                                   | §11.1.2   |
| !expr                                     | Négation logique                         | !ok                                  | §11.1.1   |
| -expr, +expr                              | Moins/plus unaire                        | -x, +x                               | §2.2.2    |
| &lvalue                                   | Adresse                                  | &x                                   | §7.2      |
| *expr                                     | Déréférencement                          | *p                                   | §7.2      |
| new type                                  | Allocation                               | new int                              | §11.2     |
| delete ptr, delete[] ptr                   | Désallocation                            | delete p, delete[] arr               | §11.2     |
| noexcept(expr)                            | Peut-il lancer une exception ?           | noexcept(f())                        | §13.5.1.2 |
| (type)expr                                | Cast C-style                             | (int)x                               | §11.5.3   |
| obj.*ptr-to-member, ptr->*ptr-to-member    | Sélection membre pointeur                | obj.*pm, ptr->*pm                    | §20.6     |
| expr * expr, expr / expr, expr % expr      | Multiplication, division, modulo          | a*b, a/b, a%b                        | §10.2.1   |
| expr + expr, expr - expr                  | Addition, soustraction                   | a+b, a-b                             | §10.2.1   |
| expr << expr, expr >> expr                | Décalage gauche/droite                   | a<<2, a>>1                           | §11.1.2   |
| expr < expr, expr <= expr                 | Inférieur, inférieur ou égal             | a<b, a<=b                            | §2.2.2    |
| expr > expr, expr >= expr                 | Supérieur, supérieur ou égal             | a>b, a>=b                            | §2.2.2    |
| expr == expr, expr != expr                | Égalité, différence                      | a==b, a!=b                           | §2.2.2    |
| expr & expr, expr ^ expr, expr | expr      | ET, XOR, OU bit à bit                    | a&b, a^b, a|b                        | §11.1.2   |
| expr && expr, expr || expr                | ET, OU logique                           | a&&b, a||b                           | §11.1.1   |
| expr ? expr : expr                        | Ternaire (condition)                     | a > b ? a : b                        | §11.1.3   |
| {expr-list}                               | Liste d'initialisation                   | {1,2,3}                              | §11.3     |
| throw expr                                | Lancer une exception                     | throw e                              | §13.5     |
| lvalue = expr                             | Affectation simple                       | x = 5                                | §10.2.1   |
| lvalue += expr, lvalue -= expr, ...       | Affectations composées                   | x += 2, x *= 3, ...                  | §10.2.1   |
| Alternative: and, or, not, xor, ...       | Représentation alternative               | a and b, a or b, not a               | §iso.2.12 |

### 10.6 Advice
[1] Prefer the standard library to other libraries and to ‘‘handcrafted code’’; §10.2.8.
[2] Use character-level input only when you have to; §10.2.3.
[3] When reading, always consider ill-formed input; §10.2.3.
[4] Prefer suitable abstractions (classes, algorithms, etc.) to direct use of language features (e.g.,
ints, statements); §10.2.8.
[5] Avoid complicated expressions; §10.3.3.
[6] If in doubt about operator precedence, parenthesize; §10.3.3.
[7] Avoid expressions with undefined order of evaluation; §10.3.2.
[8] Avoid narrowing conversions; §10.5.2.
[9] Define symbolic constants to avoid ‘‘magic constants’’; §10.4.1.
[10] Avoid narrowing conversions; §10.5.2.