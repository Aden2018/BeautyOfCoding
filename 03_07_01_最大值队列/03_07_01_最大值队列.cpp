////���Ͽ�����https://blog.csdn.net/caryaliu/article/details/8097209
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <climits>
//#include <cassert>
//using namespace std;
//
//#define MAXN    100  
//class Stack
//{
//public:
//	//���캯������ʼ����ջ��  
//	//|stackTop|ָ��ǰ��ջ�Ķ���Ԫ�أ�  
//	//|maxStackItemIndex|�洢��ǰ��ջ�����Ԫ�ص�index  
//	Stack()
//	{
//		stackTop = -1;
//		maxStackItemIndex = -1;
//	}
//
//	//�жϵ�ǰ��ջ�Ƿ�Ϊ��  
//	bool isEmpty()
//	{
//		return stackTop == -1;
//	}
//
//	//�жϵ�ǰ��ջ�Ƿ���  
//	bool isFull()
//	{
//		return stackTop == MAXN - 1;
//	}
//
//	//���ջ��pushԪ�أ�  
//	void push(int x)
//	{
//		if (this->isFull())
//		{                //���ȼ���ջ�ռ��Ƿ���  
//			cout << "the stack is full now." << endl;
//		}
//		else
//		{
//			stackItem[++stackTop] = x;
//			//���ѹ���ջ��ֵ��֮ǰ��¼�����ֵ����ô��֮ǰ�����ֵ��¼��  
//			//link2NextMaxItem[stackTop]��λ�ã��ѵ�ǰ���ֵ�ڶ�ջstackItem  
//			//�е�λ����maxStackItemIndex����  
//			if (x > maxValue())
//			{
//				link2NextMaxItem[stackTop] = maxStackItemIndex;
//				maxStackItemIndex = stackTop;
//			}
//			else
//				link2NextMaxItem[stackTop] = -1;
//		}
//	}
//
//	int pop()
//	{
//		int ret;
//		if (this->isEmpty())
//		{
//			cout << "the stack is empty." << endl;
//		}
//		else
//		{
//			ret = stackItem[stackTop];
//			//���pop����ֵ�ǵ�ǰ�����ֵ����ô����Ҫ��֮ǰ���浽link2NextMaxItem[stackTop]  
//			//�е����ֵȡ��������maxStackItemIndex��ֵ  
//			if (stackTop == maxStackItemIndex)
//			{
//				maxStackItemIndex = link2NextMaxItem[stackTop];
//			}
//		}
//		--stackTop;
//		return ret;
//	}
//
//	//ȡ����ջ�е�ǰ�����ֵ  
//	int maxValue()
//	{
//		if (maxStackItemIndex >= 0)
//			return stackItem[maxStackItemIndex];
//		else
//		{
//			return INT_MIN;
//		}
//	}
//	void printItems()
//	{
//		for (int i = 0; i <= stackTop; ++i)
//		{
//			cout << " " << stackItem[i];
//		}
//	}
//	void reversePrintItems()
//	{
//		for (int i = stackTop; i >= 0; --i)
//		{
//			cout << " " << stackItem[i];
//		}
//	}
//private:
//	int stackItem[MAXN];
//	int stackTop;
//	int link2NextMaxItem[MAXN];
//	int maxStackItemIndex;
//};
//
//
//class Queue
//{
//public:
//	int maxValue(int x, int y)
//	{
//		if (x > y)
//			return x;
//		else
//			return y;
//	}
//
//	//���ض��������ֵ  
//	int max()
//	{
//		return maxValue(stackA.maxValue(), stackB.maxValue());
//	}
//
//	void printQueue()
//	{
//		stackA.reversePrintItems();
//		stackB.printItems();
//		cout << endl;
//	}
//
//	//�ڶ���ĩβ����Ԫ��  
//	void insertQueue(int x)
//	{
//		stackB.push(x);
//	}
//
//	//ɾ�������ض���Ԫ��,
//	//���stackA���ǿգ����Ƚ�stackB�е�����Ԫ��pop��stackA�У�  
//	//����stackB���Ȳ����Ԫ�ؾͻ�pop��stackA�еĶ���  
//	int deQueue()
//	{
//		if (stackA.isEmpty())
//		{
//			while (!stackB.isEmpty())
//				stackA.push(stackB.pop());
//		}
//		return stackA.pop();
//	}
//private:
//	Stack stackA;    //ά�������в���  
//	Stack stackB;    //ά������в���  
//};
//
//int main()
//{
//	Queue queue;
//	int a[] = { 909, 2, 3, 4, 9, 4, 5, 10, 6 };
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		queue.insertQueue(a[i]);
//	}
//	queue.insertQueue(101);
//	cout << "queue maxvalue = " << queue.max() << endl;
//	queue.insertQueue(590);
//	cout << "queue maxvalue = " << queue.max() << endl;
//	queue.printQueue();
//	int deq = queue.deQueue();
//	cout << "deq = " << deq << endl;
//	cout << "queue maxvalue = " << queue.max() << endl;
//}


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <stack>

