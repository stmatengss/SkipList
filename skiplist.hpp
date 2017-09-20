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
		SkipListNode *tail;
		int skiplist_level;

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
			for (int i = skiplist_level; i >= 0; i -- ) {
				while (node->next_list[i] && node->next_list[i] < num) {
					node = node->next_list[i];
				}
				update[i] = node;
			}
			int level = random_level();
			SkipListNode *new_node = new SkipListNode(num, level);

			if (level > skiplist_level) {
				for (i = skiplist_level; i < level; i ++ ) {
					
				}
			}

			return true;
		}

		bool drop(double num) {
			return true;
		}

		bool search(double num) {
			return true;
		}

	private:
		int random_level() {
			int num = 1;
			while (gen_random() % 128 < 64) {
				num ++;
			}
			return num < max_skiplist_level ? num : max_skiplist_level;
		}

	};
}