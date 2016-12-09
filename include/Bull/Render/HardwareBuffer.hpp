#ifndef Bull_HardwareBuffer_hpp
#define Bull_HardwareBuffer_hpp

#include <utility>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class HardwareBuffer : public NonCopyable, public ContextResource
    {
    public:

        enum Type
        {
            Array   = 0x8892,
            Element = 0x8893,
        };

        enum Usage
        {
            StaticDraw  = 0x88E4,
            DynamicDraw = 0x88E8,
            StreamDraw  = 0x88E0,
        };

        /*! \brief Bind a buffer
         *
         * \param buffer The buffer to bind
         *
         */
        static void bind(const HardwareBuffer& buffer);

        /*! \brief Unbind any buffer
         *
         * \param type The type of buffer to unbind
         *
         */
        static void unbind(Type type);

    public:

        /*! \brief Constructor
         *
         * \param type The type the of OpenGL buffer to create
         *
         */
        HardwareBuffer(Type type);

        /*! \brief Destructor
         *
         */
        ~HardwareBuffer();

        /*! \brief Create the buffer in the VRAM
         *
         * \param size  The size of the buffer
         * \param usage The usage of the buffer
         *
         * \return Return true if the buffer was created successfully, false otherwise
         *
         */
        bool create(std::size_t size, Usage usage = Usage::StaticDraw);

        /*! \brief Fill the buffer
         *
         * \param data    Data to use to fill the buffer
         * \param size    The size of data
         * \param offset  The offset of the data in the buffer
         * \param discard True to flush the buffer before fill it, false to keep the original content
         *
         * \return Return true if the buffer was filled successfully, false otherwise
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0, bool discard = false);

        /*! \brief Flush the buffer
         *
         * \param keepMemory True to keep the allocated memory, false otherwise
         *
         */
        void flush(bool keepMemory = true);

        /*! \brief Destroy the buffer
         *
         */
        void destroy();

        /*! \brief Get the buffer system handler
         *
         * \return Return the native buffer system handler
         *
         */
        unsigned int getSystemHandler() const;

    private:

        unsigned int m_id;
        Type         m_type;
        std::size_t  m_size;
    };
}

#endif // Bull_HardwareBuffer_hpp
