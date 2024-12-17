#include "File.h"

Block File::getBlock(int index) const
{
	if (blocks.containsNode(blocks.getNodeAtIndex(index))) {
		return (blocks.getNodeAtIndex(index))->data;
	}
	else {
		return Block();
	}


}

size_t File::fileSize() const
{
	if (isEmpty()) {
		return 0;
	}
	else {
		size_t size = 0;
		Node<Block>* temp = blocks.getFirstNode();
		while (temp != NULL) {
			size += (temp->data).getSize();
			temp = temp->next;
		}
		return size;

	}
}

int File::numBlocks() const
{
	return blocks.getSize();
}

bool File::isEmpty() const
{
	if (numBlocks() == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool File::operator==(const File& rhs) const
{
	int i;
	if (this->numBlocks() != rhs.numBlocks()) {
		return false;
	}
	for (i = 0; i < numBlocks(); i++) {
		if (!(this->getBlock(i) == rhs.getBlock(i))) {
			return false;
		}

	}
	return true;

}

void File::newBlock(const Block& block)
{
	blocks.append(block);
}

void File::removeBlock(int index)
{
	blocks.removeNodeAtIndex(index);
}

void File::mergeBlocks(int sourceIndex, int destIndex)
{
	blocks.mergeNodes(sourceIndex, destIndex);
}

void File::printContents() const {
	if (isEmpty()) {
		std::cout << "File is empty" << std::endl;
	}
	else {
		for (int i = 0; i < blocks.getSize(); i++) {
			Node<Block>* block = blocks.getNodeAtIndex(i);
			std::cout << block->data.getContent();
		}
		std::cout << std::endl << fileSize() << std::endl;
	}
}