#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename K, typename V> // 안씀 -> 사전이니까 string만 쓰면 되기 때문
//test
class Dic // 사전 자료형 
{
public:
	struct Word // 단어의 구조체
	{
		string key;		// 단어
		string value;	// 뜻
	};

	Dic(const int& cap) // 생성자
	{
		capacity_ = cap;	// cap = 169999
		table_ = new Word[capacity_];

		// 파일에서 단어, 뜻 table에 저장하기
		ifstream readFile;
		readFile.open("eng_dic.txt");
		int i = 0;
		if (readFile.is_open())
		{
			while (!readFile.eof())	//파일내용이 끝날 때까지 복사 후 파일 닫기.
			{
				getline(readFile, table_[i].key);	// warning 발생. Reading invalid data from 'table_'
				// i인덱스 key에는 단어
				getline(readFile, table_[i].value);	// i인덱스 value에는 의미
				i++;
			}
			readFile.close();
		}
	}

	~Dic()
	{
		delete[] table_;
	}
	
	string Get(const string& key) // 탐색방법을 조금 더 빠르게 하는 방법은?
	{
		for (int i = 0; i < capacity_; i++)
		{
			if (table_[i].key == key)
				return table_[i].value;
		}
		return "No result";
	}

private:
	Word* table_ = nullptr;
	int capacity_ = 0;
}; 


int main()
{
	using Word = Dic<char, char>::Word;

	Dic<char, char> dic(169999); // 용량 공간설정 다시 생각해보자.

	string input;

	cout << "-----------------" << endl;
	cout << "-               -" << endl;
	cout << "-   1 : Quit    -" << endl;
	cout << "-               -" << endl;
	cout << "-----------------" << endl;
	while (true)
	{
		cout << "Input a word : ";

		cin >> input;
		if (input == "1") {
			cout << endl << "------QUIT-------" << endl;
			break;
		}
		else {
			
			cout << dic.Get(input) << endl;
			cout << endl;
			
		}
	}


	return  0;
	
}