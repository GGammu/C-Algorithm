#pragma once

namespace cppalgo
{
	template <class TYPE>
	class CircularQueue
	{
	public:
		enum Exception
		{
			QUEUE_OVERFLOW,
			QUEUE_UNDERFLOW,
			INVALID_QUEUE_SIZE,
			MEMALLOC_FAILED,
			QUEUE_EMPTY
		};
	public:
		CircularQueue(long nSize = 100);
		~CircularQueue();
		long GetCount() const { return m_nCount; }
		bool IsEmpty() const { return GetCount() == 0; }
		void RemoveAll();
		TYPE GetFront() const;
		TYPE GetRear() const;
		void Put(const TYPE &newElem);
		TYPE Get();
	protected:
		long _inc(long n);
		long _dec(long n);
		TYPE *m_pArray;
		long m_nFront;
		long m_nRear;
		long m_nCount;
		long m_nSize;
	};

	template<class TYPE>
	inline CircularQueue<TYPE>::CircularQueue(long nSize)
	{
		if (nSize <= 0)
			throw INVALID_QUEUE_SIZE;

		m_pArray = new TYPE[m_nSize];

		if (m_pArray == 0)
			throw MEMALLOC_FAILED;

		m_nFront = 0;
		m_nRear = 0;

		m_nCount = 0;
		m_nSize = nSize;
	}

	template<class TYPE>
	inline CircularQueue<TYPE>::~CircularQueue()
	{
		delete[]m_pArray;
	}

	template<class TYPE>
	inline void CircularQueue<TYPE>::RemoveAll()
	{
		m_nCount = 0;
		m_nFront = 0;
		m_nRear = 0;
	}

	template<class TYPE>
	inline TYPE CircularQueue<TYPE>::GetFront() const
	{
		if (IsEmpty())
			throw QUEUE_EMPTY;

		return m_pArray[m_nFront];
	}

	template<class TYPE>
	inline TYPE CircularQueue<TYPE>::GetRear() const
	{
		if (IsEmpty())
			throw QUEUE_EMPTY;

		return m_pArray[_dec(m_nRear)];
	}

	template<class TYPE>
	inline void CircularQueue<TYPE>::Put(const TYPE & newElem)
	{
		if (_inc(m_nRear) == m_nFront)
			throw QUEUE_OVERFLOW;

		m_pArray[m_nRear] = newElem;
		m_nRear = _inc(m_nRear);
		m_nCount++;
	}

	template<class TYPE>
	inline TYPE CircularQueue<TYPE>::Get()
	{
		if (m_nFront == m_nRear)
			throw QUEUE_                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  UNDERFLOW;

		TYPE t = m_pArray[m_nFront];
		m_nFront = _inc(m_nFront);
		m_nCount--;
		return t;
	}

	template<class TYPE>
	inline long CircularQueue<TYPE>::_inc(long n)
	{
		return (n + 1) % m_nSize;
	}

	template<class TYPE>
	inline long CircularQueue<TYPE>::_dec(long n)
	{
		return (m_nSize + n - 1) % m_nSize;
	}

}

