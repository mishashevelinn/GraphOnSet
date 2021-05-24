//
// Created by misha on 2/13/2021.
//

#ifndef PRACTICE_SET_H
#define PRACTICE_SET_H


#include <iostream>

using namespace std;


#define INITIAL_ARRAY_SIZE 12;
namespace DS {
    template<class T, class F>
    class Set {
    public:
        Set(const string &name);

        Set();

        explicit Set(Set *other);

        bool is_empty() const { return ord == 0; }

        bool contains(T &element);

        bool add(T &element);

        int get_size() const { return arr_size; }

        int get_ord() const { return ord; }

        string get_name() { return name; }

        void sort();

        void print_set(bool for_P);

        Set *unite(Set *other, const string &result_name);

        Set *intersect(Set *other, const string &result_name);

        T &get(int i);

        void set_name(string name);

        virtual ~Set();

        bool is_bigger(Set &other);

        bool has_larger_elements(Set &other);


        class Iterator {
        private:
            T *curr;
        public:
            Iterator(T *p_elem) : curr(p_elem) {};

            Iterator() { curr = arr; }

            Iterator operator++() {
                if (!curr) {
                    throw "null pointer in Set::Iterator";
                }
                curr++;
                return *this;
            }

            Iterator operator--() {
                if (!curr) {
                    throw "null pointer in Set::Iterator";
                }
                curr--;
            }

            T *getCurr() { return curr; }

            bool operator!=(Iterator it) {
                return curr != it.curr;
            }

            T &operator*() {
                if (!curr) {
                    throw "null pointer in Set::Iterator";
                }
                return *curr;
            }

            explicit operator T *() {
                return curr ? curr : NULL;
            }


        };

        Iterator begin() {
            return Iterator(arr);
        }

        Iterator end() {
            return Iterator(arr + ord);
        }

        Iterator find(Iterator begin, Iterator end, const T &elem) {
            while (begin != end && *begin != elem)
                ++begin;
            return begin;
        }

        void print(Iterator begin, Iterator end) const;

        void forEach(Iterator begin, Iterator end, const F &function);


    private:
        int arr_size;
        int ord;
        static T *arr;
        string name;


    };

    template<class T, class F>
    T *Set<T, F>::arr = new T[10];
}

#endif //PRACTICE_SET_H

#include "set_imp.h"