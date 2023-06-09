#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template<typename T>
class Stack : public LinkedList<T> {
public:
	bool Delete(T& element) {
		//first가 0이면 false반환
		if (this->first == 0)
			return false;
		Node<T>* current = this->first;
		// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
		if (current->link == 0) //스택에 1개의 원소만 존재한다면
		{
			this->first = this->first->link; //스택의 첫노드를 없애는 만드는 방식
		}
		else { //스택에 2개 이상의 노드가 있다면
			this->first = this->first->link;
		}
		element = current->data;
		current = 0;
		this->current_size--;
		delete current;
		return true;
	}
};
