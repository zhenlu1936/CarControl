#pragma once
namespace car{
    template <typename T>
    class Singleton final{
        public:
        static T& instance(void) noexcept{
            static T instance;
            return instance;
        }
        Singleton(const Singleton&)noexcept =delete;
        Singleton& operator=(const Singleton&)noexcept =delete;
        private:
        Singleton(void)noexcept=default;
        ~Singleton(void)noexcept=default;
    };
}