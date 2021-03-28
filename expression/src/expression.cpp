#include "Common.h"
#include <iostream>

class ValueExpression : public Expression {
public:
	ValueExpression(int value):value_(value) {
	}

	virtual int Evaluate() const override {
		return value_;
	}

    virtual std::string ToString() const override {
    	return std::to_string(value_);
    }

private:
	int value_;
};

class SumExpression : public Expression {
public:
	SumExpression(ExpressionPtr left, ExpressionPtr right):left_(move(left)), right_(move(right)) {
	}

	virtual int Evaluate() const override {
		return left_->Evaluate() + right_->Evaluate();
	}

    virtual std::string ToString() const override {
    	return "(" + left_->ToString() + ")" + "+" + "(" + right_->ToString() + ")";
    }

private:
    const ExpressionPtr left_, right_;
};

class ProductExpression : public Expression {
public:
	ProductExpression(ExpressionPtr left, ExpressionPtr right):left_(move(left)), right_(move(right)) {
	}

	virtual int Evaluate() const override {
		return left_->Evaluate() * right_->Evaluate();
	}

    virtual std::string ToString() const override {
    	return "(" + left_->ToString() + ")" + "*" + "(" + right_->ToString() + ")";
    }

private:
    const ExpressionPtr left_, right_;
};

// Функции для формирования выражения
ExpressionPtr Value(int value) {
	auto v = std::make_unique<ValueExpression>(value);
	return move(v);
}

ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
	auto v = std::make_unique<SumExpression>(move(left), move(right));
	return move(v);
}

ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
	auto v = std::make_unique<ProductExpression>(move(left), move(right));
	return move(v);
}
