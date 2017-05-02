#include <iostream>

#include <Bull/Utility/TransformationPipeline/Transformation.hpp>

using namespace Bull;

void showMatrix(const Matrix4F& matrix)
{
    for(unsigned int i = 0; i < 4; i++)
    {
        for(unsigned int j = 0; j < 4; ++j)
        {
            std::cout << "|" << matrix(j, i);
        }

        std::cout << "|" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    Vector3F scale;
    Vector3F translation;
    Transformation transformation;

    scale = Vector3F(3.f, 3.f, 3.f);
    translation = Vector3F(2.f, 2.f, -3.f);

    transformation = Transformation::make(translation, EulerAnglesF(AngleF::Zero, AngleF::Zero, AngleF::degree(90.f)), scale);

    showMatrix(transformation.toMatrix());

    return 0;
}