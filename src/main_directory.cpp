/*#ifndef DIRECTORY_MAIN_H
#define DIRECTORY_MAIN_H

#include "Node.h"
#include "Block.h"
#include "LinkedList.h"
#include "File.h"
#include "Directory.h"

int main()
{
	Block c("aaaaaa");
	Block d("bbbbbbbbbb");
	File b;
	b.newBlock(c);
	b.newBlock(d);
	b.mergeBlocks(0, 1);
	Directory a;
	a.newFile(b);
	a.newFile(b);
	a.newFile(b);

	a.removeBiggestFile();
}

#endif //DIRECTORY_MAIN_H*/