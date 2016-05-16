#pragma once
#pragma once

namespace cppalgo {

	typedef void* POS;

	template <class TYPE> class DoubleList
	{
	public:
		enum Exception
		{
			INVALID_POS,
			EMPTY_LIST
		};
	public:
		// constructor / destructor
		DoubleList() { _init(); }
		~DoubleList() { _clear(); }

		int GetCount() const { return m_nCount; }
		bool IsEmpty() const { return m_nCount == 0; }

		TYPE &GetHead();
		TYPE GetHead() const;
		TYPE &GetTail();
		TYPE GetTail() const;

		bool IsValid(POS pos) const { return (pos != (POS)m_pNodeHead && pos != (POS)m_pNodeTail && pos != 0); }

		// basic operation
		TYPE DeleteAt(POS pos);
		POS InsertBefore(POS pos, const TYPE& newElem);
		POS InsertNext(POS pos, const TYPE& newElem);

		TYPE RemoveHead() { return DeleteAt(m_pNodeHead->pNext); }
		TYPE RemoveTail() { return DeleteAt(m_pNodeTail->pPrev); }

		// head operation
		POS AddHead(const TYPE& newElem) { return InsertNext(m_pNodeHead, newElem); }
		POS AddTail(const TYPE& newElem) { return InsertBefore(m_pNodeTail, newElem); }

		void RemoveAll();

		// traverse
		POS GetHeadPosition() const { return (m_nCount > 0) ? m_pNodeHead->pNext : 0; }
		TYPE &GetNext(POS& pos);
		TYPE GetNext(POS& pos) const;

		POS GetTailPosition() const { return (m_nCount > 0) ? m_pNodeTail->pPrev : 0; }
		TYPE &GetPrev(POS& pos);
		TYPE GetPrev(POS pos) const;

		// Get / Set
		TYPE &GetAt(POS pos);
		TYPE GetAt(POS pos) const;
		void SetAt(POS pos, const TYPE& newElem);

		// Find
		POS Find(const TYPE& searchVal, POS startAfter = 0) const;
		POS FindReverse(const TYPE& searchVal, POS startFrom = 0) const;
		POS FindIndex(int nIndex) const;

	protected:
		struct Node
		{
			TYPE data;
			Node *pPrev;
			Node *pNext;
			Node()
			{
				pPrev = 0;
				pNext = 0;
			}
		};

		Node *m_pNodeHead;
		Node *m_pNodeTail;
		int m_nCount;

		void _init();
		void _clear();
	};

	template <class TYPE> void DoubleList<TYPE>::_init()
	{
		m_pNodeHead = new Node;
		m_pNodeTail = new Node;

		m_pNodeHead->pPrev = m_pNodeHead;
		m_pNodeHead->pNext = m_pNodeTail;

		m_pNodeTail->pPrev = m_pNodeHead;
		m_pNodeTail->pNext = m_pNodeTail;

		m_nCount = 0;
	}

	template <class TYPE> void DoubleList<TYPE>::_clear()
	{
		RemoveAll();

		if (m_pNodeHead)
			delete m_pNodeHead;
		if (m_pNodeTail)
			delete m_pNodeTail;

		m_pNodeHead = 0;
		m_pNodeTail = 0;
		m_nCount = 0;
	}

