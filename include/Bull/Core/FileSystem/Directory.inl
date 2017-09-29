namespace Bull
{
    template <typename... Args>
    DirectoryRef Directory::make(Args&&... args)
    {
        Directory* directory = new Directory(std::forward<Args>(args)...);
        directory->setPersistent(false);

        return directory;
    }
}