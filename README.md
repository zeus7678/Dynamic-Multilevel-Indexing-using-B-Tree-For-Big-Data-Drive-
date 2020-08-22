 #Dynamic-Multilevel-Indexing-using-B-Tree-For-Big-Data-Drive
 
 Dynamic Multilevel Indexing was done using B-Tree to implement a dictionary containing words and their meaning. Here the key was our word.
 B-Tree provided fast retrieval of data from the Secondary Memory. The data address being generated in binary was of 32-bit to keep the size of
 dictionary sufficiently large. The whole code was written in C language.
 
 #To Do
*first we make a B-tree then an infinity loop runs to get meaning for given key until it gets key board input ".".

*first we make a B-tree from an input file "binput.dat" and store this formed B-tree in a binary file "btree.dat".
*to make B-tree from input file first a cunstructor will be called that will create the binary file and open it in write mode then then set root to null and number of nodes to 0 and number of items to 0 as well then root, number of nodes and number of items will be set in current node's branch values then we write information of current node in the binary file.
*after that we will read a predefined size of characters until end of file, lets call it block, in each block since size of key, and data is predefined, it will separate key and related data from block. from this given key and given data, an item will be formed and this item will be inserted in B-tree then. during insertion it will load information for new node in the end of binary file.
*then a destructor will be called which will load current node at begining of the binary file because after each iteration the current node will be set to root node then it will close the file

*to search for the meaning of a word first the given programme will open preformed binary file in read mode only.
then read first node will be read from the file since it contains the value for root node and numbers of node and numbers of items it will set current node's branch values as number of nodes, numbers of items and root.
*then an infinity loop runs to get meaning for given key until it gets key board input ".". in this loop it will take user input as searching key and it will search this asked key in binary file using defined B-tree data structure.