//��ʵ������������ջ��ʵ��һ������ʱ�������ֵ��ջMaxStack
//Ȼ����������MaxStackʵ��һ��MaxQueue


template<class T>
class MaxStack
{

public:
	MaxStack() = default;
	void push(const T&val)
	{
		data_stack_.push(val);
		if (max_stack_.empty())
			max_stack_.push(val);
		else
		{
			if (val > max_stack_.top())
				max_stack_.push(val);
			else
				max_stack_.push(max_stack_.top());
		}
	}

	T pop()
	{
		if (data_stack_.empty())
			throw std::exception("Empty Stack!!!");

		T& top_val = data_stack_.top();
		data_stack_.pop();
		max_stack_.pop();
		return top_val;
	}

	T& top()
	{
		if (data_stack_.empty())
			throw std::exception("Empty Stack!!!");
		return data_stack_.top();
	}

	T max()
	{
		if (data_stack_.empty())
			throw std::exception("Empty Stack!!!");
		return max_stack_.top();
	}

	bool empty()
	{
		return data_stack_.empty();
	}

	size_t size()
	{
		return data_stack_.size();
	}

private:
	std::stack<T> data_stack_;
	std::stack<T> max_stack_;
};



template<class T, class Comp = std::less<T>>
class MaxMinStack
{
public:
	MaxMinStack() = default;
	void push(const T&val)
	{
		data_stack_.push(val);
		if (max_min_stack_.empty())
			max_min_stack_.push(val);
		else
		{
			//if (val > max_min_stack_.top())
			if (Comp(val,max_min_stack_.top()))
				max_min_stack_.push(val);
			else
				max_min_stack_.push(max_min_stack_.top());
		}
	}

	T pop()
	{
		if (data_stack_.empty())
			throw std::exception("Empty Stack!!!");

		T& top_val = data_stack_.top();
		data_stack_.pop();
		max_min_stack_.pop();
		return top_val;
	}

	T& top()
	{
		if (data_stack_.empty())
			throw std::exception("Empty Stack!!!");
		return data_stack_.top();
	}

	T max()
	{
		if (data_stack_.empty())
			throw std::exception("Empty Stack!!!");
		return max_min_stack_.top();
	}

	bool empty()
	{
		return data_stack_.empty();
	}

	size_t size()
	{
		return data_stack_.size();
	}

private:
	std::stack<T> data_stack_;
	std::stack<T> max_min_stack_;
};


template<class T>
class MaxQueue
{
public:
	void push(const T&val)
	{
		push_stack_.push(val);
	}

	T pop()
	{
		MoveBetweenStack();
		return pop_stack_.pop();
	}

	T& top()
	{
		MoveBetweenStack();
		return pop_stack_.top();
	}

	T max()
	{
		MoveBetweenStack();
		if (!push_stack_.empty())
			return std::max(push_stack_.max(), pop_stack_.max());
		else
			return pop_stack_.max();
	}

	bool empty()
	{
		return push_stack_.empty() && pop_stack_.empty();
	}

	size_t size()
	{
		return push_stack_.size() + pop_stack_.size();
	}

private:
	void MoveBetweenStack()
	{
		if (pop_stack_.empty())
		{
			if (push_stack_.empty())
				throw std::exception("empty stack!!!");
			while (!push_stack_.empty())
				pop_stack_.push(push_stack_.pop());
		}
	}

private:
	MaxStack<T> push_stack_;
	MaxStack<T> pop_stack_;
};


void testMaxStack()
{
	MaxStack<int> maxStack;
	maxStack.push(5);
	maxStack.push(4);
	maxStack.push(6);
	maxStack.push(3);

	assert(maxStack.max() == 6);
	assert(maxStack.top() == 3);
	assert(maxStack.pop() == 3);
	assert(maxStack.max() == 6);
	assert(maxStack.pop() == 6);
	assert(maxStack.max() == 5);
	assert(maxStack.pop() == 4);
	assert(maxStack.max() == 5);
	assert(maxStack.pop() == 5);

}

void testMaxQueue()
{
	MaxQueue<int> maxQueue;

	maxQueue.push(5);
	maxQueue.push(4);
	maxQueue.push(6);
	maxQueue.push(3);

	assert(maxQueue.max() == 6);
	assert(maxQueue.pop() == 5);
	assert(maxQueue.max() == 6);
	assert(maxQueue.top() == 4);
	assert(maxQueue.pop() == 4);
	assert(maxQueue.max() == 6);
	assert(maxQueue.pop() == 6);
	assert(maxQueue.max() == 3);
	assert(maxQueue.pop() == 3);
}



int main()
{
	testMaxStack();
	testMaxQueue();
	return 0;
}