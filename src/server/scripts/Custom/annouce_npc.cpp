#include "Creature.h"
#include "Define.h"
#include "EventProcessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"

class DelayedWhisper : public BasicEvent
{
public:
	DelayedWhisper(Player* player) : BasicEvent(), player(player)
	{
		player->m_Events.AddEvent(this, player->m_Events.CalculateTime(5000));
	}

	bool Execute(uint64, uint32) override
	{
		if (Creature* creature = player->FindNearestCreature(600000, 25.0f))
		{
			creature->Whisper("Welcome %s to our mall. Please feel free to vote for us on our Website.", LANG_UNIVERSAL, player);
		}
		return true;
	}

	Player* player;
};

class FirstLogin : public PlayerScript
{
public:
	FirstLogin() : PlayerScript("FirstLogin") {}

	void OnLogin(Player* player, bool) override
	{
			return;
		new DelayedWhisper(player);
	}
};

void AddSC_FirstLogin()
{
	new FirstLogin();
}

void OnPlayerEnterMap(Map* map, Player* player);