#include "libs/data_structures/bitset/bitset.h"

void test_bitset_create() {
    bitset receivedSet = bitset_create(3);
    bitset expectedSet = {0, 3};
    assert(receivedSet.values == expectedSet.values && receivedSet.maxValue == expectedSet.maxValue);
}

void test_bitset_in1() {
    bitset receivedSet = {2, 3};
    assert(bitset_in(receivedSet, 0) == 0);
}

void test_bitset_in2() {
    bitset receivedSet = {3, 10};
    assert(bitset_in(receivedSet, 1) == 1);
}

void test_bitset_in() {
    test_bitset_in1();
    test_bitset_in2();
}

void test_bitset_isEqual1() {
    bitset receivedSet1 = {10, 31};
    bitset receivedSet2 = {10, 31};
    assert(bitset_isEqual(receivedSet1, receivedSet2));
}

void test_bitset_isEqual2() {
    bitset set1 = {13, 10};
    bitset set2 = {4, 10};
    assert(!bitset_isEqual(set1, set2));
}

void test_bitset_isEqual() {
    test_bitset_isEqual1();
    test_bitset_isEqual2();
}

void test_bitset_isSubset1() {
    bitset subSet = {2, 5};
    bitset receivedSet = {7, 5};
    assert(bitset_isSubset(subSet, receivedSet));
}

void test_bitset_isSubset2() {
    bitset subSet = {10, 5};
    bitset receivedSet = {9, 5};
    assert(!bitset_isSubset(subSet, receivedSet));
}

void test_bitset_isSubset() {
    test_bitset_isSubset1();
    test_bitset_isSubset2();
}

void test_bitset_insert1() {
    bitset receivedSet = bitset_create(15);
    bitset expectedSet = {1, 15};
    bitset_insert(&receivedSet, 0);
    assert(receivedSet.values == expectedSet.values);
}

void test_bitset_insert2() {
    bitset receivedSet = {5, 5};
    bitset expectedSet = {7, 5};
    bitset_insert(&receivedSet, 1);
    assert(receivedSet.values == expectedSet.values);
}

void test_bitset_insert() {
    test_bitset_insert1();
    test_bitset_insert2();
}

void test_bitset_deleteElement1() {
    bitset receivedSet = {1, 3};
    bitset expectedSet = {0, 3};
    bitset_deleteElement(&receivedSet, 0);
    assert(receivedSet.values == expectedSet.values);
}

void test_bitset_deleteElement2() {
    bitset receivedSet = {5, 5};
    bitset expectedSet = {0, 5};
    bitset_deleteElement(&receivedSet, 0);
    bitset_deleteElement(&receivedSet, 2);
    assert(receivedSet.values == expectedSet.values);
}

void test_bitset_deleteElement() {
    test_bitset_deleteElement1();
    test_bitset_deleteElement2();
}

void test_bitset_union1() {
    bitset receivedSet1 = {0, 1};
    bitset receivedSet2 = {0, 1};
    bitset unionSet = bitset_union(receivedSet1, receivedSet2);

    bitset expectedSet = {0, 1};
    assert(unionSet.values == expectedSet.values);
}

void test_bitset_union2() {
    bitset receivedSet1 = {2, 10};
    bitset receivedSet2 = {1, 10};

    bitset unionSet = bitset_union(receivedSet1, receivedSet2);
    bitset expectedSet = {3, 10};
    assert(unionSet.values == expectedSet.values);
}

void test_bitset_union() {
    test_bitset_union1();
    test_bitset_union2();
}

void test_bitset_intersection1() {
    bitset receivedSet1 = {7, 10};
    bitset receivedSet2 = {2, 10};
    bitset intersectionSet = bitset_intersection(receivedSet1, receivedSet2);
    bitset expectedSet = {2, 10};
    assert(intersectionSet.values == expectedSet.values);
}

void test_bitset_intersection2() {
    bitset receivedSet1 = {7, 7};
    bitset receivedSet2 = {0, 7};
    bitset intersectionSet = bitset_intersection(receivedSet1, receivedSet2);
    bitset expectedSet = {0, 7};
    assert(intersectionSet.values == expectedSet.values);
}

void test_bitset_intersection() {
    test_bitset_intersection1();
    test_bitset_intersection2();
}

void test_bitset_difference1() {
    bitset receivedSet1 = {3, 3};
    bitset receivedSet2 = {2, 3};
    bitset expectedSet = {1, 3};
    assert(bitset_difference(receivedSet1, receivedSet2).values == expectedSet.values);
}

void test_bitset_difference2() {
    bitset receivedSet1 = {2, 3};
    bitset receivedSet2 = {0, 3};
    bitset expectedSet = {2, 3};
    assert(bitset_difference(receivedSet1, receivedSet2).values == expectedSet.values);
}

void test_bitset_difference() {
    test_bitset_difference1();
    test_bitset_difference2();
}

void test_bitset_symmetricDifference1() {
    bitset receivedSet1 = {1, 1};
    bitset receivedSet2 = {1, 1};
    bitset expectedSet = {0, 1};
    assert(bitset_symmetricDifference(receivedSet1, receivedSet2).values == expectedSet.values);
}

void test_bitset_symmetricDifference2() {
    bitset receivedSet1 = {0, 5};
    bitset receivedSet2 = {5, 5};
    bitset expectedSet = {5, 5};
    assert(bitset_symmetricDifference(receivedSet1, receivedSet2).values == expectedSet.values);
}

void test_bitset_symmetricDifference() {
    test_bitset_symmetricDifference1();
    test_bitset_symmetricDifference2();
}

void test_bitset_complement1() {
    bitset receivedSet = {3, 5};
    bitset expectedComplement = {60, 5};
    assert(bitset_complement(receivedSet).values == expectedComplement.values);
}

void test_bitset_complement2() {
    bitset receivedSet = {4, 3};
    bitset expectedComplement = {11, 3};
    assert(bitset_complement(receivedSet).values == expectedComplement.values);
}

void test_bitset_complement() {
    test_bitset_complement1();
    test_bitset_complement2();
}

void test_bitset() {
    test_bitset_create();
    test_bitset_in();
    test_bitset_isEqual();
    test_bitset_isSubset();
    test_bitset_insert();
    test_bitset_deleteElement();
    test_bitset_union();
    test_bitset_intersection();
    test_bitset_difference();
    test_bitset_symmetricDifference();
    test_bitset_complement();
}

int main() {
    test_bitset();
    return 0;
}