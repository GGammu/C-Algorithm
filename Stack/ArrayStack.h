#pragma once
namespace cppalgo
{

	template <class TYPE>
	class ArrayStack
	{
	public:
		enum Exception {
			STACK_OVERFLOW,
			STACK_UNDERFLOW,
			INVALID_STACK_SIZE,
			MEMALLOC_FAILED,
			STACK_EMPTY
		};
	public:
		ArrayStack(int nSize = 100);
		~ArrayStack();
		long GetCount() const;
		bool IsEmpty() const;
		void RemoveAll();
		TYPE GetTop() const;
		void Push(const TYPE& newElem);
		TYPE Pop();
	protected:
		TYPE* m_pArray;
		long m_nTop;
		long m_nSize;
	};

	template <class TYPE>
	ArrayStack<TYPE>::ArrayStack(int nSize)
	{
		if (nSize <= 0)
			throw INVALID_STACK_SIZE;

		m_pArray = new TYPE[nSize];

		if (m_pArray == 0)
			throw MEMALLOC_FAILED;

		m_nTop = -1;
		m_nSize = nSize;
	}

	template <class TYPE>
	ArrayStack<TYPE>::~ArrayStack()
	{
		delete[] m_pArray;
	}

	template<class TYPE>
	long ArrayStack<TYPE>::GetCount() const
	{
		return m_nTop + 1;
	}

	template<class TYPE>
	bool ArrayStack<TYPE>::IsEmpty() const
	{
		return GetCount() == 0;
	}

	template<class TYPE>
	void ArrayStack<TYPE>::RemoveAll()
	{
		m_nTop = -1;
	}

	template<class TYPE>
	TYPE ArrayStack<TYPE>::GetTop() const
	{
		if (IsEmpty())
			throw STACK_EMPTY;

		return m_pArray[m_nTop];
	}

	template<class TYPE>
	void ArrayStack<TYPE>::Push(const TYPE & newElem)
	{
		if (m_nTop >= m_nSize - 1)
			throw STACK_OVERFLOW;

		m_pArray[++m_nTop] = newElem;
	}

	template<class TYPE>
	TYPE ArrayStack<TYPE>::Pop()
	{
		if (IsEmpty())
			throw STACK_UNDERFLOW;

		return m_pArray[m_nTop--];
	}

}
