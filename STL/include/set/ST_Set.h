#pragma once

/*
* Custom Set implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: May 5~, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../tree/ST_RBTree.h"

namespace ST
{
	template <typename T>
	class set
	{
	private:
		RBTree<T> m_Tree;	// Member variable to store the redblack tree.
	
	public:
		// Assigning traits for iterator functions.
		using value_type = T;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using size_type = int;
		using difference_type = int;

		// Using shorter name for iterators.
		using iterator = typename RBTree<T>::iterator;
		using const_iterator = typename RBTree<T>::const_iterator;
		using reverse_iterator = typename RBTree<T>::reverse_iterator;
		using const_reverse_iterator = typename RBTree<T>::const_reverse_iterator;

	public:
		// RBTree Functions
		// empty Function; Check if the tree is empty.
		bool empty() const { return m_Tree.empty(); }
		// size Function; Return the size of the tree.
		size_t size() const { return m_Tree.size(); }
		// clear Function; Erase all the data from the tree.
		void clear() { m_Tree.clear(); }
		// insert Function; Insert the given value to the tree.
		ST::pair<iterator, bool> insert(const T& value) { return m_Tree.insert(value); }
		// erase Function; Erase the given value from the tree.
		size_t erase(const T& value) { return m_Tree.erase(value); }
		// find Function; Find the given value from the tree.
		iterator find(const T& value) { return m_Tree.find(value); }
		// count Function; Count the number of value from the tree.
		size_t count(const T& value) const { return m_Tree.count(value); }

		// Iterator Functions
		// begin Function; Return the iterator that points to the left most node.
		iterator		begin()			{ return m_Tree.begin(); }
		// end Function; Return the iterator that points to nil node.
		iterator		end()			{ return m_Tree.end(); }
		// begin Function; Constant version of begin function.
		const_iterator	begin() const	{ return m_Tree.begin(); }
		// end Function; Constant version of end function.
		const_iterator	end() const		{ return m_Tree.end(); }
		// cbegin Function; Constant version of begin function that returns constant iterator explicitly.
		const_iterator	cbegin() const	{ return m_Tree.cbegin(); }
		// cend Function; Constant version of end function that returns constant iterator explicitly.
		const_iterator	cend() const	{ return m_Tree.cend(); }

		// rbegin Function; Return the reverse iterator that points to the right most node.
		reverse_iterator		rbegin()		{ return m_Tree.rbegin(); }
		// rend Function; Return the reverse iterator that points to nil node.
		reverse_iterator		rend()			{ return m_Tree.rend(); }
		// rbegin Function; Constant version of rbegin function.
		const_reverse_iterator	rbegin() const	{ return m_Tree.rbegin(); }
		// rend Function; Constant version of rend function.
		const_reverse_iterator	rend() const	{ return m_Tree.rend(); }
		// crbegin Function; Constant version of rbegin function that returns constant reverse iterator explicitly.
		const_reverse_iterator	crbegin()		{ return m_Tree.crbegin(); }
		// crend Function; Constant version of rend function that returns constant reverse iterator explicitly.
		const_reverse_iterator	crend()			{ return m_Tree.crend(); }

	public:
		// Constructor; Initialize the root node to nothing, then set the root as 'nil'.
		set() = default;
		~set() = default;
	};
}