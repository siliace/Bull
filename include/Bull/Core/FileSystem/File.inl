namespace Bull
{
    template <typename... Args>
    FileRef File::make(Args&&... args)
    {
        File* file = new File(std::forward<Args>(args)...);
        file->setPersistent(false);

        return file;
    }
}