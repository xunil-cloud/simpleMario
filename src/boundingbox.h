// boundingbox.h 
// BoundingBox class defination
// Member functions are implement in boundingbox.cpp


#ifndef BOUNDINGBOX_h
#define BOUNDINGBOX_h


class BoundingBox {

    public:
		BoundingBox(float x, float y, float width, float height);
		float getCenterX();
        float getCenterY();
        float getHalfHeight();
        float getHalfWidth();
        float getLeft(){return centerX - halfwidth;}
        float getTop(){return centerY - halfheight;}
        float getRight(){return centerX + halfwidth;}
        float getBottom(){return centerY + halfheight;}
    
    
        float centerX{0.0};
        float centerY{0.0};
        float halfheight{0.0};
		float halfwidth{0.0};
};

#endif