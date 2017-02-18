#include <limits>

namespace Bull
{
    template<typename T>
    Rectangle<T> Polygon<T>::getBounds() const
    {
        T xMin, xMax, yMin, yMax;

        xMin = yMin = std::numeric_limits<T>::max();
        xMax = yMax = std::numeric_limits<T>::min();

        for(unsigned int i = 0; i < getVertexCount(); i++)
        {
            Vector2<T> vertex = getVertex(i);

            xMin = std::min(xMin, vertex.x);
            yMin = std::min(yMin, vertex.y);
            xMax = std::max(xMax, vertex.x);
            yMax = std::max(yMax, vertex.y);
        }

        return Rectangle<T>(xMin, yMin, xMax - xMin, yMax - yMin);
    }
}
