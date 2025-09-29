### Characters Types

That is an interesting way of going through a user input!!
***
void intval()
{
for (char c; cin >> c; )
cout << "the value of '" << c << "' is " << int{c} << '\n';
}
***

Another cool example of a static cast

***
void digits()
{
for (int i=0; i!=10; ++i)
cout << static_cast<char>('0'+i);
}
This is a way of writing the ten digits to cout. The character literal '0' is converted to its integer
value and i is added. The resulting int is then converted to a char and written to cout. Plain '0'+i is
an int, so if I had left out the static_cast<char>, the output would have been something like 48, 49,
and so on, rather than 0, 1, and so on.
***

#### Character Literals

A character literal is a single character enclosed in single quotes, for example, 'a' and '0'. The type
of a character literal is char. A character literal can be implicitly converted to its integer value in
the character set of the machine on which the C++ program is to run.


| Name             | ASCII Name | C++ Name   |
|------------------|------------|------------|
| Newline          | NL (LF)    | `\n`       |
| Horizontal tab   | HT         | `\t`       |
| Vertical tab     | VT         | `\v`       |
| Backspace        | BS         | `\b`       |
| Carriage return  | CR         | `\r`       |
| Form feed        | FF         | `\f`       |
| Alert            | BEL        | `\a`       |
| Backslash        | \          | `\\`       |
| Question mark    | ?          | `\?`       |
| Single quote     | ’          | `\'`       |
| Double quote     | "          | `\"`       |
| Octal number     | ooo        | `\ooo`     |
| Hexadecimal num. | hhh        | `\xhhh`    |


***
Sizes of C++ objects are expressed in terms of multiples of the size of a char, so by definition
the size of a char is 1. The size of an object or type can be obtained using the sizeof operator
This is what is guaranteed about sizes of fundamental types:
• 1 ≡ sizeof(char) ≤ sizeof(short) ≤ sizeof(int) ≤ sizeof(long) ≤ sizeof(long long)
• 1 ≤ sizeof(bool) ≤ sizeof(long)
• sizeof(char) ≤ sizeof(wchar_t) ≤ sizeof(long)
• sizeof(float) ≤ sizeof(double) ≤ sizeof(long double)
• sizeof(N) ≡ sizeof(signed N) ≡ sizeof(unsigned N)
***

***
The decltype() Specifier
We can use auto when we have a suitable initializer. But sometimes, we want to have a type
deduced without defining an initialized variable. Then, we can use a declaration type specifier:
decltype(expr) is the declared type of expr. This is mostly useful in generic programming. Consider
writing a function that adds two matrices with potentially different element types. What should be
the type of the result of the addition? A matrix, of course, but what might its element type be? The
obvious answer is that the element type of the sum is the type of the sum of the elements. So, I can
declare:

template<class T, class U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) −> Matrix<decltype(T{}+U{})>;

I use the suffix return type syntax to be able to express the return type in terms of the arguments: Matrix<decltype(T{}+U{})>. That is, the result is a Matrix with the element type being what you get from adding a pair of elements from the argument Matrixes: T{}+U{}.

In the definition, I again need decltype() to express Matrix’s element type:

template<class T, class U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) −> Matrix<decltype(T{}+U{})>
{
Matrix<decltype(T{}+U{})> res;
for (int i=0; i!=a.rows(); ++i)
for (int j=0; j!=a.cols(); ++j)
res(i,j) += a(i,j) + b(i,j);
return res;
}
***