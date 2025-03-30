#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP


class UnionFind {
public:
    UnionFind(int size);
    ~UnionFind();
    
    int find(int x);
    void union_sets(int x, int y);
    
private:
    int* parent;
    int* rank;
    int size;
};

#endif
