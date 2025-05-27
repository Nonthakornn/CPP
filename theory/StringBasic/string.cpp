#include <iostream>
#include <string>
using namespace std;

int main()
{
	{
		//Insert
		string str = "Hello";
		str.insert(3, "KK"); //insert at index 3
		cout << str << endl; // HelKKlo
		str.insert(3,"123", 2); //Hel12KKlo
		cout << str << endl; // HelKKlo
	}
	{
		//Replace
		string str = "Programming";
		// replace(index that want to replace, number of replace, string)
		str.replace(3, 4, "kk"); //Prokkming , Prokk--ming
		cout << str << endl;
	}
	{
		//Erase
		string str = "Clear";
		str.erase();
	}
	{
		// Swap string
		string s1= "aaa";
		string s2 = "bbb";
		s1.swap(s2);
		cout << s1 << endl;
		cout << s2 << endl;
	}
	{
		//Copy
		string str = "Hello";
		char copy_str[10];

		// str.copy(copy_str, str.length());
		//If we copy like this we will need to add NULL other wise it will print garbage value.
		str.copy(copy_str, 3);
		copy_str[3] = '\0';
		cout <<"str: " << str << endl;
		cout <<"copy_str: " << copy_str << endl;
	}
	{
		//Find the first index of str
		string str = "How are you";
		cout << "Position founded at idx: "<< str.find("are") << endl;

		cout << str.find("axx") << endl; // It will return -1 or largest index possible
		/* std::string npos is a static constant member of the std::string class that represents "no position" or "not found" */
		if (str.find("axx") == string::npos)
			cout << "No Position Founded!" << endl;
	}
	{
		//Substring substr(index, how many number that you want)
		string str = "0123456789";
		cout << str.substr(3) << endl; // 3456789
		cout << str.substr(3,4) << endl; // 3456
	}
	{
		//Compare - return 0 if is is equal 
		string s1= "aaa";
		string s2 = "aaa";
		cout << s1.compare(s2) << endl;
	}
	{
		//Iterator
		string str = "Hello World";
		string::iterator it;

		for (it=str.begin(); it != str.end(); it++)
			cout << *it << endl;
	}
}
