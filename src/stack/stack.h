#ifndef WPP_STACK_H
#define WPP_STACK_H

namespace wpp {

    template <typename T, size_t X>
    class stack {

        private:
            std::array<T, X> items_;
            unsigned int index_;

        public:
            stack(): index_(0) {}
            ~stack() {}

            inline std::array<T, X>* get_ref() noexcept {
                return &items_;
            }

            inline void push(const T &value) noexcept {
                items_[index_++] = value;
            }

            inline T pop() noexcept {
                return items_[--index_];
            }

            inline T peek(const unsigned int &index) const noexcept {
                return items_[index];
            }

            inline T peek_top() const noexcept {
                return items_[index_];
            }

            inline void clear() noexcept {
                index_ = 0;
            }

            inline size_t size() const noexcept {
                return index_;
            }
    };
}

#endif