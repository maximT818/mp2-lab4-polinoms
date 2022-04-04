#include "pch.h"
#include "Polinom.h"

TEST(Node, can_create_node) {
	ASSERT_NO_THROW(Node<int> node(1,1));
}

TEST(List, can_create_List) {
	ASSERT_NO_THROW(List<int> lst);
}

TEST(List, can_get_size) {

	List<int> lst;
	for (int i = 0; i < 5; i++)
	{
		lst.push_back(1, 1);
	}
	EXPECT_EQ(5, lst.GetSize());
}

TEST(List, can_push_back) {
	List<int> lst();
	ASSERT_NO_THROW(lst.push_back(1, 1));
}

TEST(List, can_push_front) {
	List<int> lst();
	ASSERT_NO_THROW(lst.push_front(1, 1));
}

TEST(List, can_pop_front) {
	List<int> lst();
	lst.push_back(1, 1);
	ASSERT_NO_THROW(lst.pop_front());
}

TEST(List, can_pop_back) {
	List<int> lst();
	lst.push_back(1, 1);
	ASSERT_NO_THROW(lst.pop_back());
}

TEST(List, can_clear_list) {

	List<int> lst;
	for (int i = 0; i < 5; i++)
	{
		lst.push_back(1, 1);
	}
	lst.clear();
	EXPECT_EQ(0, lst.GetSize());
}

TEST(List, can_insert_element) {
	List<int> lst();
	lst.push_back(1, 1);
	ASSERT_NO_THROW(lst.insert(5, 7, 1);
}

TEST(List, can_remove_element) {

	List<int> lst;
	for (int i = 0; i < 5; i++)
	{
		lst.push_back(1, 1);
	}
	lst.removeAt(3);
	EXPECT_EQ(4, lst.GetSize());
}

TEST(List, can_swap) {
	List<int> lst();
	for (int i = 0; i < 5; i++)
	{
		lst.push_back(1, 1);
	}
	ASSERT_NO_THROW(lst.swap(1, 2));
}

TEST(Polinom, can_create_polinom) {
	ASSERT_NO_THROW(Polinom<int> pol);
}

TEST(Polinom, can_be_assigned_a_polynomial) {

	Polynom<int> pol, pol1;
	for (int i = 0; i < 5; i++)
	{
		pol.push_back(1, 1);
	}
	pol1 = pol;
	EXPECT_EQ(pol1, pol);
}

TEST(Polinom, can_merge_polinoms) {
	Polinom<int> pol, pol1, res;
	ASSERT_NO_THROW(MergePolinoms(pol, pol1, res));
}

TEST(Polinom, can_subtract_polinoms) {
	Polinom<int> pol, pol1, res;
	ASSERT_NO_THROW(SubtractPolinoms(pol, pol1, res));
}

TEST(Polinom, can_multiply_polinoms) {
	Polinom<int> pol, pol1, res;
	ASSERT_NO_THROW(MultiplyPolinoms(pol, pol1, res));
}