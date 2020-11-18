/*

Algorithm Used -  Karatsuba's Algorithm

*/


#include<bits/stdc++.h>
using namespace std;


long long toDecimal(string s) // converts binary string into decimal number
{
	long long  ans = 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		ans = (ans << 1) + s[i] - '0';
	}
	return ans;
}


void addZero(string *num1, string *num2) // takes two strings as argument and makes them equal in length by adding 0's at the beginning
{
	int n1 = (*num1).size();
	int n2 = (*num2).size();
	while (n1 < n2) // if first string is smaller than add 0 at the beginning until it becomes equal to 2nd string
	{
		*num1 = "0" + *num1;
		n1++;
	}

	while (n2 < n1) // if second string is smaller than add 0 at the beginning until it becomes equal to 1st string
	{
		*num2 = "0" + *num2;
		n2++;
	}
}


string getSum(string num1, string num2) // takes two binary string as argument and returns sum of these strings
{
	addZero(&num1, &num2);
	int size = num1.length();
	int carry = 0;
	string ans;

	for (int i = size - 1; i > -1; i--) // start from the least significant bit i.e. (size-1)th bit
	{
		if (carry) // if carry is 1
		{
			if (num1[i] == '1' && num2[i] == '1') // if both bits are 1 then sum = 1, carry = 1 (unchanged)
				ans.push_back('1');

			else if (num1[i] == '1' || num2[i] == '1') // if only 1 bit is 1 then sum = 0 and carry = 1(unchanged)
				ans.push_back('0');

			else
			{
				ans.push_back('1'); // if both bits are 0 then sum = 1 and carry = 0
				carry = 0;
			}
		}

		else // if carry is 0
		{
			if (num1[i] == '1' && num2[i] == '1') // if both bits are 1 then sum = 0, carry = 1
			{
				ans.push_back('0');
				carry = 1;
			}

			else if (num1[i] == '1' || num2[i] == '1') // if only one bit is 1 then sum = 1, carry = 0
				ans.push_back('1');

			else
				ans.push_back('0'); // if both bits are 0 then sum = 0, carry = 0
		}
	}
	if (carry)
		ans = ans + '1'; // if final carry is 1 then push into string

	reverse(ans.begin(), ans.end()); // reverse the string
	return ans;
}



long long recurMultiply(string num1, string num2) // takes two strings as argument and returns integer as output
{
	addZero(&num1, &num2); // make length of the string equal
	int n = num1.size();

	if (n == 1)
		return (num1[0] - '0') & (num2[0] - '0'); // 1 bit multiplication - if both bits are 1 return 1 else return 0
	if (n == 0)			// if length of string is zero return 0
		return 0;
	int part1 = n / 2;
	int part2 = n - n / 2;
	string x1 = num1.substr(0, part1); // calculate substring of 0 to half length of num1
	string x0 = num1.substr(part1, part2); // calculate substring from half to end of num1
	string y1 = num2.substr(0, part1); //calculate substring of 0 to half length of num2
	string y0 = num2.substr(part1, part2); // calculate substring from half to end of num2

	string sum1 = getSum(x1, x0);   // sum1 = x1+x0
	string sum2 = getSum(y1, y0);  // sum2 = y1+y0

	// makes three recursive calls for length n/2
	long long  p = recurMultiply(sum1, sum2);
	long long  x1y1 = recurMultiply(x1, y1);
	long long  x0y0 = recurMultiply(x0, y0);


	// Result = x1y1 · 2^n + (p − x1y1 − x0y0 ) · 2 ^ n/2 + x0y0  (Section 5.5 Algorithm Design by Kleinberg and Tardos)

	long long result = (x1y1) * (1ll << part2) * (1ll << part2);
	result += (p - x1y1 - x0y0) *  (1ll << part2);
	result += x0y0;

	return result;
}


int main()
{

	string num1, num2;
	cout << "Enter positive integers a and b in binary\n";
	cin >> num1 >> num2;
	long long ans = recurMultiply(num1, num2);

	long long a = toDecimal(num1);
	long long b = toDecimal(num2);
	cout << "The product of " << a << " and " << b << " is " << ans << "\n";

	return 0;
}