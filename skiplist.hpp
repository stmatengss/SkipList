/*
 * Designed by stmatengss
 * TODO
 * */
#include <iostream>
#include <random>

namespace SkipList {

	const static int max_skiplist_level = 16;

	template <typename T>
	struct SkipListNode {
		T value;
		int level;
		SkipListNode *next_list[max_skiplist_level];
		SkipListNode(): level(1) { }
		SkipListNode(T value, int level):value(value), level(level) { } 
	}; 

	template <typename T>
	class SkipList {

	public:
		// int max_skiplist_level; // Drop this.
		std::random_device gen_random;
		SkipListNode<T> *header;
		// SkipListNode *tail; // Useless
		int skiplist_level;
		int length;

		SkipList(): skiplist_level(1) {
			init();
		}
		~SkipList() {

		}

		void print() {
			_print();
		}

		void init() {
			header = new SkipListNode<T>();
			header->level = 1;
			for(auto &p: header->next_list) {
				p = NULL;
			}
		}

		bool insert(T num) {
			SkipListNode<T> *node;
			SkipListNode<T> *update[max_skiplist_level];
			
			// Find matching position
			node = _search(num, update);

			int level = random_level();
			SkipListNode<T> *new_node = new SkipListNode<T>(num, level);

			if (level > skiplist_level) {
				for (int i = skiplist_level; i < level; i ++ ) {
					update[i] = header;
				}
			}

			// Insert new Node to Skip List
			for (int i = 0; i < level; i ++ ) {
				new_node->next_list[i] = update[i]->next_list[i];
				update[i]->next_list[i] = new_node;
			}

			length ++;
			return true;
		}

		bool drop(T num) {
			SkipListNode<T> *node;
			SkipListNode<T> *update[max_skiplist_level];

			node = _search(num, update);

			if (node == NULL || node->next_list[0] == NULL) {
				return false;
			}

			if (node->next_list[0]->value == num) {
				
				SkipListNode<T> *update[max_skiplist_level];
				for (int i = 0; i < node->level; i ++ ) {
					update[i] = node->next_list[i];
				}

				delete node;

				while (skiplist_level > 1 && 
					header->next_list[skiplist_level - 1]) {
					skiplist_level --;
				}

				length --;
				return true;
			}

			return false;
		}

		bool search(double num) {
			SkipListNode<T> *node = _search(num);

			if (node == NULL || node->next_list[0] == NULL) {
				return false;
			}

			if (node->next_list[0]->value == num) {
				return true;
			}

			return false;
		}

		

	private:

		SkipListNode<T> *_search(T num) {
			SkipListNode<T> *node = header;

			for (int i = skiplist_level - 1; i >= 0; i -- ) {
				while (node->next_list[i] && node->next_list[i]->value < num) {
					node = node->next_list[i];
				}
			}

			return node;
		}

		SkipListNode<T> *_search(T num, SkipListNode<T> **update) {
			SkipListNode<T> *node = header;

			for (int i = skiplist_level - 1; i >= 0; i -- ) {
				while (node->next_list[i] && node->next_list[i]->value < num) {
					node = node->next_list[i];
				}
				update[i] = node;
			}

			return node;
		}

		int random_level() {
			int num = 1;
			while (gen_random() % 128 < 64) {
				num ++;
			}
			return num < max_skiplist_level ? num : max_skiplist_level;
		}

		void _print() {
			for (int i = 0; i < skiplist_level; i ++ ) {
				SkipListNode<T> *tmp = header->next_list[i];
				while(tmp) {
					std::cout << tmp->value << " ";
					tmp = tmp->next_list[i];
				}
				printf("\n");
			}
		}

	};
}