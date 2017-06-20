#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"mediator.h"

TEST_CASE("mediator"){
	Chat* mediator1 = new Chat;
	
	Human* anna = new Human(mediator1, "Anna");
	Human* john = new Human(mediator1, "John");
	Bot* bot1 = new Bot(mediator1);
	SECTION("one chat") {
		anna->Send("Hello");
		REQUIRE(anna->GetLastMessage() == "");
		REQUIRE(john->GetLastMessage() == "I'm human John and I received a message: Hello from Anna");
		REQUIRE(bot1->GetLastMessage() == "I'm bot and I received a message: Hello from Anna");
		bot1->Send("Hi");
		REQUIRE(anna->GetLastMessage() == "I'm human Anna and I received a message: Hi from bot");
		REQUIRE(john->GetLastMessage() == "I'm human John and I received a message: Hi from bot");
		REQUIRE(bot1->GetLastMessage() == "I'm bot and I received a message: Hello from Anna");
	}
	Chat* mediator2 = new Chat; //other chat
	Human* liza = new Human(mediator2, "Liza");
	Bot* bot2 = new Bot(mediator2);
	SECTION("more chats") {
		REQUIRE(liza->GetLastMessage() == "");
		REQUIRE(bot2->GetLastMessage() == "");
		liza->Send("Hey");
		REQUIRE(anna->GetLastMessage() == "");
		REQUIRE(john->GetLastMessage() == "");
		REQUIRE(bot1->GetLastMessage() == "");
		REQUIRE(liza->GetLastMessage() == "");
		REQUIRE(bot2->GetLastMessage() == "I'm bot and I received a message: Hey from Liza");
	}
}