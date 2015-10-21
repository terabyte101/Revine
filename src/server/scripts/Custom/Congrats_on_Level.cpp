#include "ScriptMgr.h"
#include "Player.h"

class custom_CongratsOnLevel : public PlayerScript
{
public:
    custom_CongratsOnLevel() : PlayerScript("custom_CongratsOnLevel") { }

    void OnLevelChanged(Player* player, uint8 newLevel)
    {
        /*uint32 money, item, item2, spell;*/

        switch(++newLevel)
        {
        /*    case 10:
				*/
        break;
        /*    case 20:
				*/
        break;
         /*   case 30:
				*/
        break;
         /*   case 40:
				*/
        break;
            case 50:
		/*
		money = 200;
        item = ITEMID;
        item2 = ITEMID2;
        spell = SPELLID;	
		*/
        break;
        /*    case 60:
				*/
        break;
            case 70:
		/*
		money = 200;
        item = ITEMID;
        item2 = ITEMID2;
        spell = SPELLID;	
		*/
        break;
            case 80:
		/*
		money = 200;
        item = ITEMID;
        item2 = ITEMID2;
        spell = SPELLID;	
		*/
        break;
            default:
        return;
        }

        std::ostringstream ss;
        ss << "|cffFF0000[Level Bot]|r Congrats to " << player->GetName() << " on reaching level " << (uint32)newLevel;
        sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
		/*
        std::ostringstream ss2;
        ss2 << "For your hard work and dedication you have been awarded " << money << " gold and a special item!";
        player->GetSession()->SendNotification(ss2.str().c_str());
		
        player->ModifyMoney(money*GOLD);
		player->AddItem(item, 1);
        player->AddItem(item2, 1);
		player->LearnSpell(spell, false);
		*/
    }
};

void AddSC_custom_CongratsOnLevel()
{
    new custom_CongratsOnLevel();
}