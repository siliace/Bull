set(BULL_INC_CORE_FUNCTOR ${BULL_INC_CORE}/Functor)
set(BULL_SRC_CORE_FUNCTOR ${BULL_SRC_CORE}/Functor)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_FUNCTOR}/Functor.hpp
            ${BULL_INC_CORE_FUNCTOR}/Functor.inl
        PRIVATE
            ${BULL_INC_CORE_FUNCTOR}/AbstractFunctor.hpp
            ${BULL_INC_CORE_FUNCTOR}/AbstractFunctor.inl
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodConstWithArgs.hpp
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodConstWithArgs.inl
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodConstWithoutArgs.hpp
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodConstWithoutArgs.inl
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodWithArgs.hpp
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodWithArgs.inl
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodWithoutArgs.hpp
            ${BULL_INC_CORE_FUNCTOR}/FunctorMethodWithoutArgs.inl
            ${BULL_INC_CORE_FUNCTOR}/FunctorWithArgs.hpp
            ${BULL_INC_CORE_FUNCTOR}/FunctorWithArgs.inl
            ${BULL_INC_CORE_FUNCTOR}/FunctorWithoutArgs.hpp
            ${BULL_INC_CORE_FUNCTOR}/FunctorWithoutArgs.inl
        )