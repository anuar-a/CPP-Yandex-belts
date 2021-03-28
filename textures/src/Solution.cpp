#include "Common.h"

using namespace std;

// Этот файл сдаётся на проверку
// Здесь напишите реализацию необходимых классов-потомков `IShape`

class Rectangle : public IShape {
public:
	virtual unique_ptr<IShape> Clone() const override {
		auto clone = make_unique<Rectangle>();
		clone->point_ = point_;
		clone->size_ = size_;
		clone->t_ptr = t_ptr;
		return clone;
	}

	virtual void SetPosition(Point point) override {
		point_ = point;
	}
	virtual Point GetPosition() const override {
		return point_;
	}

	virtual void SetSize(Size size) {
		size_ = size;
	}
	virtual Size GetSize() const override {
		return size_;
	}

	virtual void SetTexture(shared_ptr<ITexture> texture) override {
		t_ptr = texture;
	}
	virtual ITexture* GetTexture() const override {
		return t_ptr.get();
	}

	// Рисует фигуру на указанном изображении
	virtual void Draw(Image& image) const override {
		Point edge = {point_.x + size_.width, point_.y + size_.height};
		Point t_edge;
		if (t_ptr) {
			t_edge = {point_.x + t_ptr->GetSize().width, point_.y + t_ptr->GetSize().height};
		} else {
			t_edge = {0, 0};
		}
		for (int y = point_.y; y < image.size() && y < edge.y; ++y) {
			for (int x = point_.x; x < image[y].size() && x < edge.x; ++x) {
				if (t_ptr && x < t_edge.x && y < t_edge.y) {
					image[y][x] = t_ptr->GetImage().at(y - point_.y).at(x - point_.x);
				} else {
					image[y][x] = '.';
				}
			}
		}
	}
protected:
	Point point_;
	Size size_;
	shared_ptr<ITexture> t_ptr;
};

class Ellipse : public IShape {
public:
	virtual unique_ptr<IShape> Clone() const override {
		auto clone = make_unique<Ellipse>();
		clone->point_ = point_;
		clone->size_ = size_;
		clone->t_ptr = t_ptr;
		return clone;
	}

	virtual void SetPosition(Point point) override {
		point_ = point;
	}
	virtual Point GetPosition() const override {
		return point_;
	}

	virtual void SetSize(Size size) {
		size_ = size;
	}
	virtual Size GetSize() const override {
		return size_;
	}

	virtual void SetTexture(shared_ptr<ITexture> texture) override {
		t_ptr = texture;
	}
	virtual ITexture* GetTexture() const override {
		return t_ptr.get();
	}

	// Рисует фигуру на указанном изображении
	virtual void Draw(Image& image) const override {
		Point edge = {point_.x + size_.width, point_.y + size_.height};
		Point t_edge;
		if (t_ptr) {
			t_edge = {point_.x + t_ptr->GetSize().width, point_.y + t_ptr->GetSize().height};
		} else {
			t_edge = {0, 0};
		}
		for (int y = point_.y; y < image.size() && y < edge.y; ++y) {
			for (int x = point_.x; x < image[y].size() && x < edge.x; ++x) {
				Point centered = {x - point_.x, y - point_.y};
				if (t_ptr && IsPointInEllipse(centered, size_)) {
					if (x < t_edge.x && y < t_edge.y) {
						image[y][x] = t_ptr->GetImage().at(y - point_.y).at(x - point_.x);
					} else {
						image[y][x] = '.';
					}
				}
			}
		}
	}

protected:
	Point point_;
	Size size_;
	shared_ptr<ITexture> t_ptr;
};

// Напишите реализацию функции
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
	if (shape_type == ShapeType::Ellipse) {
		return make_unique<Ellipse>();
	} else if (shape_type == ShapeType::Rectangle){
		return make_unique<Rectangle>();
	}
}
