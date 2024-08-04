#include <iostream>
#include <memory>
#include <list>
#include <set>

template <class T>
struct pool_allocator {
    typedef T value_type;

    static int pos;
    static constexpr int size = sizeof(T) * 1000;
    static uint8_t data[size];

    pool_allocator () noexcept {}
    ~pool_allocator() {}

    template <class U> pool_allocator  (const pool_allocator <U>&) noexcept {}

    T* allocate (std::size_t n) {
        if (pos + n > size)
            throw std::bad_alloc();
        
        int cur = pos;
        pos += n;
        return reinterpret_cast<T*>(data) + cur;
    }

    void deallocate (T* p, std::size_t n) {}

    template< class U >
    struct rebind
    {
        typedef pool_allocator<U> other;
    };
};



int main(int, char *[]) {
    pool_allocator<int> alloc_;
    std::set<int, pool_allocator<int>> pool_list(alloc_);   

    std::cout << "Hello" << std::endl;

	return 0;
}
