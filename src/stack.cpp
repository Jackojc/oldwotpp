// For the custom stack object.

#ifndef WPP_STACK
#define WPP_STACK

#include <array>

namespace wpp {

    template <typename T, size_t X>
    class stack {

        private:
            std::array<T, X> items_;
            unsigned int index_;

        public:
            stack(): index_(0) {}
            ~stack() {}


            inline void push(const T &value) noexcept {
                items_[index_++] = value;
            }

            inline T pop() noexcept {
                return items_[--index_];
            }

            inline T peek(const unsigned int &index_) const noexcept {
                return items_[index_];
            }

            inline void clear() noexcept {
                index_ = 0;
            }

            inline size_t size() const noexcept {
                return X;
            }

    };

}


#endif