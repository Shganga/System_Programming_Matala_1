//yanig1000@gmail.com
#include "doctest.h"
#include "PriorityQueue.hpp"
#include <iostream>
#include "Stack.hpp"
#include "UnionFind.hpp"

TEST_CASE("PriorityQueue Basic Operations") {
    PriorityQueue pq(5);

    SUBCASE("Enqueue and Dequeue") {
        pq.enqueue(10, 2);
        pq.enqueue(20, 1);
        pq.enqueue(30, 3);

        CHECK(pq.dequeue() == 20); // priority 1
        CHECK(pq.dequeue() == 10); // priority 2
        CHECK(pq.dequeue() == 30); // priority 3
        CHECK(pq.is_empty());
    }

    SUBCASE("Decrease Key") {
        pq.enqueue(1, 5);
        pq.enqueue(2, 3);
        pq.enqueue(3, 4);

        pq.decrease_key(1, 1); // now 1 has the highest priority

        CHECK(pq.dequeue() == 1);
        CHECK(pq.dequeue() == 2);
        CHECK(pq.dequeue() == 3);
    }

    SUBCASE("Contains Function") {
        pq.enqueue(7, 1);
        CHECK(pq.contains(7));
        CHECK(!pq.contains(9));
    }

    SUBCASE("Overflow Error") {
        pq.enqueue(1, 1);
        pq.enqueue(2, 2);
        pq.enqueue(3, 3);
        pq.enqueue(4, 4);
        pq.enqueue(5, 5);
        CHECK_THROWS_AS(pq.enqueue(6, 0), std::overflow_error);
    }

    SUBCASE("Underflow Error") {
        CHECK_THROWS_AS(pq.dequeue(), std::underflow_error);
    }

    SUBCASE("Decrease Key Errors") {
        pq.enqueue(8, 10);
        CHECK_THROWS_AS(pq.decrease_key(9, 1), std::invalid_argument);
        CHECK_THROWS_AS(pq.decrease_key(8, 20), std::invalid_argument);
    }
}

TEST_CASE("Basic Stack Operations") {
    Stack s(3);

    SUBCASE("Empty at start") {
        CHECK(s.empty());
    }

    SUBCASE("Push and Peek") {
        s.push(10);
        CHECK(!s.empty());
        CHECK(s.peek() == 10);
    }

    SUBCASE("Push and Pop") {
        s.push(1);
        s.push(2);
        s.push(3);
        CHECK(s.pop() == 3);
        CHECK(s.pop() == 2);
        CHECK(s.pop() == 1);
        CHECK(s.empty());
    }

    SUBCASE("Overflow") {
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);  // Should trigger overflow but not crash
        CHECK(s.peek() == 3);  // 4 should not be inserted
    }

    SUBCASE("Underflow") {
        CHECK(s.pop() == -1);  // Should trigger underflow but return -1
    }

    SUBCASE("Peek on empty stack") {
        CHECK(s.peek() == -1);  // Should return -1 and not crash
    }
}

TEST_CASE("UnionFind Basic Operations") {
    UnionFind uf(6);  // create 6 disjoint sets: {0}, {1}, ..., {5}

    SUBCASE("Initial state") {
        for (int i = 0; i < uf.get_size(); ++i) {
            CHECK(uf.find(i) == i);
        }
    }

    SUBCASE("Simple union") {
        uf.union_sets(0, 1);
        CHECK(uf.find(0) == uf.find(1));
    }

    SUBCASE("Union by rank") {
        uf.union_sets(0, 1);  // 0 <- 1
        uf.union_sets(2, 3);  // 2 <- 3
        uf.union_sets(0, 2);  // (0,1) <- (2,3)

        CHECK(uf.find(1) == uf.find(3));
    }

    SUBCASE("Already in same set") {
        uf.union_sets(4, 5);
        int rep1 = uf.find(4);
        uf.union_sets(4, 5);  // Should not change anything
        int rep2 = uf.find(5);
        CHECK(rep1 == rep2);
    }

    SUBCASE("Path compression check") {
        uf.union_sets(0, 1);
        uf.union_sets(1, 2);
        uf.union_sets(2, 3);
        uf.union_sets(3, 4);
        // All should have the same representative
        int root = uf.find(0);
        for (int i = 1; i <= 4; ++i) {
            CHECK(uf.find(i) == root);
        }
    }
}

