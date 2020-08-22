 #Dynamic-Multilevel-Indexing-using-B-Tree-For-Big-Data-Drive
 
 Dynamic Multilevel Indexing was done using B-Tree to implement a dictionary containing words and their meaning. Here the key was our word.
 B-Tree provided fast retrieval of data from the Secondary Memory. The data address being generated in binary was of 32-bit to keep the size of
 dictionary sufficiently large. The whole code was written in C language.
 
#To Do
#first we make a B-tree then an infinity loop runs to get meaning for given key until it gets key board input ".".

#first we make a B-tree from an input file "binput.dat" and store this formed B-tree in a binary file "btree.dat".

#to make B-tree from input file first a cunstructor will be called that will create the binary file and open it in write mode then then set root to null and number of nodes to 0 and number of items to 0 as well then root, number of nodes and number of items will be set in current node's branch values then we write information of current node in the binary file.
