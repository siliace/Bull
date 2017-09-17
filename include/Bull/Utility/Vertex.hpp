#ifndef BULL_UTILITY_VERTEX_HPP
#define BULL_UTILITY_VERTEX_HPP

#include <Bull/Math/Vector/Vector2.hpp>
#include <Bull/Math/Vector/Vector3.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

#include <Bull/Utility/Export.hpp>

namespace Bull
{
    struct BULL_UTILITY_API Vertex
    {
        /*! \brief Default constructor
         *
         */
        Vertex() = default;

        /*! \brief Constructor
         *
         * \param position The position of the Vertex
         *
         */
        explicit Vertex(const Vector3F& position);

        /*! \brief Constructor
         *
         * \param position The position of the Vertex
         * \param texCoord The texture coordinate of the Vertex
         *
         */
        Vertex(const Vector3F& position, const Vector2F& texCoord);

        /*! \brief Constructor
         *
         * \param position The position of the Vertex
         * \param normal   The normal of the Vertex
         *
         */
        Vertex(const Vector3F& position, const Vector3F& normal);

        /*! \brief Constructor
         *
         * \param position The position of the Vertex
         * \param texCoord The texture coordinate of the Vertex
         * \param normal   The normal of the Vertex
         *
         */
        Vertex(const Vector3F& position, const Vector2F& texCoord, const Vector3F& normal);

        /*! \brief Constructor
         *
         * \param position The position of the Vertex
         * \param color    The color of the Vertex
         * \param texCoord The texture coordinate of the Vertex
         * \param normal   The normal of the Vertex
         *
         */
        Vertex(const Vector3F& position, const Vector4F& color, const Vector2F& texCoord = Vector2F::Zero, const Vector3F& normal = Vector3F::Zero);

        /*! \brief Compare a Vertex to this
         *
         * \param right The Vertex to compare to this
         *
         * \return True if right and this are equal
         *
         */
        bool operator==(const Vertex& right) const;

        /*! \brief Compare a Vertex to this
         *
         * \param right The Vertex to compare to this
         *
         * \return True if right and this are not equal
         *
         */
        bool operator!=(const Vertex& right) const;

        Vector3F position; /*!< The position of the Vertex */
        Vector4F color;    /*!< The color of the Vertex */
        Vector2F texCoord; /*!< The texture coordinate of the Vertex */
        Vector3F normal;   /*!< The normal of the Vertex */
    };
}

#endif // BULL_UTILITY_VERTEX_HPP
