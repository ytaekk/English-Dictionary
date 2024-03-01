#include <iostream>
#include <fstream>
#include <string>
// #include <vector>
#include <unordered_map>

using namespace std;

// template<typename K, typename V> // �Ⱦ� -> �����̴ϱ� string�� ���� �Ǳ� ����

class Dic // ���� �ڷ��� Using Vector 
{
public:
	//struct Word // �ܾ��� ����ü
	//{
	//	string key;		// �ܾ�
	//	string value;	// ��
	//};
	// �ʿ����, hash table ��ü�� Ű-���� ������ �����ϱ� ������ ���� ������ �ʿ����.
	// �ܾ� �� �ܿ� �߰��� ������ ��¥ �̷� ����� ���ǰ� �ʿ��ϸ� ����ü�� ���°� ����.

	Dic()
	{
		ifstream readFile;
		string key, value;

		readFile.open("eng_dic.txt");

		if (readFile.is_open())
		{
			while (getline(readFile, key) && getline(readFile, value))
				//key value���� ����
			{
				table_.[key] = value;
			}
			readFile.close();
		}
	}
	//Hash Table ���� : 

	// 1. �ؽ� �Լ� ���� : ����, �Է��� �ܾ�(Ű)�� ���� �ؽ� �Լ��� �����մϴ�.�� �Լ��� �ܾ ���� ������ �ؽ� �ڵ�� ��ȯ�մϴ�.
	//					 �� �ؽ� �ڵ�� �ܾ �ؽ� ���̺� ������ ����ǰų� ã���� ��ġ(�ε���)�� �����ϴ� �� ���˴ϴ�.
	// 2. �ؽ� �ڵ带 �ε����� ��� : ��ȯ�� �ؽ� �ڵ带 ������� �ؽ� ���̺��� �ش� �ε���(��ġ)�� �ٷ� �����մϴ�.
	//							�� ��ġ�� �ܾ ����Ǿ� �ִ� ���̰ų�, �ش� �ܾ ã�� ���� �˻��ؾ� �ϴ� �������� �˴ϴ�.
	// 3. �� Ž�� �� ��ȯ : �ε��� ��ġ���� �ش� �ܾ�(Ű)�� ��ġ�ϴ� ���� ã���ϴ�.	���� �浹 �ذ� �������� ü�̴��� ���Ǿ��ٸ�, 
	//					�� ��ġ�� ���� ����Ʈ�� ��ȸ�ϸ� ��Ȯ�� Ű - �� ���� ã�Ƴ��ϴ�.
	//					���� ��巹�� ����� ����ߴٸ�, ������ ��Ģ�� ���� �ٸ� �ε����� Ž���Ͽ� Ű - �� ���� ã���ϴ�.
	// 4. ��� ��ȯ : ã�� ��(�ܾ��� �� �Ǵ� ����)�� ��ȯ�մϴ�.
	//				���� Ű�� �ش��ϴ� ���� �ؽ� ���̺� ���� ���ٸ�, "ã�� �� ����"�� ���� �޽����� ��ȯ�� �� �ֽ��ϴ�.

	string Get(const string& key) // Hash Table
	{
		{
			auto search = table_.find(key);
			if (search != table_.end())
				return search->second;
		}
		return "No result";
	}

private:
	// vector<Word>table_;
	// vector�� �Ϸ��� ��Ҹ� ���������� �����ϴ� ���� �迭�� 
	// Ư�� Ű�� ���� �˻��Ϸ��� �迭 ��ü�� ��ȸ�ؾ��ϱ� ������ ��ȿ�����̶� �Ⱦ���.
	unordered_map<string, string>table_;
}; 


int main()
{
	Dic dic;
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