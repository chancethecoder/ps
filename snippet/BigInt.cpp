#include <string>
#include <algorithm>
using namespace std;

// BigInt //
// 1. string type
string add(string a, string b)
{
    string ret;
    int add = 0, round = 0;
    int a_len = a.length();
    int b_len = b.length();
 
    while(a_len && b_len)
    {
        add = a[--a_len] + b[--b_len] + round - 96;
        round = add / 10;
        add %= 10;
        ret.push_back(add + 48);
    }
    while(a_len)
    {
        add = a[--a_len] + round - 48;
        round = add / 10;
        add %= 10;
        ret.push_back(add + 48);
    }
    while(b_len)
    {
        add = b[--b_len] + round - 48;
        round = add / 10;
        add %= 10;
        ret.push_back(add + 48);
    }
    if(round) ret.push_back(round + 48);
    reverse(ret.begin(), ret.end());
    return ret;
}

// 2. bigint type
class BigInt{
public:
    BigInt() {}
    BigInt(string _d) : data(_d) {}
    BigInt operator = (BigInt rt_side);
    string operator = (string _data);
    BigInt operator + (BigInt &rt_side);
//  BigInt operator * (BigInt &a);		// not implemented..
    string data;
};
 
BigInt BigInt::operator = (BigInt rt_side)
{
    this->data = rt_side.data;
    return rt_side;
}
 
string BigInt::operator = (string _data)
{
    this->data = _data;
    return _data;
}
 
BigInt BigInt::operator + (BigInt &rt_side)
{
    string temp, left(this->data), right(rt_side.data);
    int l_len = left.length(), r_len = right.length();
    int sum, round_up = 0;
    while(l_len && r_len)
    {
        sum = left[--l_len] + right[--r_len] + round_up - 96;
        round_up = sum / 10;
        sum %= 10;
        temp.push_back(sum + 48);
    }
    while(l_len)
    {
        sum = left[--l_len] + round_up - 48;
        round_up = sum / 10;
        sum %= 10;
        temp.push_back(sum + 48);
    }
    while(r_len)
    {
        sum = right[--r_len] + round_up - 48;
        round_up = sum / 10;
        sum %= 10;
        temp.push_back(sum + 48);
    }
    if(round_up) temp.push_back(round_up + 48);
    reverse(temp.begin(), temp.end());
    BigInt ret(temp);
    return ret;
}
