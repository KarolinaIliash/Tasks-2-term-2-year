#include "mediator.h"

void Chat::Send(std::string message, Participant* from) {
	for (auto& p : parts) {
		if (p != from) {
			p->Receive(message, from);
		}
	}
}
void Chat::AddParticipant(Participant* p) {
	parts.push_back(p);
}