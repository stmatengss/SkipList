/*
 * Designed by stmatengss
 * TODO
 * */
#include <iostream>
#include <random>

namespace SkipList {

	const static int max_skiplist_level = 16;

	struct SkipListNode {
		double value;
		int level;
		SkipListNode *next_list[max_skiplist_level];
		SkipListNode(): value(0.0), level(1) { }
		SkipListNode(double value, int level):value(value), level(level) { } 
	}; 

	class SkipList {

	public:
		// int max_skiplist_level; // Drop this.
		std::random_device gen_random;
		SkipListNode *header;
		// SkipListNode *tail; // Useless
		int skiplist_level;
		int length;

		SkipList(): skiplist_level(1) {

		}
		~SkipList() {

		}

		void init() {
			header = new SkipListNode();
			header->level = 1;
			for(auto &p: header->next_list) {
				p = NULL;
			}
		}

		bool insert(double num) {
			SkipListNode *node;
			SkipListNode *update[max_skiplist_level];
			node = header;
			
			// Find matching position
			for (int i = skiplist_level - 1; i >= 0; i -- ) {
				while (node->next_list[i] && node->next_list[i]->value < num) {
					node = node->next_list[i];
				}
				update[i] = node;
			}
			int level = random_level();
			SkipListNode *new_node = new SkipListNode(num, level);

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

		bool drop(double num) {
			SkipListNode *node = _search(num);

			if (node == NULL || node->next_list[0] == NULL) {
				return false;
			}

			if (node->next_list[0]->value == num) {
				length --;
				SkipListNode *update[max_skiplist_level];
				for (int i = 0; i < update; i ++ ) {
					update[in] = ode->next_list[i];
				}
				return true;
			}

			return false;
		}

		bool search(double num) {
			SkipListNode *node = _search(num);

			if (node == NULL || node->next_list[0] == NULL) {
				return false;
			}

			if (node->next_list[0]->value == num) {
				return true;
			}

			return false;
		}

		

	private:

		SkipListNode *node _search(double num) {
			SkipListNode *node = header;

			for (int i = skiplist_level - 1; i >= 0; i -- ) {
				while (node->next_list[i] && node->next_list[i]->value < num) {
					node = node->next_list[i];
				}
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

	};
}