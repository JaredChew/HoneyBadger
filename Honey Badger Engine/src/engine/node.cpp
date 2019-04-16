#include "node.h"

HoneyBadger::Node::Node() {

	x = 0;
	y = 0;

	openNode = true;
	visited = false;
	passable = true;

}

HoneyBadger::Node::~Node() { }

void HoneyBadger::Node::setNodePositions(int x, int y) {
	this->x = x;
	this->y = y;
}

void HoneyBadger::Node::setX(int x) {
	this->x = x;
}

void HoneyBadger::Node::setY(int y) {
	this->y = y;
}

int HoneyBadger::Node::getX() {
	return x;
}

int HoneyBadger::Node::getY() {
	return y;
}

void HoneyBadger::Node::setOpenNode(bool openNode) {
	this->openNode = openNode;
}

void HoneyBadger::Node::setVisited(bool visited) {
	this->visited = visited;
}

void HoneyBadger::Node::setPassable(bool passable) {
	this->passable = passable;
}

bool HoneyBadger::Node::getOpenNode() {
	return openNode;
}

bool HoneyBadger::Node::getVisited() {
	return visited;
}

bool HoneyBadger::Node::getPassable() {
	return passable;
}
