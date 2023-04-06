#include<iostream>
#include<cassert>

class Pyramid {
public:
	Pyramid(int length, int height, int width):length_(length), height_(height), width_(width){}

	int getLength() { return length_; }
	int getHeight() { return height_; }
	int getWidth() { return width_; }


	void setLength(int length);
	void setHeight(int height);
	void setWidth(int width);

	int pyramidVolume();
	int pyramidSurface();


private:
	int length_;
	int height_;
	int width_;
};

void Pyramid::setHeight(int height) {
	if (height > 0)
		this->height_ = height;
}

void Pyramid::setLength(int length) {
	if (length > 0) {
		this->length_ = length;
	}
}

void Pyramid::setWidth(int width) {
	if (width > 0) {
		this->width_ = width;
	}
}

int Pyramid::pyramidVolume() {
	return length_ * width_ * height_ / 3;
}

int Pyramid::pyramidSurface() {
		return (length_ * width_) + (length_ * height_) + (width_ * height_);
}

int main() {
	Pyramid pyramid(1, 2, 3);

	assert(pyramid.getLength() == 1);
	assert(pyramid.getHeight() == 2);
	assert(pyramid.getWidth() == 3);
	assert(pyramid.pyramidVolume() == 2);
	assert(pyramid.pyramidSurface() == 11);

	pyramid.setHeight(8);
	pyramid.setWidth(5);
	pyramid.setLength(5);

	assert(pyramid.getLength() == 5);
	assert(pyramid.getHeight() == 8);
	assert(pyramid.getWidth() == 5);
	assert(pyramid.pyramidVolume() == 66);
	assert(pyramid.pyramidSurface() == 105);

	

	


}