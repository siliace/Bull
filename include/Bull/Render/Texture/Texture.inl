namespace Bull
{
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