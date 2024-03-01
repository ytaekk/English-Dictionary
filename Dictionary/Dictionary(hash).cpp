#include <iostream>
#include <fstream>
#include <string>
// #include <vector>
#include <unordered_map>

using namespace std;

// template<typename K, typename V> // 안씀 -> 사전이니까 string만 쓰면 되기 때문

class Dic // 사전 자료형 Using Vector 
{
public:
	//struct Word // 단어의 구조체
	//{
	//	string key;		// 단어
	//	string value;	// 뜻
	//};
	// 필요없음, hash table 자체가 키-값을 쌍으로 저장하기 때문에 따로 정의할 필요없다.
	// 단어 뜻 외에 추가로 생성된 날짜 이런 사용자 정의가 필요하면 구조체를 쓰는게 좋다.

	Dic()
	{
		ifstream readFile;
		string key, value;

		readFile.open("eng_dic.txt");

		if (readFile.is_open())
		{
			while (getline(readFile, key) && getline(readFile, value))
				//key value에만 저장
			{
				table_.[key] = value;
			}
			readFile.close();
		}
	}
	//Hash Table 원리 : 

	// 1. 해시 함수 적용 : 먼저, 입력한 단어(키)에 대해 해시 함수를 적용합니다.이 함수는 단어를 정수 형태의 해시 코드로 변환합니다.
	//					 이 해시 코드는 단어가 해시 테이블 내에서 저장되거나 찾아질 위치(인덱스)를 결정하는 데 사용됩니다.
	// 2. 해시 코드를 인덱스로 사용 : 변환된 해시 코드를 기반으로 해시 테이블의 해당 인덱스(위치)로 바로 접근합니다.
	//							이 위치는 단어가 저장되어 있는 곳이거나, 해당 단어를 찾기 위해 검사해야 하는 시작점이 됩니다.
	// 3. 값 탐색 및 반환 : 인덱스 위치에서 해당 단어(키)와 일치하는 값을 찾습니다.	만약 충돌 해결 전략으로 체이닝이 사용되었다면, 
	//					이 위치의 연결 리스트를 순회하며 정확한 키 - 값 쌍을 찾아냅니다.
	//					오픈 어드레싱 방법을 사용했다면, 정해진 규칙에 따라 다른 인덱스를 탐색하여 키 - 값 쌍을 찾습니다.
	// 4. 결과 반환 : 찾은 값(단어의 뜻 또는 정보)을 반환합니다.
	//				만약 키에 해당하는 값이 해시 테이블 내에 없다면, "찾을 수 없음"과 같은 메시지를 반환할 수 있습니다.

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
	// vector는 일련의 요소를 순차적으로 저장하는 동적 배열로 
	// 특정 키에 대해 검색하려면 배열 전체를 순회해야하기 때문에 비효율적이라 안쓴다.
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