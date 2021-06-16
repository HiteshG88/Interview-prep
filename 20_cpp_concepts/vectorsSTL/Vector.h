template<typename t>
class Vector {
private:
    int curr_size;
    int max_size;
    t* arr;

public:
    Vector() {
        curr_size = 0;
        max_size = 1;
        arr = new t[max_size];
    }

    void push_back(t d) {
        // if arr is full
        if (curr_size == max_size) {
            t *oldArr = arr;
            arr = new t[max_size * 2];
            max_size *= 2;

            for (int i = 0; i < curr_size; i++)
                arr[i] = oldArr[i];

            delete [] oldArr;
        }

        arr[curr_size] = d;
        curr_size++;
    }

    void pop_back() {
        curr_size--;
    }

    t front() const {
        return arr[0];
    }

    t back() const {
        return arr[curr_size - 1];
    }

    bool empty() const {
        return curr_size == 0;
    }

    int capacity() const {
        return max_size;
    }

    int size() const {
        return curr_size;
    }

    t at(const int i) const {
        return arr[i];
    }

    // operator overload

    t operator [](int i) {
        return arr[i];
    }

    ~Vector() {
        delete [] arr;
    }
};
