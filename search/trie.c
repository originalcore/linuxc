#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* 假设字典中的每个节点值有26个小写字母组成 */
#define ALPHABET_SIZE 26
#define LOWCASE_A_ASCII_VALUE 97

/* 最大单词容量 */
#define NUMBER_OF_WORDS (354935)

/* 假设字典中每个单词长度最大为100 */
#define INPUT_WORD_SIZE (100)

/* 字典树中的一个节点 */
typedef struct TrieNode
{
	/* 每个节点下的子节点, 这里假设只能是26个字母 */
	struct TrieNode *children[ALPHABET_SIZE];

	/* 每个节点表示的字符 */
	char character;

	/* 是否是单词结尾标志 */
	bool is_end_word;
} TrieNode;

/* 创建字典树的一个节点 */
TrieNode *createTrieNode()
{
	int i;
	TrieNode *node;

	node = malloc(sizeof(TrieNode));
	if (NULL == node)
		perror("No memory\n");

	node->is_end_word = false;

	/* 初始化子树 */
	for (i = 0; i < ALPHABET_SIZE; i++)
		node->children[i] = NULL;

	return node;
}

/* 将一个单词插入到字典树中 */
void insert_word(TrieNode *root, char *word)
{
	char character;

	/*
	 * 单词不为空
	 * 将单词每一个字符插入到字典树中
	 */
	if ((strlen(word) - 1) != 0)
	{
		character = *word;
		/* 当前节点的子节点未发现该字符 */
		if (NULL == root->children[character - LOWCASE_A_ASCII_VALUE])
		{
			TrieNode *node = NULL;
			node = createTrieNode();
			node->character = character;
			root->children[character - LOWCASE_A_ASCII_VALUE] = node;
		}

		/* 继续第归插入后续字符 */
		word++;
		insert_word(root->children[character - LOWCASE_A_ASCII_VALUE], word);
	}
	else /* 空,说明是词尾 */
	{
		root->is_end_word = true;
	}
}

/* 在字典树中查找单词 */
TrieNode *search_word(TrieNode *root, char *word)
{
	char character;
	TrieNode *node;

	/* 遍历单词中的每一个字符, 对比字典树中的节点值 */
	while (*word != '\0')
	{
		/* 在子节点中能找到对应的字符 */
		character = *word;
		if (root->children[character - LOWCASE_A_ASCII_VALUE] != NULL)
		{
			/* 修改查找的root节点为当前子节点 */
			node = root->children[character - LOWCASE_A_ASCII_VALUE];
			word++;
			root = node;
		}
		else
		{
			printf("No possible words\n");
			return NULL;
		}
	}

	return root;
}

/* 将字符串中的每一个字符打印出来 */
void print_array(char array[], int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%c", array[i]);
	printf("\n");
}

/*
 * @node : 当前所处的节点
 * 打印所有相关的单词
 * 将给定节点的所有可能都打印出来
 *
 * @prefix : 输入的模糊查找(词引)
 * 将所有可能的可不齐的内容添加到prefix后即为所有相关的词
 *
 * @len : perfix的长度
 */
void print_relevant_word(TrieNode *node, char prefix[], int len)
{
	int i;

	if (NULL == node)
		return;

	prefix[len] = node->character;
	len++;

	/* 已经是词尾, 打印出结果 */
	if (node->is_end_word)
		print_array(prefix, len);

	/* 递归不齐后续的字符 */
	for (i = 0; i < ALPHABET_SIZE; i++)
		print_relevant_word(node->children[i], prefix, len);
}

/* 更具词引prefix遍历整个字典树, 找出相关的单词 */
void fuzzy_find(TrieNode *root, char prefix[])
{
	int i;
	TrieNode *node = NULL;

	node = search_word(root, prefix);
	print_relevant_word(node, prefix, strlen(prefix) - 1);
}

int main(int argc, char *argv[])
{
	char keyword[INPUT_WORD_SIZE];
	int word_count = 0;
	char *words[NUMBER_OF_WORDS];
	FILE *fp;
	TrieNode *root = NULL;
	int i;

	/* load dictionary from file */
	fp = fopen("dictionary.txt", "r");
	if (NULL == fp)
	{
		printf("Dictornay not found, try below\n");
		printf("wget https://raw.githubusercontent.com/TheAlgorithms/C/master/data_structures/trie/dictionary.txt\n");
		exit(1);
	}

	words[word_count] = malloc(INPUT_WORD_SIZE);
	/* 从文件中读入每一个单词 */
	while (fgets(words[word_count], INPUT_WORD_SIZE, fp))
		words[++word_count] = malloc(INPUT_WORD_SIZE);

	/* 将所有单词装如字典树中 */
	root = createTrieNode();
	for (i = 0; i < NUMBER_OF_WORDS; i++)
		insert_word(root, words[i]);

	while (1)
	{
		printf("Enter keyword: ");
		scanf("%99s", keyword);
		printf("\n==========================================================\n");
		printf("\n********************* Possible Words *********************\n");

		/* Find the word through the Trie */
		fuzzy_find(root, keyword);
	}

	/* TODO free all memory here... */
	fclose(fp);

	return 0;
}
