#pragma once

/*
* Custom AVL Tree implementation by Seungtack Lee
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

/** 
* @brief Characteristics of Red Black Tree
* @details 
* 1. Root node has to be Black.
* 2. Red nodes cannot have red children.
* 3. Every path from radom node to all nil nodes have the same number of black nodes (Black Height).
* 4. ALL leaves (nils) are Black.
* 5. New inserted nodes are always Red.
* 
* @author Seungtack Lee
* @date May 5, 2025
*/

#include "../utility/utility.h"
#include "set_iterators.h"


namespace ST
{
	// enum Class for tree colors.
	enum class COLOR
	{
		RED,
		BLACK,
	};

	template <typename T>
	class set; // Declaration of set.

	template <typename T>
	class RBNode
	{
	private:
		T m_Data;				// Member variable to store data.
		COLOR color;			// Member variable to store node color.
		RBNode<T>* m_Parent;	// Member variable to store parent node.
		RBNode<T>* m_LChild;	// Member variable to store left child.
		RBNode<T>* m_RChild;	// Member variable to store right child.

	public:
		// Constructor; Initialize the node with given data, set the node for insertion.
		RBNode(const T& data)
			: m_Data(data)
			, color(COLOR::RED)
			, m_Parent(nullptr)
			, m_LChild(nullptr)
			, m_RChild(nullptr)
		{ }

		friend class set<T>;	// Grant access to private member by set class. 
	};

	template <typename T>
	class set
	{
	private:
		RBNode<T>* m_Root;	// Member variable to store the root node.
		RBNode<T>* nil;		// Member variable for nil node.
	
	private:
		// Helper Functions
		// Init_nil Function; Initialize the nil node to use, and mark leaf nodes.
		void Init_nil()
		{
			// Create a new node and assign it to 'nil'.
			nil = new RBNode<T>(T());
			// Initialize the 'nil' node to its own properties.
			nil->color = COLOR::BLACK;
			nil->m_Parent = nullptr;
			nil->m_LChild = nullptr;
			nil->m_RChild = nullptr;
		}

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
		using iterator = set_iterator<T>;
		using const_iterator = set_const_iterator<T>;
		using reverse_iterator = set_reverse_iterator<T>;
		using const_reverse_iterator = set_const_reverse_iterator<T>;

	public:
		// RBTree Functions
		// empty Function; Check if the tree is empty.
		bool empty() const;
		// size Function; Return the size of the tree.
		size_t size() const;
		// clear Function; Erase all the data from the tree.
		void clear();
		// insert Function; Insert the given value to the tree.
		ST::pair<iterator, bool> insert(const T& value);
		// erase Function; Erase the given value from the tree.
		size_t erase(const T& value);
		// find Function; Find the given value from the tree.
		iterator find(const T& value);
		// count Function; Count the number of value from the tree.
		size_t count(const T& value) const;

		// Iterator Functions
		// begin Function; Return the iterator that points to the left most node.
		iterator begin();
		// end Function; Return the iterator that points to nil node.
		iterator end();
		// cbegin Function; Constant version of begin function.
		const_iterator cbegin() const;
		// cend Function; Constant version of end function.
		const_iterator cend() const;
		// rbegin Function; Return the reverse iterator that points to the right most node.
		reverse_iterator rbegin();
		// rend Function; Return the reverse iterator that points to nil node.
		reverse_iterator rend();
		// crbegin Function; Constant version of rbegin function.
		const_reverse_iterator crbegin();
		// crend Function; Constant version of rend function.
		const_reverse_iterator crend();

	public:
		// Constructor; Initialize the root node to nothing, then set the root as 'nil'.
		set()
			: m_Root(nullptr)
		{
			// Initialize nil node.
			Init_nil();
			m_Root = nil;
		}
		~set()
		{
			// Delete all data.
			clear();
			delete nil;
		}
	};
}