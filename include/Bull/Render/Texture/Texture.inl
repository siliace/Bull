namespace Bull
{
    template <typename... Args>
    TextureRef Texture::make(Args&&... args)
    {
        Texture* texture = new Texture(std::forward<Args>(args)...);
        texture->setPersistent(false);

        return texture;
    }

    bool Texture::isEnableRepeat() const
    {
        return m_isRepeated;
    }

    bool Texture::isEnableSmooth() const
    {
        return m_isSmooth;
    }

    const Vector2UI& Texture::getSize() const
    {
        return m_size;
    }
}