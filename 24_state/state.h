#pragma once
#include<string>

class Request {
private:
	class RequestState* state;
public:
	Request();
	std::string SendAnswer();
	void SetCurrent(RequestState* currentState);
	bool Postpone();
	bool Examine();
	bool Accept();
	bool Refuse();
	bool Broke();
};

class RequestState {
public:
	virtual bool Postpone(Request* request) { return 0; };
	virtual std::string SendAnswer() { return "No news"; };
	virtual bool Examine(Request* request) { return 0; };
	virtual bool Accept(Request* request) { return 0; };
	virtual bool Refuse(Request* request) { return 0; };
	virtual bool Broke(Request* request) { return 0; };
};

class Existed : public RequestState {
public:
	static RequestState* SetState();
	virtual bool Postpone(Request* request) override;
	virtual std::string SendAnswer() override;
	virtual bool Examine(Request* request) override;
	virtual bool Accept(Request* request) override;
	virtual bool Refuse(Request* request) override;
	virtual bool Broke(Request* request) override;
};

class Postpone : public RequestState {
public:
	static RequestState* SetState();
	virtual std::string SendAnswer() override;
	virtual bool Examine(Request* request) override;
	virtual bool Broke(Request* request) override;
};
class Examine : public RequestState {
public:
	static RequestState* SetState();
	virtual bool Postpone(Request* request) override;
	virtual std::string SendAnswer() override;
	virtual bool Accept(Request* request) override;
	virtual bool Refuse(Request* request) override;
	virtual bool Broke(Request* request) override;
};
class Accept : public RequestState {
public:
	static RequestState* SetState();
	virtual std::string SendAnswer() override;
	virtual bool Broke(Request* request) override;
};
class Refuse : public RequestState {
public:
	static RequestState* SetState();
	virtual std::string SendAnswer() override;
	virtual bool Broke(Request* request) override;
};
class Broke : public RequestState {
public:
	static RequestState* SetState();
	virtual std::string SendAnswer() override;
};