#include "inc/UpdateNode.h"

#include <sstream>

UpdateNode::UpdateNode() {
	_leftInput = nullptr;
	_rightInput = nullptr;
	_output = nullptr;
}

void UpdateNode::setLeftInput(BaseNode* n) {
        _leftInput = n;
}

void UpdateNode::setRightInput(BaseNode* n) {
        _rightInput = n;
}

void UpdateNode::setLeftOutput(BaseNode* n) {
        _output = n;
}

void UpdateNode::setOutput(BaseNode* n) {
        _output = n;
}

std::string UpdateNode::getType() {
        return "U";
}

std::string UpdateNode::toString() {
	std::stringstream ss;
	ss<<BaseNode::toString();
	if(_output)
		ss<<_output->getID()<<" "<<_output->getConnectedPort(this);
	ss<<")\t\t(- -) \t\t INFO";
	return ss.str();
}

int UpdateNode::getConnectedPort(BaseNode* n) {
	if(_leftInput == n) {
		return 0;
	} else if(_rightInput == n) {
		return 1;
	}
	return -1;
}
