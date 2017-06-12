#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include"state.h"

TEST_CASE("class Request"){
	SECTION("Constructor") {
		Request* request = new Request();
		REQUIRE(request->SendAnswer() == "Request is existed");
	}
	Request* request = new Request();
		SECTION("SetCurrent") {
			RequestState* state = Existed::SetState();
			request->SetCurrent(state);
			REQUIRE(request->SendAnswer() == "Request is existed");
			state = Examine::SetState();
			request->SetCurrent(state);
			REQUIRE(request->SendAnswer() == "Request is examining now");
			state = Postpone::SetState();
			request->SetCurrent(state);
			REQUIRE(request->SendAnswer() == "Request will be examine later");
			state = Broke::SetState();
			request->SetCurrent(state);
			REQUIRE(request->SendAnswer() == "Request was broken");
			state = Accept::SetState();
			request->SetCurrent(state);
			REQUIRE(request->SendAnswer() == "Request is accepted");
			state = Refuse::SetState();
			request->SetCurrent(state);
			REQUIRE(request->SendAnswer() == "Request is refused");
	}
		SECTION("Postpone") {
			SECTION("After constructor") {
				REQUIRE(request->Postpone());
				REQUIRE(request->SendAnswer() == "Request will be examine later");
				REQUIRE(!request->Postpone());
				REQUIRE(request->SendAnswer() == "Request will be examine later");
			}
			RequestState* state = Existed::SetState();
			SECTION("After state Exist") {
				request->SetCurrent(state);
				REQUIRE(request->Postpone());
				REQUIRE(request->SendAnswer() == "Request will be examine later");
			}
			SECTION("After state Examine") {
				state = Examine::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Postpone());
				REQUIRE(request->SendAnswer() == "Request will be examine later");
			}
			SECTION("After state Accept") {
				state = Accept::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Postpone());
				REQUIRE(request->SendAnswer() == "Request is accepted");
			}
			SECTION("After state Refuse") {
				state = Refuse::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Postpone());
				REQUIRE(request->SendAnswer() == "Request is refused");
			}
			SECTION("After state Broke") {
				state = Broke::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Postpone());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
		}
		SECTION("Examine") {
			SECTION("After constructor") {
				REQUIRE(request->Examine());
				REQUIRE(request->SendAnswer() == "Request is examining now");
				REQUIRE(!request->Examine());
				REQUIRE(request->SendAnswer() == "Request is examining now");
			}
			RequestState* state = Existed::SetState();
			SECTION("After state Existed") {
				request->SetCurrent(state);
				REQUIRE(request->Examine());
				REQUIRE(request->SendAnswer() == "Request is examining now");
			}
			SECTION("After state Postpone") {
				state = Postpone::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Examine());
				REQUIRE(request->SendAnswer() == "Request is examining now");
			}
			SECTION("After state Accept") {
				state = Accept::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Examine());
				REQUIRE(request->SendAnswer() == "Request is accepted");
			}
			SECTION("After state Refuse") {
				state = Refuse::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Examine());
				REQUIRE(request->SendAnswer() == "Request is refused");
			}
			SECTION("After state Broke") {
				state = Broke::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Examine());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
		}
		SECTION("Accept") {
			SECTION("After constructor") {
				REQUIRE(request->Accept());
				REQUIRE(request->SendAnswer() == "Request is accepted");
				REQUIRE(!request->Accept());
				REQUIRE(request->SendAnswer() == "Request is accepted");
			}
			RequestState* state = Existed::SetState();
			SECTION("After state Existed") {
				request->SetCurrent(state);
				REQUIRE(request->Accept());
				REQUIRE(request->SendAnswer() == "Request is accepted");
			}
			SECTION("After state Examine") {
				state = Examine::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Accept());
				REQUIRE(request->SendAnswer() == "Request is accepted");
			}
			SECTION("After state Postpone") {
				state = Postpone::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Accept());
				REQUIRE(request->SendAnswer() == "Request will be examine later");
			}
			SECTION("After state Refuse") {
				state = Refuse::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Accept());
				REQUIRE(request->SendAnswer() == "Request is refused");
			}
			SECTION("After state Broke") {
				state = Broke::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Accept());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
		}
		SECTION("Refuse") {
			SECTION("After constructor") {
				REQUIRE(request->Refuse());
				REQUIRE(request->SendAnswer() == "Request is refused");
				REQUIRE(!request->Refuse());
				REQUIRE(request->SendAnswer() == "Request is refused");
			}
			RequestState* state = Existed::SetState();
			SECTION("After state Existed") {
				request->SetCurrent(state);
				REQUIRE(request->Refuse());
				REQUIRE(request->SendAnswer() == "Request is refused");
			}
			SECTION("After state Examine") {
				state = Examine::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Refuse());
				REQUIRE(request->SendAnswer() == "Request is refused");
			}
			SECTION("After state Postpone") {
				state = Postpone::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Refuse());
				REQUIRE(request->SendAnswer() == "Request will be examine later");
			}
			SECTION("After state Accept") {
				state = Accept::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Refuse());
				REQUIRE(request->SendAnswer() == "Request is accepted");
			}
			SECTION("After state Broke") {
				state = Broke::SetState();
				request->SetCurrent(state);
				REQUIRE(!request->Refuse());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
		}
		SECTION("Broke") {
			SECTION("After constructor") {
				REQUIRE(request->Broke());
				REQUIRE(request->SendAnswer() == "Request was broken");
				REQUIRE(!request->Broke());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
			RequestState* state = Existed::SetState();
			SECTION("After state Existed") {
				request->SetCurrent(state);
				REQUIRE(request->Broke());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
			SECTION("After state Examine") {
				state = Examine::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Broke());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
			SECTION("After state Postpone") {
				state = Postpone::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Broke());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
			SECTION("After state Accept") {
				state = Accept::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Broke());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
			SECTION("After state Refuse") {
				state = Refuse::SetState();
				request->SetCurrent(state);
				REQUIRE(request->Broke());
				REQUIRE(request->SendAnswer() == "Request was broken");
			}
		}
		delete request;
}

TEST_CASE("States") {
	Request* request = new Request();
	SECTION("Existed") {
		RequestState* state = Existed::SetState();
		request->SetCurrent(state);
		REQUIRE(state->Accept(request));
		state = Existed::SetState();
		request->SetCurrent(state);
		REQUIRE(state->Broke(request));
		request->SetCurrent(state);
		REQUIRE(state->Examine(request));
		request->SetCurrent(state);
		REQUIRE(state->Postpone(request));
		request->SetCurrent(state);
		REQUIRE(state->Refuse(request));
		request->SetCurrent(state);
		REQUIRE(state->SendAnswer() == "Request is existed");
	}
	SECTION("Examine") {
		RequestState* state = Examine::SetState();
		request->SetCurrent(state);
		REQUIRE(state->Accept(request));
		request->SetCurrent(state);
		REQUIRE(state->Broke(request));
		request->SetCurrent(state);
		REQUIRE(!state->Examine(request));
		request->SetCurrent(state);
		REQUIRE(state->Postpone(request));
		request->SetCurrent(state);
		REQUIRE(state->Refuse(request));
		request->SetCurrent(state);
		REQUIRE(state->SendAnswer() == "Request is examining now");
	}
	SECTION("Postpone") {
		RequestState* state = Postpone::SetState();
		request->SetCurrent(state);
		REQUIRE(!state->Accept(request));
		request->SetCurrent(state);
		REQUIRE(state->Broke(request));
		request->SetCurrent(state);
		REQUIRE(state->Examine(request));
		request->SetCurrent(state);
		REQUIRE(!state->Postpone(request));
		request->SetCurrent(state);
		REQUIRE(!state->Refuse(request));
		request->SetCurrent(state);
		REQUIRE(state->SendAnswer() == "Request will be examine later");
	}
	SECTION("Accept") {
		RequestState* state = Accept::SetState();
		request->SetCurrent(state);
		REQUIRE(!state->Accept(request));
		request->SetCurrent(state);
		REQUIRE(state->Broke(request));
		request->SetCurrent(state);
		REQUIRE(!state->Examine(request));
		request->SetCurrent(state);
		REQUIRE(!state->Postpone(request));
		request->SetCurrent(state);
		REQUIRE(!state->Refuse(request));
		request->SetCurrent(state);
		REQUIRE(state->SendAnswer() == "Request is accepted");
	}
	SECTION("Refuse") {
		RequestState* state = Refuse::SetState();
		request->SetCurrent(state);
		REQUIRE(!state->Accept(request));
		request->SetCurrent(state);
		REQUIRE(state->Broke(request));
		request->SetCurrent(state);
		REQUIRE(!state->Examine(request));
		request->SetCurrent(state);
		REQUIRE(!state->Postpone(request));
		request->SetCurrent(state);
		REQUIRE(!state->Refuse(request));
		request->SetCurrent(state);
		REQUIRE(state->SendAnswer() == "Request is refused");
	}
	SECTION("Broke") {
		RequestState* state = Broke::SetState();
		request->SetCurrent(state);
		REQUIRE(!state->Accept(request));
		request->SetCurrent(state);
		REQUIRE(!state->Broke(request));
		REQUIRE(!state->Examine(request));
		request->SetCurrent(state);
		REQUIRE(!state->Postpone(request));
		request->SetCurrent(state);
		REQUIRE(!state->Refuse(request));
		request->SetCurrent(state);
		REQUIRE(state->SendAnswer() == "Request was broken");
	}
	delete request;
}