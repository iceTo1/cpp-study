#pragma once
#include <cstdio>

namespace ST
{
	class ST_istream
	{
	private:
		template <typename F>
		ST_istream& readFloat(F& f)
		{
			f = 0;
			F fraction = 0;
			bool negative = false;
			bool decimal = false;
			F divisor = 1;

			char c = getchar();

			while (c == ' ' || c == '\n')
			{
				c = getchar();
			}

			if (c == '-')
			{
				negative = true;
				c = getchar();
			}

			while ((c >= '0' && c <= '9') || c == '.')
			{
				if (c == '.')
				{
					decimal = true;
				}
				else if (!decimal)
				{
					f = f * 10 + (c - '0');
				}
				else
				{
					// Store the digits after the fraction point
					fraction = fraction * 10 + (c - '0');
					divisor *= 10;
				}

				c = getchar();
			}

			// Adding the digits stored after the fraction point
			f += fraction / divisor;
			if (negative)
			{
				f = -f;
			}

			return *this;
		}
	public:
		// Operator overloading: "string"
		// the read data will be store into 'str'
		ST_istream& operator>> (char* str)
		{
			int idx = 0;
			char c = 0;
			// Read the string by character until 'newline' or ' ' or 'end of file'
			while ((c = getchar()) != '\n' && c != ' ' && c != EOF)
			{
				// Store the read chacater to the object.
				str[idx++] = c;
			}

			// Set the last character as 'null'
			str[idx] = '\0';
			return *this;
		}

		// Operator overloading: "int"
		// the read data will be stored into 'n'
		ST_istream& operator>> (int& n)
		{
			// Initialize the 'n' to '0' -> avoid having garbage value.
			n = 0;
			// Flag for negative number.
			bool negative = false;
			// Read the first digit.
			char c = getchar();

			// Ignore the invalid inputs at the beginning
			while (c == ' ' || c == '\n')
			{
				c = getchar();
			}

			// If the first valid value is '-',
			if (c == '-')
			{
				// Update the flag
				negative = true;
				// Read the next value
				c = getchar();
			}

			// Reading the actual values and store the data to 'n'
			while (c >= '0' && c <= '9')
			{
				// Multiply the existing data of 'n' by 10, 
				// add the integer value of 'c' to the 'n'
				n = n * 10 + (c - '0');
				// Read the next value
				c = getchar();
			}

			// If negative,
			if (negative)
			{
				// inverse the data stored
				n = -n;
			}

			return *this;
		}

		// Operator overloading: "short"
		ST_istream& operator>> (short& s)
		{
			int temp = 0;
			*this >> temp;
			s = static_cast<short>(temp);

			return *this;
		}

		// Operator overloading: "long"
		ST_istream& operator>> (long& l)
		{
			long temp = 0;
			*this >> temp;
			l = static_cast<long>(temp);

			return *this;
		}

		// Operator overloading: "char"
		ST_istream& operator>> (char& c)
		{
			c = getchar();
			return *this;
		}

		// Operator overloading: "unsigned int"
		ST_istream& operator>> (unsigned int& n)
		{
			n = 0;
			char c = getchar();

			// Ignoring invalid data
			while (c == ' ' || c == '\n')
			{
				c = getchar();
			}

			while (c >= '0' && c <= '9')
			{
				n = n * 10 + (c - '0');
				c = getchar();
			}

			return *this;
		}

		// Operator overloading: "unsigned short"
		ST_istream& operator>> (unsigned short& us)
		{
			unsigned int temp = 0;
			*this >> temp;
			us = static_cast<unsigned short>(temp);

			return *this;
		}

		// Operator overloading: "unsigned long"
		ST_istream& operator>> (unsigned long& ul)
		{
			unsigned int temp = 0;
			*this >> temp;
			ul = static_cast<unsigned long>(ul);

			return *this;
		}

		// Operator overloading: "float"
		ST_istream& operator>> (float& f)
		{
			return readFloat(f);
		}

		// Operator overloading: "double"
		ST_istream& operator>> (double& d)
		{
			return readFloat(d);
		}

		// Operator overloading: "long double"
		ST_istream& operator>> (long double& l)
		{
			return readFloat(l);
		}
	};

	inline ST_istream cin;
}