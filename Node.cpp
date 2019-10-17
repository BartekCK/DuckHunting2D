#include "Node.h"

Node::Node(const char* backgroundBitmap):backgroundBitmap(backgroundBitmap)
{
	this->objectBitmap = al_load_bitmap(this->backgroundBitmap);
	if (!objectBitmap)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}

	this->width = al_get_bitmap_width(this->objectBitmap);
	this->height = al_get_bitmap_height(this->objectBitmap);
}

Node::~Node()
{
	al_destroy_bitmap(this->objectBitmap);
	cout << "DESTRUKTOR Z NODE" << endl;
}

int Node::getWidth()
{
	return this->width;
}

int Node::getHeight()
{
	return this->height;
}

void Node::setXposition(int x)
{
	this->xPosition = x;
}

void Node::setYposition(int y)
{
	this->yPosition = y;
}