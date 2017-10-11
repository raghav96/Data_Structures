/* Necessary import statements */
#include <stdio.h>
#include <stdlib.h>

struct HeapNode{

	char key;
	unsigned freq;
	struct HeapNode *left, *right;
};

struct Heap{

	unsigned size;
	unsigned capacity;
	struct HeapNode **heapNodes;

};

struct HeapNode* createNode(char data, unsigned freq){
	struct HeapNode * temp = (struct HeapNode *) malloc(sizeof(struct HeapNode));
	temp->left = temp->right = NULL;
	temp->key = data;
	temp->freq = freq;
	return temp;
};

void swapNodes(struct HeapNode** node1, struct HeapNode** node2){
	struct HeapNode * temp = *node1;
	*node1 = *node2;
	*node2 = temp;
};

struct Heap* createHeap(unsigned int capacity){
	struct Heap* temp = (struct Heap *) malloc(sizeof(struct Heap));
	temp->capacity = capacity;
	temp->size = 0;
	temp->heapNodes = (struct HeapNode **) malloc(capacity * sizeof(struct HeapNode*));
	return temp;
};

void heapify(struct Heap * heap, int index){

	int smallest = index;
	int right = 2*index + 1;
	int left = 2*index + 2;

	if (left < heap->size && heap->heapNodes[left]->freq < heap->heapNodes[smallest]->freq){
		smallest = left;
	}


	if (right < heap->size && heap->heapNodes[right]->freq < heap->heapNodes[smallest]->freq){
		smallest = right;
	}

	if (smallest != index){

	   swapNodes(&heap->heapNodes[smallest], &heap->heapNodes[index]);
	   heapify(heap, smallest);	
	}
	

};

void insertNode(struct Heap * heap, struct HeapNode* node){
	heap->size++;
	int i = heap->size -  1;
	while (i && node->freq < heap->heapNodes[(i-1)/2]->freq)
    {
        heap->heapNodes[i] = heap->heapNodes[(i-1)/2];
        i = (i-1)/2;
    }
    heap->heapNodes[i] = node;
    
};

void buildHeap(struct Heap * heap){
	int i = 0;
	int n = heap->size -1;
	for (i = (n - 1) / 2; i >= 0; --i){
		heapify(heap, i);
	}
};

struct Heap* initHeap(char data[], int freq[], int size)
{
	struct Heap* heap = createHeap(size);
	for (int i = 0; i < size; ++i)
        heap->heapNodes[i] = createNode(data[i], freq[i]);
    heap->size = size;
    buildHeap(heap);
    return heap;
};

struct HeapNode* extractTop(struct Heap* heap){
    struct HeapNode* retVal = heap->heapNodes[0];
	heap->heapNodes[0] = heap->heapNodes[heap->size - 1];
	heap->size--;
	heapify(heap, 0);
	return retVal;
};

int isLeaf(struct HeapNode * node){
	return !(node->left) && !(node->right) ;
};


struct HeapNode* Huffman(char data[], int freq[], int size)
{
	struct HeapNode* left;
	struct HeapNode* right;
	struct HeapNode* top;

	struct Heap* heap = initHeap(data, freq, size);

	while (heap->size != 1)
    {
        left = extractTop(heap);
        right = extractTop(heap);
 
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(heap, top);
    }

    return extractTop(heap);
};

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// Prints huffman codes from the root of Huffman Tree.  It uses arr[] to
// store codes
void printCodes(struct HeapNode* root, int arr[], int top_n)
{
    // Assign 0 to left edge and recur
    if (root->left)
    {
        arr[top_n] = 0;
        printCodes(root->left, arr, top_n + 1);
    }
 
    // Assign 1 to right edge and recur
    if (root->right)
    {
        arr[top_n] = 1;
        printCodes(root->right, arr, top_n + 1);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (isLeaf(root))
    {
        printf("%c: ", root->key);
        printArr(arr, top_n);
    }
};
 
// The main function that builds a Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
   //  Construct Huffman Tree
   struct HeapNode* tree = Huffman(data, freq, size);
 
   // Print Huffman codes using the Huffman tree built above
   int arr[100];
   int top_n = 0;
   printCodes(tree, arr, top_n);
};

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}