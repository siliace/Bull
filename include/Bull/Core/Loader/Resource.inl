namespace Bull
{
    template <typename T, typename S, typename L, typename P>
    void Resource<T, S, L, P>::setSaver(S* saver)
    {
        s_saver.reset(saver);
    }

    template <typename T, typename S, typename L, typename P>
    void Resource<T, S, L, P>::setLoader(L* loader)
    {
        s_loader.reset(loader);
    }

    template <typename T, typename S, typename L, typename P>
    Resource<T, S, L, P>::~Resource() = default;

    template <typename T, typename S, typename L, typename P>
    const S* Resource<T, S, L, P>::getSaver() const
    {
        return s_saver.get();
    }

    template <typename T, typename S, typename L, typename P>
    const L* Resource<T, S, L, P>::getLoader() const
    {
        return s_loader.get();
    }
}