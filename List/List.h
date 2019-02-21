//
// Created by baqkqpfhv on 2018/10/8.
//

#ifndef DSLAB1_LIST_H
#define DSLAB1_LIST_H

template <typename T, typename It>
class List
{
private:
    int _size;
protected:
    void up_size() { _size++; }
    void down_size() { _size--; }
    void reset_size(int new_size) { _size = new_size; }
public:
    List() : _size(0) {}
    List(const List &rhs) : _size(rhs._size) {}
    virtual ~List() = default;

    bool empty() const { return _size == 0; }
    int size() const { return _size; }

    virtual It begin() const = 0;
    virtual It end() const = 0;
    virtual It find(const T &rhs) const = 0;
    virtual It insert(It pos, const T &rhs) = 0;
    virtual It erase(It pos) = 0;
    virtual void clear() = 0;
};

#endif //DSLAB1_LIST_H
