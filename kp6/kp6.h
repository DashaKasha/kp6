#pragma once
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename TKey, typename TValue>
class HashTable {
private:
	int tableSize;
	int num; /// number of added elements
	vector <list<pair<TKey, TValue>>> table;

public:
	HashTable(const int t) {
		tableSize = t;
		table = vector<list<pair<TKey, TValue>>>(t);
	}

	int hash_function(const TKey& Tkey)							// хэш функцию
	{
		int M = 97; 

		unsigned long hash = 0;
		hash = Tkey % M;

		return hash;  
	}

	void Insert(const TKey& key_val, const TValue& el_value)			// Вставка пары ключ-значение
	{
		int pos = hash_function(key_val);
		table[pos].push_back(make_pair(key_val, el_value));
	}

	const TValue Search(const TKey& key_val) 					// Поиск по ключу
	{
		int pos = hash_function(key_val);
			for (auto elem : table[pos]) {
				if (elem.first == key_val) {
					return elem.second;
				}
			}
		
	}

	void Output() const 											// Вывести хэш таблицу
	{

		for (auto list : table) {
			for (auto el : list) {
				cout << el.first << ' ' << el.second << endl;
			}
		}
	}

	void Delete(TValue element)									// удаление по значению
	{
		int pos = 0;
		for (auto lst : table) {
			for (auto elem : lst)
			{
				if (elem.second == element) {
					pos = hash_function(elem.first);
					table[pos].clear();
				}
			}
		}
	}


	const TValue operator[](const TKey& key)							// оператор [Key]
	{
		size_t pos = hash_function(key);
		for (auto elem : table[pos]) {
			if (elem.first == key) {
				return elem.second;
			}
		}
	}



	~HashTable() {
		table.clear();
	};


};