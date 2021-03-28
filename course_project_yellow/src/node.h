#pragma once

#include "date.h"
#include <iostream>
#include <string>
#include <memory>
#include <functional>

using namespace std;

enum class LogicalOperation {
	And,
	Or
};

enum class Comparison {
    Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const=0;
};
//
class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& date);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison cmp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& event);
	bool Evaluate(const Date& date, const string& event) const override;
	const Comparison cmp_;
	const string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& log_op, const shared_ptr<Node>& left, const shared_ptr<Node>& right);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const LogicalOperation log_op_;
	const shared_ptr<Node> left_;
	const shared_ptr<Node> right_;
};
