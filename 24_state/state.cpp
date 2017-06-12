#include"state.h"

Request::Request() {
	Request::state = Existed::SetState();
}

std::string Request::SendAnswer() {
	return Request::state->SendAnswer();
}

bool Request::Accept() {
	return Request::state->Accept(this);
}

bool Request::Broke() {
	return Request::state->Broke(this);
}

bool Request::Examine() {
	return Request::state->Examine(this);
}

bool Request::Postpone() {
	return Request::state->Postpone(this);
}

bool Request::Refuse() {
	return Request::state->Refuse(this);
}

void Request::SetCurrent(RequestState* currentState) {
	Request::state = currentState;
}

RequestState* Existed::SetState() {
	static Existed existState;
	return &existState;
}

std::string Existed::SendAnswer() {
	return "Request is existed";
}

bool Existed::Postpone(Request* request) {
	request->SetCurrent(Postpone::SetState());
	return 1;
}

bool Existed::Accept(Request* request) {
	request->SetCurrent(Accept::SetState());
	return 1;
}

bool Existed::Broke(Request* request) {
	request->SetCurrent(Broke::SetState());
	return 1;
}

bool Existed::Refuse(Request* request) {
	request->SetCurrent(Refuse::SetState());
	return 1;
}

bool Existed::Examine(Request* request) {
	request->SetCurrent(Examine::SetState());
	return 1;
}

RequestState* Examine::SetState() {
	static Examine examState;
	return &examState;
}

std::string Examine::SendAnswer() {
	return "Request is examining now";
}

bool Examine::Accept(Request* request) {
	request->SetCurrent(Accept::SetState());
	return 1;
}

bool Examine::Broke(Request* request) {
	request->SetCurrent(Broke::SetState());
	return 1;
}

bool Examine::Postpone(Request* request) {
	request->SetCurrent(Postpone::SetState());
	return 1;
}

bool Examine::Refuse(Request* request) {
	request->SetCurrent(Refuse::SetState());
	return 1;
}

RequestState* Postpone::SetState() {
	static Postpone postState;
	return &postState;
}

std::string Postpone::SendAnswer() {
	return "Request will be examine later";
}

bool Postpone::Examine(Request* request) {
	request->SetCurrent(Examine::SetState());
	return 1;
}

bool Postpone::Broke(Request* request) {
	request->SetCurrent(Broke::SetState());
	return 1;
}

RequestState* Accept::SetState() {
	static Accept accState;
	return &accState;
}

std::string Accept::SendAnswer() {
	return "Request is accepted";
}

bool Accept::Broke(Request* request) {
	request->SetCurrent(Broke::SetState());
	return 1;
}

RequestState* Refuse::SetState() {
	static Refuse refState;
	return &refState;
}

std::string Refuse::SendAnswer() {
	return "Request is refused";
}

bool Refuse::Broke(Request* request) {
	request->SetCurrent(Broke::SetState());
	return 1;
}

RequestState* Broke::SetState() {
	static Broke brokeState;
	return &brokeState;
}

std::string Broke::SendAnswer() {
	return "Request was broken";
}