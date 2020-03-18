// vevtor2.h 
// Vector2 class defination
// Member functions are implement in vector2.cpp


#ifndef VECTOR2_h
#define VECTOR2_h


class Vector2 {

    public:
		Vector2(float x = 0, float y = 0);
        void addScaledVector(const Vector2& vector, float scale);
        float x{0.0};
        float y{0.0};
};

#endif