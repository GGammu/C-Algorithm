#pragma once
#include "../List/DoubleList.h"

namespace cppalgo
{
	template<class TYPE>
	class ListQueue
	{
	public:
		enum Exception
		{
			QUEUE_OVERFLOW,
			QUEUE_UNDERFLOW,
			QUEUE_EMPTY
		};
	public:
		ListQueue() { }
		~ListQueue() { }

		long GetCount() const { m_list.GetCount(); }
		long IsEmpty() const { return m_list.IsEmpty(); }
		void RemoveAll() { m_list.RemoveAll(); }

		TYPE GetFront() const;
		TYPE GetRear() const;

		void Put(const TYPE & newElem);
		TYPE Get();
	protected:
		DoubleList<TYPE> m_list;
	};

	template<class TYPE>
	inline TYPE ListQueue<TYPE>::GetFront() const
	{
		TYPE t;

		try
		{
			t = m_list.GetHead();
		}
		catch (const DoubleList<TYPE>::Exception)
		{
			throw QUEUE_EMPTY;
		}
		
		return t;
	}

	template<class TYPE>
	inline TYPE ListQueue<TYPE>::GetRear() const
	{
		TYPE t;

		try
		{
			t = m_list.GetTail();
		}
		catch (const DoubleList<TYPE>::Exception&)
		{
			throw QUEUE_EMPTY
		}

		return t;
	}

	template<class TYPE>
	inline void ListQueue<TYPE>::Put(const TYPE & newElem)
	{
		m_list.AddTail(newElem);
	}

	template<class TYPE>
	inline TYPE ListQueue<TYPE>::Get()
	{
		TYPE t;

		try
		{
			t = m_list.RemoveHead();
		}
		catch (const DoubleList<TYPE>::Exception)
		{
			throw QUEUE_UNDERFLOW;
		}

		return t;
	}
}