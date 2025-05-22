#pragma once
#include <cstdio>

namespace ST
{
	class ST_ostream
	{
	private:
		const static int precision_float = 6;
		const static int precision_double = 15;
		const static int precision_longdouble = 21;

		template <typename F>
		ST_ostream& printFloat(F f, int p)
		{
			// Negative number
			if (f < 0)
			{
				// Print the sign first, 
				// and convert the negative number to positive number.
				putchar('-');
				f = -f;
			}

			// Print integer part
			long long int_part = static_cast<long long>(f);
			*this << int_part; // Uses operator overloading of long long

			putchar('.');

			// Print fraction part
			F fraction = f - int_part;

			for (int i = 0; i < p; ++i)
			{
				fraction *= 10;
				int digit = static_cast<int>(fraction);
				putchar('0' + digit);
				fraction -= digit;
			}

			return *this;
		}

	public:
		// flush Function: calls the fflush from <cstdio>
		void flush()
		{
			std::fflush(stdout);
		}

		// Operator overloading: "string"
		ST_ostream& operator<< (const char* str)
		{
			// Print character by character until '\0'
			while (*str)
			{
				putchar(*str++);
			}
			return *this;
		}

		// Operator overloading: "char"
		ST_ostream& operator<< (char c)
		{
			// Print the given character
			putchar(c);
			return *this;
		}

		// Operator overloading: "int"
		ST_ostream& operator<< (int n)
		{
			// Print the 0 with separate case - for while loop of (n > 0)
			if (0 == n)
			{
				putchar('0');
				return *this;
			}

			// Negative number
			if (n < 0)
			{
				// Print the sign first,
				putchar('-');
				// convert the number to positive number
				n = -n;
			}

			// Buffer to store the integer digits (int has 10 digit)
			char buf[16];
			int idx = 0;

			// Extract digits from the integer
			while (n > 0)
			{
				// Type conversion to char
				buf[idx++] = '0' + (n % 10);
				n /= 10;
			}

			// Print the stored digits from the end, using index
			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}

		// Operator overloading: "short"
		ST_ostream& operator<< (short s)
		{
			// Print the 0 with separate case - for while loop of (n > 0)
			if (0 == s)
			{
				putchar('0');
				return *this;
			}

			// Negative number
			if (s < 0)
			{
				// Print the sign first,
				putchar('-');
				// convert the number to positive number
				s = -s;
			}

			// Buffer to store the integer digits (short has 5 digit)
			char buf[8];
			int idx = 0;

			// Extract digits from the integer
			while (s > 0)
			{
				// Type conversion to char
				buf[idx++] = '0' + (s % 10);
				s /= 10;
			}

			// Print the stored digits from the end, using index
			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}

		// Operator overloading: "long"
		ST_ostream& operator<< (long l)
		{
			// Print the 0 with separate case - for while loop of (n > 0)
			if (0 == l)
			{
				putchar('0');
				return *this;
			}

			// Negative number
			if (l < 0)
			{
				// Print the sign first,
				putchar('-');
				// convert the number to positive number
				l = -l;
			}

			// Buffer to store the integer digits (long has 19 digit)
			char buf[32];
			int idx = 0;

			// Extract digits from the integer
			while (l > 0)
			{
				// Type conversion to char
				buf[idx++] = '0' + (l % 10);
				l /= 10;
			}

			// Print the stored digits from the end, using index
			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}

		// Operator overloading: "long long"
		ST_ostream& operator<< (long long ll)
		{
			// Print the 0 with separate case - for while loop of (n > 0)
			if (0 == ll)
			{
				putchar('0');
				return *this;
			}

			// Negative number
			if (ll < 0)
			{
				// Print the sign first,
				putchar('-');
				// convert the number to positive number
				ll = -ll;
			}

			// Buffer to store the integer digits (long long has 19 digit)
			char buf[32];
			int idx = 0;

			// Extract digits from the integer
			while (ll > 0)
			{
				// Type conversion to char
				buf[idx++] = '0' + (ll % 10);
				ll /= 10;
			}

			// Print the stored digits from the end, using index
			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}

		// Operator overloading: "unsigned int"
		ST_ostream& operator<< (unsigned int n)
		{
			char buf[16];
			int idx = 0;

			if (0 == n)
			{
				putchar('0');
				return *this;
			}

			while (n > 0)
			{ 
				buf[idx++] = '0' + n % 10;
				n /= 10;
			}

			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}

		// Operator overloading: "unsigned short"
		ST_ostream& operator<< (unsigned short us)
		{
			char buf[8];
			int idx = 0;

			if (0 == us)
			{
				putchar('0');
				return *this;
			}

			while (us > 0)
			{
				buf[idx++] = '0' + us % 10;
				us /= 10;
			}

			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}

		// Operator overloading: "unsigned long"
		ST_ostream& operator<< (unsigned long ul)
		{
			char buf[32];
			int idx = 0;

			if (0 == ul)
			{
				putchar('0');
				return *this;
			}

			while (ul > 0)
			{
				buf[idx++] = '0' + ul % 10;
				ul /= 10;
			}

			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}

		// Unsigned long long is considered as unsigned long
		/*
		// Operator overloading: "unsigned long long"
		ST_cout& operator<< (unsigned long ull)
		{
			char buf[32];
			int idx = 0;

			if (0 == ull)
			{
				putchar('0');
				return *this;
			}

			while (ull > 0)
			{
				buf[idx++] = '0' + ull % 10;
				ull /= 10;
			}

			while (idx--)
			{
				putchar(buf[idx]);
			}

			return *this;
		}
		*/

		// Operator overloading: "float"
		ST_ostream& operator<< (float f)
		{
			return printFloat(f, precision_float);
		}

		// Operator overloading: "double"
		ST_ostream& operator<< (double d)
		{
			return printFloat(d, precision_double);
		}

		// Operator overloading: "long double"
		ST_ostream& operator<< (long double ld)
		{
			return printFloat(ld, precision_longdouble);
		}

		// Operator overloading: "bool"
		ST_ostream& operator<< (bool b)
		{
			putchar(b ? '1' : '0');
			return *this;
		}

		// Operator overloading for "endl"
		ST_ostream& operator<< (ST_ostream& (*pfunc)(ST_ostream&))
		{
			// Takes endl (or function that takes ST_cout reference) and executes the function
			return pfunc(*this);
		}
	};

	inline ST_ostream cout;

	inline ST_ostream& endl(ST_ostream& out)
	{
		// print '\n'
		out << '\n';
		// calls flush
		out.flush();
		// return object
		return out;
	}
}