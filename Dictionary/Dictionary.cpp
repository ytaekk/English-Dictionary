#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename K, typename V> // �Ⱦ� -> �����̴ϱ� string�� ���� �Ǳ� ����
//test
class Dic // ���� �ڷ��� 
{
public:
	struct Word // �ܾ��� ����ü
	{
		string key;		// �ܾ�
		string value;	// ��
	};

	Dic(const int& cap) // ������
	{
		capacity_ = cap;	// cap = 169999
		table_ = new Word[capacity_];

		// ���Ͽ��� �ܾ�, �� table�� �����ϱ�
		ifstream readFile;
		readFile.open("eng_dic.txt");
		int i = 0;
		if (readFile.is_open())
		{
			while (!readFile.eof())	//���ϳ����� ���� ������ ���� �� ���� �ݱ�.
			{
				getline(readFile, table_[i].key);	// warning �߻�. Reading invalid data from 'table_'
				// i�ε��� key���� �ܾ�
				getline(readFile, table_[i].value);	// i�ε��� value���� �ǹ�
				i++;
			}
			readFile.close();
		}
	}

	~Dic()
	{
		delete[] table_;
	}
	
	string Get(const string& key) // Ž������� ���� �� ������ �ϴ� �����?
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

	Dic<char, char> dic(169999); // �뷮 �������� �ٽ� �����غ���.

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