	template<class TYPE>
	inline TYPE & DoubleList<TYPE>::GetHead()
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		if (m_nCount > 0)
			return m_pNodeHead->pNext->data;
		else
			throw EMPTY_LIST;
	}

	template<class TYPE>
	inline TYPE DoubleList<TYPE>::GetHead() const
	{
		if (m_nCount > 0)
			return m_pNodeHead->pNext->data;
		else
			throw EMPTY_LIST;
	}

	template<class TYPE>
	inline TYPE & DoubleList<TYPE>::GetTail()
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		if (m_nCount > 0)
			return m_pNodeTail->pPrev->data;
		else
			throw EMPTY_LIST;
	}

	template<class TYPE>
	inline TYPE DoubleList<TYPE>::GetTail() const
	{
		if (m_nCount > 0)
			return m_pNodeTail->pPrev->data;
		else
			throw EMPTY_LIST;
	}

	template<class TYPE>
	inline TYPE DoubleList<TYPE>::DeleteAt(POS pos)
	{
		Node *pNode = (Node*)pos;

		if (pNode == 0)
			throw INVALID_POS;
		else if (pNode == m_pNodeHead || pNode == m_pNodeTail)
			throw EMPTY_LIST;

		pNode->pPrev->pNext = pNode->pNext;
		pNode->pNext->pPrev = pNode->pPrev;

		TYPE rt = pNode->data;
		delete pNode;

		m_nCount--;

		return rt;
	}

	template<class TYPE>
	inline POS DoubleList<TYPE>::InsertBefore(POS pos, const TYPE & newElem)
	{
		if (pos == (POS)m_pNodeHead || pos == 0)
			throw INVALID_POS;

		Node *pNode = (Node*)pos;
		Node *pNewNode = new Node;

		pNewNode->data = newElem;
		pNewNode->pPrev = pNode->pPrev;
		pNode->pPrev->pNext = pNewNode;
		pNewNode->pNext = pNode;
		pNode->pPrev = pNewNode;

		m_nCount++;

		return pNewNode;
	}

	template<class TYPE>
	inline POS DoubleList<TYPE>::InsertNext(POS pos, const TYPE & newElem)
	{
		if (pos == m_pNodeTail || pos == 0)
			throw INVALID_POS;

		Node *pNode = (Node*)pos;
		Node *pNewNode = new Node;

		pNewNode->data = newElem;

		pNode->pNext->pPrev = pNewNode;
		pNewNode->pNext = pNode->pNext;
		pNode->pNext = pNewNode;
		pNewNode->pPrev = pNode;

		m_nCount++;

		return pNewNode;
	}

	template<class TYPE>
	inline void DoubleList<TYPE>::RemoveAll()
	{
		int n = GetCount();

		for (int i = 0; i < n; i++)
			RemoveHead();
	}

	template<class TYPE>
	inline TYPE & DoubleList<TYPE>::GetNext(POS & pos)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		if (!IsValid(pos))
			throw INVALID_POS;

		Node *pNode = (Node*)pos;

		if (IsValid(pNode->pNext))
			pos = pNode->pNext;
		else
			pos = 0;

		return pNode->data;
	}

	template<class TYPE>
	inline TYPE DoubleList<TYPE>::GetNext(POS & pos) const
	{
		if (!IsValid(pos))
			throw INVALID_POS;

		Node *pNode = (Node*)pos;

		if (IsValid(pNode->pNext))
			pos = pNode->pNext;
		else
			pos = 0;

		return pNode->data;
	}

	template<class TYPE>
	inline TYPE & DoubleList<TYPE>::GetPrev(POS & pos)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		if (!IsValid(pos))
			throw INVALID_POS;

		Node *pNode = (Node*)pos;

		if (IsValid(pNode->pPrev))
			pos = pNode->pPrev;
		else
			pos = 0;

		return pNode->data;
	}

	template<class TYPE>
	inline TYPE DoubleList<TYPE>::GetPrev(POS pos) const
	{
		if (!IsValid(pos))
			throw INVALID_POS;

		Node *pNode = (Node*)pos;

		if (IsValid(pNode->pPrev))
			pos = pNode->pPrev;
		else
			pos = 0;

		return pNode->data;
	}

	template<class TYPE>
	inline TYPE & DoubleList<TYPE>::GetAt(POS pos)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		if (IsValid(pos))
			return ((Node*)pos)->data;
		else
			throw INVALID_POS;
	}

	template<class TYPE>
	inline TYPE DoubleList<TYPE>::GetAt(POS pos) const
	{
		if (IsValid(pos))
			return ((Node*)pos)->data;
		else
			throw INVALID_POS;
	}

	template<class TYPE>
	inline void DoubleList<TYPE>::SetAt(POS pos, const TYPE & newElem)
	{
		if (IsValid(pos))
			((Node*)pos)->data = newElem;
		else
			throw INVALID_POS;
	}

	template<class TYPE>
	inline POS DoubleList<TYPE>::Find(const TYPE & searchVal, POS startAfter) const
	{
		POS pos;

		if (IsValid(startAfter))
			pos = startAfter;
		else
			pos = GetHeadPosition();

		while (pos)
		{
			TYPE d = GetAt(pos);
			if (d == searchVal)
				break;
			GetNext(pos);
		}

		return pos;
	}

	template<class TYPE>
	inline POS DoubleList<TYPE>::FindReverse(const TYPE & searchVal, POS startFrom) const
	{
		POS pos;

		if (IsValid(startFrom))
			pos = startFrom;
		else
			pos = GetTailPosition();

		while (pos)
		{
			TYPE d = GetAt(pos);
			if (d == searchVal)
				break;
			GetPrev(pos);
		}
		return pos;
	}

	template<class TYPE>
	inline POS DoubleList<TYPE>::FindIndex(int nIndex) const
	{
		if (nIndex >= GetCount())
			return 0;
		int nCount = 0;

		POS pos = GetHeadPosition();

		for (int i = 0; i < nIndex; i++)
		{
			GetNext(pos);
		}
		return pos;
	}

}