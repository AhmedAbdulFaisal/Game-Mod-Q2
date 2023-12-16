/*
	By Ahmed Faisal
	lighting class for the 'illumination flare' effect 

*/

#include "g_local.h"

void flare_create(edict_t* ent) {
	edict_t* flare;
	flare = G_Spawn();
	flare->think = flare_think;
	flare->nextthink = level.time + 0.1;
	flare->s.effects = EF_BLASTER;
	flare->s.modelindex = 1;
	flare->s.solid = SOLID_NOT;
	flare->owner = ent;
	flare->movetype = MOVETYPE_NOCLIP;
	flare->clipmask = MASK_SHOT;
	
	gi.linkentity(flare);
	VectorCopy(ent->s.origin, flare->s.origin);
	ent->client->flare = 1;
	
}

void flare_destroy(edict_t* ent) {
	ent->flare->think = G_FreeEdict;
	ent->client->flare = 0;
}

void flare_think(edict_t* ent) {
	
	VectorCopy(ent->owner->s.origin, ent->s.origin);
	ent->nextthink = level.time + 0.1;
}
