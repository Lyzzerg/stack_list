#pragma once
template <class QueueType>
class TQueue
{
private:
	int begin, end, queuelen, MaxSize;
	QueueType *queue;

public:
	TQueue(int _maxsize = 10);
	virtual ~TQueue() { delete[] queue; }
	TQueue(const TQueue& _queue);
	bool IsEmpty(){return queuelen == 0;}
	bool IsFull(){return queuelen == MaxSize;}
	void Push(const QueueType _elem);
	QueueType Pop();
	QueueType Top();
	QueueType Bot();
	void Clear();
};

template<class QueueType>
TQueue<QueueType>::TQueue(int _maxsize)
{
	if (_maxsize <= 0)
		throw _maxsize;
	MaxSize = _maxsize;
	queue = new QueueType[MaxSize];
	begin = 0;
	end = -1;
	queuelen = 0;
}

template<class QueueType>
TQueue<QueueType>::TQueue(const TQueue & _queue)
{
	MaxSize = _queue.MaxSize;
	begin = _queue.begin;
	end = _queue.end;
	queuelen = _queue.queuelen;
	queue = new QueueType[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		queue[i] = _queue.queue[i];
}

template<class QueueType>
void TQueue<QueueType>::Push(const QueueType _elem)
{
	if (queuelen == MaxSize)
		throw len;
	if (end < MaxSize - 1)
		end++;
	else 
		end = 0;
	queuelen++;
	queue[end] = _elem;
}

template<class QueueType>
QueueType TQueue<QueueType>::Pop()
{
	if (!queuelen)
		throw - 1;
	QueueType tmp = queue[begin];
	if (begin < MaxSize - 1)
		begin++;
	else 
		begin = 0;
	queuelen--;
	return tmp;
}

template<class QueueType>
QueueType TQueue<QueueType>::Top()
{
	if (!queuelen)
		throw - 1;
	return queue[begin];
}

template<class QueueType>
QueueType TQueue<QueueType>::Bot()
{
	if (!queuelen)
		throw - 1;
	return queue[end];
}

template<class QueueType>
void TQueue<QueueType>::Clear()
{
	begin = 0;
	end = -1;
	queuelen = 0;
}
